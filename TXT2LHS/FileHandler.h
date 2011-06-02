/*
 * FileHandler.h
 *
 *  Created on: Jan 20, 2011
 *      Author: Nic
 */

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include "StandardIncludes.h"

class FileHandler
{
private:
	string fileName;
	fstream fileStream;
	bool fileExists();		// Returns true if fileName already exists
public:
	FileHandler();
	FileHandler(const FileHandler&);
	FileHandler(string fileName);
	virtual ~FileHandler();
	void saveToFile(string data);
	string loadFromFile();
	void setFile(string fileName);
};

#endif /* FILEHANDLER_H_ */
