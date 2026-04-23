#include "InputCollector.h"
#include "validation\InputValidator.h"
#include "InputLoopHelper.h"
#include "resources\Strings.h"
#include <string>
#include <iostream>
#include <cctype>

//Constructor
InputCollector::InputCollector() {}


std::string InputCollector::inputCollectionHelper(std::string_view prompt, int iterator)
{
	std::string userInput;
	if (iterator > 0) { std::cout << std::string(prompt) + std::to_string(iterator) << ": "; }
	else std::cout << prompt;
	std::getline(std::cin, userInput);
	return userInput;
}

//collectName() collects user's name as input
//Utilizes reader and validation lambdas for prompting, taking input, validating input and assigning.
std::string InputCollector::collectName()
{
	InputValidator validatedName;

	//reader
	auto userNameCollection = [prompt = Prompts::namePrompt]() 
		{
			return inputCollectionHelper(prompt);
		};
	//validator takes raw input and outputs final, validated input
	auto userNameValidation = [&validatedName](std::string userName, std::string& outName)
		{
			bool nameValidator = false;
			nameValidator = validatedName.validateName(userName);
			if (nameValidator)
			{   //stores final output in outName is validation comes back true.
				outName = userName;
			}
			return nameValidator;
		};
	//InputLoopHelper calls reader and validator. Returns final value.
	return inputLoopLogic<std::string>(userNameCollection, userNameValidation);
}

//collectAge() collects users Age and Validates input
int InputCollector::collectAge()
{
	InputValidator ageValidator;

	//reader
	auto userAgeCollection = [prompt = Prompts::agePrompt]()
		{
			return inputCollectionHelper(prompt);
		};
	//validator
	auto userAgeValidation = [&ageValidator](std::string& inputAge, int& outPutAge)
		{
			bool ageValidation = false;
			ageValidation = ageValidator.validateAge(inputAge, outPutAge);
			return ageValidation;
		};
	
	return inputLoopLogic<int>(userAgeCollection, userAgeValidation);
}

