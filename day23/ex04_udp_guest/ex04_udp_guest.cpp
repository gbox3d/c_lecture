// ex04_udp_guest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma warning(disable:4996)
#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main()
{
    sockaddr_in si_other;
    SOCKET hSocket;
    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("start up error \n");
        return 1;
    }

    hSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (hSocket == SOCKET_ERROR)
    {
        printf("socket create error\n");
        return 1;
    }
    printf("scoket create ok\n");

    //주소 초기화 
    memset(&si_other, 0, sizeof(si_other));
    InetPton(AF_INET, L"127.0.0.1", &si_other.sin_addr.s_addr);
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(8284);

    printf("send data \n");
    const char* message = "hello udp";
    sendto(hSocket, message, strlen(message), 0, (sockaddr *)&si_other, sizeof(si_other));

    closesocket(hSocket);
    WSACleanup();

    return 0;    
}
