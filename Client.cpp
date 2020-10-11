// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WinSock2.h>
#include <iostream>
#include <string>

int main()
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}

	while (1)
	{

		auto sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (INVALID_SOCKET == sClient)
		{
			std::cout << "create socket failed!" << std::endl;
		}

		sockaddr_in sin;
		sin.sin_family = AF_INET;
		sin.sin_port = htons(8080);
		sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		if (connect(sClient, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
		{
			FD_SET fd;
			timeval
			std::cout << "connect error!" << std::endl;
			closesocket(sClient);
			return 0;
		}

		std::string str;
		std::cin >> str;
		if (str == "break")
		{
			closesocket(sClient);
			break;
		}

		send(sClient, str.c_str(), str.length(), 0);

		char recvBuffer[100];
		int ret = recv(sClient, recvBuffer, 100, 0);
		if (ret > 0)
		{
			recvBuffer[ret] = '\0';
			std::cout << recvBuffer << std::endl;
		}
	}

	WSACleanup();
    return 0;
}

