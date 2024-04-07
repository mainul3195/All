#include "testlib.h"

using namespace std;

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    int t = inf.readInt();
    bool ok = 1;
    for (int i = 0; i < t; i++)
    {
        long long pans = ouf.readInt();
        long long jans = ans.readInt();

        if (pans != jans)
        {
            ok = !ok;
            break;
        }
    }
    if (ok)
        quitf(_ok, "all ok");
    else
        quitf(_wa, "wrong answer");
}