#include "Room.h"
#include <iostream>
using namespace std;
Room::Room()
{
	for (unsigned int i = 0; i < static_cast <unsigned int> (eJoiningDirections::Max); i++)
	{
		m_pJoiningRooms[i] = nullptr;
	}
}

void Room::AddRoom(eJoiningDirections direction, Room * pRoom)
{
	m_pJoiningRooms[static_cast <unsigned int>(direction)] = pRoom;
}

Room* Room::GetRoom(eJoiningDirections direction) const
{
	return m_pJoiningRooms[static_cast <unsigned int>(direction)];
}