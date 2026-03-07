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
	bob.setUserDisplayChoice(infoCollection.userDisplayChoice());

	double federalTax = taxCalculator.calculateFederalTaxBracketData(bob, taxRepository);

	display.displayUserInformation(bob);
	display.displayFederalTaxResult(bob, federalTax);

	
}
