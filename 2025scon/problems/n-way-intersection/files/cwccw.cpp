#include "testlib.h"
#include <string>
 
using namespace std;
 
const string CCW = "CCW";
const string CW = "CW";
 
int main(int argc, char * argv[])
{
    setName((CCW + " or " + CW + " (case insensetive)").c_str());
    registerTestlibCmd(argc, argv);
 
    std::string ja = upperCase(ans.readWord());
    std::string pa = upperCase(ouf.readWord());
 
    if (ja != CCW && ja != CW)
        quitf(_fail, "%s or %s expected in answer, but %s found", CCW.c_str(), CW.c_str(), compress(ja).c_str());
 
    if (pa != CCW && pa != CW)
        quitf(_pe, "%s or %s expected, but %s found", CCW.c_str(), CW.c_str(), compress(pa).c_str());
 
    if (ja != pa)
        quitf(_wa, "expected %s, found %s", compress(ja).c_str(), compress(pa).c_str());
 
    quitf(_ok, "answer is %s", ja.c_str());
}