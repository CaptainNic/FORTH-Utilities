/*
 * StringTokenizer.h
 *
 *  Created on: Jan 23, 2011
 *      Author: Nick
 */

#ifndef STRINGTOKENIZER_H_
#define STRINGTOKENIZER_H_

#include "StandardIncludes.h"

class StringTokenizer
{
private:
	string data;
	string delimiter;
public:
	StringTokenizer(string data, string delimiter);
	virtual ~StringTokenizer();
	vector<string> getTokens(void);
};

#endif /* STRINGTOKENIZER_H_ */
