/*
 * CppToken.h
 *
 *  Created on: Feb 7, 2019
 *      Author: bobbyhaus
 */

#ifndef WCI_FRONTEND_CPP_CPPTOKEN_H_
#define WCI_FRONTEND_CPP_CPPTOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;
using namespace wci::frontend;

/**
 * Cpp token types.
 */
enum class CppTokenType
{
    // Reserved words.
	AUTO, BREAK, CASE, CHAR, CLASS, CONST, CONTINUE, DO,
	DOUBLE, ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF,
	INT, LONG, NAMESPACE, OPERATOR,PROTECTED,PUBLIC, RETURN, STATIC,
	STRUCT, SWITCH, TEMPLATE, THIS, THROW, UNION, VOID, WHILE,


    // Special symbols.
    TILDA, NOT, AT, MOD, CARROT, AND, STAR, MINUS, PLUS, EQUALS, OR,
	SLASH, COLON, SEMI_COLON, QUESTION, LESS_THAN, GREATER_THAN,
	DOT, COMMA, QUOTE, DOUBLE_QUOTE, LEFT_PAR, RIGHT_PAR, LEFT_BRACKET,
	RIGHT_BRACKET, LEFT_CURLY, RIGHT_CURLY, PLUS_PLUS, MINUS_MINUS, OUT, IN,
	LESS_EQUALS, GREATER_EQUALS, PLUS_EQUALS, MINUS_EQUALS, STAR_EQUALS,
	SLASH_EQUALS, EQUALS_EQUALS, OR_EQUALS, MOD_EQUALS, AND_EQUALS,
	CARROT_EQUALS, NOT_EQUALS, OUT_EQUALS, IN_EQUALS, OR_OR, AND_AND,
	COMMENT, OP_COMMENT, CL_COMMENT,

    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

constexpr CppTokenType CT_AUTO = CppTokenType::AUTO;
constexpr CppTokenType CT_BREAK = CppTokenType::BREAK;
constexpr CppTokenType CT_CASE = CppTokenType::CASE;
constexpr CppTokenType CT_CHAR = CppTokenType::CHAR;
constexpr CppTokenType CT_CONST = CppTokenType::CONST;
constexpr CppTokenType CT_CONTINUE = CppTokenType::CONTINUE;
constexpr CppTokenType CT_DO = CppTokenType::DO;
constexpr CppTokenType CT_DOUBLE = CppTokenType::DOUBLE;

constexpr CppTokenType CT_ELSE = CppTokenType::ELSE;
constexpr CppTokenType CT_ENUM = CppTokenType::ENUM;
constexpr CppTokenType CT_EXTERN = CppTokenType::EXTERN;
constexpr CppTokenType CT_FLOAT = CppTokenType::FLOAT;
constexpr CppTokenType CT_FOR = CppTokenType::FOR;
constexpr CppTokenType CT_GOTO = CppTokenType::GOTO;
constexpr CppTokenType CT_IF = CppTokenType::IF;
constexpr CppTokenType CT_INT = CppTokenType::INT;

constexpr CppTokenType CT_LONG = CppTokenType::LONG;
constexpr CppTokenType CT_NAMESPACE = CppTokenType::NAMESPACE;
constexpr CppTokenType CT_OPERATOR = CppTokenType::OPERATOR;
constexpr CppTokenType CT_PROTECTED = CppTokenType::PROTECTED;
constexpr CppTokenType CT_PUBLIC = CppTokenType::PUBLIC;
constexpr CppTokenType CT_RETURN = CppTokenType::RETURN;
constexpr CppTokenType CT_STATIC = CppTokenType::STATIC;
constexpr CppTokenType CT_STRUCT = CppTokenType::STRUCT;

constexpr CppTokenType CT_SWITCH = CppTokenType::SWITCH;
constexpr CppTokenType CT_TEMPLATE = CppTokenType::TEMPLATE;
constexpr CppTokenType CT_THIS = CppTokenType::THIS;
constexpr CppTokenType CT_THROW = CppTokenType::THROW;
constexpr CppTokenType CT_UNION = CppTokenType::UNION;
constexpr CppTokenType CT_VOID = CppTokenType::VOID;
constexpr CppTokenType CT_WHILE = CppTokenType::WHILE;


constexpr CppTokenType CT_TILDA = CppTokenType::TILDA;
constexpr CppTokenType CT_NOT = CppTokenType::NOT;
constexpr CppTokenType CT_AT = CppTokenType::AT;
constexpr CppTokenType CT_MOD = CppTokenType::MOD;
constexpr CppTokenType CT_CARROT = CppTokenType::CARROT;
constexpr CppTokenType CT_AND = CppTokenType::AND;
constexpr CppTokenType CT_STAR = CppTokenType::STAR;
constexpr CppTokenType CT_MINUS = CppTokenType::MINUS;
constexpr CppTokenType CT_PLUS = CppTokenType::PLUS;
constexpr CppTokenType CT_EQUALS = CppTokenType::EQUALS;
constexpr CppTokenType CT_OR = CppTokenType::OR;
constexpr CppTokenType CT_SLASH = CppTokenType::SLASH;

constexpr CppTokenType CT_COLON = CppTokenType::COLON;
constexpr CppTokenType CT_SEMI_COLON = CppTokenType::SEMI_COLON;
constexpr CppTokenType CT_QUESTION = CppTokenType::QUESTION;
constexpr CppTokenType CT_LESS_THAN = CppTokenType::LESS_THAN;
constexpr CppTokenType CT_GREATER_THAN = CppTokenType::GREATER_THAN;
constexpr CppTokenType CT_DOT = CppTokenType::DOT;
constexpr CppTokenType CT_COMMA = CppTokenType::COMMA;
constexpr CppTokenType CT_QUOTE = CppTokenType::QUOTE;
constexpr CppTokenType CT_DOUBLE_QUOTE = CppTokenType::DOUBLE_QUOTE;
constexpr CppTokenType CT_LEFT_PAR = CppTokenType::LEFT_PAR;
constexpr CppTokenType CT_RIGHT_PAR = CppTokenType::RIGHT_PAR;
constexpr CppTokenType CT_LEFT_BRACKET = CppTokenType::LEFT_BRACKET;
constexpr CppTokenType CT_RIGHT_BRACKET = CppTokenType::RIGHT_BRACKET;

constexpr CppTokenType CT_LEFTY_CURLY = CppTokenType::LEFT_CURLY;
constexpr CppTokenType CT_RIGHT_CURLY = CppTokenType::RIGHT_CURLY;
constexpr CppTokenType CT_PLUS_PLUS = CppTokenType::PLUS_PLUS;
constexpr CppTokenType CT_MINUS_MINUS = CppTokenType::MINUS_MINUS;
constexpr CppTokenType CT_OUT = CppTokenType::OUT;
constexpr CppTokenType CT_IN = CppTokenType::IN;
constexpr CppTokenType CT_LESS_EQUALS = CppTokenType::LESS_EQUALS;
constexpr CppTokenType CT_GREATER_EQUALS = CppTokenType::GREATER_EQUALS;
constexpr CppTokenType CT_PLUS_EQUALS = CppTokenType::PLUS_EQUALS;
constexpr CppTokenType CT_MINUS_EQUALS = CppTokenType::MINUS_EQUALS;
constexpr CppTokenType CT_STAR_EQUALS = CppTokenType::STAR_EQUALS;

constexpr CppTokenType CT_SLASH_EQUALS = CppTokenType::SLASH_EQUALS;
constexpr CppTokenType CT_EQUALS_EQUALS = CppTokenType::EQUALS_EQUALS;
constexpr CppTokenType CT_OR_EQUALS = CppTokenType::OR_EQUALS;
constexpr CppTokenType CT_MOD_EQUALS = CppTokenType::MOD_EQUALS;
constexpr CppTokenType CT_AND_EQUALS = CppTokenType::AND_EQUALS;
constexpr CppTokenType CT_CARROT_EQUALS = CppTokenType::CARROT_EQUALS;
constexpr CppTokenType CT_NOT_EQUALS = CppTokenType::NOT_EQUALS;
constexpr CppTokenType CT_OUT_EQUALS = CppTokenType::OUT_EQUALS;
constexpr CppTokenType CT_IN_EQUALS = CppTokenType::IN_EQUALS;
constexpr CppTokenType CT_OR_OR = CppTokenType::OR_OR;
constexpr CppTokenType CT_AND_AND = CppTokenType::AND_AND;
constexpr CppTokenType CT_COMMENT = CppTokenType::COMMENT;
constexpr CppTokenType CT_OP_COMMENT = CppTokenType::OP_COMMENT;
constexpr CppTokenType CT_CL_COMMENT = CppTokenType::CL_COMMENT;

constexpr CppTokenType CT_IDENTIFIER = CppTokenType::IDENTIFIER;
constexpr CppTokenType CT_INTEGER = CppTokenType::INTEGER;
constexpr CppTokenType CT_REAL = CppTokenType::REAL;
constexpr CppTokenType CT_STRING = CppTokenType::STRING;
constexpr CppTokenType CT_ERROR = CppTokenType::ERROR;
constexpr CppTokenType CT_END_OF_FILE = CppTokenType::END_OF_FILE;

class CppToken : public Token
{
public:
    static map<string, CppTokenType> RESERVED_WORDS;
    static map<string, CppTokenType> SPECIAL_SYMBOLS;
    static map<CppTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CppToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::cpp




#endif /* WCI_FRONTEND_CPP_CPPTOKEN_H_ */
