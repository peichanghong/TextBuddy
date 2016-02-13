#include "DataFile.h"

const std::string MESSAGE_WELCOME = "Welcome to TextBuddy. %s is ready for use";
const std::string MESSAGE_ADD_LINE = "added to %s: \"%s\"";
const std::string MESSAGE_DELETE_LINE = "deleted from %s: \"%s\"";
const std::string MESSAGE_CLEAR_CONTENTS = "all content deleted from %s";
const std::string MESSAGE_EMPTY_CONTENTS = "%s is empty";
const std::string MESSAGE_DISPLAY_CONTENTS = "%d. %s";
const std::string MESSAGE_COMMAND_PROMPT = "command: ";
const std::string MESSAGE_TEXT_NAME_PROMPT = "Please input the text file: ";

void DataFile::setEnvironment(int argc, char* argv[]) {
	if(checkForArguments(argc, argv) == false) { //MISSING ONE .TXT CHECKER
		_textFileName = promptForTextName();
	} else {
		_textFileName = argv[1];
	}

	if(checkForExistingTextFile() == true) {
		writeTextFiletoDataFile();
	} else {
		openNewTextFile();
	}
}

bool DataFile::checkForArguments(int argc, char* argv[]) {
	if (argc < 2) {
		return false;
	} else {
		return true;
	}
}

std::string DataFile::promptForTextName() {
	std::string textName;
	std::cout << MESSAGE_TEXT_NAME_PROMPT;
	std::cin >> textName;

	return textName;
}
bool DataFile::checkForExistingTextFile() {
	std::ifstream readFile(_textFileName);

	if (readFile.is_open()) {
		return true;
	} else {
		return false;
	}
}

void DataFile::writeTextFiletoDataFile() {
	std::string descriptionString;
	std::ifstream readFile(_textFileName);

	while (getline(readFile, descriptionString)) {	
		addLineToDataFile(descriptionString);
	}
}

void DataFile::openNewTextFile() {
	std::ofstream writeFile;

	writeFile.open(_textFileName);
}

void DataFile::displayWelcomePage() {
	sprintf_s(buffer, MESSAGE_WELCOME.c_str(), _textFileName.c_str());
	std::cout << buffer << std::endl;
}

DataFile::DataFile() {

}

DataFile::~DataFile() {
}

void DataFile::executeCommandUntilExit() {
	std::string input;
	std::string command;
	COMMAND_TYPE commandType;
	do {
		std::getline( std::cin, input);
		command = commandExtraction(input);
		commandType = determineCommandType(command);

	} while(commandType != EXIT);

}

void DataFile::executeCommand(COMMAND_TYPE commandType , std::string descriptionString) {
	switch(commandType) {
	case ADD:
		addLineToDataFile(descriptionString);
		
		break;
	case DELETE:
		break;
	case CLEAR:
		break;
	case DISPLAY:
		break;
	case EXIT:
		break;
	}
}

std::string DataFile::commandExtraction(std::string &input) {
	std::istringstream iss(input);
	std::string command;

	iss >> command;
	input.erase(0,command.size()+1);

	return command;
}

DataFile::COMMAND_TYPE DataFile::determineCommandType(std::string command) {

	if(isAdd(command)) {
		return ADD;
	} else if(isDelete(command)) {
		return DELETE;
	} else if(isClear(command)) {
		return CLEAR;
	} else if(isDisplay(command)) {
		return DISPLAY;
	} else if(isExit(command)) {
		return EXIT;
	}
}


bool DataFile::isAdd(std::string command) {
	if(command.compare("add")==0) {
		return true;
	} else {
		return false;
	}
}

bool DataFile::isDelete(std::string command) {
	if(command.compare("delete")==0) {
		return true;
	} else {
		return false;
	}
}

bool DataFile::isClear(std::string command) {
	if(command.compare("clear")==0) {
		return true;
	} else {
		return false;
	}
}

bool DataFile::isDisplay(std::string command) {
	if(command.compare("display")==0) {
		return true;
	} else {
		return false;
	}
}
bool DataFile::isExit(std::string command) {
	if(command.compare("exit")==0) {
		return true;
	} else {
		return false;
	}
}

void DataFile::addLineToDataFile(std::string descriptionString) {
	_dataFile.push_back(descriptionString);
}

void DataFile::displayContents() {
	std::vector<std::string>::iterator dataFileIter = _dataFile.begin();
	int indexCount = 1; 

	if(_dataFile.empty()) {
		sprintf_s(buffer, MESSAGE_EMPTY_CONTENTS.c_str(), _textFileName.c_str());
		std::cout << buffer << std::endl;
	} else {
		while (dataFileIter != _dataFile.end()) {
			sprintf_s(buffer, MESSAGE_DISPLAY_CONTENTS.c_str(), indexCount, (*dataFileIter).c_str());
			std::cout << buffer << std::endl;
			dataFileIter++;
			indexCount++;
		}
	}
}

void DataFile::printMessageAfterCommand(COMMAND_TYPE commandType , std::string descriptionString) {
		switch(commandType) {
	case ADD:
		sprintf_s(buffer, MESSAGE_ADD_LINE.c_str(), _textFileName, descriptionString.c_str());
		std::cout << buffer << std::endl;
		break;
	case DELETE:
		break;
	case CLEAR:
		break;
	case DISPLAY:
		break;
	case EXIT:
		break;
	}
}

int testUnit(int i) {
	return i;
}