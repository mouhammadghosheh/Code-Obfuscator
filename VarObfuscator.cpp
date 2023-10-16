//
// Created by mouha on 16/12/2021.
//

#include "Obfuscator.h"
#include "VarObfuscator.h"
#include <list>

void VarObfuscator::obfuscate(string fileName) {
    //to randomize randomization every time
    srand((unsigned) time(NULL));
    string *FileArray = parseFile(fileName);
    string temp;
    int mainLine = 0;
    string str;
    for (int i = 0; i < NumOfLines(fileName); ++i) {

        //find the main line
        if (FileArray[i].compare("Void main(){") > 0) {
            mainLine = i;
            break;
        }
    }
    int randLine = mainLine + rand() % (NumOfLines(fileName) - mainLine);
    //take a random line and check if it has an int initilization
    for (int i = 0; i < NumOfLines(fileName); ++i) {
        if (FileArray[randLine].find("int ", 0) != -1) {

            str = FileArray[randLine].substr(FileArray[randLine].find("int ", 0), FileArray[randLine].length());

            temp = str;
            int pos = FileArray[randLine].find("int ");

          
            int pos2 = temp.find("int");
            if (temp.find("=") != -1) {
                temp = temp.substr(pos2, temp.find("="));
                temp.replace(0, 3, " ");
            } else
                temp = temp.substr(pos-1, temp.find(";") - 3);

        //remove spaces from string to extract variable name easily
          string::iterator iter = temp.begin();
            while ( iter != temp.end() )
            {
                if ( isspace ( *iter ) )
                {
                    iter = temp.erase ( iter );
                }
                else
                {
                    iter++;
                }
            }

           
            break;
        }

        randLine = mainLine + rand() % (NumOfLines(fileName) - mainLine - 2);
    }
    //random variable
   const string gg = generateRandomVar();



    for (int i = mainLine + 1; i < NumOfLines(fileName); ++i) {
        int index = FileArray[i].find(temp);
        string tt = FileArray[i];
        if (index != -1 && temp.length() != 1) {
            //check every possibility of the int appearance
            if (FileArray[i][index + temp.length()] == ';' || FileArray[i][index + temp.length()] == ' ' ||
                FileArray[i][index + temp.length()] == '+' || FileArray[i][index + temp.length()] == '(' ||
                FileArray[i][index + temp.length()] == ')' || FileArray[i][index + temp.length()] == '=' ||
                FileArray[i][index + temp.length()] == ',') {

                //replace it with the random variable
                FileArray[i].replace(index, temp.length() - 1, gg);

                if (FileArray[i].find(temp) != -1)
                    i--;
            }
        } else {
            index = FileArray[i].find(" " + temp);
            if (index != -1)
                if (FileArray[i][index + temp.length()+1] == ';' || FileArray[i][index + temp.length()+1] == ' ' ||
                    FileArray[i][index + temp.length()+1] == '+' || FileArray[i][index + temp.length()+1] == '(' ||
                    FileArray[i][index + temp.length()+1] == ')' || FileArray[i][index + temp.length()+1] == '=' ||
                    FileArray[i][index + temp.length()+1] == ','){


                    FileArray[i].replace(index + 1, temp.length(), gg);

            if (index != -1)
                i--;}
          


        }
    }


    writeToFile(FileArray);
}

