#include <iomanip>
#include <sstream>
#include <iostream>
#include "DisplayService.h"

DisplayService::DisplayService() {}

std::string DisplayService::getFilingStatusName(int filingStatus) const
{
	switch (filingStatus)
	{
	case 1: return "Single";

	case 2: return "Married Filing Jointly";

	case 3: return "Married Filing Separately";

	case 4: return "Head of Household";

	default: return "Invalid";
	}
}

void DisplayService::displayUserInformation(const User& user) const
{
	
	std::cout << "Name: " << user.getName() << std::endl;
	std::cout << "Age: " << user.getAge() << std::endl;
	std::cout << "Days worked: " << user.getDaysPerWeek() << std::endl;
	std::cout << "Annual Income: $" << user.getAnnualIncome() << std::endl;
	std::cout << "Filing Status: " << getFilingStatusName(user.getFilingStatus()) << std::endl;
	std::cout << "Pay Frequency: " << frequencyConversionHelper(user.getIncomeFrequency()) <<  std::endl;
	std::cout << "Calculated Federal Tax: $" << user.getTaxableIncome() << std::endl;
}

void DisplayService::displayFederalTaxResult(const User& user) const
{
	std::cout << "Federal Tax Owed: $" << formatCurrency(user.getTaxableIncome()) << std::endl;
	std::cout << "Effective Tax Rate: " << std::fixed << std::setprecision(2) << calculateAndDisplayEffectiveTaxRate(user) << "%" << std::endl;

}

double DisplayService::calculateAndDisplayEffectiveTaxRate(const User& user) const
{
	if (user.getAnnualIncome() == 0)
	{
		return 0.0;
	}
	double effectiveTaxRate = (user.getTaxableIncome() / user.getAnnualIncome()) * 100;
	return effectiveTaxRate;
}

std::string DisplayService::formatCurrency(double amount) const
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << amount;
	return oss.str();
}

void DisplayService::displayController(const User& displayChoice) const
{
	if (displayChoice.getUserDisplayChoice() == 'Y' || displayChoice.getUserDisplayChoice() == 'y')
	{
		std::cout << "Displaying results..." << std::endl;
		std::cout << "\n========== TAX CALCULATION RESULTS ==========" << std::endl;
		displayUserInformation(displayChoice);
		std::cout << std::endl;
		displayFederalTaxResult(displayChoice);
		std::cout << "=============================================" << std::endl;
		
	}

	else if (displayChoice.getUserDisplayChoice() == 'N' || displayChoice.getUserDisplayChoice() == 'n')
	{
		std::cout << "Results will not be displayed. " << std::endl;
	}
	else
	{
		std::cout << "Invalid display choice. Results will not be displayed. " << std::endl;
	}

}

std::string DisplayService::frequencyConversionHelper(User::IncomePeriod userSelection) const
{
	switch (userSelection)
	{
		case User::IncomePeriod::STOP: 
			{
			return "STOP";
			}

		case User::IncomePeriod::DAY: 
			{
			return "DAY";
			}	

		case User::IncomePeriod::WEEK:
			{
				return "WEEK";
			}

		case User::IncomePeriod::MONTH:
			{
				return "MONTH";
			}
	}

}