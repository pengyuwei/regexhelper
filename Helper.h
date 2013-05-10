#pragma once
#include "Global.h"

class CHelper
{
public:
	CHelper(void);
	~CHelper(void);
public:
	static Global::EnumStrings Split(const char* str, const char sp);
	static std::string AutoMakeRegex(const char* log);
	static std::string RegexTest(Global::EnumStrings strFields, char cSp);
};
