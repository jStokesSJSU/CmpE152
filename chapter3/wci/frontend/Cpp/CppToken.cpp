/*
 * CppToken.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: bobbyhaus
 */

#include <string>
#include <vector>
#include <map>
#include "CppToken.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;

map<string, CppTokenType> CppToken::RESERVED_WORDS;
map<string, CppTokenType> CppToken::SPECIAL_SYMBOLS;
map<CppTokenType, string> CppToken::SPECIAL_SYMBOL_NAMES;

bool CppToken::INITIALIZED = false;

void CppToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
    	"AUTO", "BREAK", "CASE", "CHAR", "CLASS", "CONST", "CONTINUE", "DO",
    	"DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF",
    	"INT", "LONG", "NAMESPACE", "OPERATOR", "PROTECTED", "PUBLIC", "RETURN",
		"STATIC", "STRUCT", "SWITCH", "TEMPLATE", "THIS", "THROW", "UNION", "VOID", "WHILE"
    };

    vector<CppTokenType> rw_keys =
    {
        CppTokenType::AUTO,
        CppTokenType::BREAK,
        CppTokenType::CASE,
        CppTokenType::CHAR,
        CppTokenType::CLASS,
        CppTokenType::CONST,
        CppTokenType::CONTINUE,
        CppTokenType::DO,

        CppTokenType::DOUBLE,
        CppTokenType::ELSE,
        CppTokenType::ENUM,
        CppTokenType::EXTERN,
        CppTokenType::FLOAT,
        CppTokenType::FOR,
        CppTokenType::GOTO,
        CppTokenType::IF,

        CppTokenType::INT,
        CppTokenType::LONG,
        CppTokenType::NAMESPACE,
        CppTokenType::OPERATOR,
        CppTokenType::PROTECTED,
        CppTokenType::PUBLIC,
        CppTokenType::RETURN,
        CppTokenType::STATIC,

        CppTokenType::STRUCT,
        CppTokenType::SWITCH,
        CppTokenType::TEMPLATE,
        CppTokenType::THIS,
        CppTokenType::THROW,
        CppTokenType::UNION,
        CppTokenType::VOID,
        CppTokenType::WHILE

    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
        "~", "!", "@", "%", "^", "&", "*", "-", "+", "=", "|",
		"/", ":", ";" , "?", "<", ">", ".", ",", "'", "++",
		"--", "<<", ">>", "<=", ">=", "+=", "-=", "*=", "/=",
		"==", "|=", "%=", "&=", "^=", "!=", "<<=", ">>=",
		"||", "&&", "//", "/*", "*/"
    };

    vector<CppTokenType> ss_keys =
    {
        CppTokenType::TILDA,
        CppTokenType::NOT,
        CppTokenType::AT,
        CppTokenType::MOD,
        CppTokenType::CARROT,
        CppTokenType::AND,
        CppTokenType::STAR,
        CppTokenType::MINUS,
        CppTokenType::PLUS,
        CppTokenType::EQUALS,
        CppTokenType::OR,
        CppTokenType::SLASH,

        CppTokenType::COLON,
        CppTokenType::SEMI_COLON,
        CppTokenType::QUESTION,
		CppTokenType::LESS_THAN,
        CppTokenType::GREATER_THAN,
		CppTokenType::DOT,
		CppTokenType::COMMA,
		CppTokenType::QUOTE,
		CppTokenType::DOUBLE_QUOTE,
        CppTokenType::LEFT_PAR,
        CppTokenType::RIGHT_PAR,
        CppTokenType::LEFT_BRACKET,
        CppTokenType::RIGHT_BRACKET,

		CppTokenType::LEFT_CURLY,
        CppTokenType::RIGHT_CURLY,
        CppTokenType::PLUS_PLUS,
		CppTokenType::MINUS_MINUS,
        CppTokenType::OUT,
        CppTokenType::IN,
        CppTokenType::LESS_EQUALS,
        CppTokenType::GREATER_EQUALS,
        CppTokenType::PLUS_EQUALS,
        CppTokenType::MINUS_EQUALS,
        CppTokenType::STAR_EQUALS,

		CppTokenType::SLASH_EQUALS,
        CppTokenType::EQUALS_EQUALS,
        CppTokenType::OR_EQUALS,
        CppTokenType::MOD_EQUALS,
        CppTokenType::AND_EQUALS,
        CppTokenType::CARROT_EQUALS,
        CppTokenType::NOT_EQUALS,
        CppTokenType::OUT_EQUALS,
        CppTokenType::IN_EQUALS,
        CppTokenType::OR_OR,

        CppTokenType::AND_AND,
        CppTokenType::COMMENT,
        CppTokenType::OP_COMMENT,
        CppTokenType::CL_COMMENT,

    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
    	"TILDA", "NOT", "AT", "MOD", "CARROT", "AND", "STAR", "MINUS", "PLUS", "EQUAL", "OR",
    	"SLASH", "COLON", "SEMI_COLON", "QUESTION", "LESS_THAN", "GREATER_THAN",
    	"DOT", "COMMA", "QUOTE", "DOUBLE_QUOTE", "LEFT_PAR", "RIGHT_PAR", "LEFT_BRACKET",
   		"RIGHT_BRACKET", "LEFT_CURLY", "RIGHT_CURLY", "PLUS_PLUS", "MINUS_MINUS", "OUT, IN",
   		"LESS_EQUALS", "GREATER_EQUALS", "PLUS_EQUALS", "MINUS_EQUALS", "STAR_EQUALS",
   		"SLASH_EQUALS", "EQUALS_EQUALS", "OR_EQUALS", "MOD_EQUALS, AND_EQUALS",
   		"CARROT_EQUALS", "NOT_EQUALS", "OUT_EQUALS", "IN_EQUALS", "OR_OR", "AND_AND",
   		"COMMENT", "OP_COMMENT", "CL_COMMENT",
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

CppToken::CppToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::Cpp



