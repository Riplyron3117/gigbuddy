#pragma once
#ifndef User_h
#define User_h

#include <string>

class User
{
private:
		std::string name_ = "";
		int age_ = 0;
		float annualIncome_ = 0.0;
		int filingStatus_ = 0;

public:
	//getters for user data
	User();
		
	std::string getName() const { return name_; }
	 
	int getAge() const { return age_; }

	float getAnnualIncome() const { return annualIncome_; }

	int getFilingStatus() const { return filingStatus_; }

	//setters for user data
	void setName(const std::string& name) { name_ = name; }

	void setAge(int age) { age_ = age; }

	void setAnnualIncome(float income) { annualIncome_ = income; }

	void setFilingStatus(int status) { filingStatus_ = status; }






};
#endif //!User_h

