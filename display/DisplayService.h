#pragma once
#include <string>
#include "models\User.h"

class DisplayService
{
public:

		DisplayService();

		void displayUserInformation(const User& user) const;

		void displayFederalTaxResult(const User& user) const;

		std::string getFilingStatusName(int filingStatus) const; //converts filing status index to name for display

		void displayController(const User& displayChoice) const; //displays message asking if user would like to display results


private:

	std::string formatCurrency(double amount) const;

	double calculateAndDisplayEffectiveTaxRate(const User& user) const;

	std::string frequencyConversionHelper(User::IncomePeriod userSelection) const; //converts frequency from 1-4 to 0-3 to ensure it is properly displayed


	
};

