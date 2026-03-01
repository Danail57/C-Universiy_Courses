/*  Създай структура NetworkPacket. Тя трябва
 *  да включва: source_ip (масив от 4 цели числа),
 *  destination_ip, payload_size (в байтове)
 *  и checksum (hex или integer).
 Напиши логика, която проверява
 дали source_ip и destination_ip
 са в една и съща подмрежа
 (напр. дали първите три числа от масива съвпадат).
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct NetworkPacket{
    int source_ip[4];
    int destination_ip[4];
    int payload_size;
    unsigned int checksum;
};


bool in_same_connection(int source_ip[4], int destination_ip[4])
{
    for (int i = 0; i < 3; i++)
    {
        if (source_ip[i] != destination_ip[i])
        {
            return false;
        }
    }
    return true;
}

void read_ip(int ip_array[4])
{
    string ip_string;
    cin >> ip_string;
    stringstream ss(ip_string);
    string part;
    int i = 0;
    while (getline(ss, part, '.') && i < 4) {
        ip_array[i] = stoi(part);
        i++;
    }

}

int main()
{
    NetworkPacket packet;
    cout << "Enter Source IP (format: 192.168.1.1): ";
    read_ip(packet.source_ip);

    cout << "Enter Destination IP (format: 192.168.1.55): ";
    read_ip(packet.destination_ip);

    cout << "Enter Payload Size (bytes): ";
    cin >> packet.payload_size;

    cout << "Enter Checksum (integer): ";
    cin >> packet.checksum;

    if (in_same_connection(packet.source_ip, packet.destination_ip))
    {
        cout << "Result: Source and Destination are in the same subnet." << endl;
    }
    else
    {
        cout << "Result: Source and Destination are not in the same subnet." << endl;
    }
    return 0;
}
