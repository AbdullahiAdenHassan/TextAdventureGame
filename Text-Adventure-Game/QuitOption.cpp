#include "QuitOption.h"

bool QuitOption::Evaluate(const std::string & optionText, Player & player)
{
	m_shouldQuit = m_optionText.compare(optionText) == 0;

	if (m_shouldQuit == true)
	{
		cout << "You have chosen to quit!" << endl << endl;
	}
	return m_shouldQuit;
}