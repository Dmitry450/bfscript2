#ifndef CODE_GENERATOR
#define CODE_GENERATOR

#include "includes.hpp"
#include "color.hpp"
#include "functions.hpp"

string generate(vector<string> &tokens, int &i, map<string, string> &aliases, int &line_num, bool &error);

#endif