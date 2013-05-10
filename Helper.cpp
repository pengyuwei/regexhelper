#include "stdafx.h"
#include ".\helper.h"
#include <string>
using namespace Global;

CHelper::CHelper(void)
{
}

CHelper::~CHelper(void)
{
}

// 拆分字符串
// 输入串 a=1;b=c;
// 输出数组
// a=1
// b=c
Global::EnumStrings CHelper::Split(const char* str, const char sp)
{
	Global::EnumStrings strFields;
	char* buf = new char[strlen(str)+1];
	int sPos = 0;
	for (int i=0;i<strlen(str);i++)
	{
		if (str[i]==sp)
		{
			memset(buf, 0, strlen(str)+1);
			memcpy(buf, str+sPos, i-sPos);
			sPos = i+1;
			strFields.push_back(EnumStrings::value_type(buf));
		}
	}
	delete[] buf;

	return strFields;
}
std::string CHelper::AutoMakeRegex(const char* log)
{
	EnumStrings strFields;
	char sp[]={':'
				, ' ' 
				, ','
				, ';'};
	std::string strRet;
	std::string strLog = log;
	int lens[sizeof(sp)]={0};
	int i=0;
	
	// 统计常见分隔符的数量
	for (i=0;i<sizeof(sp);i++)
	{
		for (int j=0;j<strlen(log);j++)
		{
			if (log[j]==sp[i])
			{
				lens[i]++;
			}
		}
	}

	//// 按照数量排序
	//for (i=0;i<sizeof(sp)-1;i++)
	//{
	//	if (lens[i]<lens[i+1])
	//	{
	//		// 2,5
	//		lens[i]  += lens[i+1];//7,5
	//		lens[i+1] = lens[i] - lens[i+1];//7,2
	//		lens[i]   = lens[i] - lens[i+1]; //5,2 
	//	}
	//}
	//if (lens[0]==0)
	//{
	//	return "(.*)";
	//}

	// 找到最大值
	int nMax = 0;
	char cSp = 0;
	for (i=0;i<sizeof(sp);i++)
	{
		if (nMax<lens[i])
		{
			nMax = lens[i];
			cSp = sp[i];
		}
	}
	if (nMax==0)
	{
		return "(.*)";
	}

	// 拆分字符串
	strFields = Split(log, cSp);

	// 依次尝试所有的可能
	strRet += RegexTest(strFields, cSp);
	

	return strRet;
}

// 输入已经拆分好的原始文本串数组，逐一试验每个字段最适合的正则表达式
// 组合所有的试验结果，返回
std::string CHelper::RegexTest(EnumStrings strFields, char cSp)
{
	int i = 0;
	int nVaildLen = 0;
	bool bMatched = false;
	std::string strRet;
	std::string strField, strName, strVal, strRegex;
	EnumStrings::iterator itor;
	char* szRegex[] = {"(\\d+)", "(\\S+)", "(.*?)", "(.*)"};// 按顺序

	for (itor=strFields.begin();itor!=strFields.end();itor++)
	{
		strField = *itor;
		// 取出变量           a=1中的a=
		Global::Func::SingleMatch("(\\S+=)", strField, strName);
		nVaildLen = strField.size() - strName.size();
		// 组合变量
		strRet += strName;

		// 尝试如何取值       a=1中的1的正则表达式是什么
		bMatched = false;
		for (i=0;i<4;i++)
		{
			//(?<=a=)\d+
			strRegex = "(?<=" + strName + ")";
			strRegex += szRegex[i];
			if (Func::MATCH_SUCCESS==Global::Func::SingleMatch(strRegex.c_str(), strField, strVal))
			{
				// 值验证，取出值，但值必须正确才行
				if (strVal.size()==nVaildLen)
				{
					bMatched = true;
					break;
				}
				continue;
			}
		}

		if (bMatched)
		{
			// 组合取值
			strRet += szRegex[i];

			// 组合分隔符
			strRet += cSp;
		}
	}

	return strRet;
}