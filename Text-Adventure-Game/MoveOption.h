#pragma once
#include "Option.h"
class MoveOption : public Option
{
private:
	Room::eJoiningDirections m_directionToMove;
public:
	MoveOption(Room::eJoiningDirections joiningDirection, ePlayerOptions chosenOption, const std::string& outputText)
		: Option(chosenOption, outputText)
		, m_directionToMove(joiningDirection)
	{}
	virtual bool Evaluate(const std::string& optionText, Player& player);
};