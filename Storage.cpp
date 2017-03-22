#include "Storage.h"
#include "Assert.h"
#include <vector>
#include <fstream>
#include <queue>
#include <boost/algorithm/string/trim.hpp>

using namespace std;

vector <string> Storage::namelist;
const string IDENTIFIERS = "/";



bool Storage::writeFile(Person person, string outputfile,string filePath) {      

	ofstream myfile;				                                   
	outputfile = filePath + outputfile;   
	myfile.open(outputfile.c_str(),ios::app);                        
	myfile << person.getDescription() << endl;
	myfile.close();

	return checkAdd(person, outputfile,filePath);                      
}




bool Storage::writeBackToFile(string deletedString, string fileName,string filePath) {
	ofstream myfile;
	fileName = filePath + fileName;
	myfile.open(fileName.c_str(),ios::app);
	myfile << deletedString << endl;
	return true;
}



int Storage::startIndex(string input) {
	
	return input.find_first_not_of(IDENTIFIERS);
}



int Storage::endIndex(string input) {
	return input.find_first_of(IDENTIFIERS);
}



string Storage::extractUserCommand(string input , string &substring) {
	int start;
	start = startIndex(input);
	int end;
	end = endIndex(input);
	substring = input.substr(end+1); 
	return input.substr(start,end-start);
}



string Storage::readFile(string outputfile,string filePath) {				
	outputfile = filePath + outputfile;
	ifstream readfile(outputfile);
	string fileContent="";
	string line;
	if(readfile.peek()==std::ifstream::traits_type::eof()) {                //if file is empty
		return "Error: Currently there are no name found. The file is empty.\n" ;
	}  else {

		int lineNumber=1;
		while(!readfile.eof()) {
			getline(readfile,line);	
			if(!line.empty()) {
				fileContent = fileContent + line + "\n";					//sending data back in a string 
				lineNumber++;			
			}
		}
	}
	readfile.close();
	return fileContent;

}
	





bool Storage::clearFile(string outputFile,string filePath) {
	outputFile = filePath + outputFile;                                         //get whole file path of file
	ofstream writefile;
	writefile.open(outputFile,ios::trunc);                                      //clear all contents of file
	writefile.close();

	return checkClear(outputFile, filePath);
}


//delete function, ignore same line and loop all other lines that's not deleted
bool Storage::replaceFileData(string deletedData,string outputFile,string filePath) {
	string fileData=readFile(outputFile,filePath);								//display data and return in string
	string lineFromFile;
	string newData="";
	istringstream in(fileData);
	boost::trim(deletedData);
 	while(getline(in,lineFromFile)) {								//using istringstream
		string originalLine = lineFromFile;                          //trim lines i obtain from my file cause i've also trimmed the line i wanna delete
		boost::trim(lineFromFile);
		if(lineFromFile!=deletedData) {
			newData = newData + originalLine + "\n";                 //compile the lines i dont intend to replace
		}
	}
	clearFile(outputFile,filePath);

	replaceData(deletedData, outputFile, filePath, newData);
	return checkDelete(deletedData, outputFile, filePath);

}


string Storage::lowerCase(string input) {

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	return input;
}




bool Storage::checkAdd(Person person, string outputfile,string filePath) {   
	ifstream readfile(outputfile);                                   //outputfile is the name of the file where data is stored. Open file to READ
	string readLine = "";
	int i = 0;

	while(!readfile.eof()) {						                //final getline obtains a blank string. Reloop using i-1 to obtain last meaningful line
		getline(readfile, readLine);
		i++;
	} 
	readfile.close();
	ifstream readagain(outputfile);									 //reopen file
	string readlineagain = "";

	for (int k=1; k < i; k++) {
		getline(readagain, readlineagain);
	}

	if (readlineagain == (person.getDescription() )) {
		readagain.close();
		return true;
	}  else {
		return false;
	} 
}





bool Storage::checkClear(string outputFile,string filePath) {
	ifstream readfile(outputFile);
	assert(readfile.peek() == std::ifstream::traits_type::eof());
	if(readfile.peek() == std::ifstream::traits_type::eof()) {              	//if file is empty
		readfile.close();
		return true;
	}
	else {
		return false;                                                           //return success status
	}
}




bool Storage::checkDelete(string deletedData,string outputFile,string filePath) {
		ifstream readfile(outputFile);											 //reopen file
	string readline = "";

	while (!readfile.eof()) {
		getline(readfile, readline);
		if (readline == deletedData) {
			readfile.close();
			return false;
		}
	}
			readfile.close();
			return true;

}
			

		
void Storage::replaceData (string deletedData,string outputFile,string filePath, string newData) {
	string line;
	istringstream data(newData);
	ofstream writefile;												          //open w intention to write new updated information into file
	outputFile = filePath + outputFile;
	writefile.open(outputFile);
	while(getline(data,line)) {
		writefile << line << endl;										    //newData (data) into output file
	}
	writefile.close();

}


void Storage::replaceUpdateData(string originalData, string updatedData,string outputFile,string filePath, string newData) {
	string line;
	istringstream data(newData);
	ofstream writefile;
	outputFile = filePath + outputFile;
	writefile.open(outputFile);
	while(getline(data,line)) {
		writefile << line << endl;
	}
	writefile.close();
}