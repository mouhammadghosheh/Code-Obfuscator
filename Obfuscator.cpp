//
// Created by mouha on 16/12/2021.
//

#include <string>
#include "Obfuscator.h"
#include "stdio.h"



string Obfuscater::generateRandomVar() {


    
    int randomLength = 1+rand()%9;
    string Variable;
    int random = rand()%4;
    if(random==0)
        Variable = '_';
    else if(random == 1)
        Variable = (char)(65+rand()%26);
    else
        Variable = (char)(97+rand()%26);
    randomLength = 1+rand()%9;

    for (int i = 1; i < randomLength; ++i) {
        random = rand()%6;
        if(random==0)

            Variable += '_';
        else if(random == 1)
            Variable+= (char)(65+rand()%26);
        else if(random == 2)
            Variable+= (char)(48 + rand()%10);
        else
            Variable+= (char)(97+rand()%26);
    }
    return Variable;

    }



string* Obfuscater::parseFile(string filename) {

    string *Lines = new string[NumOfLines(filename)];

    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return NULL;
    }
    int i = 0;
    while (getline(input_file, line)){
        Lines[i] = line;
        i++;
    }



    input_file.close();
    return Lines;
}
int Obfuscater::NumOfLines(string fileName) {
    int number_of_lines = 0;
    std::string line;
    std::ifstream myfile(fileName);

    while (std::getline(myfile, line))
        ++number_of_lines;
myfile.close();
    NumberOfLines = number_of_lines;

    return number_of_lines;
}

void Obfuscater::writeToFile(string *codeArray) {

    fstream new_file;
    new_file.open(OUT,ios::out);
    if(!new_file)
    {
        cout<<"File creation failed";
    }
    else
    {
        for (int i = 0; i < NumberOfLines; ++i) {
            new_file<<codeArray[i]<<"\n";
        }
            //Writing to file
        new_file.close();
    }
}

