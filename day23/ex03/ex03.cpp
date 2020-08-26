// ex03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib,"ws2_32.lib")

int main()
{
	WSADATA wsaData;
	SOCKET socketCli;
	char szMsg[32];

	addrinfo addrServer;

	WSAStartup(MAKEWORD(2, 0), &wsaData);
	socketCli = socket(AF_INET, SOCK_STREAM, 0);

	//접속할 서버 주소 구조체 만들기 

	
	//addrServer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	memset((char*)&addrServer, 0, sizeof(addrServer));
	InetPton(AF_INET, L"127.0.0.1", &addrServer..S_un.S_addr);
	addrServer.ai_family = AF_INET;
	addrServer.sin_por = htonl(8282);

	printf("connecting server \n");
	//서버에 접속
	if (connect(socketCli, (struct sockaddr*)&addrServer, sizeof(addrServer)) == SOCKET_ERROR)
	{
		printf("erro code %d \n",WSAGetLastError());
		return 1;
	}
	printf("connected server \n");
	send(socketCli, "hello TCP", 10, 0);

	closesocket(socketCli);

	return 0;
}
