/*
 * CppNumberToken.h
 *
 *  Created on: Feb 7, 2019
 *      Author: justinstokes
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_CPP_TOKENS_CPPNUMBERTOKEN_H_
#define WCI_FRONTEND_CPP_TOKENS_CPPNUMBERTOKEN_H_

#include <string>
#include "../CppToken.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend::Cpp;

class CppNumberToken : public CppToken
{
public:
	CppNumberToken(Source *source) throw (string);

protected:
	void extract() throw (string);
	void extract_number(string text) throw (string);

private:
	static int MAX_EXPONENT;
	string unsigned_integer_digits() throw (string);
	int computer_integer_value(string digits);
	float compute_float_value(string whole_digits, string fraction_digits,
							  string exponentDigits, char exponent_sign);
};

}}}}

#endif /* WCI_FRONTEND_CPP_TOKENS_CPPNUMBERTOKEN_H_ */
