#ifndef PARSERINTERFACE_H
#define PARSERINTERFACE_H

// SMS

#ifdef PARSE_EXPORTS
#define PARSE_API __declspec(dllexport)
#else
#define PARSE_API __declspec(dllimport)
#endif

struct SMS_Info
{
	std::wstring name;		// ����
	std::wstring number;	// �绰��
	std::wstring time;		// ʱ�䣬�� 2014-12-10 16:32
	std::wstring message;	// ��������
	bool isSend;			// ����ǽ��յ��Ķ��� isSend = true
};

extern "C" PARSE_API bool SMS_Start(const wchar_t* dataPath);
extern "C" PARSE_API int SMS_GetRecordCount();
extern "C" PARSE_API SMS_Info* SMS_GetRecordAt(int index);
extern "C" PARSE_API bool SMS_Free();

struct CONTACT_Info
{
	std::wstring name;			// ����
	std::wstring number;		// �绰��
	std::wstring email;			// ����
	std::wstring address;		// סַ
	std::wstring profession;	// ��˾ְλ
	std::wstring group;			// ��
};

extern "C" PARSE_API bool CONTACT_Start(const wchar_t* dataPath);
extern "C" PARSE_API int CONTACT_GetRecordCount();
extern "C" PARSE_API CONTACT_Info* CONTACT_GetRecordAt(int index);
extern "C" PARSE_API bool CONTACT_Free();

struct RECORD_Info
{
	std::wstring name;			// ����
	std::wstring number;		// �绰����
	std::wstring date;			// ͨ��ʱ��
	std::wstring time;			// ͨ��ʱ��
	std::wstring type;			// ͨ������
	std::wstring location;		// �ֻ�������
};

extern "C" PARSE_API BOOL RECORD_Start(const wchar_t* dataPath);  
extern "C" PARSE_API DWORD RECORD_GetRecordCount();
extern "C" PARSE_API RECORD_Info* RECORD_GetRecordAt(int index);
extern "C" PARSE_API BOOL RECORD_Free();

#endif // PARSERINTERFACE_H