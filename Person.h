#ifndef PERSON_H
#define PERSON_H


#include <string>
#include <stack>
#include <vector>
using namespace std;

class Person {

private:
	string description;
	string personNumber;
	string updatedDescription;
	string personStatus;
	bool isCommandError;
	vector <string> updateTokens;
	string personKeywords;
	stack <string> inputStack;
	bool isBlankString;

public:
	Person();
	~Person();
	void setDescription(string);
	string getDescription();
	void setNumber(string);
	string getNumber();
	void setUpdated(string);
	string getUpdated();
	void setStatus(string);
	string getStatus();
	void setErrorDate(bool);
	bool getErrorDate();
	void setCommandError(bool);
	bool getCommandError();
	void setKeywords(string);
	string getKeywords();
	stack <string> getStack();
	void setStack(stack <string>);
	void setBlankString(bool);
	bool getBlankString();
};
#endif
