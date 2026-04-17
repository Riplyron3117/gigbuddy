#include "TaxBracketRepository.h"
#include "resources\strings.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>
#include <string>

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
		throw std::runtime_error(ErrorMessages::fileNotFound);
	}

	nlohmann::json fedTaxJson = nlohmann::json::parse(fedTaxFile);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			const auto& bracket = fedTaxJson["federal"][i]["brackets"][j];

			std::optional<double> max = bracket["max"].is_null()

				? std::nullopt : std::optional<double>(bracket["max"].get<double>());
			federalFilingStatus[i].percentageRates[j] = { bracket["rate"], bracket["min"], max };
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