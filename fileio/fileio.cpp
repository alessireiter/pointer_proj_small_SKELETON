#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../includes/constants.h"
#include "../includes/fileio.h"

using namespace std;

const bool COULD_OPEN_FILE = true;
const bool COULD_NOT_OPEN_FILE = false;

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*
  returns True - file opened successfully
          False - file not opened*/
bool openFile(fstream& myfile, const std::string& myFileName, ios_base::openmode mode){

	myfile.open(myFileName.c_str(), mode);

	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	return COULD_OPEN_FILE;
}

/*iff myfile is open then close it*/
void closeFile(std::fstream& myfile){
	if (myfile.is_open()){
		myfile.close();
	}
}

/**
 * write data in contents to filename
 *
 * \param filename: where data will go, overwrite if already there
 * \param contents: data to write to filename
 *        hint:  you can get a const char * by calling the method .c_str() on a std::string
 * \return
 *        INVALID_NULL_PTR_DETECTED if contents ==NULL
 *        SUCCESS otherwise
 */
int writeFile(std::string &filename,char *contents){
	fstream myfile;

		ios_base::openmode mode = ios_base::out;
		bool file_opened = openFile(myfile, filename, mode);

		if (!file_opened) {
			return FAIL_CANNOT_OPEN_FILE;
		}

		if (contents == NULL) {
			return INVALID_NULL_PTR_DETECTED;
		}

		myfile << contents;
		closeFile(myfile);

		return SUCCESS;
}

/**
 * Reads info from filename into contents
 *
 * \param filename where data is
 * \param contents data to write to file
 * \return
 *        CANNOT_OPEN_FILE  if filename cannot be opened
 *        SUCCESS
 */
int readFile(std::string &filename,std::string &contents){
	fstream myfile;
	ios_base::openmode mode = ios_base::in;
	bool file_opened = openFile(myfile, filename, mode);

	if (!file_opened) {
		return FAIL_CANNOT_OPEN_FILE;
	}

	getline(myfile, contents);

	closeFile(myfile);

	return SUCCESS;
}
