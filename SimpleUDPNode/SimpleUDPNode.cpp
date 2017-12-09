#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>

#pragma comment(lib,"ws2_32") 

<<<<<<< HEAD
using namespace std;

=======
>>>>>>> 6076f858bbcf53d50bff68a32c680e959bd43afa
void listenMessages()
{
	SOCKET receiveSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	sockaddr_in localAddress;

	localAddress.sin_family = AF_INET;
	localAddress.sin_addr.s_addr = inet_addr("10.0.0.60");
	localAddress.sin_port = htons(3038);

	bind(receiveSocket, (SOCKADDR *)(&localAddress), sizeof(localAddress));

	sockaddr_in remoteAddress;

	remoteAddress.sin_family = AF_INET;

	int remoteAddressSize = sizeof(remoteAddress);

	while (true)
	{
<<<<<<< HEAD
		string message(1024, 0);

		int count = recvfrom(receiveSocket, &message[0], 1024, 0, (sockaddr *)&remoteAddress, &remoteAddressSize);

		cout << inet_ntoa(remoteAddress.sin_addr) << ": " << message.substr(0, count) << "\n";
=======
		std::string message(1024, 0);

		int count = recvfrom(receiveSocket, &message[0], 1024, 0, (sockaddr *)&remoteAddress, &remoteAddressSize);

		std::cout << inet_ntoa(remoteAddress.sin_addr) << ": " << message.substr(0, count) << "\n";
>>>>>>> 6076f858bbcf53d50bff68a32c680e959bd43afa
	}

	closesocket(receiveSocket);
}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	WSADATA wsa;

	WSAStartup(MAKEWORD(2, 2), &wsa);

<<<<<<< HEAD
	thread receiveThread(listenMessages);
=======
	std::thread receiveThread(listenMessages);
>>>>>>> 6076f858bbcf53d50bff68a32c680e959bd43afa

	SOCKET sendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	struct sockaddr_in destination;
	int addressSize = sizeof(destination);
	memset((char *)&destination, 0, sizeof(destination));
	destination.sin_family = AF_INET;
	destination.sin_port = htons(3038);
	destination.sin_addr.S_un.S_addr = inet_addr("10.0.0.58");


<<<<<<< HEAD
	string message;

	while (true)
	{
		getline(cin, message);
		sendto(sendSocket, message.c_str(), (int)message.size(), 0, (struct sockaddr *) &destination, addressSize);
		cout << "Me: " << message << "\n";
=======
	std::string message;

	while (true)
	{
		std::getline(std::cin, message);
		sendto(sendSocket, message.c_str(), (int)message.size(), 0, (struct sockaddr *) &destination, addressSize);
		std::cout << "Me: " << message << "\n";
>>>>>>> 6076f858bbcf53d50bff68a32c680e959bd43afa
		Sleep(2000);
	}

	closesocket(sendSocket);
	WSACleanup();

	return 0;
}