//
// Created by mouha on 16/12/2021.
//



#include "CommentObfuscator.h"
#include "Obfuscator.h"

void CommentObfuscator::obfuscate(string fileName) {
    srand(time(NULL));
    string *FileArray = parseFile(fileName);
    int mainLine;
    int randomNum1 = rand()%2;
    //comments array
    string Comments[3] = {"//Repeats Copying the file","//Gets a number and puts it in the strings array","//scans two numbers and does nothing with them"};

    for (int i = 0; i < NumOfLines(fileName); ++i) {
        //find all arrays and delete them
        if(FileArray[i].find("//",0)!= -1){
            FileArray[i].replace(FileArray[i].find("//",0),FileArray[i].length(),"");
        }
    }
    for (int i = 0; i < NumOfLines(fileName); ++i) {


        if (FileArray[i].compare("Void main(){") > 0) {
            mainLine = i;
            break;
        }
    }
    //insert random comment in a random line
    int randLine = mainLine + rand() % (NumOfLines(fileName) - mainLine);
    FileArray[randLine] += "\n" + Comments[randomNum1];
    writeToFile(FileArray);
}
