#pragma once

#include <string>

class InputValidator
{
	public:
		InputValidator();
		bool validateName(const std::string& name) const;
		bool validateAge(const std::string& age, int& outAge) const;
		bool validateAnnualIncome(const std::string& income, double& outIncome) const;
		bool validateFilingStatus(const std::string& filingStatus, int& outFilingStatus) const;
		bool validateDisplayChoice(const std::string& displayChoice) const;
		bool validateFrequencyChoice(const std::string& inFrequencyChoice, int& outFrequencyChoice) const;
		bool validateDaysPerWeek(const std::string& inDaysPerWeek, int& outDaysPerWeek) const;

private:
	bool validateIntegerValue(std::string_view errormsg, const std::string& input, int min, int max, int& outPut) const;
	bool validateIncomeValue(std::string_view errormsg, const std::string& input, double min, double& outPut) const;
};

