/*
 * CppSpecialToken.h
 *
 *  Created on: Feb 7, 2019
 *      Author: david
 */

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend::cpp


CppSpecialToken::CppSpecialToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

void CppSpecialToken::extract() throw (string)
{
    char current_ch = current_char();
    bool good_symbol = true;

    text = current_ch;

    switch (current_ch)
    {

        case '~': case '!': case '@': case '%': case '^':
        case '&': case '*': case '-': case '+': case '=':
        case '|': case '/': case ':': case ';': case '?':
        case '<': case '>': case '.': case ',': case'++':
        case '--': case '<<': case '>>': case '<=': case '>=':
        case '+=': case '/=': case '==': case '|=': case '%=':
        case '&=': case '^=': case '!=': case '<<=': case '>>=':
        case '||': case '&&': case '//': case '/*': case '*/':

        {
            next_char();  // consume character
            break;
        }

        //~
        case '~':
        {
            current_ch = next_char();  // consume '~';
 			
 			if (current_ch == '~')
            {
                text += current_ch;
                next_char();  // consume '~'
            }

            break;
        }

        //:
        case ':':
        {
            current_ch = next_char();  // consume ':';
 			
 			if (current_ch == ':')
            {
                text += current_ch;
                next_char();  // consume ':'
            }

            break;
        }


        //;
        case ';':
        {
            current_ch = next_char();  // consume ';';
 			
 			if (current_ch == ';')
            {
                text += current_ch;
                next_char();  // consume ';'
            }

            break;
        }

        //@
        case '@':
        {
            current_ch = next_char();  // consume '@';
 			
 			if (current_ch == '@')
            {
                text += current_ch;
                next_char();  // consume '@'
            }

            break;
        }
 
        //?
        case '?':
        {
            current_ch = next_char();  // consume '?';
 			
 			if (current_ch == '?')
            {
                text += current_ch;
                next_char();  // consume '?'
            }

            break;
        }

 
        //.
        case '.':
        {
            current_ch = next_char();  // consume '.';
 			
 			if (current_ch == '.')
            {
                text += current_ch;
                next_char();  // consume '.'
            }

            break;
        }

        //,
        case ',':
        {
            current_ch = next_char();  // consume ',';
 			
 			if (current_ch == ',')
            {
                text += current_ch;
                next_char();  // consume ','
            }

            break;
        }

        // + or ++ or +=
        case '+':
        {
            current_ch = next_char();  // consume '+';

            if (current_ch == '+')
            {
                text += current_ch;
                next_char();  // consume '+'
            }
            else if (current_ch == '=')
            {
            	text += current_ch;
				next_char();  // consume '='
            }

            break;
        }

        // - or -- or -=
        case '-':
        {
            current_ch = next_char();  // consume '-';

            if (current_ch == '-')
            {
                text += current_ch;
                next_char();  // consume '-'
            }
            else if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }

            break;
        }

        // < or <= or << or <<=
        case '<':
	{
		current_ch = next_char();  // consume '<';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}
		else if (current_ch == '<')
		{
			text += current_ch;
			current_ch = next_char();  // consume '<'

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
		}
		break;
	}

		// > or >= or >> or >>=
	case '>':
	{
		current_ch = next_char();  // consume '>';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}
		else if (current_ch == '>')
		{
			text += current_ch;
			current_ch = next_char();  // consume '>'

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
		}
		break;
	}

		// * or *= or */
		case '*':
		{
			current_ch = next_char();  // consume '*';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '/')
			{
				text += current_ch;
				next_char();  // consume '/'
			}

			break;
		}

		// / or /= or /* or //
		case '/':
		{
			current_ch = next_char();  // consume '/';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '*')
			{
				text += current_ch;
				next_char();  // consume '*'
			}
			else if (current_ch == '/')
			{
				text += current_ch;
				next_char();  // consume '/'
			}

			break;
		}

		// = or ==
		case '=':
		{
			current_ch = next_char();  // consume '=';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}

			break;
		}

		// | or |= or ||
		case '|':
		{
			current_ch = next_char();  // consume '=';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '|')
			{
				text += current_ch;
				next_char();  // consume '|'
			}

			break;
		}

		// % or %=
		case '%':
		{
			current_ch = next_char();  // consume '%';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}

			break;
		}

		// & or &= or &&
		case '&':
		{
			current_ch = next_char();  // consume '&';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '&')
			{
				text += current_ch;
				next_char();  // consume '&'
			}

			break;
		}

		// ^ or ^=
		case '^':
		{
			current_ch = next_char();  // consume '^';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}

			break;
		}

		// ! or !=
		case '!':
		{
			current_ch = next_char();  // consume '!';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}

			break;
		}

        default:
        {
            next_char();  // consume bad character
            type = (TokenType) (PT_ERROR);
            value = new DataValue((int) INVALID_CHARACTER);
            good_symbol = false;
        }
    }

    // Set the type if it wasn't an error.
    if (good_symbol) {
        type = (TokenType) (CppToken::SPECIAL_SYMBOLS[text]);
    }
}

}}}}  // namespace wci::frontend::cpp::tokens
