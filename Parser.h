#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#include "Command.h"
#include "CommandType.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <vector>
#include <string>
#include "CommandType.h"
#include "Add.h"
#include "List.h"
#include "Delete.h"
#include "Clear.h"
#include "Find.h"
#include "WrongFormatCommand.h"
#include "Person.h"
#include <algorithm>
#include <iterator>

using namespace std;



class CommandParser {

public:
	
	CommandParser();
	~CommandParser();
	CommandType getParserInput(string,stack <string>);
	string extractUserCommand(string);
    Person parserUpdate(string);
	string check(string);
	string trim(string const&);
	int findKeywordPosition(string, string);
	string getUserInput();
	Person getPersonObject();
	string changeToLowerCase(string input);
	string getCommand();
	vector <string> trimUserInputTokens(string);
	vector <string> convertTokensToLowerCase(vector <string>);

private:
	string userInput;
	string command;
	CommandType  C1;
	Person personDetails; 
};

#endif