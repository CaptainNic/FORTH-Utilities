/*
 * Driver.cpp
 *
 *  Created on: Feb 28, 2011
 *      Author: Nick
 */

#include "StandardIncludes.h"
#include "FileHandler.h"
#include "FileConverter.h"

int main()
{
	FileHandler inputFileHandler = FileHandler("inputFile.txt");
	FileHandler outputFileHandler = FileHandler("outputFile.txt");

	string inputData = inputFileHandler.loadFromFile();
	FileConverter fileConverter = FileConverter(inputData);
	string outputData = fileConverter.convertToLHS();
	outputFileHandler.saveToFile(outputData);
	return 0;
}
