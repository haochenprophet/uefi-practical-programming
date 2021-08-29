/**
 * ��UEFI���ʵ�����������
 * �����UEFI̽�������Բο����ߵĲ��ͺ�ר����
 * CSDN: https://blog.csdn.net/luobing4365
 * ֪��: https://www.zhihu.com/column/c_1233025362843209728
 * **/
// EchoServerTCP4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <Ws2tcpip.h>	//InetPton() ͷ�ļ�

#pragma comment(lib,"ws2_32")//����⺯��

void ErrorOutput(char * msg);
#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	char message[BUFFER_SIZE];
	int strLen, i;
	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrSize;

	if (argc != 2) {
		printf("TCP4 Server by robin. Usage: %s <port>", argv[0]);
		exit(1);
	}
	else
	{
		printf("Ready to start TCP4 Server. port=%d\n", atoi(argv[1]));
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorOutput("Start WSA error,Quit!");

	hServSock = socket(AF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		ErrorOutput("socket() error!");
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR *)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorOutput("bind() error");
	if (listen(hServSock, 10) == SOCKET_ERROR)  //���Խ���10������
		ErrorOutput("listen() error");

	clntAdrSize = sizeof(clntAdr);
	for (i = 0; i < 10; i++) //�����ӽ��д���
	{
		hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSize);
		if (hClntSock == INVALID_SOCKET)
			ErrorOutput("accept() error");
		else
			printf("Connect client %d (port: %d)\n", i + 1, clntAdr.sin_port);

		while ((strLen = recv(hClntSock, message, BUFFER_SIZE, 0)) != 0)
		{
			if (strLen == SOCKET_ERROR)
				break;
			message[strLen] = '\0';
			printf("Receive from client(port:%d):%s\n", clntAdr.sin_port, message);
			send(hClntSock, message, strLen, 0);
		}
		closesocket(hClntSock);
	}
	closesocket(hServSock);
	WSACleanup();
    return 0;
}

void ErrorOutput(char * msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}