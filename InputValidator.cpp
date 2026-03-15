#include "InputValidator.h"
#include "ErrorMessages.h"
#include <iostream>
#include <stdexcept>
#include <cctype>

InputValidator::InputValidator() {}

bool InputValidator::validateName(const std::string& name) const
{
	if (name.empty()) //checks for empty input
	{
		std::cout << ErrorMessages::invalidName << std::endl;
		return false;
	}

	//adds check bounds to prevent out of range errors when validating input.
	if (name.length() > 100)
	{
		std::cout << ErrorMessages::invalidName << std::endl;
		return false;
	}

	bool hasAlpha = false; //checks for at least one alpha character

	for (char c : name)		//iterates through Input checking for invalid characters.
	{
		if (!std::isalpha(static_cast<unsigned char>(c)) && !std::isspace(static_cast<unsigned char>(c)))
		{
			std::cout << ErrorMessages::invalidName << std::endl;
			return false;
		}

		if (std::isalpha(static_cast<unsigned char>(c)))
		{
			hasAlpha = true;
		}
	}

	if (!hasAlpha) //calidates the presence of at least one alpha character.
	{
		std::cout << ErrorMessages::invalidName << std::endl;
		return false;
	}

	return true;
}

bool InputValidator::validateAge(const std::string& age, int& outAge) const
{
	if (age.find(' ') != std::string::npos)	//checks for spaces in input
	{
		std::cout << ErrorMessages::invalidAge << std::endl;
		return false;
	}
		
	if (age.length() > 3)		//adds check bounds to prevent out of range errors when validating input.
	{
		std::cout << ErrorMessages::invalidAge << std::endl;
		return false;
	}

	for (char c : age)		//iterates over input, checking for non digit characters
	{
		if (!std::isdigit(static_cast<unsigned char>(c)))
		{
			std::cout << ErrorMessages::invalidAge << std::endl;
			return false;
		}
	}

	try		//converts string inputAge into integar and stors in variable age.
	{
		outAge = std::stoi(age);
	}
	catch (const std::invalid_argument&) //catches invalid argument exceptions.
	{
		std::cout << ErrorMessages::invalidAge << std::endl;
		return false;
		
	}
	catch (const std::out_of_range&)	//catches arguments that are out of range.
	{
		std::cout << ErrorMessages::invalidAge << std::endl;
		return false;
	}

	if (outAge < 18 || outAge > 120)			//Validates age
	{
		std::cout << ErrorMessages::invalidAge << std::endl;
		return false;
	}

	return true;
}

bool InputValidator::validateIncome(const std::string& income, double& outIncome) const
{
	bool decimalSeen = false;

	if (income.empty())
	{
		std::cout << ErrorMessages::invalidIncome << std::endl;
		return false;
	}

	if (income.length() > 15) //adds check bounds to prevent out of range errors when validating input.
	{
		std::cout << ErrorMessages::invalidIncome << std::endl;
		return false;
	}
		
	if (income.find(' ') != std::string::npos)
	{
		std::cout << ErrorMessages::invalidIncome << std::endl;
		return false;
	}

	for (size_t input_size = 0; input_size < income.size(); input_size++)
	{
		char c = income[input_size];

		if (c == '.')
		{
			if (decimalSeen)
			{
				std::cout << ErrorMessages::invalidIncome << std::endl;
				return false;
			}
			decimalSeen = true;
		}

		else if (!std::isdigit(static_cast<unsigned char>(c)))
		{
			std::cout << ErrorMessages::invalidIncome << std::endl;
			return false;
		}
	}

	try
	{
		outIncome = std::stod(income);
	}
	catch (const std::invalid_argument&)
	{
		std::cout << ErrorMessages::invalidIncome << std::endl;
		return false;
	}
	catch (const std::out_of_range&)
	{
		std::cout << ErrorMessages::invalidIncome << std::endl;
		return false;
	}

	if (outIncome < 0)
	{
		std::cout << ErrorMessages::invalidIncome << std::endl;
		return false;
	}
	return true;
}

bool InputValidator::validateFilingStatus(const std::string& filingStatus, int& outFilingStatus) const
{
	if (filingStatus.length() > 1) 	//adds check bounds to prevent out of range errors when validating input.
	{
		std::cout << ErrorMessages::invalidFilingStatus << std::endl;
		return false;
	}

	for (size_t input_size = 0; input_size < filingStatus.size(); input_size++)

	{
		char c = filingStatus[input_size];

		if (!std::isdigit(static_cast<unsigned char>(c)))
		{
			std::cout << ErrorMessages::invalidFilingStatus << std::endl;
			return false;
		}
	}

	try
	{
		outFilingStatus = std::stoi(filingStatus);
	}
	catch (const std::invalid_argument&)
	{
		std::cout << ErrorMessages::invalidFilingStatus << std::endl;
		return false;
	}
	catch (const std::out_of_range&)
	{
		std::cout << ErrorMessages::invalidFilingStatus << std::endl;
		return false;
	}

	if (outFilingStatus < 1 || outFilingStatus > 4)
	{
		std::cout << ErrorMessages::invalidFilingStatus << std::endl;
		return false;
	}
	return true;
}

bool InputValidator::validateDisplayChoice(const std::string& displayChoice) const
{
	if (displayChoice.length() > 1) //adds check bounds to prevent out of range errors when validating input.
	{
		std::cout << ErrorMessages::invalidDisplayChoice << std::endl;
		return false;
	}

	//check for empty input
	if (displayChoice.empty())
	{
		std::cout << ErrorMessages::invalidDisplayChoice << std::endl;
		return false;
	}

	//check for whitespace
	if (displayChoice.find_first_not_of(" \t") == std::string::npos)
	{
		std::cout << ErrorMessages::invalidDisplayChoice << std::endl;
		return false;
	}

	char outDisplayChoice = displayChoice[0];
	if (outDisplayChoice != 'Y' && outDisplayChoice != 'y' && outDisplayChoice != 'N' && outDisplayChoice != 'n')
	{
		std::cout << ErrorMessages::invalidDisplayChoice << std::endl;
		return false;
	}

	return true;
}
