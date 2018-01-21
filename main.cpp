#include <regex>
#include <iostream>
#include <map>
#include "extension_database.h"
#include "main.h"

using namespace std;

const string ERRORS[] = {
	"What The Extension takes only 1 argument, which is the filename. Type -h to see the usage",
	"This file has no extension",
	"We do not have information about this extension :("
};

const int ERR_INVALID_ARGUMENT_NUMBER = 0;
const int ERR_FILE_HAS_NO_EXTENSION = 1;
const int ERR_NO_INFORMATION_FOUND = 2;


int main(int argc, char * argsv[]){
	if(argc != 2){
		return error(ERR_INVALID_ARGUMENT_NUMBER);
	}
	return showExtensionInfo(argsv[1]);
}


string getExtension(string filename){
	regex rgx (".*\\.(.*)$");
	smatch match;
	if(regex_search(filename, match, rgx)){
		return match[1];
	}
	else{
		throw NoExtensionException();
	}

}

int showExtensionInfo(string filename){
	string extension = "";
	try{
		extension = getExtension(filename);
	}
	catch(NoExtensionException e){
		return error(ERR_FILE_HAS_NO_EXTENSION);
	}
	try{
		string extensionInfo = getExtensionInfo(extension);
		cout << endl << extension << ':' << endl << extensionInfo << endl;
	}
	catch(NoInformationException e){
		return error(ERR_NO_INFORMATION_FOUND);
	}
	//SU SU SU SUCESSO :D
	return 0; 
}



int error(int errorId){
	cout << endl << ERRORS[errorId] << endl;
	return 1; 
}

string getExtensionInfo(string extension){
	map<string, string>::const_iterator iterator = EXTENSIONS_INFO.find(extension); 
	//If true, no information about extension was found
	if(iterator == EXTENSIONS_INFO.end()){
		throw NoInformationException();
	}
	return iterator->second;
}
