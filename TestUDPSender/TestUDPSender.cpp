#include <Windows.h>
#include <iostream>

#pragma comment(lib,"ws2_32") 

int main(void)
{
	WSADATA wsa;

	WSAStartup(MAKEWORD(2, 2), &wsa);
	SOCKET socketHandle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	/*
	sockaddr_in localAddress;

	localAddress.sin_family = AF_INET;
	localAddress.sin_addr.s_addr = inet_addr("10.0.0.58");
	localAddress.sin_port = htons(56770);

	bind(socketHandle, (SOCKADDR *)(&localAddress), sizeof(localAddress));
	*/

	struct sockaddr_in destination;
	int addressSize = sizeof(destination);
	memset((char *)&destination, 0, sizeof(destination));
	destination.sin_family = AF_INET;
	destination.sin_port = htons(3038);
	destination.sin_addr.S_un.S_addr = inet_addr("10.0.0.60");

	size_t i = 0;

	while (true)
	{
		const std::string message("HELLO from 10.0.0.58:56770!!!");
		i++;
		sendto(socketHandle, message.c_str(), (int)message.size(), 0, (struct sockaddr *) &destination, addressSize);
		Sleep(500);
	}

	closesocket(socketHandle);
	WSACleanup();

	return 0;
}