//Collects and validates annual income of user.
double InputCollector::collectIncome(User::IncomePeriod frequency, int iterator = 0)
{
	InputValidator annualIncomeValidator;
	
	std::string_view userPrompt;
	switch (frequency)
	{
	case User::IncomePeriod::STOP: { userPrompt = Prompts::perStopPrompt; break; };
	case User::IncomePeriod::DAY: { userPrompt = Prompts::dailyIncomePrompt; break; };
	case User::IncomePeriod::WEEK: { userPrompt = Prompts::weeklyIncomePrompt; break; };
	case User::IncomePeriod::MONTH: { userPrompt = Prompts::monthlyIncomePrompt; break; };
	};

	auto userCollectAnnualIncome = [userPrompt, iterator]()
		{
			return inputCollectionHelper(userPrompt, iterator);
		};

	auto userValidateAnnualIncome = [&annualIncomeValidator](std::string inAnnualIncome, double& outAnnualIncome)
		{
			bool isAnnualValid = false;
			isAnnualValid = annualIncomeValidator.validateAnnualIncome(inAnnualIncome, outAnnualIncome);
			return isAnnualValid;
		};

	return inputLoopLogic<double>(userCollectAnnualIncome, userValidateAnnualIncome);
}
//Collects and validates the filing status of the user.
int InputCollector::collectFilingStatus()
{
	InputValidator filingStatusValidator;

	auto userCollectFilingStatus = [prompt = Prompts::filingStatusPrompt]()
		{
			return inputCollectionHelper(prompt);
		};

	auto userValidateFilingStatus = [&filingStatusValidator](std::string inFilingStatus, int& outFilingStatus)
		{
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
	InputValidator displayChoiceValidator;

	auto userCollectDisplayChoice = [prompt = Prompts::displayChoicePrompt]()
		{
			return inputCollectionHelper(prompt);
		};

	auto userValidateDisplayChoice = [&displayChoiceValidator](std::string inDisplayChoice, char& outDisplayChoice)
		{
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
	InputValidator payFrequencyValidator;

	auto userCollectPayFrequency = [prompt = Prompts::payFrequencyPrompt]()
		{
			return inputCollectionHelper(prompt);
		};

	auto userValidatePayFrequency = [&payFrequencyValidator](std::string inPayFrequency, int& outPayFrequency)
		{
			bool isPayFrequencyValid = false;
			isPayFrequencyValid = payFrequencyValidator.validateFrequencyChoice(inPayFrequency, outPayFrequency);
			return isPayFrequencyValid;
		};
		//stores the value returned by the InputLoop into an int variable to be cast to IncomePeriod before returning.
		int outPayFrequency = inputLoopLogic<int>(userCollectPayFrequency, userValidatePayFrequency);
	
		return static_cast<User::IncomePeriod>(outPayFrequency - 1);
}


//Collects and validates the days per week worked by the user.
int InputCollector::collectDaysPerWeek()
{
	InputValidator daysPerWeekValidator;

	auto userDaysPerWeek = [prompt = Prompts::daysPerWeekPrompt]()
		{
			return inputCollectionHelper(prompt);
		};

	auto userValidateDaysPerWeek = [&daysPerWeekValidator](std::string inDaysPerWeek, int& outDaysPerWeek)
		{
			bool isDaysPerWeekValid = false;
			isDaysPerWeekValid = daysPerWeekValidator.validateDaysPerWeek(inDaysPerWeek, outDaysPerWeek);
			return isDaysPerWeekValid;
		};

	return inputLoopLogic<int>(userDaysPerWeek, userValidateDaysPerWeek);
}
//Collects and validates the number of stops per day of the user.
int InputCollector::collectStopsPerDay()
{
	InputValidator stopsPerDayValidator;

	auto userStopsPerDay = [prompt = Prompts::stopsPerDayPrompt]()
		{
			return inputCollectionHelper(prompt);
		};
	auto userValidateStopsPerDay = [&stopsPerDayValidator](std::string inStopsPerDay, int& outStopsPerDay)
	{
		bool isStopsPerDayValid = false;
		isStopsPerDayValid = stopsPerDayValidator.validateStopsPerDay(inStopsPerDay, outStopsPerDay);
		return isStopsPerDayValid;
	};

	return inputLoopLogic<int>(userStopsPerDay, userValidateStopsPerDay);
}
//collectIncomeDetails() handles the collection of user 
//income details and applies the proper income frequency
//calculations for figuring out annual income.
void InputCollector::collectIncomeDetails(User& user)
{
	User::IncomePeriod userSelection = user.getIncomeFrequency();
	double runningTotal = 0.0;
	switch (userSelection)
	{
	case User::IncomePeriod::STOP :
	{

		user.setStopsPerDay(collectStopsPerDay());
		//Keeps a running total of the Income/stop
		for (int i = 0; i <= (user.getStopsPerDay()-1); i++)
		{
			runningTotal = runningTotal + collectIncome(User::IncomePeriod::STOP, i+1);
			user.setIncomeAmount(runningTotal);
		}
		user.setDaysPerWeek(collectDaysPerWeek());
		break;
	};
	case User::IncomePeriod::DAY :
	{
		user.setDaysPerWeek(collectDaysPerWeek());
		for (int i = 0; i <= (user.getDaysPerWeek() - 1); i++)
		{
			runningTotal = runningTotal + collectIncome(User::IncomePeriod::DAY, i + 1);
			user.setIncomeAmount(runningTotal);
		}
		break;
	};
	case User::IncomePeriod::WEEK : 
	{
		user.setIncomeAmount(collectIncome(user.getIncomeFrequency()));
		break;
	};
	case User::IncomePeriod::MONTH :
	{
		user.setIncomeAmount(collectIncome(user.getIncomeFrequency()));
		break;
	};
	}
}




