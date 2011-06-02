/*
 * FileHandler.cpp
 *
 *  Created on: Jan 20, 2011
 *      Author: Nic
 */

#include "FileHandler.h"

FileHandler::FileHandler()
{

}

FileHandler::FileHandler(string fileName)
{
	this->fileName = fileName;
}

FileHandler::~FileHandler()
{

}

string FileHandler::loadFromFile()
{
	if(!fileExists())
		return "";

	ifstream inputFile;		// File stream for file being read
	string fileData = "";	// string data that will be returned

	// Open file
	inputFile.open(fileName.c_str());
	if(!inputFile.is_open())
	{
		cout << "Could not open file.";
		return NULL;
	}
	// Read file in by line
	string currentLine;
	while(!inputFile.eof())
	{
		getline(inputFile, currentLine);
		fileData += currentLine + "\n";
	}
	// Close file
	inputFile.close();
	return fileData;
}

void FileHandler::saveToFile(string data)
{
	ofstream writeFile;
	writeFile.open(fileName.c_str(), ofstream::out);
	writeFile << data;
	writeFile.close();
}

void FileHandler::setFile(string fileName)
{
	this->fileName = fileName;
}

// Returns true if an fstream can be opened with fileName
bool FileHandler::fileExists()
{
	fileStream.open(fileName.c_str(), fstream::in | fstream::out);
	if(fileStream.is_open())
	{
		fileStream.close();
		return true;
	}
	return false;
}
