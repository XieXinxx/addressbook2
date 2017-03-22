#include "Parser.h"
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include "Assert.h"

using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

const string INDENTIFIERS = "./?! ";


Person CommandParser::getPersonObject() {
	return personDetails;
}

string CommandParser::getUserInput() {
	return userInput;
}

string CommandParser::changeToLowerCase(string input) {
	string lowerCase="";
	for(int i=0;i<input.size();i++) {
		if(input[i]>='A' && input[i]<='Z') {
			input[i] = tolower(input[i]);
			lowerCase = lowerCase + input[i];
		} else {
			lowerCase = lowerCase + input[i];
		}
	}
	return lowerCase;
}

vector <string> CommandParser::trimUserInputTokens(string input) {
	vector <string> tokensBeforeTrim;
	boost::split(tokensBeforeTrim,input,boost::is_any_of(" "));
	vector <string> tokens;
	for(int i=0;i<tokensBeforeTrim.size();i++) {
		if(tokensBeforeTrim[i]!=" ") {
			tokens.push_back(tokensBeforeTrim[i]);
		}
	}
	return tokens;
}

string CommandParser::extractUserCommand(string input) {
	vector <string> tokens;
	tokens = trimUserInputTokens(input);
	string taskString;
	int i;
	for(i=1;i<tokens.size()-1;i++) {
		taskString = taskString + tokens[i] + " ";
	}
	if(i==tokens.size()-1) {
		taskString = taskString + tokens[i];
	}
	userInput =taskString;
	return tokens[0];
}

CommandType CommandParser::getParserInput(string input,stack <string> inputStack){
	boost::trim(input);
	command = extractUserCommand(input);
	command = changeToLowerCase(command);
	boost::trim(command);
	boost::trim(userInput);
	personDetails.setStack(inputStack);
	if(userInput=="")
		personDetails.setBlankString(true);

	if(command=="add") {
		//personDetails = userInput(userInput);
		Add *A1;
		A1=new Add(personDetails);
		CommandType C1(A1);
		return C1;
	} /*else if(command=="list") {
		List *D1;
		Logic L1;
		if(changeToLowerCase(userInput)=="done") {
			L1.setDisplayDone(true);
			personDetails.setKeywords(userInput);
		} else {
			personDetails.setKeywords(userInput);
		}
		D1 = new List(personDetails);
			CommandType C1(D1);
			return C1;
	}*/ else if(command=="delete") {
		Logic L1;
		personDetails.setNumber(L1.correctNumber(userInput));
		Delete *Del;
		Del = new Delete(personDetails);
		CommandType C1(Del);
		return C1;
	
	}else if(command=="clear") {
		Person P1;
		P1.setKeywords(userInput);
		Clear *C2;
		C2 = new Clear(P1);
		CommandType C1(C2);
		return C1;
	}else if(command=="exit") {
		WrongFormat *W1;
		W1 = new WrongFormat();
		CommandType C1(W1);
		return C1;
	}else if(command=="find") {
		personDetails.setKeywords(userInput);
		Find *F1;
		F1 = new Find(personDetails);
		CommandType C1(F1);
		return C1;
	
	}else {
		WrongFormat *W1;
		W1 = new WrongFormat();
		CommandType C1(W1);
		return C1;
	}
}

/*void CommandParser::setCommand(string input) {
	command=input;
}*/

string CommandParser::getCommand() {
	return command;
}


