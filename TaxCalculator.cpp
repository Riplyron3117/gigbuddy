#include "TaxCalculator.h"
using namespace std;

TaxCalculator::TaxCalculator() {}

double TaxCalculator::calculateFederalTaxBracketData(const User& user, const TaxBracketRepository& repository)
{
	//gets the users data
	int filingStatus = user.getFilingStatus();
	double annualIncome = user.getAnnualIncome();

	//converts filing status(1 - 4) to array index(0 - 3) for accessing tax brackets
	int statusIndex = filingStatus - 1;

	//validates the index
	if (statusIndex < 0 || statusIndex >= 4)
	{
		return 0.0; // Invalid filing status
	}

	//gets the federal tax brackets for this filing status
	const TaxBracketRepository::FederalTaxBrackets& brackets = repository.getFederalTaxBrackets(statusIndex);

	double federalTax = calculateTaxForBracket(statusIndex, annualIncome, brackets);
	return federalTax;
}

double TaxCalculator::calculateTaxForBracket(int filingStatusIndex, double income, const TaxBracketRepository::FederalTaxBrackets& brackets)
{
	double tax = 0.0;

	for (int i = 0; i < 7; ++i)
	{
		const auto& bracket = brackets.percentageRates[i];

		if (income <= bracket.minIncome)
			break;

		double taxableInBracket = std::min(income, static_cast<double>(bracket.maxIncome))
			- static_cast<double>(bracket.minIncome);
		tax += taxableInBracket * bracket.rate;
	}

	return tax;
}