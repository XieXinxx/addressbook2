#include "Clear.h"
#include <boost/algorithm/string.hpp>

using namespace std;

string Clear::originalData;
const string ERROR_CLEAR_KEYWORDS = "Error: Please enter *CLEAR* to clear your name list";
const string SUCCESS_CLEAR = "The name has been cleared\n";

Clear::Clear(Person personObject) {
	P1 = personObject;
}

Clear::~Clear() {

}

string Clear::execute(string fileName,string filePath) {
	if(P1.getKeywords()!="") {
		return ERROR_CLEAR_KEYWORDS;
	}
	string blankFile="";
	setData(S1.readFile(fileName,filePath));
	S1.clearFile(fileName,filePath);
	return SUCCESS_CLEAR;
}

void Clear::setData(string data) {
	originalData = data;
}

string Clear::getData() {
	return originalData;
}