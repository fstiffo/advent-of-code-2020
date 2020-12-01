#include "utils.h"
#include <fstream>
#include <iostream>


/*
 * It will iterate through all the lines in file and
 * put them in given vector
 */
bool getFileContent(std::string fileName, std::vector<std::string>& vecOfStrs)
{
    // Open the File
    std::ifstream in(fileName.c_str());
    // Check if object is valid
    if (!in)
    {
        std::cerr << "Cannot open the File : " << fileName << std::endl;
        return false;
    }
    std::string str;
    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }
    //Close The File
    in.close();
    return true;
}
