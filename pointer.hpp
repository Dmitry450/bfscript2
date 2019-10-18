#ifndef POINTERS
#define POINTERS

#include "includes.hpp"
using namespace std;

struct Pointer
{
public:
    string tname;
    int start;
    int end; // Initialise only if tname == "array"
    Pointer(string tname, int start, int end = 0)
    {
        this->start = start;
        this->tname = tname;
        if (tname == "array")
        {
            this->end = end;
        }
    }
};


#endif