#include "TaxBracketRepository.h"
#include <climits>

TaxBracketRepository::TaxBracketRepository()
{
	initializeFederalTaxBracketData();
	initializeStateTaxBracketData();
}

void TaxBracketRepository::initializeFederalTaxBracketData()
{
	federalFilingStatus[0].percentageRates[0] = { .10, 0 ,11600 };
	federalFilingStatus[0].percentageRates[1] = { .12, 11601, 47150 };
	federalFilingStatus[0].percentageRates[2] = { .22, 47151, 100525 };
	federalFilingStatus[0].percentageRates[3] = { .24, 100526, 191950 };
	federalFilingStatus[0].percentageRates[4] = { .32, 191951, 243725 };
	federalFilingStatus[0].percentageRates[5] = { .35, 243726, 609350 };
	federalFilingStatus[0].percentageRates[6] = { .37, 609351, INT_MAX };

	federalFilingStatus[1].percentageRates[0] = { .10, 0 ,23200 };
	federalFilingStatus[1].percentageRates[1] = { .12, 23201, 94300 };
	federalFilingStatus[1].percentageRates[2] = { .22, 94301, 201050 };
	federalFilingStatus[1].percentageRates[3] = { .24, 201051, 383900 };
	federalFilingStatus[1].percentageRates[4] = { .32, 383901, 487450 };
	federalFilingStatus[1].percentageRates[5] = { .35, 487451, 731200 };
	federalFilingStatus[1].percentageRates[6] = { .37, 731201, INT_MAX };

	federalFilingStatus[2].percentageRates[0] = { .10, 0 ,11600 };
	federalFilingStatus[2].percentageRates[1] = { .12, 11601, 47150 };
	federalFilingStatus[2].percentageRates[2] = { .22, 47151, 100525 };
	federalFilingStatus[2].percentageRates[3] = { .24, 100526, 191950 };
	federalFilingStatus[2].percentageRates[4] = { .32, 191951, 243725 };
	federalFilingStatus[2].percentageRates[5] = { .35, 243726, 365600 };
	federalFilingStatus[2].percentageRates[6] = { .37, 365601, INT_MAX };

	federalFilingStatus[3].percentageRates[0] = { .10, 0 ,16550 };
	federalFilingStatus[3].percentageRates[1] = { .12, 16551, 63100 };
	federalFilingStatus[3].percentageRates[2] = { .22, 63101, 100500 };
	federalFilingStatus[3].percentageRates[3] = { .24, 100501, 191950 };
	federalFilingStatus[3].percentageRates[4] = { .32, 191951, 243700 };
	federalFilingStatus[3].percentageRates[5] = { .35, 243701, 609350 };
	federalFilingStatus[3].percentageRates[6] = { .37, 609351, INT_MAX };
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
		throw std::abort; // Invalid filing status index.
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