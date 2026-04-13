#include "InputCollector.h"
#include "InputValidator.h"
#include "InputLoopHelper.h"
#include "Strings.h"
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

InputCollector::InputCollector() {}


//collectName() collects user's name as input

std::string InputCollector::collectName()
{
	auto userNameCollection = []() 
		{
			std::string userName;
			std::cout << Prompts::namePrompt;
			std::getline(cin, userName);
			return userName;
		};

	auto userNameValidation = [](std::string userName, std::string& outName)
		{
			InputValidator validatedName;
			bool nameValidator = false;
			nameValidator = validatedName.validateName(userName);
			if (nameValidator)
			{
				outName = userName;
			}
			return nameValidator;
		};
	
	return inputLoopLogic<std::string>(userNameCollection, userNameValidation);;
}

//collectAge() collects users Age and Validates input
int InputCollector::collectAge()
{

	auto userAgeCollection = []()
		{
			std::string inputAge;	//initial string variable for checking for spaces, alpha characters, and symbols.
			std::cout << Prompts::agePrompt;
			std::getline(std::cin, inputAge);
			return inputAge;
		};

	auto userAgeValidation = [](std::string& inputAge, int& outPutAge)
		{
			InputValidator ageValidator;
			bool ageValidation = false;
			ageValidation = ageValidator.validateAge(inputAge, outPutAge);
			return ageValidation;
		};
	
	return inputLoopLogic<int>(userAgeCollection, userAgeValidation);
}

double InputCollector::collectIncome()
{

	auto userCollectAnnualIncome = []()
		{
			std::string inAnnualIncome;
			std::cout << Prompts::incomePrompt;
			std::getline(cin, inAnnualIncome);
			return inAnnualIncome;
		};

	auto userValidateAnnualIncome = [](std::string inAnnualIncome, double& outAnnualIncome)
		{
			InputValidator annualIncomeValidator;
			bool isAnnualValid = false;
			isAnnualValid = annualIncomeValidator.validateIncome(inAnnualIncome, outAnnualIncome);
			return isAnnualValid;
		};

	return inputLoopLogic<double>(userCollectAnnualIncome, userValidateAnnualIncome);
}

int InputCollector::collectFilingStatus()
{
	auto userCollectFilingStatus = []()
		{
			std::string inFilingStatus;
			std::cout << Prompts::filingStatusPrompt;
			std::getline(cin, inFilingStatus);
			return inFilingStatus;
		};

	auto userValidateFilingStatus = [](std::string inFilingStatus, int& outFilingStatus)
		{
			InputValidator filingStatusValidator;
			bool isFilingStatusValid = false;
			isFilingStatusValid = filingStatusValidator.validateFilingStatus(inFilingStatus, outFilingStatus);
			return isFilingStatusValid;
		};

	return inputLoopLogic<int>(userCollectFilingStatus, userValidateFilingStatus);
}

//prompts the user on whether they want to display results or not.
//collects and validates the users choice before displaying results.
char InputCollector::userDisplayChoice()
{
	auto userCollectDisplayChoice = []()
		{
			std::string inDisplayChoice;
			std::cout << Prompts::displayChoicePrompt;
			std::getline(cin, inDisplayChoice);
			return inDisplayChoice;
		};

	auto userValidateDisplayChoice = [](std::string inDisplayChoice, char& outDisplayChoice)
		{
			InputValidator displayChoiceValidator;
			bool isDisplayChoiceValid = false;
			isDisplayChoiceValid = displayChoiceValidator.validateDisplayChoice(inDisplayChoice);
			if (isDisplayChoiceValid)
			{
				outDisplayChoice = inDisplayChoice[0];
			}
			return isDisplayChoiceValid;
		};

	return inputLoopLogic<char>(userCollectDisplayChoice, userValidateDisplayChoice);
}

User::IncomePeriod InputCollector::payFrequency()
{
	auto userCollectPayFrequency = []()
		{
			std::string inPayFrequency;
			std::cout << Prompts::payFrequencyPrompt;
			std::getline(cin, inPayFrequency);
			return inPayFrequency;
		};

	auto userValidatePayFrequency = [](std::string inPayFrequency, int& outPayFrequency)
		{
			InputValidator payFrequencyValidator;
			bool isPayFrequencyValid = false;
			isPayFrequencyValid = payFrequencyValidator.validateFrequencyChoice(inPayFrequency, outPayFrequency);
			return isPayFrequencyValid;
		};

		int outPayFrequency = inputLoopLogic<int>(userCollectPayFrequency, userValidatePayFrequency);
	
		return static_cast<User::IncomePeriod>(outPayFrequency);
}

double InputCollector::collectDailyIncome()
{
	auto userDailyIncome = []()
		{
			std::string inDailyIncome;
			std::cout << Prompts::dailyIncomePrompt;
			std::getline(cin, inDailyIncome);
			return inDailyIncome;
		};

	auto userValidateDailyIncome = [](std::string inDailyIncome, double& outDailyIncome)
		{
			InputValidator dailyIncomeValidator;
			bool isDailyIncomeValid = false;
			isDailyIncomeValid = dailyIncomeValidator.validateIncome(inDailyIncome, outDailyIncome);
			return isDailyIncomeValid;
		};

	return inputLoopLogic<double>(userDailyIncome, userValidateDailyIncome);
}

