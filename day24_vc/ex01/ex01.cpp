// ex04_udp_guest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <WinSock2.h>
#include <WS2tcpip.h>

struct S_PACKET {
    unsigned char header;
    unsigned char code;
    unsigned short data1;
    float data2;
};


struct S_PACKET_RES {
    unsigned char header;
    unsigned char code;
    unsigned short data1;
    unsigned short data2;
};



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
    InetPton(AF_INET, L"192.168.0.9", &si_other.sin_addr.s_addr);
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(8284);
    

    printf("send data \n");
    //const char* message = "hello udp";
    S_PACKET req_packet;
    req_packet.header = 0x01;
    req_packet.code = 0x00;
    req_packet.data1 = 10;
    req_packet.data2 = 3.14;
    sendto(hSocket,(const char *)&req_packet , sizeof(S_PACKET), 0, 
        (sockaddr*)&si_other, sizeof(si_other));

    S_PACKET_RES res_packet;
    int recv_len;
    int packet_size = sizeof(si_other);
    recv_len = recvfrom(hSocket,
        (char*)&res_packet, sizeof(S_PACKET_RES), 0,
        (sockaddr*)&si_other, &packet_size
    );

    char _szIp[256];
    inet_ntop(AF_INET, &si_other.sin_addr, _szIp, sizeof(_szIp));

    printf("from : %s : %d \n", _szIp, ntohs(si_other.sin_port));
    printf("%d,%d,%d,%d \n", res_packet.header, res_packet.code, res_packet.data1, res_packet.data2);


    //printf("press any key \n");
    //getchar();
    //printf("close socket \n");

    closesocket(hSocket);
    WSACleanup();

    return 0;
}
