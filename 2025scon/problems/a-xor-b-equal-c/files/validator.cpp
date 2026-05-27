#include "testlib.h"
 
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    
    int max=3000;
    
    int a = inf.readInt(0, max, "a");
    inf.readSpace();
    int b = inf.readInt(0, max, "b");
    
    ensuref((a+b)%3==0, "a + b is not a multiple of 3.");
    ensuref((a+b)>=3, "a + b is smaller than 3.");
 
    inf.readEoln();
    inf.readEof();
    return 0;
}