#include <exception>
#include <iostream>

using namespace std;

/**
 * Exceptions
 * 
 */

class NoExtensionException : public std::exception{

};

class NoInformationException : public std::exception{

};
/**
 * Functions
 * 
 */

int error(int errorId);
int showExtensionInfo(string filename);
string getExtension(string filename);
string getExtensionInfo(string extension);
string strtoupper(string str);
