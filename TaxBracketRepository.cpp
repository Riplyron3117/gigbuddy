#include "TaxBracketRepository.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>
#include <string>
#include <optional>

TaxBracketRepository::TaxBracketRepository()
{
	initializeFederalTaxBracketData();
	initializeStateTaxBracketData();
}

void TaxBracketRepository::initializeFederalTaxBracketData()
{
	std::ifstream fedTaxFile("tax_brackets.json");
	if (!fedTaxFile.is_open())
	{
		throw std::runtime_error("Could not open the file");
	}

	nlohmann::json fedTaxJson = nlohmann::json::parse(fedTaxFile);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			std::optional<double> max;
			if (fedTaxJson["federal"][i]["brackets"][j]["max"].is_null())
			{
				max = std::nullopt;
			}
			else
			{
				max = fedTaxJson["federal"][i]["brackets"][j]["max"].get<double>();
			}
		
			federalFilingStatus[i].percentageRates[j] = { fedTaxJson["federal"][i]["brackets"][j]["rate"],
														  fedTaxJson["federal"][i]["brackets"][j]["min"],
														  max};
		}

	}

}

void TaxBracketRepository::initializeStateTaxBracketData()
{
	stateFilingStatus[0].statePercentageRates[0] = { 0.01, 0, 10756 };
	stateFilingStatus[0].statePercentageRates[1] = { 0.02, 10757, 25499 };
	stateFilingStatus[0].statePercentageRates[2] = { 0.04, 25500, 40245 };
	stateFilingStatus[0].statePercentageRates[3] = { 0.06, 40246, 55866 };
}

// ═══════════════════════════════════════════════════════════════
// getFederalTaxBrackets() - Returns federal tax brackets for filing status
// ═══════════════════════════════════════════════════════════════

const TaxBracketRepository::FederalTaxBrackets& TaxBracketRepository::getFederalTaxBrackets(int filingStatusIndex) const
{
	if (filingStatusIndex < 0 || filingStatusIndex >= 4)
	{
		throw std::out_of_range("Filing status index out of range " + std::to_string(filingStatusIndex)); // Invalid filing status index.
	}
	return federalFilingStatus[filingStatusIndex];
}

//═══════════════════════════════════════════════════════════════
// getStateTaxBrackets() - Returns state tax brackets for filing status
// ═══════════════════════════════════════════════════════════════

const TaxBracketRepository::StateTaxBrackets& TaxBracketRepository::getStateTaxBrackets(int filingStatusIndex) const
{
	return stateFilingStatus[filingStatusIndex];
}