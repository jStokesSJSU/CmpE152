/*
 * CppSpecialToken.h
 *
 *  Created on: Feb 7, 2019
 *      Author: david
 */


#ifndef WCI_FRONTEND_CPP_CPPSPECIALTOKEN_H_
#define WCI_FRONTEND_CPP_CPPSPECIALTOKEN_H_

#include <string>
#include <map>
#include "../CppToken.h"
#include "../CppSpecialToken.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend:cpp

class CppSpecialToken : public CppToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CppSpecialToken(Source *source) throw (string);

protected:
    /**
     * Extract a Cpp special symbol token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::cpp::tokens

#endif /* WCI_FRONTEND_CPP_TOKENS_CPPSPECIALTOKEN_H_ */

