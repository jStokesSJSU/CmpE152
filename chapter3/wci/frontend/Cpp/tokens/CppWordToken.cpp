/*
 * CppWordToken.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: justinstokes
 */
#include <map>
#include <string>
#include <iostream>
#include <ctype.h>
#include "CppWordToken.h"
#include "../CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cpp;


/*
 * Extract word tokens from source, throw exception on error
 */
CppWordToken::CppWordToken(Source *source) throw (string) : CppToken(source)
{
	extract();
}

void CppWordToken::extract() throw (string)
{
	//grabs character/number from source.
	char curent_char = current_char();

	while(isalnum(current_ch))
	{

		text += current_ch;
		current_ch = next_char();
	}

	string upper_case = to_upper(text);

	if(CppToken::RESERVED_WORDS.find(upper_case) != CppToken::RESERVED_WORDS.end())
	{
		type = (TokenType) CppToken::RESERVED_WORDS[upper_case];
		value = upper_case;
	}
	else
	{
		type = (TokenType) CT_IDENTIFIER;
	}
}

}}}} //namespace wci::frontend::pascal::tokens



