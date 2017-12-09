#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

#pragma comment(lib,"ws2_32") 


int main(void)
{
	WSADATA wsa;

	WSAStartup(MAKEWORD(2, 2), &wsa);
	SOCKET socketHandle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	sockaddr_in localAddress;

	localAddress.sin_family = AF_INET;
	localAddress.sin_addr.s_addr = inet_addr("10.0.0.60");
	localAddress.sin_port = htons(3038);

	bind(socketHandle, (SOCKADDR *)(&localAddress), sizeof(localAddress));

	sockaddr_in remoteAddress;

	remoteAddress.sin_family = AF_INET;
	int remoteAddressSize = sizeof(remoteAddress);

	while (true)
	{
		std::string message(1024, 0);

		int count = recvfrom(socketHandle, &message[0], 1024, 0, (sockaddr *)&remoteAddress, &remoteAddressSize);

<<<<<<< HEAD
		std::cout << inet_ntoa(remoteAddress.sin_addr) << ": "<< message.substr(0, count) <<endl;
=======
		std::cout << message.substr(0, count) << " from "<< inet_ntoa(remoteAddress.sin_addr)<<endl;
>>>>>>> 6076f858bbcf53d50bff68a32c680e959bd43afa
	}

	closesocket(socketHandle);
	WSACleanup();

	return 0;
}