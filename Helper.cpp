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

// ����ַ���
// ���봮 a=1;b=c;
// �������
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
	
	// ͳ�Ƴ����ָ���������
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

	//// ������������
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

	// �ҵ����ֵ
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

	// ����ַ���
	strFields = Split(log, cSp);

	// ���γ������еĿ���
	strRet += RegexTest(strFields, cSp);
	

	return strRet;
}

// �����Ѿ���ֺõ�ԭʼ�ı������飬��һ����ÿ���ֶ����ʺϵ�������ʽ
// ������е�������������
std::string CHelper::RegexTest(EnumStrings strFields, char cSp)
{
	int i = 0;
	int nVaildLen = 0;
	bool bMatched = false;
	std::string strRet;
	std::string strField, strName, strVal, strRegex;
	EnumStrings::iterator itor;
	char* szRegex[] = {"(\\d+)", "(\\S+)", "(.*?)", "(.*)"};// ��˳��

	for (itor=strFields.begin();itor!=strFields.end();itor++)
	{
		strField = *itor;
		// ȡ������           a=1�е�a=
		Global::Func::SingleMatch("(\\S+=)", strField, strName);
		nVaildLen = strField.size() - strName.size();
		// ��ϱ���
		strRet += strName;

		// �������ȡֵ       a=1�е�1��������ʽ��ʲô
		bMatched = false;
		for (i=0;i<4;i++)
		{
			//(?<=a=)\d+
			strRegex = "(?<=" + strName + ")";
			strRegex += szRegex[i];
			if (Func::MATCH_SUCCESS==Global::Func::SingleMatch(strRegex.c_str(), strField, strVal))
			{
				// ֵ��֤��ȡ��ֵ����ֵ������ȷ����
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
			// ���ȡֵ
			strRet += szRegex[i];

			// ��Ϸָ���
			strRet += cSp;
		}
	}

	return strRet;
}