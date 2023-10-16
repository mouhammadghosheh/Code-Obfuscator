//
// Created by mouha on 16/12/2021.
//
#include <stdio.h>
using namespace std;
#include<iostream>
#include <fstream>
#include <string>
#include "LineObfuscator.h"
#ifndef EX5_OBFUSCATOR_H
#define EX5_OBFUSCATOR_H


class Obfuscater{

public:
     const string OUT = "newCode.c";
     int NumberOfLines;
    virtual void obfuscate(string fileName) = 0;
     string generateRandomVar();
     string* parseFile(string filename);
     void writeToFile(string* codeArray);
    int NumOfLines(string fileName);


};


#endif //EX5_OBFUSCATOR_H
