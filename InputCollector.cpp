#include "InputCollector.h"
#include "InputValidator.h"
#include "InputLoopHelper.h"
#include "Strings.h"
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

//Constructor
InputCollector::InputCollector() {}


//collectName() collects user's name as input
//Utilizes reader and validation lambdas for prompting, taking input, validating input and assigning.
std::string InputCollector::collectName()
{	//reader
	auto userNameCollection = []() 
		{
			std::string userName;
			std::cout << Prompts::namePrompt;
			std::getline(cin, userName);
			return userName;
		};
	//validator takes raw input and outputs final, validated input
	auto userNameValidation = [](std::string userName, std::string& outName)
		{
			InputValidator validatedName;
			bool nameValidator = false;
			nameValidator = validatedName.validateName(userName);
			if (nameValidator)
			{   //stores final output in outName is validation comes back true.
				outName = userName;
			}
			return nameValidator;
		};
	//InputLoopHelper calls reader and validator. Returns final value.
	return inputLoopLogic<std::string>(userNameCollection, userNameValidation);;
}

//collectAge() collects users Age and Validates input
int InputCollector::collectAge()
{
	//reader
	auto userAgeCollection = []()
		{
			std::string inputAge;	
			std::cout << Prompts::agePrompt;
			std::getline(std::cin, inputAge);
			return inputAge;
		};
	//validator
	auto userAgeValidation = [](std::string& inputAge, int& outPutAge)
		{
			InputValidator ageValidator;
			bool ageValidation = false;
			ageValidation = ageValidator.validateAge(inputAge, outPutAge);
			return ageValidation;
		};
	
	return inputLoopLogic<int>(userAgeCollection, userAgeValidation);
}
//Collects and validates annual income of user.
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
//Collects and validates the filing status of the user.
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
			{	//Stores the value at index 0 of std::string inDisplayChoice 
				//inside of char outDisplayChoice.
				outDisplayChoice = inDisplayChoice[0];
			}
			return isDisplayChoiceValid;
		};

	return inputLoopLogic<char>(userCollectDisplayChoice, userValidateDisplayChoice);
}
//Collects and validates the pay frequency of the user.
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
		//stores the value returned by the InputLoop into an int variable to be cast to IncomePeriod before returning.
		int outPayFrequency = inputLoopLogic<int>(userCollectPayFrequency, userValidatePayFrequency);
	
		return static_cast<User::IncomePeriod>(outPayFrequency);
}
// Collects and validates the daily income of the user.
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

