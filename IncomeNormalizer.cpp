
#include "IncomeNormalizer.h"
#include "InputCollector.h"
#include "strings.h"
#include <stdexcept>

IncomeNormalizer::IncomeNormalizer() {};

double IncomeNormalizer::normalizeIncome(const User& user)
{
	InputCollector userDailyIncome;
	double dailyIncome = 0.0;

	switch (user.getIncomeFrequency())
	{
		case User::IncomePeriod::STOP :
		{
			userDailyIncome.collectDailyIncome();

			dailyIncome = (user.getIncomeAmount() * user.getStopsPerDay());

			return (dailyIncome * user.getDaysPerWeek()) * 52;
		}

		case User::IncomePeriod::DAY :
		{
			dailyIncome = user.getIncomeAmount();
			return (dailyIncome * user.getDaysPerWeek()) * 52;
		}

		case User::IncomePeriod::WEEK :
		{
			return (user.getIncomeAmount() * 52);
		}

		case User::IncomePeriod::MONTH :
		{
			return (user.getIncomeAmount() * 12);
		}

		default: throw std::invalid_argument(std::string(ErrorMessages::invalidPayFrequency));
	}

}