#include ".\global.h"
#include "regexpr2.h"

//////////////////////////////////////////////////////////////////////////
// 匹配单一结果
// 返回值：匹配成功的数量
int Global::Func::SingleMatch(const std::string &strRule, const std::string &strSourceString, std::string &strResult)
{
	int nRet = MATCH_NONE;
	regex::match_results *results = new regex::match_results();
		regex::match_results::backref_type *br = new regex::match_results::backref_type();

	regex::rpattern *pat = new regex::rpattern(strRule.c_str());
	*br = pat->match(strSourceString.c_str(), *results);
	

	if (br->matched)
	{
		strResult = br->str();
		nRet = MATCH_SUCCESS;
	}
	delete pat;
	delete br;
	delete results;

	return nRet;
}
//////////////////////////////////////////////////////////////////////////
// 匹配多结果
// 返回值表示匹配成功的结果个数，0:匹配失败；-1:异常；>0:成功
// 结果存放在vector中
// 注意vector必须调用者维护，函数自身不负责清空
int Global::Func::MultiMatch(const std::string &strRule, const std::string &strProtype, std::vector<std::string> &vsResult)
{
	std::string::size_type ret = -1;

 	try
	{
		regex::match_results results;
		regex::rpattern pat(strRule, regex::NOCASE | regex::GLOBAL | regex::ALLBACKREFS);
		regex::match_results::backref_type br = pat.match(strProtype, results);
		if( !br.matched )
		{
			return (int)MATCH_NONE;
		}
		regex::match_results::backref_vector backrefs = results.all_backrefs();

		ret = backrefs.size();
		for (int i=0; i<ret; i++)
		{
			vsResult.push_back(backrefs[i].str());
		}

		if (ret == 0)
		{
			//vsResult.push_back("匹配失败");
		}
	}
	catch (...)
	{
		vsResult.push_back("发生异常! 非法的正则表达式!");
		ret = (int)MATCH_FAILED;
	}

	return ret;
}