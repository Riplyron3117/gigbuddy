#pragma once
#include <string>
#include <iostream>
#include "User.h"

class DisplayService
{
public:
		DisplayService();

		void displayUserInformation(const User& user) const;

		void displayFederalTaxResult(const User& user, double federalTax) const;

		std::string getFilingStatusName(int filingStatus) const; //converts filing status index to name for display
private:

	std::string formatCurrency(double amount) const;

	double calculateAndDisplayEffectiveTaxRate(const User& user, double federalTax) const;


	
};

