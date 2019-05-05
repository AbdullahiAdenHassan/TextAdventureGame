#pragma once
#include <string>
#include "PlayerOptions.h"
#include "Player.h"
#include <iostream>
using namespace std;
class Option
{
protected:
	ePlayerOptions m_chosenOption;
	std::string m_outputText;
	std::string m_optionText;

public:
	Option(ePlayerOptions chosenOption, const std::string& outputText)
		: m_chosenOption(chosenOption)
		, m_outputText(outputText)
	{

	}

	void SetOptionText(const std::string& optionText)
	{
		m_optionText = optionText;
	}

	const std::string& GetOutputText()const
	{
		return m_outputText;
	}

	ePlayerOptions GetChosenOption() const
	{
		return m_chosenOption;
	}

	virtual bool Evaluate(const std::string& optionText, Player& player) = 0;
};