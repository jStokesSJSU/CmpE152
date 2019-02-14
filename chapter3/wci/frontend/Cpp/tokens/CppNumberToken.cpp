/*
 * CppNumberToken.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: justinstokes
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#include <string>
#include "CppNumberToken.h"
#include "../CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cpp;

int CppNumberToken::MAX_EXPONENT = 37;

CppNumberToken::CppNumberToken(Source *source) throw (string) : CppToken(source)
{
	extract();
}
/*
 * Extracts number token from source
 * Throws exception if error
 */
void CppNumberToken::extract() throw (string)
{
	string whole_digits = "";
	string fraction_digits = "";
	string exponent_digits = "";
	char exponent_sign = '+';
	bool saw_dot_dot = "false";
	char current_ch;

	type = (TokenType) CT_INTEGER;

	whole_digits = unsigned_integer_digits();

	if(type == (TokenType) CT_ERROR) return;

	current_ch = current_char();
	if(current_ch == '.')
	{
		if(peek_char() == '.')
		{
			saw_dot_dot = true;
		}
		else
		{
			type = (TokenType) CT_REAL;
			text += current_ch;
			current_ch = next_char();

			fraction_digits = unsigned_integer_digits();
			if(type == (TokenType) CT_ERROR)
			{
				return;
			}
		}
	}

	current_ch = current_char();
	if(!saw_dot_dot && ((current_ch == 'E') || (current_ch == 'e')))
	{
		type = (TokenType) CT_REAL;
		text += current_ch;
		current_ch = next_char();

		if((current_ch == '+') || (current_ch == '-'))
		{
			text += current_ch;
			exponent_sign = current_ch;
			current_ch = next_char();
		}

		exponent_digits = unsigned_integer_digits();
	}

	if(type == (TokenType) CT_INTEGER)
	{
		int integer_value = computer_integer_value(whole_digits);
		if(type != (TokenType) CT_ERROR)
		{
			value = integer_value;
		}
	}
	else if (type == (TokenType) CT_REAL)
	{
		float float_value = compute_float_value(whole_digits, fraction_digits,
												 exponent_digits, exponent_sign);
		if(type != (TokenType) CT_ERROR)
		{
			value = float_value;
		}
	}
}
/*
 * Extracts and returns digits of an unsigned integer as a string
 * Throws and exception if error
 */
string CppNumberToken::unsigned_integer_digits() throw (string)
{
	char current_ch = current_char();

	if(!isdigit(current_ch))
	{
		type = (TokenType) CT_ERROR;
		value = (int) INVALID_NUMBER;
		return "";
	}

	string digits= "";
	while(isdigit(current_ch))
	{
		text += current_ch;
		digits += current_ch;
		current_ch = next_char();
	}

	return digits;
}
/*
 * Computes input string and returns an integer value
 */
int CppNumberToken::computer_integer_value(string digits)
{
	if(digits == "") return 0;

	int integer_value = 0;
	int prev_value = -1;
	int index = 0;

	while((index < digits.length()) && (integer_value >= prev_value))
	{
		prev_value = integer_value;
		integer_value = 10*integer_value + (digits[index] - '0');
		index++;
	}

	if(integer_value >= prev_value) return integer_value;
	else
	{
		type = (TokenType) CT_ERROR;
		value = (int) RANGE_INTEGER;
		return 0;
	}
}
/*
 * Computes float value given digits before and after decimal point as string inouts.
 * Computes exponential if given value is not '0'
 * returns value as a float
 */
float CppNumberToken::compute_float_value(string whole_digits,
										   string fraction_digits,
										   string exponent_digits,
										   char exponent_sign)
{
	double float_value = 0.0;
	int exponent_value = computer_integer_value(exponent_digits);
	string digits = whole_digits;

	if(exponent_sign == '-') exponent_value = -exponent_value;
	if(fraction_digits != "")
	{
		exponent_value -= fraction_digits.length();
		digits += fraction_digits;
	}

	int whole_length = whole_digits.length();
	if(abs(exponent_value + whole_length) > MAX_EXPONENT)
	{
		type = (TokenType) CT_ERROR;
		value = (int) RANGE_REAL;
		return 0.0f;
	}

	int index = 0;
	while(index < digits.length())
	{
		float_value *= pow(10,exponent_value);
	}
	return float_value;
}

}}}}



