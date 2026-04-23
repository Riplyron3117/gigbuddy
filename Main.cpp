#include <iostream>
#include "models\User.h"
#include "input\InputCollector.h"
#include "display\DisplayService.h"
#include "tax_logic\TaxCalculator.h"
#include "tax_logic\TaxBracketRepository.h"
#include "tax_logic/IncomeNormalizer.h"

using namespace std;

int main()
{	
	
	try
	{
	DisplayService display;
	TaxCalculator taxCalculator;
	TaxBracketRepository taxRepository;
	InputCollector infoCollection;
	IncomeNormalizer incomeNorm;
	User user;

		user.setName(infoCollection.collectName());
		user.setAge(infoCollection.collectAge());
		user.setIncomeFrequency(infoCollection.payFrequency());

		infoCollection.collectIncomeDetails(user);

		user.setAnnualIncome(incomeNorm.normalizeIncome(user));
		user.setFilingStatus(infoCollection.collectFilingStatus());

		//calculate federal tax and store result
		// Note: This line chains two operations:
		//   1. calculateFederalTaxBracketData() - Computes tax using bob's income/filing status and tax bracket tables
		//   2. setTaxableIncome() - Stores the computed tax value in bob for later display.
		user.setTaxableIncome(taxCalculator.calculateFederalTaxBracketData(user, taxRepository)); //

		user.setUserDisplayChoice(infoCollection.userDisplayChoice());

		display.displayController(user);
	}

	catch(const std::exception& e)
	{
		std::cerr << "\n[Error]:" << e.what() << std::endl;
	}
}
