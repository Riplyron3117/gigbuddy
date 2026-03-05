#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <climits>
#include "TaxRedux.h"

using namespace std;

TaxCalculate::TaxCalculate() {
	federalTaxBracketData();
}

void TaxCalculate::federalTaxBracketData()
{
	federalFilingStatus[0].percentageRates[0] = { .10, 0 ,11600 };
	federalFilingStatus[0].percentageRates[1] = { .12, 11601, 47150 };
	federalFilingStatus[0].percentageRates[2] = { .22, 47151, 100525 };
	federalFilingStatus[0].percentageRates[3] = { .24, 100526, 191950 };
	federalFilingStatus[0].percentageRates[4] = { .32, 191951, 243725 };
	federalFilingStatus[0].percentageRates[5] = { .35, 243726, 609350 };
	federalFilingStatus[0].percentageRates[6] = { .37, 609351, INT_MAX};

	federalFilingStatus[1].percentageRates[0] = { .10, 0 ,23200 };
	federalFilingStatus[1].percentageRates[1] = { .12, 23201, 94300 };
	federalFilingStatus[1].percentageRates[2] = { .22, 94301, 201050 };
	federalFilingStatus[1].percentageRates[3] = { .24, 201051, 383900 };
	federalFilingStatus[1].percentageRates[4] = { .32, 383901, 487450 };
	federalFilingStatus[1].percentageRates[5] = { .35, 487451, 731200 };
	federalFilingStatus[1].percentageRates[6] = { .37, 731201, INT_MAX};

	federalFilingStatus[2].percentageRates[0] = { .10, 0 ,11600 };
	federalFilingStatus[2].percentageRates[1] = { .12, 11601, 47150 };
	federalFilingStatus[2].percentageRates[2] = { .22, 47151, 100525 };
	federalFilingStatus[2].percentageRates[3] = { .24, 100526, 191950 };
	federalFilingStatus[2].percentageRates[4] = { .32, 191951, 243725 };
	federalFilingStatus[2].percentageRates[5] = { .35, 243726, 365600 };
	federalFilingStatus[2].percentageRates[6] = { .37, 365601, INT_MAX};

	federalFilingStatus[3].percentageRates[0] = { .10, 0 ,16550 };
	federalFilingStatus[3].percentageRates[1] = { .12, 16551, 63100 };
	federalFilingStatus[3].percentageRates[2] = { .22, 63101, 100500 };
	federalFilingStatus[3].percentageRates[3] = { .24, 100501, 191950 };
	federalFilingStatus[3].percentageRates[4] = { .32, 191951, 243700 };
	federalFilingStatus[3].percentageRates[5] = { .35, 243701, 609350 };
	federalFilingStatus[3].percentageRates[6] = { .37, 609351, INT_MAX};
}

void TaxCalculate::stateTaxBracketData()
{
	stateFilingStatus[0].statePercentageRates[0] = { 0.01, 0, 10756 };
	stateFilingStatus[0].statePercentageRates[1] = { 0.02, 10757, 25499 };
	stateFilingStatus[0].statePercentageRates[2] = { 0.04, 25500, 40245 };
	stateFilingStatus[0].statePercentageRates[3] = { 0.06, 40246, 55866 };
}


//collectName() collects user's name as input

std::string TaxCalculate::collectName()
{
	string userName;			
	bool userNameValidation;	

	do		//do-while loop collects users input and validates. 
	{		
		std::cout << "Please Enter your Full Name: ";
		std::getline(cin, userName);

		userNameValidation = true;

		if (userName.empty()) //checks for empty input
		{
			userNameValidation = false;
			cout << "Invalid Input: Please enter a valid name " << endl;
			continue;
		}

		bool hasAlpha = false; //checks for at least one alpha character

		for (char c : userName)		//iterates through Input checking for invalid characters.
		{
			if (!std::isalpha(static_cast<unsigned char>(c)) && !isspace(static_cast<unsigned char>(c)))
			{
				userNameValidation = false;
				cout << "Invalid Input: Please enter a valid name " << endl;
				break;
			}
			if (std::isalpha(static_cast<unsigned char>(c)))
			{
				hasAlpha = true;
			}
		}

		if (!hasAlpha) //calidates the presence of at least one alpha character.
		{
			userNameValidation = false;
			cout << "Invalid Input: Please enter a valid name " << endl;
			continue;
		}

		if (userNameValidation == true) break;

		} while (userNameValidation==false);

	name_ = userName;
	return name_;
}

//collectAge() collects users Age and Validates input
int TaxCalculate::collectAge() 
{
	std::string inputAge;	//initial string variable for checking for spaces, alpha characters, and symbols.
	int age = 0;
	bool ageValidation;

	do		//do-while collects user input and validates before value is returned.
	{
		std::cout << "Please enter a Valid age over 18 years old:  ";
		std::getline(std::cin, inputAge);
		
		ageValidation = true;

		if (inputAge.find(' ') != std::string::npos)	//checks for spaces in input
		{
			ageValidation = false;
			std::cout << "Invalid Input. ";
			continue;
		}
	
		for (char c : inputAge)		//iterates over input, checking for non digit characters
		{
			if (!std::isdigit(static_cast<unsigned char>(c)))
			{
				ageValidation = false;
				std::cout << "Invalid Input. ";
				break;
			}
		}

		if (!ageValidation) continue;  //if false, skips to condition check.

		try		//converts string inputAge into integar and stors in variable age.
		{
			age = std::stoi(inputAge);
		}
		catch (const std::invalid_argument&) //catches invalid argument exceptions.
		{
			std::cout << "Invalid Input. ";
			ageValidation = false;
			continue;
		}
		catch (const std::out_of_range&)	//catches arguments that are out of range.
		{
			std::cout << "Invalid Input. ";
			ageValidation = false;
			continue;
		}

		if (age < 18 || age > 120)			//Validates age
		{
			ageValidation = false;
			std::cout << "Invalid Input. ";
			continue;
		}
	
		if (ageValidation == true) break;
	}
	while (ageValidation == false);

	age_ = age;

	return age_;
}

