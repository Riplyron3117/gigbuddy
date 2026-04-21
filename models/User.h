#pragma once

#include <string>

class User
{
public:
	User();

	enum class IncomePeriod
	{
		STOP,
		DAY,
		WEEK,
		MONTH,
		NONE
	};

private:
		std::string name_ = "";
		std::string state_ = "";

		char userDisplayChoice_ = ' ';

		int age_ = 0,
		    filingStatus_ = 0,
		    stopsPerDay_ = 0,
		    daysPerWeek_ = 0;

		double safeSpendingAmount_ = 0.0,
			   quarterlyPayment_ = 0.0,
			   totalTaxOwed_ = 0.0,
			   stateTax_ = 0.0,
			   federalIncomeTax_ = 0.0,
			   federalTaxableIncome_ = 0.0,
			   seDeduction_ = 0.0,
			   seTax_ = 0.0,
			   standardDeduction_ = 0.0,
			   netSEIncome_ = 0.0,
			   annualIncome_ = 0.0,
			   taxableIncome_ = 0.0,
			   businessExpenses_ = 0.0,
			   incomeAmount_ = 0.0;

	    IncomePeriod incomeFrequency_ = IncomePeriod::NONE;


public:
	//getters for user data

		
	std::string getName() const { return name_; }
	
	std::string getState() const { return state_; }

	IncomePeriod getIncomeFrequency() const { return incomeFrequency_; }

	char getUserDisplayChoice() const { return userDisplayChoice_; }

	int getAge() const { return age_; }

	int getFilingStatus() const { return filingStatus_; }

	int getStopsPerDay() const { return stopsPerDay_; }

	int getDaysPerWeek() const { return daysPerWeek_; }

	double getAnnualIncome() const { return annualIncome_; }

	double getTaxableIncome() const { return taxableIncome_; }

	double getIncomeAmount() const { return incomeAmount_; }

	double getBusinessExpenses() const { return businessExpenses_; }

	double getNetSEIncome() const { return netSEIncome_; }

	double getStandardDeduction() const { return standardDeduction_; }

	double getSeTax() const { return seTax_; }

	double getSeDeduction() const { return seDeduction_; }

	double getFederalTaxableIncome() const { return federalTaxableIncome_; }

	double getFederalIncomeTax() const { return federalIncomeTax_; }

	double getStateTax() const { return stateTax_; }

	double getTotalTaxOwed() const { return totalTaxOwed_; }

	double getQuarterlyPayments() const { return quarterlyPayment_; }

	double getSafeSpendingAmount() const { return safeSpendingAmount_; }

	//setters for user data
	void setState(const std::string& state) { state_ = state; }

	void setName(const std::string& name) { name_ = name; }

	void setAge(int age) { age_ = age; }

	void setAnnualIncome(double income) { annualIncome_ = income; }

	void setFilingStatus(int status) { filingStatus_ = status; }

	void setTaxableIncome(double taxableIncome) { taxableIncome_ = taxableIncome; }

	void setUserDisplayChoice(char choice) { userDisplayChoice_ = choice; }

	void setIncomeFrequency(IncomePeriod frequency) { incomeFrequency_ = frequency; }

	void setStopsPerDay(int stops) { stopsPerDay_ = stops; }

	void setDaysPerWeek(int days) { daysPerWeek_ = days; }

	void setIncomeAmount(double income) { incomeAmount_ = income; }
	
	void setBusinessExpense(double expense) { businessExpenses_ = expense; }

	void setNetSEIncome(double SeIncome) { netSEIncome_ = SeIncome; }

	void setStandardDeduction(double deduction) { standardDeduction_ = deduction; }

	void setSeTax(double seTax) { seTax_ = seTax; }

	void setSeDeduction(double deDeduction) { seDeduction_ = deDeduction; }

	void setFederalTaxableIncome(double federalTaxableIncome) { federalTaxableIncome_ = federalTaxableIncome; }

	void setFederalIncomeTax(double federalIncomeTax) { federalIncomeTax_ = federalIncomeTax; }

	void setStateTax(double stateTax) { stateTax_ = stateTax; }

	void setTotalTaxOwed(double totalTaxOwed) { totalTaxOwed_ = totalTaxOwed; }

	void setQuarterlyPayments(double quarterlyPayments) { quarterlyPayment_ = quarterlyPayments; }

	void setSafeSpendingAmount(double safeSpendingAmount) {safeSpendingAmount_ = safeSpendingAmount; }

};
	





