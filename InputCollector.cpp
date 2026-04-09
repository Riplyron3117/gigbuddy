#include "InputCollector.h"
#include "InputValidator.h"
#include "Strings.h"
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
		std::cout << Prompts::namePrompt;
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
		std::cout << Prompts::agePrompt;
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
		std::cout << Prompts::incomePrompt;
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
		std::cout << Prompts::filingStatusPrompt;
		std::getline(std::cin, filingStatusSelection);

		validSelection = filingStatusValidator.validateFilingStatus(filingStatusSelection, selection);

		if (validSelection == true) break;
		 
	} while (!validSelection);

	return selection;
}

//prompts the user on whether they want to display results or not.
//collects and validates the users choice before displaying results.
char InputCollector::userDisplayChoice()
{
	std::string userInput;
	bool validChoice = false;
	InputValidator displayChoiceValidator;

	do
	{
		std::cout << Prompts::displayChoicePrompt;
		std::getline(std::cin, userInput);

		validChoice = displayChoiceValidator.validateDisplayChoice(userInput);

		if (validChoice == true) break;


	} while (!validChoice);

	return userInput[0];
}

User::IncomePeriod InputCollector::payFrequency()
{
	std::string frequencySelection;
	int finalSelection = 0;
	bool validInput = false;
	InputValidator frequencyChoiceValidator;

	do
	{
		std::cout << Prompts::payFrequencyPrompt;
		std::getline(std::cin, frequencySelection);

		validInput = frequencyChoiceValidator.validateFrequencyChoice(frequencySelection, finalSelection);

		if (validInput == true) break;

	} while (!validInput);
	
	return static_cast<User::IncomePeriod>(finalSelection - 1);
}

double InputCollector::collectedDailyIncome()
{
	std::string inputDailyIncome;
	double dailyIncome = 0.0;
	bool dailyIncomeValidation = false;
	InputValidator dailyIncomeValidator;

	std::cout << Prompts::dailyIncomePrompt;
	std::getline(std::cin, inputDailyIncome);

	dailyIncome = std::stod(inputDailyIncome);

	return dailyIncome;
}

