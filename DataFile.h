#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class DataFile {
private:
	std::vector<std::string> _dataFile;
	std::string _textFileName;
	char buffer[255];

	enum COMMAND_TYPE {
		ADD, DELETE, CLEAR, DISPLAY, EXIT 
	};

	//set environment stage
	bool checkForArguments(int argc, char* argv[]);
	bool checkForExistingTextFile();
	std::string promptForTextName();
	void writeTextFiletoDataFile();
	void openNewTextFile();

	//Parser string extraction
	std::string commandExtraction(std::string input);
	std::string descriptionExtraction(std::string input);

	//Logic command determination stage
	COMMAND_TYPE determineCommandType(std::string command);
	bool isAdd(std::string command);
	bool isDelete(std::string command);
	bool isClear(std::string command);
	bool isDisplay(std::string command);
	bool isExit(std::string command);

	//Implementation function
	void executeCommand(COMMAND_TYPE commandType , std::string descriptionString);
	void addLineToDataFile(std::string descriptionString);
	void deleteLineFromDataFile(int index);
	void clearContentsFromDataFile();
	void displayContents();

	void promptUserCommandUntilExit();
	void saveDataFiletoTextFile();
	
public:
	DataFile();
	~DataFile();
	void setEnvironment(int argc, char* argv[]);
	

};

