#pragma once
#include "User.h"
#include <string>


class InputCollector
{
public:

	InputCollector(); //Constructor

	std::string collectName();
	int collectAge();

	double collectIncome();

	double collectDailyIncome();

	int collectDaysPerWeek();

	int collectFilingStatus();

	char userDisplayChoice();

	User::IncomePeriod payFrequency();
};
