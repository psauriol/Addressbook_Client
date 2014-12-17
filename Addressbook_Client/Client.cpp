#include "Client.h"
using namespace std;

void main ()
{
	long successful;
	WSAData WinSockData;
	WORD DLLVERSION;

	DLLVERSION = MAKEWORD(2,1);//concats word
	successful = WSAStartup(DLLVERSION, & WinSockData);

	string request;
	string converter;
	char message[200];

	SOCKADDR_IN address;
	SOCKET sock;
	sock = socket(AF_INET,  SOCK_STREAM,NULL);

	address.sin_addr.s_addr = inet_addr("127.0.0.1");//IP address to use change as needed for computer to computer test
	address.sin_family = AF_INET;
	address.sin_port = htons(7777);//port number to use

	cout << "Connect to server?";
	cin >> request;
	//request = "y";
	request[0] = tolower(request[0]);

	if(request == "no")
	{
		cout << "Exiting" << endl;
	}
	else if(request == "yes" || "y")
	{
		
		connect(sock, (SOCKADDR*)&address, sizeof(address));
		successful = recv(sock,message, sizeof(message), NULL);
		converter = message;

		cout << "Message from server: " << converter << endl;

		cin.sync();
		cin.clear();
		while( request != "quit")
		{
			//query
			cout << "Send query: ";
			getline (cin, request);

			int temp = request.size();
			for(int i = 0; i < temp; i++)//converts to char*
			{
				message[i] = request[i];
			}
			message[temp] = NULL;

			successful = send(sock, message, 46, NULL);

			successful = recv(sock,message, sizeof(message), NULL);
			converter = message;

			cout << "Message from server: " << converter << endl;
		}
	}
	else
	{
		cout << "Not an recognized request." << endl;
	}

	cout << " ";
	system("PAUSE");
	exit(1);




}


