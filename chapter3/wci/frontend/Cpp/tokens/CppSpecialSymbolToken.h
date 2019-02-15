/*
 * CppSpecialSymbolToken.h
 *
 *  Created on: Feb 7, 2019
 *      Author: david
 */


#ifndef WCI_FRONTEND_CPP_CPPSPECIALSYMBOLTOKEN_H_
#define WCI_FRONTEND_CPP_CPPSPECIALSYMBOLTOKEN_H_

#include <string>
#include <map>
#include "../CppToken.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend::Cpp;

class CppSpecialSymbolToken : public CppToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CppSpecialSymbolToken(Source *source) throw (string);

protected:
    /**
     * Extract a Cpp special symbol token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::cpp::tokens

#endif /* WCI_FRONTEND_CPP_TOKENS_CPPSPECIALSYMBOLTOKEN_H_ */
