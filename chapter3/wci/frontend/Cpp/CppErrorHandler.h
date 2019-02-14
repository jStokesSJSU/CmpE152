/*
 * CppErroHandler.h
 *
 *  Created on: Feb 14, 2019
 *      Author: justinstokes
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_CPP_CPPERRORHANDLER_H_
#define WCI_FRONTEND_CPP_CPPERRORHANDLER_H_

#include "../Token.h"
#include "../Parser.h"
#include "CppError.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;
using namespace wci::frontend;

class CppErrorHandler
{
public:
	int get_error_count() const;
	void flag(Token *token, CppErrorCode error_code, Parser *parser);
	void abort_translation(CppErrorCode error_code, Parser *parser);

private:
	static int error_count;
	static const int MAX_ERRORS;
};

}}}

#endif /* WCI_FRONTEND_CPP_CPPERRORHANDLER_H_ */
