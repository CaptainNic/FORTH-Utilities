/*
 * FileConverter.cpp
 *
 *  Created on: Feb 28, 2011
 *      Author: Nick
 */

#include "FileConverter.h"
#include "StringTokenizer.h"

FileConverter::FileConverter(string inputData)
{
	this->inputData = inputData;
}

FileConverter::~FileConverter()
{

}

string FileConverter::convertToLHS()
{
	StringTokenizer tokenizer = StringTokenizer(inputData, "\n");
	vector<string> tokenizedData = tokenizer.getTokens();
	vector<string> formattedData;
	stringstream currentLine;
	int page = PAGE_NUM_MIN;
	int line = LINE_NUM_MIN;
	stringIterator = tokenizedData.begin();
	while (stringIterator != tokenizedData.end())
	{
		for (page = PAGE_NUM_MIN; page <= PAGE_NUM_MAX && stringIterator
				!= tokenizedData.end(); ++page)
		{
			for (line = LINE_NUM_MIN; line <= LINE_NUM_MAX && stringIterator
					!= tokenizedData.end(); ++line, ++stringIterator)
			{
				currentLine.str("");
				currentLine << addLineIndex(page, line);
				currentLine << addCodeLine(*stringIterator);
				formattedData.push_back(currentLine.str());
			}
			if (line > LINE_NUM_MAX)
			{
				currentLine.str("");
				currentLine << addPageSpacer();
				formattedData.push_back(currentLine.str());
			}
		}
	}
	if (line < LINE_NUM_MAX)
	{
		formattedData = finishPageFormatting(formattedData, page - 1, line);
	}
	formattedData.push_back(addClosingPhrase());
	outputData = collapseToString(formattedData);
	return outputData;
}

string FileConverter::addCodeLine(string codeLine)
{
	return codeLine.substr(0, LINE_WIDTH_MAX);
}

string FileConverter::addPageSpacer()
{
	return "";
}

string FileConverter::addLineIndex(int page, int line)
{
	stringstream stringStream;
	if (page < 10)
	{
		stringStream << " ";
	}
	stringStream << page << "|";
	if (line < 10)
	{
		stringStream << " ";
	}
	stringStream << line << "|";
	return stringStream.str();
}

string FileConverter::collapseToString(vector<string> formattedData)
{
	stringstream stringStream;
	stringIterator = formattedData.begin();
	while (stringIterator != formattedData.end())
	{
		stringStream << *stringIterator << endl;
		++stringIterator;
	}
	return stringStream.str();
}

vector<string> FileConverter::finishPageFormatting(
		vector<string> formattedData, int page, int line)
{
	while (line <= LINE_NUM_MAX)
	{
		formattedData.push_back(addLineIndex(page, line));
		++line;
	}

	return formattedData;
}

string FileConverter::addClosingPhrase()
{
	return "ZZZZ";
}
