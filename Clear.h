#ifndef CLEAR_H
#define CLEAR_H

#include "Command.h"
#include "Storage.h"
using namespace std;

class Clear:public Command {

private:
	Storage S1;
	Person P1;
	static string originalData;

public:
	Clear(Person);
	~Clear();
	string execute(string,string);
	void setData(string);
	string getData();
};

#endif