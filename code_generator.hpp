#ifndef CODE_GENERATOR
#define CODE_GENERATOR

#include "includes.hpp"
#include "color.hpp"
#include "functions.hpp"
#include "pointer.hpp"

string generate(vector<string> &tokens, int &i, map<string, string> &aliases, map<string, Pointer*> &pointers,
                int &line_num, int &current_cell, bool &error);

#endif