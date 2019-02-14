/*
 * CppScanner.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: justinstokes
 */

#include <iostream>
#include "CppScanner.h"
#include "tokens/CppWordToken.h"
#include "tokens/CppNumberToken.h"
#include "tokens/CppStringToken.h"
#include "tokens/CppSpecialToken.h"
#include "tokens/CppErrorToken.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cpp::tokens;

CppScanner::CppScanner(Source *source) : Scanner(source)
{

}

Token *CppScanner::extract_token() throw (string)
{
	skip_white_space();

	Token *token;
	char current_ch = current_ch();
	string string_ch = " ";

	string_ch[0] = current_ch;
	//Construct next token, current ch detemermines token type
	if(current_ch == Source::END_OF_FILE)
	{
		token = nullptr;
	}
	else if(isalpha(current_ch))
	{
		token = new CppWordToken(source);
	}
	else if(isdigit(current_ch))
	{
		token = new CppNumberToken(source);
	}
	else if(current_ch == '\'')
	{
		token = new CppStringToken(source);
	}
	else if(CppToken::SPECIAL_SYMBOLS.find(string_ch) != CppToken::SPECIAL_SYMBOLS.end())
	{
		token = new CppSpecialToken(source);
	}
	else
	{
		token = new CppErrorToken(source, INVALID_CHARACTER, string_ch);
		next_char(); //consumes the invalid character
	}

	return token;
}

void CppScanner::skip_white_space() throw (string)
{
	char current_ch = current_char();

	while(isspace(current_ch) || (current_ch == '/'))
	{
		if(current_ch == '/')   //start of comment?
		{
			if(next_char == '/' || next_char == '*') //single/multi line comment
			{
				do
				{
					current_ch = next_char();
				} while ((current_ch != '/') && (current_ch != Source::END_OF_FILE));

				if(current_ch == '\'') //looking for end of multi line comment
				{
					current_ch = next_char();
				}
			}
		}
		else current_ch = next_char();
	}
}

}}}


