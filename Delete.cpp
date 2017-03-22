#include "Delete.h"
#include <sstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <stack>
using namespace std;

string Delete::deletePerson;
const string LIST_COMMAND = "list";
const string ERROR_PREVIOUS_COMMAND = "Error: Please view your name list using the *DISPLAY* command before deleting a person";
const string ERROR_DELETE = "Error: Please enter *DELETE* followed by the correct number of the name to be deleted.\n";
const string SUCCESS_DELETE = "Deleted person successfully\n";

Delete::Delete(Person PersonAttributes) {
	P1=PersonAttributes;
}

Delete::~Delete() {

}

bool Delete::isValidCommand(string input) {   
	if(input==LIST_COMMAND) {
		return true;
	} else {
		return false;
	}
}


string Delete::execute(string fileName,string filePath) {
	CommandParser CP1;
	string s;
	stack <string> commandStack = P1.getStack();
	commandStack.pop();
	if(commandStack.empty()) {
		return ERROR_PREVIOUS_COMMAND;
	}
	string lastInput = commandStack.top();
	CommandType C1 = CP1.getParserInput(lastInput,commandStack);
	string command = CP1.getCommand();
	if(!isValidCommand(command)) {
		return ERROR_PREVIOUS_COMMAND;
	}
	string input = C1.run(fileName,filePath);
	istringstream file(input);
	string lineFromFile;
	int lineNumber=1;
	string deletedData="";
	string userLine = P1.getNumber();
	while(getline(file,lineFromFile)) {
		if(!lineFromFile.empty()) {
			if(atoi(userLine.c_str())==lineNumber) {
				deletedData = deletedData + lineFromFile + "\n";
			}
			
	}
		lineNumber++;
	}
	if(deletedData!="") {            //If the line has been found, it is removed from the file
		S1.replaceFileData(deletedData,fileName,filePath);
		setDeletePerson(deletedData);
		return SUCCESS_DELETE;
	} else {
		return ERROR_DELETE;
	}
}

string Delete::getDeletePerson() {
	return deletePerson;
}
void Delete::setDeletePerson(string person) {
	deletePerson=person;
}