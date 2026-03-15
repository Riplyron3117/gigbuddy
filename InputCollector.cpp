#include "InputCollector.h"
#include "InputValidator.h"
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

InputCollector::InputCollector() {}


//collectName() collects user's name as input

std::string InputCollector::collectName()
{
    std::string userName;
    bool userNameValidation = false;
	InputValidator nameValidator;

    do		//do-while loop collects users input and validates. 
	{
		std::cout << "Please Enter your Full Name: ";
		std::getline(std::cin, userName);

		userNameValidation = nameValidator.validateName(userName);

		if (userNameValidation == true) break;

	} while (userNameValidation == false);

	return userName;
}

//collectAge() collects users Age and Validates input
int InputCollector::collectAge()
{
	InputValidator ageValidator;
	std::string inputAge;	//initial string variable for checking for spaces, alpha characters, and symbols.
	int age = 0;
	bool ageValidation = false;

	do		//do-while collects user input and validates before value is returned.
	{
		std::cout << "Please enter a Valid age over 18 years old:  ";
		std::getline(std::cin, inputAge);

		ageValidation = ageValidator.validateAge(inputAge, age);

		if (ageValidation == true) break;

	} while (ageValidation == false);

	return age;
}

double InputCollector::collectIncome()
{
	std::string inputAnnualIncome;
	double annualIncome = 0;
	bool incomeValidation = false;
	InputValidator incomeValidator;

	do
	{
		std::cout << "Please enter your annual income: ";
		std::getline(std::cin, inputAnnualIncome);

		incomeValidation = incomeValidator.validateIncome(inputAnnualIncome, annualIncome);

		if (incomeValidation == true) break;

	} while (!incomeValidation);

	return annualIncome;
}

int InputCollector::collectFilingStatus()
{
	std::string filingStatusSelection;
	InputValidator filingStatusValidator;
	int selection = 0;
	bool validSelection = false;

	do
	{
		std::cout
			<< "1. Single. \n"
			<< "2. Married Filing Jointly. \n"
			<< "3. Married Filing Seperate. \n"
			<< "4. Head of Household. \n"
			<< "Please select your filing status by typing the corresponding number and pressing enter: ";
		std::getline(std::cin, filingStatusSelection);

		validSelection = filingStatusValidator.validateFilingStatus(filingStatusSelection, selection);

		if (validSelection == true) break;
		 
	} while (!validSelection);

	return selection;
}

char InputCollector::userDisplayChoice()
{
	std::string userInput;
	bool validChoice = false;
	InputValidator displayChoiceValidator;

	do
	{
		std::cout << "Would you like to display the results? (Y/N); " << std::endl;
		std::getline(std::cin, userInput);

		validChoice = displayChoiceValidator.validateDisplayChoice(userInput);

		if (validChoice == true) break;


	} while (!validChoice);

		return validChoice;

}