/*
 * StringTokenizer.cpp
 *
 *  Created on: Jan 23, 2011
 *      Author: Nick
 */

#include "StringTokenizer.h"

StringTokenizer::StringTokenizer(string data, string delimiter)
{
	this->data = data;
	this->delimiter = delimiter;
	//cout << "TOKENIZER DATA:\n" << data << endl;
}

StringTokenizer::~StringTokenizer()
{

}

vector<string> StringTokenizer::getTokens()
{
	vector<string> output;
	string::size_type leftDelimiter;	// First char of current token
	string::size_type rightDelimiter;	// First char of delimiter after current token
	// Finds first two delimeters on either side of first token
	leftDelimiter = data.find_first_not_of(this->delimiter, 0);
	rightDelimiter = data.find_first_of(this->delimiter, leftDelimiter);
	// While neither delimiters are out of range...
	while(string::npos != rightDelimiter || string::npos != leftDelimiter)
	{
		// Add token to vector and slide delimiters down one
		output.push_back(data.substr(leftDelimiter, rightDelimiter - leftDelimiter));
		leftDelimiter = data.find_first_not_of(this->delimiter, rightDelimiter);
		rightDelimiter = data.find_first_of(this->delimiter, leftDelimiter);
	}
	return output;
}
