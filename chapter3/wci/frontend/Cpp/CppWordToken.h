/*
 * CppWordToken.h
 *
 *  Created on: Feb 7, 2019
 *      Author: justinstokes
 */

#ifndef WCI_FRONTEND_CPP_TOKENS_CPPWORDTOKEN_H_
#define WCI_FRONTEND_CPP_TOKENS_CPPWORDTOKEN_H_

#include <string>
#include "../CppToken.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend::Cpp;

class CppWordToken : public CppToken
{
public:
	/*
	 * Takes the source to be turned into tokens
	 * If error, throws message in form of string
	 */
	CppWordToken(Source *source) throw(string);
protected:
	/*
	 * Extracts a Cpp word token from source
	 * Override implementation of extract found in Token.h
	 * If error, throws message in form of string
	 */
	void extract() throw (string);
};

}}}}  //namespace brackets




#endif /* WCI_FRONTEND_CPP_TOKENS_CPPWORDTOKEN_H_ */
