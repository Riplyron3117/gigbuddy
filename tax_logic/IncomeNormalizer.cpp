
#include "tax_logic\IncomeNormalizer.h"
#include "input\InputCollector.h"
#include "resources\strings.h"
#include <stdexcept>

IncomeNormalizer::IncomeNormalizer() {};

double IncomeNormalizer::normalizeIncome(const User& user)
{
	
	double dailyIncome = 0.0;
	switch (user.getIncomeFrequency())
	{
		case User::IncomePeriod::STOP :
		{
			dailyIncome = (user.getIncomeAmount());

			return (dailyIncome * user.getDaysPerWeek()) * 52;
		}

		case User::IncomePeriod::DAY :
		{
			dailyIncome = user.getIncomeAmount();
			return (dailyIncome) * 52;
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