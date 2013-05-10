#pragma once
#include <string>
#include <vector>

namespace Global
{
	// Make new syslog packet into queue
	typedef struct _SYSLOGPACKET
	{
		unsigned long		sip;	// S_addr member of in_addr struct
		unsigned short		sport;
		char*				pMsg;

		_SYSLOGPACKET()
		{
			sip = 0;
			sport = 0;
			pMsg = NULL;
		}

		~_SYSLOGPACKET()
		{
			if (pMsg != NULL)
			{
				delete pMsg;
				pMsg = NULL;
			}
		}

	}SYSLOGPACKET, *PSYSLOGPACKET;

	typedef struct _threadpara
	{
		void* pThis;
		int index;
		_threadpara():pThis(NULL),index(0){};
	}THREADPARA, *PTHREADPARA;

	typedef std::vector<std::string> EnumStrings;

	enum ERRORCODE
	{
		RET_SUCCESS,
		RET_FAILED,
		RET_DBERR,
		RET_NETERR,
		RET_THREADERR
	};
	enum FORMATRESULT
	{
		FORMAT_CANCEL,
		FORMAT_SUCCESS,
		FORMAT_FAILED
	};

	typedef bool (* CallBackFuncRecv)(int index, void *data); // 事件回调
	typedef bool (* CallBackFuncIU)(int index); // 析构/构造回调

	class Func
	{
	public:
		enum MATCHRESULT
		{
			MATCH_FAILED=-1,
			MATCH_NONE=0,
			MATCH_SUCCESS=1
		};
		static int SingleMatch(const std::string &strRule, const std::string &strSourceString, std::string &strResult);
		static int MultiMatch(const std::string &strRule, const std::string &strSourceString, std::vector<std::string> &vsResult);
	};

}