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
DataFile::DataFile() {
	
}

DataFile::~DataFile() {
}

void DataFile::addLineToDataFile(std::string descriptionString) {
	_dataFile.push_back(descriptionString);
}

void DataFile::displayContents() {
	std::vector<std::string>::iterator iter = _dataFile.begin();
	int indexCount = 1; 

	if(_dataFile.empty())
		sprintf_s(buffer, MESSAGE_EMPTY_CONTENTS.c_str(), _textFileName.c_str());
		std::cout << buffer << std::endl;
}