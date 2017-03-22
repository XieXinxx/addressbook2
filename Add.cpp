#include "Add.h"
#include "Assert.h"

using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

const string ERROR_BLANK_STRING = "Error: Task to be added cannot be empty. Please enter *ADD* followed by a task\n";
const string ERROR_END_LESSTHAN_START = "Error: Please enter a start date for the task that comes after today's date\n";
const string ERROR_ADD = "Error: Could not add the person.\n";
const string SUCCESS_ADD = "Added person successfully to the namelist!\n";

Add::Add(Person PersonAttributes) {
	P1=PersonAttributes;
}

string Add::execute(string fileName,string filePath) {
	int countOfDays=0;
	if(P1.getBlankString()) {                  //The user cannot enter a blank string after "add" command
		return ERROR_BLANK_STRING;
	}
	string status;
	bool statusOfAdd;
	
/*	bool statusOfAdd = S1.writeFile(P1,fileName,filePath);
		if(statusOfAdd) {
			status = SUCCESS_ADD;
		} else { 
			status= ERROR_ADD;
		}*/


}