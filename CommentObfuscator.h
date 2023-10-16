//
// Created by mouha on 24/12/2021.
//

#ifndef EX5_COMMENTOBFUSCATOR_H
#define EX5_COMMENTOBFUSCATOR_H
#include "Obfuscator.h"

class CommentObfuscator: public Obfuscater{
public:
    CommentObfuscator(){

    }
    void obfuscate(string fileName);
};
#endif //EX5_COMMENTOBFUSCATOR_H
