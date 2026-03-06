#pragma once
#include <string>

class InputCollector
{
public:

	InputCollector();

	std::string collectName();

	int collectAge();

	float collectIncome();

	int collectFilingStatus();
};
