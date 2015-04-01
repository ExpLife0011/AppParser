#ifndef _WEIXIN_PARSER_H
#define _WEIXIN_PARSER_H

#ifdef WEIXINPARSER_EXPORTS
#define WEIXIN_API  __declspec(dllexport)
#else
#define WEIXIN_API  __declspec(dllimport)
#endif

#include <Windows.h>
#include "datastructure.h"

//iType: 0-android 1-ios
//
WEIXIN_API bool WEIXIN_InitEntry(LPCWSTR lpwzCasePath, int iType, char *lpszImei=NULL);  
bool AndroidInitEntry(LPCWSTR lpwzCasePath);
bool IosInitEntry(LPCWSTR lpwzCasePath);

WEIXIN_API void WEIXIN_Free();

//�����˺��б���"|"����
//
WEIXIN_API bool WEIXIN_GetAccountList(char *lpszAccounts, int iSize); 
WEIXIN_API bool WEIXIN_GetAccoutInfo(const std::string &account);

//��ȡָ���˺ŵĺ�����Ϣ
//
WEIXIN_API FriendInfo* WEIXIN_GetFirstFriend(std::string &account);
WEIXIN_API FriendInfo* WEIXIN_GetNextFriend(std::string &account);

//��ȡָ�����ˡ�QQȺ��������������¼
//account:Ҫ��ȡ���˺� chatAccount:Ҫ��ȡ�����¼��QQ�š�Ⱥ�Ż���������� iType��Ҫ��ȡ�������¼������ 0-���� 1-Ⱥ 2-������
//
WEIXIN_API ChatHistory* WEIXIN_GetFirstChatHistory(std::string &account, std::string &chatAccount, int iType);
WEIXIN_API ChatHistory* WEIXIN_GetNextChatHistory(std::string &account, std::string &chatAccount, int iType);


#endif

