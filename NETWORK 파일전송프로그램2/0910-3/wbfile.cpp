//wbfile.cpp
#define _WINSOCK_DEPRECATED_NO_WARNINGS   
#include "std.h"

char filename[260]; // 전송할 파일

void wbfile_Run()
{
	CloseHandle(CreateThread(0, 0, RunThread, 0, 0, 0));
}

//소켓 생성하고 접속 관리 기능
DWORD WINAPI RunThread(void *p)
{
	WSADATA wsadata;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
	{
		printf("Can't Initialize Socket !\n");
		return -1;
	}
	//--------------------------------------------
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5000);
	addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(s, (SOCKADDR*)&addr, sizeof(addr)) == -1)
	{
		printf("Can't Bind\n");
		closesocket(s);
		return -1;
	}

	if (listen(s, 10) == -1)
	{
		printf("Can't Listen\n");
		closesocket(s);
		return -1;
	}

	while (1)
	{
		SOCKADDR_IN c_addr;
		int size = sizeof(c_addr);

		SOCKET c_s = accept(s, (SOCKADDR*)&c_addr, &size);

		//printf("Client 접속 : %s\n", inet_ntoa(c_addr.sin_addr));
		uifile_PrintIP(inet_ntoa(c_addr.sin_addr));

		CloseHandle(CreateThread(0, 0, FileServer, (void*)c_s, 0, 0));
	}
	//--------------------------------------------
	closesocket(s);
	WSACleanup();
	return 1;
}

// 접속한 Client에게 파일을 전송한다.
DWORD WINAPI FileServer(void* p)
{
	SOCKET s = (SOCKET)p;

	// 전송할 파일Open
	HANDLE hFile = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ,
		0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		printf("Can't Open File\n");
		closesocket(s);
		return 0;
	}
	// 크기를 구하고 화일의 정보를 전송한다.
	DWORD size1;
	DWORD size2 = GetFileSize(hFile, &size1);

	FILE_INFO fi;
	strcpy(fi.FileName, filename);
	fi.size = size2;

	send(s, (char*)&fi, sizeof(fi), 0);
	//-------------------------------------------------
	// 화일 전송
	int total = size2; // 전송할 전체 크기
	int current = 0;   // 전송한 크기
	int nRead = 0;
	char buf[4096];    // 4k 버퍼.

	while (total > current)
	{
		DWORD len;
		nRead = ReadFile(hFile, buf, 4096, &len, 0);

		if (len <= 0) break;

		int nSend = send(s, buf, len, 0);
		if (nSend <= 0) break;

		current += nSend;
	}
	if (total != current)	printf("전송에러\n");
	else					printf("전송완료 \n");

	closesocket(s);
	CloseHandle(hFile);
	return 0;
}


