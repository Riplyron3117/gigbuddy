#pragma once
#ifndef TAXBRACKETREPOSITORY_H
#define TAXBRACKETREPOSITORY_H	

#include <optional>
#include <array>

class TaxBracketRepository
{
public:

	struct FederalTaxRates
	{
		double rate{};
		double minIncome{};
		std::optional<double>maxIncome{};
	};

	struct FederalTaxBrackets
	{
		std::array<FederalTaxRates, 7> percentageRates{};
	};

	std::array<FederalTaxBrackets, 4> federalFilingStatus{};

	const struct StateTaxRates
	{
		double rate;
		double minIncome;
		std::optional<double>maxIncome;
	};
	const struct StateTaxBrackets
	{
		std::array<StateTaxRates, 9> statePercentageRates{};
	};
	std::array<StateTaxBrackets, 4> stateFilingStatus{};

	//initiliazation methods
	void initializeFederalTaxBracketData();
	void initializeStateTaxBracketData();

public:
	TaxBracketRepository();

	const FederalTaxBrackets& getFederalTaxBrackets(int filingStatusIndex) const;
	const StateTaxBrackets& getStateTaxBrackets(int filingStatusIndex) const;

};

#endif // TAXBRACKETREPOSITORY_H

