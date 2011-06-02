/*
 * FileConverter.h
 *
 *  Created on: Feb 28, 2011
 *      Author: Nick
 */

#ifndef FILECONVERTER_H_
#define FILECONVERTER_H_

#include "StandardIncludes.h"

class FileConverter
{
public:
	FileConverter(string inputData);
	virtual ~FileConverter();
	string convertToLHS();
private:
	static const int PAGE_NUM_MIN = 1;
	static const int PAGE_NUM_MAX = 99; // technically 125 for 128k RAM on proSeed
	static const int LINE_NUM_MIN = 0;
	static const int LINE_NUM_MAX = 15;
	static const int LINE_WIDTH_MAX = 64;
	string inputData;
	vector<string> intermediateData;
	vector<string>::iterator stringIterator;
	string outputData;
	string addLineIndex(int page, int line);
	string addCodeLine(string);
	string addPageSpacer();
	string addLine(void);
	vector<string> finishPageFormatting(vector<string>, int, int);
	string addClosingPhrase(void);
	string collapseToString(vector<string>);
};

#endif /* FILECONVERTER_H_ */
