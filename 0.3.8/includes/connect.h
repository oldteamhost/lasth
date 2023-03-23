#pragma once
class connect
{
public:
	long responseCode(const char* link, bool _proxy, const char* proxy);
	bool downloadPage(const char* link, const char* path);
};