float TaxCalculate::collectIncome()
{
	std::string inputAnnualIncome;
	float annualIncome = 0;
	bool incomeValidation;
	

	do
	{
		cout << "Please enter your annual income: ";
		std::getline(std::cin, inputAnnualIncome);

		incomeValidation = true;
		bool decimalSeen = false;


		if (inputAnnualIncome.empty())
		{
			incomeValidation = false;
			cout << "Invalid Input. ";
			continue;
		}

		if (inputAnnualIncome.find(' ') != std::string::npos)
		{
			incomeValidation = false;
			cout << "Invalid Input. ";
			continue;
		}

		for (size_t input_size = 0; input_size < inputAnnualIncome.size(); input_size++)
		{
			char c = inputAnnualIncome[input_size];

			if (c == '.')
			{
				if (decimalSeen)
				{
					incomeValidation = false;
					break;
				}
				decimalSeen = true;	
			}
			
			else if (!std::isdigit(static_cast<unsigned char>(c)))
			{
				incomeValidation = false;
				break;
			}
		}

		if (!incomeValidation)
		{
			cout << "Invalid Input. ";
			continue;
		}

		try
		{
			annualIncome = std::stof(inputAnnualIncome);
		}
		catch (const std::invalid_argument&)
		{
			cout << "Invalid Input. ";
			incomeValidation = false;
			continue;
		}
		catch (const std::out_of_range&)
		{
			cout << "Invalid Input, ";
			incomeValidation = false;
			continue;
		}

		if (annualIncome < 0)
		{
			cout << "ERROR: Income cannot be a negative number";
			incomeValidation = false;
			continue;
		}

		if (incomeValidation == true) break;

	} while (!incomeValidation);

	annualIncome_ = annualIncome;

	return annualIncome_;
}

 int TaxCalculate::collectFilingStatus()
 {
	 std::string filingStatusSelection;
	 int selection=0;
	 bool validSelection;
	
	do
	{
		std::cout
		<< "1. Single. \n"
		<< "2. Married Filing Jointly. \n"
		<< "3. Married Filing Seperate. \n"
		<< "4. Head of Household. \n"
		<< "Please select your filing status by typing the corresponding number and pressing enter: ";
		cin >> filingStatusSelection;

		validSelection = true;	

		for (char input_size = 0; input_size < filingStatusSelection.size(); input_size++)
			
		{
			char c = filingStatusSelection[input_size];

			if (!std::isdigit(static_cast<unsigned char>(c)))
			{
				std::cout << "Invalid Input: Please enter a number between 1-4. \n";
				validSelection = false;
				break;
			}
		}
			selection = std::stoi(filingStatusSelection);

			if (selection < 1 || selection > 4)
			{
				cout << "invalid input: please enter a number between 1-4. \n";
				validSelection = false;
				break;
			}
	} while (!validSelection);

	filingStatus_ = selection;
	return filingStatus_;
}

 double TaxCalculate::calculateTaxForBracket(int filingStatusIndex, double income)
 {
	 double tax = 0.0;
	
	for (int i = 0; i < 7; ++i)
	{
		const auto& bracket = federalFilingStatus[filingStatusIndex].percentageRates[i];
		
		if (income <= bracket.minIncome)
			break;
		
		double taxableInBracket = std::min(income, static_cast<double>(bracket.maxIncome)) 
			- bracket.minIncome;
		tax += taxableInBracket * bracket.rate;
	}
	
	return tax;
 }

 double TaxCalculate::getFederalTaxBracketData()
 {
	 federalTaxBracketData(); // Initialize data once

	 // Map filing status (1-4) to array index (0-3)
	 int statusIndex = filingStatus_ - 1;

	 adjustedTaxableIncome_ = calculateTaxForBracket(statusIndex, annualIncome_);
	 return adjustedTaxableIncome_;
 }

 int TaxCalculate::convertFilingStatusNameToIndex(int filingStatus) const
 {
	 switch (filingStatus)
	 {
	 case 1: return 0; //return single

	 case 2: return 1; //returns married filing jointly

	 case 3: return 2; //returns married filing seperately

	 case 4: return 3; //returns head of household

	 default: return -1; //returns -1 for invalid input
	 }
 }

 void TaxCalculate::displayTaxInfo() const
 {
	 std::string filingStatusName;
	 switch (filingStatus_)
	 {
	 case 1: filingStatusName = "Single"; break;
	 case 2: filingStatusName = "Married Filing Jointly"; break;
	 case 3: filingStatusName = "Married Filing Seperate"; break;
	 case 4: filingStatusName = "Head of Household"; break;
	 default: filingStatusName = "Unknown"; break;
	 }

	 std::cout << "Name: " << name_ << endl;
	 std::cout << "Age: " << age_ << endl;
	 std::cout << "Annual Income: $" << annualIncome_ << endl;
	 std::cout << "Filing Status: " << filingStatusName << endl;
	 std::cout << "Calculated Federal Tax: $" << adjustedTaxableIncome_ << endl;
 }

