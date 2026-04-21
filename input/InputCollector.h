#pragma once
#include "models\User.h"
#include <string>


class InputCollector
{
public:

	InputCollector(); //Constructor

	void collectIncomeDetails(User&);

	std::string collectName();
	int collectAge();

	double collectIncome(User::IncomePeriod);

	int collectDaysPerWeek();

	int collectStopsPerDay();

	int collectFilingStatus();

	char userDisplayChoice();

	User::IncomePeriod payFrequency();

	

private:
	static std::string inputCollectionHelper(std::string_view prompt);
};
