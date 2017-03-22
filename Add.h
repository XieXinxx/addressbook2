#ifndef ADD_H
#define ADD_H

#include "Person.h"
#include "Command.h"
#include "Storage.h"
#include "Delete.h"
#include <iostream>
#include <stdlib.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;

class Add: public Command {

private:
	Person P1;
	Storage S1;
	

public:
	Add(Person);
	~Add();
	string execute(string,string); 
	
};

#endif
