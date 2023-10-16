//
// Created by mouha on 24/12/2021.
//
#include "Obfuscator.h"
#include "LineObfuscator.h"

void LineObfuscator::obfuscate(string fileName) {
    //generate random numbers
    srand(2*time(NULL));
    int randomNum1 = 1 + rand()%999;
    int randomNum2 = 1 + rand()%999;
    string LineVariable = generateRandomVar();
    string *FileArray = parseFile(fileName);
    int mainLine = 0;
    for (int i = 0; i < NumOfLines(fileName); ++i) {


        if(FileArray[i].compare("Void main(){")>0) {
            FileArray[i] += "\n\tint " + LineVariable + ";";
            mainLine = i;
            break;
        }
    }
    int randLine = mainLine + rand() % (NumOfLines(fileName) - mainLine -2);
    FileArray[randLine] += "\n\t" + LineVariable + " = " + to_string(randomNum1) + " + " + to_string(randomNum2) + ";";


    Obfuscater::writeToFile(FileArray);
}