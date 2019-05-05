#include "Game.h"

void Game::InitializeRooms()
{
	//Room 0 heads North to Room 1
	m_rooms[0].AddRoom(Room::eJoiningDirections::North, &(m_rooms[1]));

	//Room 1 heads East to Room 2, South to Room 0 and West to Room 3
	m_rooms[1].AddRoom(Room::eJoiningDirections::East, &(m_rooms[2]));
	m_rooms[1].AddRoom(Room::eJoiningDirections::South, &(m_rooms[0]));
	m_rooms[1].AddRoom(Room::eJoiningDirections::West, &(m_rooms[3]));

	//Room 2 heads West to Room 1
	m_rooms[2].AddRoom(Room::eJoiningDirections::West, &(m_rooms[1]));

	//Room 3 heads East to Room 1
	m_rooms[3].AddRoom(Room::eJoiningDirections::East, &(m_rooms[1]));

	// Places the player in Room 0
	m_player.SetCurrentRoom(&(m_rooms[0]));
}

void Game::WelcomePlayer()
{
	cout << "Welcome to Text Adventure Version 5!" << endl;
	cout << "What is your name?" << endl;
	cout << "Enter your name: ";
	string name;
	getline(cin, name);
	m_player.SetName(name);
}

void Game::GivePlayerOptions() const
{
	cout << endl;
	cout << m_player.GetName() << " what would you like to do? (Enter a corresponding number)" << endl << endl;
	for (unsigned int i = 0; i < m_numberOfOptions; i++)
	{
		Option* option = m_options[i];
		const unsigned int chosenOption = i + 1;
		cout << chosenOption << ": " << option->GetOutputText() << endl << endl;
		std::ostringstream chosenOptionString;
		chosenOptionString << chosenOption;
		option->SetOptionText(chosenOptionString.str());
	}

}

void Game::GetPlayerInput(std::string& PlayerInput) const
{
	cin >> PlayerInput;
}

ePlayerOptions Game::EvaluateInput(std::string & PlayerInput)
{
	ePlayerOptions chosenOption = ePlayerOptions::None;
	for (unsigned int i = 0; i < m_numberOfOptions; i++)
	{
		Option* option = m_options[i];
		bool handled = option->Evaluate(PlayerInput, m_player);
		if (handled == true)
		{
			chosenOption = option->GetChosenOption();
			break;
		}
	}

	if (chosenOption == ePlayerOptions::None)
	{
		cout << "I do not recoqnize that option, try again!" << endl << endl;
	}

	return chosenOption;

}


Game::Game()
	:m_moveNorthOption(Room::eJoiningDirections::North, ePlayerOptions::GoNorth, "GO North")
	, m_moveEastOption(Room::eJoiningDirections::East, ePlayerOptions::GoEast, "GO East")
	, m_moveSouthOption(Room::eJoiningDirections::South, ePlayerOptions::GoSouth, "GO South")
	, m_moveWestOption(Room::eJoiningDirections::West, ePlayerOptions::GoWest, "GO West")
	, m_quitOption("Quit")
{
	m_options[0] = dynamic_cast<Option*>(&m_moveNorthOption);
	m_options[1] = dynamic_cast<Option*>(&m_moveEastOption);
	m_options[2] = dynamic_cast<Option*>(&m_moveSouthOption);
	m_options[3] = dynamic_cast<Option*>(&m_moveWestOption);
	m_options[4] = dynamic_cast<Option*>(&m_quitOption);
}

void Game::RunGame()
{
	InitializeRooms();

	WelcomePlayer();

	bool shouldEnd = false;
	while (shouldEnd == false)
	{
		GivePlayerOptions();

		string PlayerInput;
		GetPlayerInput(PlayerInput);

		ePlayerOptions selectedOption = EvaluateInput(PlayerInput);
		shouldEnd = selectedOption == ePlayerOptions::Quit;

	}
}
