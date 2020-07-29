#include<SFML/Network.hpp>
#include<iostream>
#include<string>
using namespace std;

int main() {
	
	sf::TcpSocket socket;
	char buffer[2000];
	char connectionType, mode;
	std::size_t received;
	
	std::string text = "Successfuly connected to: ";
	
	cout << "Your IP address is: " << sf::IpAddress::getLocalAddress() << endl;
	cout << "Enter (s) for server, Enter (c) for client: ";
		
	cin >> connectionType;
	
	if(connectionType == 's') {
		sf::TcpListener listener;
		listener.listen(53000);
		listener.accept(socket);				
	}
	else if(connectionType == 'c') {		
		string IP_asString;
		cout << "Please enter the IP address you want to connect: ";
		cin >> IP_asString;
		sf::IpAddress ip(IP_asString);
		socket.connect(ip, 53000);
	}
	
	text += sf::IpAddress::getLocalAddress().toString();
	socket.send(text.c_str(), text.length() + 1);
	socket.receive(buffer, sizeof(buffer), received);
	
	cout << buffer << endl;
	
	system("pause");
	
	return 0;
}
