#include <iomanip>
#include <sstream>
#include "InputCollector.h"
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
	std::string filingStatusName;
	switch (user.getFilingStatus())
	{
	case 1: filingStatusName = "Single"; break;
	case 2: filingStatusName = "Married Filing Jointly"; break;
	case 3: filingStatusName = "Married Filing Seperate"; break;
	case 4: filingStatusName = "Head of Household"; break;
	default: filingStatusName = "Unknown"; break;
	}

	std::cout << "Name: " << user.getName() << std::endl;
	std::cout << "Age: " << user.getAge() << std::endl;
	std::cout << "Annual Income: $" << user.getAnnualIncome() << std::endl;
	std::cout << "Filing Status: " << getFilingStatusName(user.getFilingStatus()) << std::endl;
	std::cout << "Calculated Federal Tax: $" << user.getTaxableIncome() << std::endl;
	std::cout << user.getUserDisplayChoice() << std::endl;
}

void DisplayService::displayFederalTaxResult(const User& user, double federalTax) const
{
	std::cout << "Federal Tax Owed: $" << formatCurrency(federalTax) << std::endl;
	std::cout << "Effective Tax Rate: " << std::fixed << std::setprecision(2) << calculateAndDisplayEffectiveTaxRate(user, federalTax) << "%" << std::endl;

}

double DisplayService::calculateAndDisplayEffectiveTaxRate(const User& user, double federalTax) const
{
	if (user.getAnnualIncome() == 0)
	{
		return 0.0;
	}
	double effectiveTaxRate = (federalTax / user.getAnnualIncome()) * 100;
	return effectiveTaxRate;
}

std::string DisplayService::formatCurrency(double amount) const
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << amount;
	return oss.str();
}

