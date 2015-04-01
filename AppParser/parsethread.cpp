#include "StdAfx.h"
#include "parsethread.h"
#include "utils.h"
#include "datamanager.h"

#include <Windows.h>

ParseThread::ParseThread(QObject *parent)
	: QThread(parent)
	, m_clear(false)
	, m_extractPassword("")
	, m_input(false)
{

}

ParseThread::~ParseThread()
{

}

void ParseThread::SetKey(std::wstring key)
{
	m_key = key;
}

void ParseThread::SetClear(bool clear)
{
	m_clear = clear;
}

void ParseThread::WaitForUserInput()
{
	while ( ! m_input )
	{
		qDebug() << "WaitForUserInput";
		Sleep(100);
	}
}

void ParseThread::run()
{
	emit TotalProcess(18);

	HANDLE hLog = Utils::LogStart();

	int process = 0;
	emit CurrentProcess(process++);

	DataManager& dm = DataManager::GetInstance();
	std::wstring device = m_key.substr(0, m_key.find('\\'));

	std::wstring path = dm.GetDirPath() + L"\\" + m_key;
	Utils::Log(hLog, L"�豸·�� : %s\r\n\r\n", path.c_str());

	if ( m_clear )
	{
		dm.Clear();
		dm.ParseCaseInfo();

		const std::list<CASE_INFO>& cases = dm.GetCaseList();

		for ( std::list<CASE_INFO>::const_iterator it = cases.begin();
			it != cases.end();
			++it )
		{
			const wchar_t* deviceName = it->wzDirPath;
			dm.ParseDeviceInfo(deviceName);;
		}
	}

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ�ѹ�ļ� ..."));
	Utils::Log(hLog, L"���ڽ�ѹ�ļ� ...\r\n");
	dm.ExtractBackupFile(m_key);

	m_cancleExtract = false;
	m_input = false;

	while ( DataManager::EXTRACT_IOS_BACKUP_FAILED == dm.GetError() )
	{
		emit QueryIosBackupPassword();
		WaitForUserInput();

		if ( m_cancleExtract )
			break;

		dm.SetIosBackupPassword(m_extractPassword);
		dm.ExtractBackupFile(m_key);
		m_input = false;
	}

	dm.SetIosBackupPassword("");

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ���������Ϣ ..."));
	Utils::Log(hLog, L"���ڽ���������Ϣ ...\r\n");
	dm.ParseKeyChainInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ���Ӧ����Ϣ ..."));
	Utils::Log(hLog, L"���ڽ���Ӧ����Ϣ ...\r\n");
	dm.ParseAppInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ������ż�¼ ..."));
	Utils::Log(hLog, L"���ڽ������ż�¼ ...\r\n");
	dm.ParseSmsInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ���ͨѶ¼ ..."));
	Utils::Log(hLog, L"���ڽ���ͨѶ¼ ...\r\n");
	dm.ParseContactInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ���ͨ����¼ ..."));
	Utils::Log(hLog, L"���ڽ���ͨ����¼ ...\r\n");
	dm.ParseRecordInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ��� QQ �����¼ ..."));
	Utils::Log(hLog, L"���ڽ��� QQ �����¼ ...\r\n");
	dm.ParseQQInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ���΢�������¼ ..."));
	Utils::Log(hLog, L"���ڽ���΢�������¼ ...\r\n");
	dm.ParseWeixinInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ��� Line �����¼ ..."));
	Utils::Log(hLog, L"���ڽ��� Line �����¼ ...\r\n");
	dm.ParseLineInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ��� UC �������ʷ��¼ ..."));
	Utils::Log(hLog, L"���ڽ��� UC �������ʷ��¼ ...\r\n");
	dm.ParseUCBrowserInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ���ϵͳ�������ʷ��¼ ..."));
	Utils::Log(hLog, L"���ڽ���ϵͳ�������ʷ��¼ ...\r\n");
	dm.ParseDefaultBrowserInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ��� QQ �������ʷ��¼ ..."));
	Utils::Log(hLog, L"���ڽ��� QQ �������ʷ��¼ ...\r\n");
	dm.ParseQQBrowserInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ����ٶ��������ʷ��¼ ..."));
	Utils::Log(hLog, L"���ڽ����ٶ��������ʷ��¼ ...\r\n");
	dm.ParseBaiduBrowserInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ����Ա��������ʷ��¼ ..."));
	Utils::Log(hLog, L"���ڽ����Ա��������ʷ��¼ ...\r\n");
	dm.ParseJinShanBrowserInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ��� Safari �������ʷ��¼ ..."));
	Utils::Log(hLog, L"���ڽ��� Safari �������ʷ��¼ ...\r\n");
	dm.ParseSafariBrowserInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ����ٶȵ�ͼ��ʷ��¼ ..."));
	Utils::Log(hLog, L"���ڽ����ٶȵ�ͼ��ʷ��¼ ...\r\n");
	dm.ParseBaiduMapInfo(m_key);

	emit CurrentProcess(process++);
	emit CurrentStatus(Utils::stoq("���ڽ����ߵµ�ͼ��ʷ��¼ ..."));
	Utils::Log(hLog, L"���ڽ����ߵµ�ͼ��ʷ��¼ ...\r\n");
	dm.ParseGaodeMapInfo(m_key);

	m_clear = false;

	emit ParseDone();

	Utils::LogEnd(hLog);
}
