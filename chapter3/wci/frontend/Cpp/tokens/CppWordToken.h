/*
 * CppWordToken.h
 *
 *  Created on: Feb 7, 2019
 *      Author: bobbyhaus
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
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CppWordToken(Source *source) throw (string);

protected:
    /**
     * Extract a Cpp word token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};



#endif /* WCI_FRONTEND_CPP_TOKENS_CPPWORDTOKEN_H_ */
