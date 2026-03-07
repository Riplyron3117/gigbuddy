#include "InputCollector.h"
#include <string>
#include <iostream>
#include <cctype>
#include <limits>

using namespace std;

InputCollector::InputCollector() {}


//collectName() collects user's name as input

std::string InputCollector::collectName()
{
    std::string userName;
    bool userNameValidation = false;

    do		//do-while loop collects users input and validates. 
	{
		std::cout << "Please Enter your Full Name: ";
		std::getline(std::cin, userName);

		//adds check bounds to prevent out of range errors when validating input.
		if (userName.length() > 100)
		{
			std::cout << "Invalid Input: Name cannot exceed 100 characters. Please enter a valid name. " << std::endl;
			continue;
		}

		userNameValidation = true;

		if (userName.empty()) //checks for empty input
		{
			userNameValidation = false;
			std::cout << "Invalid Input: Please enter a valid name " << std::endl;
			continue;
		}

		bool hasAlpha = false; //checks for at least one alpha character

		for (char c : userName)		//iterates through Input checking for invalid characters.
		{
			if (!std::isalpha(static_cast<unsigned char>(c)) && !std::isspace(static_cast<unsigned char>(c)))
			{
				userNameValidation = false;
				std::cout << "Invalid Input: Please enter a valid name " << std::endl;
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
			std::cout << "Invalid Input: Please enter a valid name " << std::endl;
			continue;
		}

		if (userNameValidation == true) break;

	} while (userNameValidation == false);

	return userName;
}

//collectAge() collects users Age and Validates input
int InputCollector::collectAge()
{
	std::string inputAge;	//initial string variable for checking for spaces, alpha characters, and symbols.
	int age = 0;
	bool ageValidation = false;

	do		//do-while collects user input and validates before value is returned.
	{
		std::cout << "Please enter a Valid age over 18 years old:  ";
		std::getline(std::cin, inputAge);

		if (inputAge.length() > 3)		//adds check bounds to prevent out of range errors when validating input.
		{
			std::cout << "Invalid Input. ";
			continue;
		}

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
	} while (ageValidation == false);

	return age;
}

double InputCollector::collectIncome()
{
	std::string inputAnnualIncome;
	double annualIncome = 0;
	bool incomeValidation = false;


	do
	{
		std::cout << "Please enter your annual income: ";
		std::getline(std::cin, inputAnnualIncome);

		if (inputAnnualIncome.length() > 15) //adds check bounds to prevent out of range errors when validating input.
		{
			std::cout << "Invalid Input. ";
			continue;
		}

		incomeValidation = true;
		bool decimalSeen = false;


		if (inputAnnualIncome.empty())
		{
			incomeValidation = false;
			std::cout << "Invalid Input. ";
			continue;
		}

		if (inputAnnualIncome.find(' ') != std::string::npos)
		{
			incomeValidation = false;
			std::cout << "Invalid Input. ";
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
			std::cout << "Invalid Input. ";
			continue;
		}

		try
		{
			annualIncome = std::stod(inputAnnualIncome);
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "Invalid Input. ";
			incomeValidation = false;
			continue;
		}
		catch (const std::out_of_range&)
		{
			std::cout << "Invalid Input, ";
			incomeValidation = false;
			continue;
		}

		if (annualIncome < 0)
		{
			std::cout << "ERROR: Income cannot be a negative number";
			incomeValidation = false;
			continue;
		}

		if (incomeValidation == true) break;

	} while (!incomeValidation);

	return annualIncome;
}

int InputCollector::collectFilingStatus()
{
	std::string filingStatusSelection;
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears input buffer

		if (filingStatusSelection.length() > 1) 	//adds check bounds to prevent out of range errors when validating input.
		{
			std::cout << "Invalid Input: Please enter a number between 1-4. \n";
			continue;
		}

		validSelection = true;

		for (size_t input_size = 0; input_size < filingStatusSelection.size(); input_size++)

		{
			char c = filingStatusSelection[input_size];

			if (!std::isdigit(static_cast<unsigned char>(c)))
			{
				std::cout << "Invalid Input: Please enter a number between 1-4. \n";
				validSelection = false;
				break;
			}
		}

		if (!validSelection) continue;

		try
		{
			selection = std::stoi(filingStatusSelection);
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "Invalid Input: Please enter a number between 1-4. \n";
			validSelection = false;
			continue;
		}
		catch (const std::out_of_range&)
		{
			std::cout << "Invalid Input: Please enter a number between 1-4. \n";
			validSelection = false;
			continue;
		}
		
		if (selection < 1 || selection > 4)
		{
			std::cout << "Invalid input: please enter a number between 1-4. \n";
			validSelection = false;
			continue;
		}
	} while (!validSelection);

	return selection;
}

char InputCollector::userDisplayChoice()
{
	std::string userInput;
	bool validChoice = false;

	do
	{
		std::cout << "Would you like to display the results? (Y/N); " << std::endl;
		std::getline(std::cin, userInput);

		if (userInput.length() > 1) //adds check bounds to prevent out of range errors when validating input.
		{
			validChoice = false;
			std::cout << "Invalid input: Please select Y for yes or N for no. " << std::endl;
			continue;
		}

		//check for empty input
		if (userInput.empty())
		{
			validChoice = false;
			std::cout << "invalid input : please select Y for yes or N for no. " << std::endl;
			continue;
		}

		//check for whitespace
		if (userInput.find_first_not_of(" \t") == std::string::npos)
		{
			validChoice = false;
			std::cout << "invalid input : please select Y for yes or N for no. " << std::endl;
			continue;
		}

		char userChoice = userInput[0];
		if (userChoice != 'Y' && userChoice != 'y' && userChoice != 'N' && userChoice != 'n')
		{
			validChoice = false;
			std::cout << "invalid input : please select Y for yes or N for no. " << std::endl;
			continue;
		}

		validChoice = true;
		return userChoice;

	} while (!validChoice);


}