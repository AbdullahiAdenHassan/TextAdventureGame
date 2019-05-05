#pragma once
class Room 
{
public:
	enum class eJoiningDirections
	{
		North = 0,
		East,
		South,
		West,
		Max
	};
private:
	Room* m_pJoiningRooms[static_cast <unsigned int>(eJoiningDirections::Max)];
public:
	Room();

	void AddRoom(eJoiningDirections direction, Room* pRoom);
	Room* GetRoom(eJoiningDirections direction)const;
};