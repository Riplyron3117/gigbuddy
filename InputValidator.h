#pragma once

#include <string>

class InputValidator
{
	public:
		InputValidator();
		bool validateName(const std::string& name) const;
		bool validateAge(const std::string& age, int& outAge) const;
		bool validateIncome(const std::string& income, double& outIncome) const;
		bool validateFilingStatus(const std::string& filingStatus, int& outFilingStatus) const;
		bool validateDisplayChoice(const std::string& displayChoice) const;
};

