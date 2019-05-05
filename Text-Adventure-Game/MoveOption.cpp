#include "MoveOption.h"

bool MoveOption::Evaluate(const std::string& optionText, Player& player)
{
	bool handled = false;

	if (m_optionText.compare(optionText) == 0)
	{
		const Room* pPlayerCurrentRoom = player.GetCurrentRoom();
		const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(m_directionToMove);
		if (pNewRoom != nullptr)
		{
			player.SetCurrentRoom(pNewRoom);
			cout << "You have chosen to " << m_outputText << endl << endl;
		}
		else
		{
			const char* strDirection = "North";
			switch (m_chosenOption)
			{
			case ePlayerOptions::GoEast:
			{
				strDirection = "East";
			}
			break;

			case ePlayerOptions::GoSouth:
			{
				strDirection = "South";
			}
			break;

			case ePlayerOptions::GoWest:
			{
				strDirection = "West";
			}
			break;
			}
			cout << "There is no room to the " << strDirection << endl << endl;
		}
		handled = true;
	}
	return handled;
}
