/**
 * ��UEFI���ʵ�����������
 * �����UEFI̽�������Բο����ߵĲ��ͺ�ר����
 * CSDN: https://blog.csdn.net/luobing4365
 * ֪��: https://www.zhihu.com/column/c_1233025362843209728
 * **/
 
// EchoClientTCP6.cpp : Defines the entry point for the console application.
// windows��IPV6�ı�̣��봫ͳsocket����һ������Ե�ַ�Ļ�ȡ�����ʹ��getaddrinfo����
//int getaddrinfo(
//	const char FAR* nodename, //����������IP��ַ���ַ���
//	const char FAR* servname, //�������ƻ��߶˿��ַ���
//	const struct addrinfo FAR* hints, //��ַ�ṹ���涨��Ӧ����ν��е�ַת��
//	struct addrinfo FAR* FAR* res //���ص�ַ�ṹ���������������������ɻ�������ַ��Ϣ
//);
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <Ws2tcpip.h>	//InetPton() ͷ�ļ�

#pragma comment(lib,"ws2_32")//����⺯��

#define BUFFER_SIZE 1024
void ErrorOutput(char * msg);

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hSocket= INVALID_SOCKET;
	char message[BUFFER_SIZE];
	int strLen;
	//SOCKADDR_IN6 servAdr;
	addrinfo hins = { 0 };
	addrinfo *servAddr = NULL;
	char pBuffer[256];

	if (argc != 3) {
		printf("TCP6 Client.Usage: %s <IP> <port>", argv[0]);
		exit(1);
	}
	else
	{
		printf("Ready to start TCP6 Client. IP=%s,port=%d\n", argv[1], atoi(argv[2]));
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorOutput("Start WSA error,Quit!");

	hins.ai_family = AF_INET6;
	hins.ai_socktype = SOCK_STREAM;
	//1 ��ȡserver�˵�ַ
	if (0 != getaddrinfo(argv[1], argv[2], &hins, &servAddr))
		ErrorOutput("getaddrinfo() error");

	if (0 == getnameinfo(servAddr->ai_addr, servAddr->ai_addrlen, pBuffer, sizeof(pBuffer), NULL, 0, NI_NUMERICHOST))
	{
		//2 ����socket
		hSocket = socket(servAddr->ai_family, SOCK_STREAM, servAddr->ai_protocol);
		//3 ���ӷ����
		if (connect(hSocket, servAddr->ai_addr, servAddr->ai_addrlen) == SOCKET_ERROR)
			ErrorOutput("connect() error");
		else
			puts("Connect.......");
		//4 ������ͨ��
		while (1)
		{
			fputs("Input message(Q to quit):", stdout);
			fgets(message, BUFFER_SIZE, stdin);
	
			if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
				break;
	
			send(hSocket, message, strlen(message), 0);
			strLen = recv(hSocket, message, BUFFER_SIZE - 1, 0);
			message[strLen] = 0;
			printf("Message from server:%s", message);
		}
	
		closesocket(hSocket);
		WSACleanup();
	}
	else
		ErrorOutput("getnameinfo() error");
	

	/*hSocket = socket(AF_INET6, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		ErrorOutput("echo_client: socket() error");*/

	
	//memset(&servAdr, 0, sizeof(servAdr));
	//servAdr.sin6_family = AF_INET;
	////servAdr.sin_addr.s_addr = inet_addr(argv[1]);
	//inet_pton(AF_INET6, argv[1], &(servAdr.sin6_addr));
	//servAdr.sin6_port = htons(atoi(argv[2]));

	//if (connect(hSocket, (SOCKADDR *)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
	//	ErrorOutput("connect() error");
	//else
	//	puts("Connect.......");
	/*while (1)
	{
		fputs("Input message(Q to quit):", stdout);
		fgets(message, BUFFER_SIZE, stdin);

		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
			break;

		send(hSocket, message, strlen(message), 0);
		strLen = recv(hSocket, message, BUFFER_SIZE - 1, 0);
		message[strLen] = 0;
		printf("Message from server:%s", message);
	}

	closesocket(hSocket);
	WSACleanup();*/

    return 0;
}

//�������
void ErrorOutput(char * msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}