#ifndef DELETE_H
#define DELETE_H

#include "Command.h"
#include "Storage.h"
#include "Person.h"
#include "Logic.h"
#include "CommandType.h"
#include "Find.h"
#include <vector>
using namespace std;

class Delete:public Command {

private:
	Storage S1;
	Person P1;
	static string deletePerson;

public:
	Delete(Person);
	~Delete();
	string execute(string,string);
	string executeUndo(string,string);
	string getDeletePerson();
	void setDeletePerson(string);
	bool isValidCommand(string);
};

#endif