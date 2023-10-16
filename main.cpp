
using namespace std;
#include <string>
#include "Obfuscator.h"
#include "LineObfuscator.h"
#include "VarObfuscator.h"
#include "CommentObfuscator.h"

int main()
{


    Obfuscater *obfs[3];

    obfs[0] = new VarObfuscator();
    obfs[1] = new LineObfuscator();
    obfs[2] = new CommentObfuscator();

 obfs[0]->obfuscate("test");
    for(int i = 1; i < 3; i++)
        obfs[i]->obfuscate(obfs[i-1]->OUT);




}

