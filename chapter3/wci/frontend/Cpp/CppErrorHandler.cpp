/*
 * CppErrorHandler.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: justinstokes
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../Token.h"
#include "../Parser.h"
#include "CppError.h"
#include "CppErrorHandler.h"
#include "../../message/Message.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;
using namespace wci::frontend;

const int CppErrorHandler::MAX_ERRORS = 25;
int CppErrorHandler::error_count = 0;

int CppErrorHandler::get_error_count() const { return error_count; }

void CppErrorHandler::flag(Token *token, CppErrorCode error_code, Parser *parser)
{
	string error_message = CppError::SYNTAX_ERROR_MESSAGES[error_code];
	Message message(SYNTAX_ERROR,
					LINE_NUMBER, to_string(token -> get_line_number()),
					POSITION, to_string(token -> get_position()),
					TOKEN_TEXT, token -> get_text(),
					ERROR_MESSAGE, error_message);
	parser -> send_message(message);

	if(++error_count > MAX_ERRORS)
	{
		abort_translation(TOO_MANY_ERRORS, parser);
	}
}

void CppErrorHandler::abort_translation(CppErrorCode error_code, Parser *parser)
{
	string error_message = "FATAL ERROR: " +
							CppError::SYNTAX_ERROR_MESSAGES[error_code];
	Message message(SYNTAX_ERROR,
					 LINE_NUMBER, "0",
					 POSITION, "0",
					 TOKEN_TEXT, "",
					 ERROR_MESSAGE, error_message);
	parser -> send_message(message);
	exit(-2);
}

}}}


