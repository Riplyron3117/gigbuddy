#pragma once
#include "User.h"
#include <string>


class InputCollector
{
public:

	InputCollector();

	std::string collectName();

	int collectAge();

	double collectIncome();

	double collectedDailyIncome();

	int collectDaysPerWeek();

	int collectFilingStatus();

	char userDisplayChoice();

	User::IncomePeriod payFrequency();
};
