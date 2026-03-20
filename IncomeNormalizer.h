#pragma once

#include "User.h"

class IncomeNormalizer
{
public:
	IncomeNormalizer();

	double normalizeIncome(const User& user);
};
