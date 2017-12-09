#include <Windows.h>
#include <iostream>
<<<<<<< HEAD
#include <string>

using namespace std;
=======
>>>>>>> 6076f858bbcf53d50bff68a32c680e959bd43afa

#pragma comment(lib,"ws2_32") 

int main(void)
{
	WSADATA wsa;

	WSAStartup(MAKEWORD(2, 2), &wsa);
	SOCKET socketHandle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	struct sockaddr_in destination;
	int addressSize = sizeof(destination);
	memset((char *)&destination, 0, sizeof(destination));
	destination.sin_family = AF_INET;
	destination.sin_port = htons(3038);
	destination.sin_addr.S_un.S_addr = inet_addr("10.0.0.58");

	size_t i = 0;

	while (true)
	{
		const std::string message("HELLO");
		i++;
		sendto(socketHandle, message.c_str(), (int)message.size(), 0, (struct sockaddr *) &destination, addressSize);
<<<<<<< HEAD
		cout << "Me: " << message.substr(0, (int)message.size()) << endl;
=======
>>>>>>> 6076f858bbcf53d50bff68a32c680e959bd43afa
		Sleep(2000);
	}

	closesocket(socketHandle);
	WSACleanup();

	return 0;
}