#pragma once
#include <string>

class InputCollector
{
public:

	InputCollector();

	std::string collectName();

	int collectAge();

	double collectIncome();

	int collectFilingStatus();

	char userDisplayChoice();
};
