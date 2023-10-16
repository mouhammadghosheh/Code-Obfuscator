//
// Created by mouha on 24/12/2021.
//
#include "Obfuscator.h"
#ifndef EX5_VAROBFUSCATOR_H
#define EX5_VAROBFUSCATOR_H
class VarObfuscator: public Obfuscater{
public:
    VarObfuscator(){

    }


void removeSpaces(string str);
    void obfuscate(string fileName);
};
#endif //EX5_VAROBFUSCATOR_H
