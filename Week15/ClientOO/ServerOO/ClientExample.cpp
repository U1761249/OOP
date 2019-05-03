#include "StdAfx.h"
#include "ClientExample.h"


ClientExample::ClientExample(void)
{

	network = new ClientNetwork();

	// send init packet
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.packet_type = INIT_CONNECTION;

	packet.serialize(packet_data);

	NetworkServices::sendMessage(network->ConnectSocket, packet_data, packet_size);
}


ClientExample::~ClientExample(void)
{
}

void ClientExample::sendActionPackets()
{
	// send action packet
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.speed = 22.2;
	packet.longitude = 123455;
	packet.latitude = 2334543;
	packet.packet_type = DATA_EVENT;
	packet.serialize(packet_data);

	NetworkServices::sendMessage(network->ConnectSocket, packet_data, packet_size);
}

void ClientExample::update()
{
	Packet packet;
	int data_length = network->receivePackets(network_data);

	if (data_length <= 0)
	{
		//no data recieved
		return;
	}

	int i = 0;
	while (i < (unsigned int)data_length)
	{
		packet.deserialize(&(network_data[i]));
		i += sizeof(Packet);

		switch (packet.packet_type) {

		case DATA_EVENT:

			printf("client received action event packet from server\n");

			sendActionPackets();

			break;

		default:

			printf("error in packet types\n");

			break;
		}
	}
}
