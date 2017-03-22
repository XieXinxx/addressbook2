#include "Person.h"

using namespace std;

Person::Person() {
	description = "";
	personNumber = "";
	updatedDescription = "";
	isCommandError=false;
	isBlankString=false;
}

Person::~Person() {

}

void Person::setDescription(string input) {
	description = input;
}


string Person::getDescription() {
	return description;
}

void Person::setNumber(string input) {
	personNumber = input;
}

string Person::getNumber() {
	return personNumber;
}

void Person::setUpdated(string newString) {
	updatedDescription = newString;
}

string Person::getUpdated() {
	return updatedDescription;
}


string Person::getKeywords() {
	return personKeywords;
}

void Person::setKeywords(string keywords) {
	personKeywords = keywords;
}

stack <string> Person::getStack() {
	return inputStack;
}

void Person::setStack(stack <string> input) {
	inputStack = input;
}


bool Person::getCommandError() {

	return isCommandError;
}

void Person::setCommandError(bool value) {
	isCommandError=value;

}


bool Person::getBlankString() {
	return isBlankString;
}

void Person::setBlankString(bool value) {
	isBlankString=value;
}
