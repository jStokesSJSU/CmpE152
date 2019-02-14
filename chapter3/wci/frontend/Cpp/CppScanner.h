/*
 * CppScanner.h
 *
 *  Created on: Feb 14, 2019
 *      Author: justinstokes
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_CPP_CPPSCANNER_H_
#define WCI_FRONTEND_CPP_CPPSCANNER_H_

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;
using namespace wci::frontend;

class CppScanner : public Scanner
{
public:
	/*
	 * Constructor, initialized with source
	 */
	CppScanner(Source *source);

protected:
	/*
	 * Extracts next token from source
	 * Returns token extracted
	 * Throws string if error
	 */
	Token *extract_token() throw (string);

private:
	/*
	 * Consumes and skips whitespace characters
	 * Throws string if error
	 */
	void skip_white_space() throw (string);
};

}}}



#endif /* WCI_FRONTEND_CPP_CPPSCANNER_H_ */
