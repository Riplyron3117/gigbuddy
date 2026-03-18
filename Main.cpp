#include <iostream>
#include "User.h"
#include "InputCollector.h"
#include "DisplayService.h"
#include "TaxCalculator.h"
#include "TaxBracketRepository.h"

using namespace std;

int main()
{	
	TaxCalculator taxCalculator;
	TaxBracketRepository taxRepository;
	DisplayService display;
	InputCollector infoCollection;
	User bob;

	bob.setName(infoCollection.collectName());
	bob.setAge(infoCollection.collectAge());
	bob.setAnnualIncome(infoCollection.collectIncome());
	bob.setFilingStatus(infoCollection.collectFilingStatus());

	//calculate federal tax and store result
	// Note: This line chains two operations:
	//   1. calculateFederalTaxBracketData() - Computes tax using bob's income/filing status and tax bracket tables
	//   2. setTaxableIncome() - Stores the computed tax value in bob for later display.
	bob.setTaxableIncome(taxCalculator.calculateFederalTaxBracketData(bob, taxRepository)); //

	bob.setUserDisplayChoice(infoCollection.userDisplayChoice());

	display.displayController(bob);

	
	

	
}
