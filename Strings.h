//strings.h stores string constants
#pragma once
#include <string_view>
#include <string>

namespace Prompts
{
	inline constexpr std::string_view namePrompt = "Please Enter your Full Name: ";
	inline constexpr std::string_view agePrompt = "Please enter a Valid age over 18 years old: ";
	inline constexpr std::string_view incomePrompt = "Please enter your annual income: ";
	inline constexpr std::string_view dailyIncomePrompt = "Please enter your income for the day: ";
	inline constexpr std::string_view filingStatusPrompt = "1. Single. \n"
														   "2. Married Filing Jointly. \n"
														   "3. Married Filing Seperate. \n"
														   "4. Head of Household. \n"
														   "Please select your filing status by typing the corresponding number and pressing enter: ";

	inline constexpr std::string_view displayChoicePrompt = "Would you like to display the results? (Y/N); ";

	inline constexpr std::string_view payFrequencyPrompt = "Please select from the following pay feqeuency choices: \n"
													     	"1. Per Stop: \n"
															"2. Per Day: \n"
															"3. Per Week: \n"
															"4. Per Month: \n";
}

namespace ErrorMessages
{
	inline constexpr const char* invalidName = "Invalid Input: Please enter a valid name. Name cannot exceed 100 characters and must contain at least one alphabetical character.";

	inline constexpr const char* invalidAge = "Invalid Input: Please enter a valid age between 18 and 120.";

	inline constexpr const char* invalidIncome = "Invalid Input: Please enter a valid income amount. ";

	inline constexpr const char* invalidFilingStatus = "Invalid Input: Please enter a valid filing status by selecting the corresponding number from the list.";

	inline constexpr const char* invalidDisplayChoice = "Invalid Input: Please enter Y for yes or N for no.";

	inline constexpr const char* fileNotFound = "Could not open the file";

	inline constexpr const char* invalidPayFrequency = "Invalid Input: Please select 1. STOP, 2. DAY, 3. WEEK, 4. MONTH ";

}
