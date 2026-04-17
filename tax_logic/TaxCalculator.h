#pragma once
#include "models\User.h"
#include "TaxBracketRepository.h"
class TaxCalculator
{
public:

	TaxCalculator();

	double calculateFederalTaxBracketData(const User& user, const TaxBracketRepository& repository);
	double calculateStateTaxBracketData(const User& user, const TaxBracketRepository& repository);

private:

	double calculateTaxForBracket(int filingStatusIndex, double income, const TaxBracketRepository::FederalTaxBrackets& brackets);
};


