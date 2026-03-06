#ifndef TAXCALCULATOR_H
#define TAXCALCULATOR_H

#include <algorithm>
#include <climits>
#include "User.h"
#include "TaxBracketRepository.h"
#pragma once
class TaxCalculator
{
public:

	TaxCalculator();

	double calculateFederalTaxBracketData(const User& user, const TaxBracketRepository& repository);
	double calculateStateTaxBracketData(const User& user, const TaxBracketRepository& repository);

private:

	double calculateTaxForBracket(int filingStatusIndex, double income, const TaxBracketRepository::FederalTaxBrackets& brackets);
};
#endif //!TAXCALCULATOR_H

