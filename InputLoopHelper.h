#pragma once
#include <string_view>

template <typename InputType, typename Reader, typename Validator>

InputType inputLoopLogic(Reader input, Validator validation)
{
	InputType result;
	bool isValid = false;
		do
		{
			std::string rawInput = input();
			isValid = validation(rawInput);
			if (isValid == true) break;
		} while (!isValid);

		return result;
}


