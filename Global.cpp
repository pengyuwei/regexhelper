#include ".\global.h"
#include "regexpr2.h"

//////////////////////////////////////////////////////////////////////////
// ƥ�䵥һ���
// ����ֵ��ƥ��ɹ�������
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
// ƥ�����
// ����ֵ��ʾƥ��ɹ��Ľ��������0:ƥ��ʧ�ܣ�-1:�쳣��>0:�ɹ�
// ��������vector��
// ע��vector���������ά�������������������
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
			//vsResult.push_back("ƥ��ʧ��");
		}
	}
	catch (...)
	{
		vsResult.push_back("�����쳣! �Ƿ���������ʽ!");
		ret = (int)MATCH_FAILED;
	}

	return ret;
}