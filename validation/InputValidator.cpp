#include "validation\InputValidator.h"
#include "resources\strings.h"
#include <iostream>
#include <stdexcept>
#include <cctype>

InputValidator::InputValidator() {}

//validateName() validates user's input for name
bool InputValidator::validateName(const std::string& name) const
{
	return validateStringValue(ErrorMessages::invalidName, name);
}
//validateAge() validates age using validateIntegerValue
bool InputValidator::validateAge(const std::string& age, int& outAge) const
{
	return  validateIntegerValue(ErrorMessages::invalidAge, age, 18, 120, outAge);
}

bool InputValidator::validateDaysPerWeek(const std::string& inDaysPerWeek, int& outDaysPerWeek) const
{
	return  validateIntegerValue(ErrorMessages::invalidDaysPerWeek, inDaysPerWeek, 1, 7, outDaysPerWeek);
}

bool InputValidator::validateStopsPerDay(const std::string& inStopsPerDay, int& outStopsPerDay) const
{
	return validateIntegerValue(ErrorMessages::invalidStopsPerDay, inStopsPerDay, 0, 350, outStopsPerDay);
}
	
//validatesIncome validates the user's income (used for all income types)
bool InputValidator::validateAnnualIncome(const std::string& income, double& outIncome) const
{
	return validateIncomeValue(ErrorMessages::invalidIncome, income, 0, outIncome);
}
//validateFilingStatus validates the filing status choice of the user.
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

bool InputValidator::validateFrequencyChoice(const std::string& inFrequencyChoice, int& outFrequencyChoice) const
{
	return validateIntegerValue(ErrorMessages::invalidPayFrequency, inFrequencyChoice, 1, 4, outFrequencyChoice);
	
}

bool InputValidator::validateIntegerValue(const std::string_view errormsg, const std::string& input, int min, int max, int& outPut) const
{
	if (input.find(' ') != std::string::npos)	//checks for spaces in input
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	if (std::to_string(max).length() > 3)		//adds check bounds to prevent out of range errors when validating input.
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	for (char c : input)		//iterates over input, checking for non digit characters
	{
		if (!std::isdigit(static_cast<unsigned char>(c)))
		{
			std::cout << errormsg << std::endl;
			return false;
		}
	}

	try		//converts string inputAge into integar and stors in variable age.
	{
		outPut = std::stoi(input);
	}
	catch (const std::invalid_argument&) //catches invalid argument exceptions.
	{
		std::cout << errormsg << std::endl;
		return false;

	}
	catch (const std::out_of_range&)	//catches arguments that are out of range.
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	if (outPut < min || outPut > max)			//Validates age is between 18-120
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	return true;
}

bool InputValidator::validateIncomeValue(std::string_view errormsg, const std::string& input, double min, double& outPut) const
{
	bool decimalSeen = false;

	if (input.empty())
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	if (input.length() > 15) //adds check bounds to prevent out of range errors when validating input.
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	if (input.find(' ') != std::string::npos)
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	for (size_t input_size = 0; input_size < input.size(); input_size++)
	{
		char c = input[input_size];

		if (c == '.')
		{
			if (decimalSeen)
			{
				std::cout << errormsg << std::endl;
				return false;
			}
			decimalSeen = true;
		}

		else if (!std::isdigit(static_cast<unsigned char>(c)))
		{
			std::cout << errormsg << std::endl;
			return false;
		}
	}

	try
	{
		outPut = std::stod(input);
	}
	catch (const std::invalid_argument&)
	{
		std::cout << errormsg << std::endl;
		return false;
	}
	catch (const std::out_of_range&)
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	if (outPut < min)
	{
		std::cout << errormsg << std::endl;
		return false;
	}
	return true;

}

bool InputValidator::validateStringValue(std::string_view errormsg, const std::string& input) const
{
	if (input.empty()) //checks for empty input
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	//adds check bounds to prevent out of range errors when validating input.
	if (input.length() > 100)
	{
		std::cout << errormsg << std::endl;
		return false;
	}

	bool hasAlpha = false; //checks for at least one alpha character

	for (char c : input)		//iterates through Input checking for invalid characters.
	{	//checks if input is not an alpha or space.
		if (!std::isalpha(static_cast<unsigned char>(c)) && !std::isspace(static_cast<unsigned char>(c)))
		{
			std::cout << errormsg << std::endl;
			return false;
		}

		if (std::isalpha(static_cast<unsigned char>(c)))
		{
			hasAlpha = true;
		}

		if (!hasAlpha) //calidates the presence of at least one alpha character.
		{
			std::cout << ErrorMessages::invalidName << std::endl;
			return false;
		}
	}
		return true;
}
