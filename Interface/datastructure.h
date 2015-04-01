#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include "ParserInterface.h"
#include "CommonDef.h"

#include <map>
#include <string>

typedef std::map<std::wstring, DEV_INFO> DeviceInfoMap;

typedef std::multimap<std::wstring, SMS_Info> SMS_InfoMap;		 // Key : phone number
typedef std::list<CONTACT_Info> CONTACT_InfoList;
typedef std::multimap<std::wstring, RECORD_Info> RECORD_InfoMap; // Key : phone number

struct APP_Info
{
	std::wstring name;
	std::wstring apk;
	std::wstring icon;
	std::wstring className;
	std::wstring activity;
	std::wstring version;
};

typedef std::map<std::wstring, APP_Info> APP_InfoMap;			// Key : app name , eg : ΢��

struct FriendInfo
{
	std::string account;
	std::string nickName;
	std::string remark;
	std::string signature;
	int groupId;
	std::string groupName;

	int iType;
	std::string alias;
};

struct GroupInfo
{
	int groupId;
	std::string groupName;
	int memberCount;
};

struct TroopInfo
{
	std::string	troopUin;
	std::string troopName;
	std::string troopMemo;
};

struct DiscInfo
{
	std::string discussUin;
	std::string discussName;
	std::string createTime;
};


struct ChatHistory
{
	std::string time;			// ʱ��
	unsigned int msgType;		// ��Ϣ����
	unsigned int isSend;		// ���� - 1 ���� - 0
	std::string message;		// �ı���Ϣ����
	std::string filePath;		// ͼƬ/¼��/��Ƶ�ļ�·��
	std::string senderUin;      // ������qq��
	std::string senderName;		// �������ǳ�
};

typedef std::list<ChatHistory> ChatHistoryList;

struct AccountInfo
{
	std::string account;
	std::map<std::string, FriendInfo> friends;
	std::list<TroopInfo> troops;
	std::list<DiscInfo> discusses;

	std::map<std::string, ChatHistoryList> chatMap;
};

typedef std::map<std::string, AccountInfo> AccountInfoMap; // key : account;

struct KeyChainInfo
{
	std::string service;
	std::string serviceName;
	std::string prefix;
	std::string name;
	std::string password;
};

typedef std::multimap<std::string, KeyChainInfo> KeyChainInfoMap;


#endif // DATASTRUCTURE_H