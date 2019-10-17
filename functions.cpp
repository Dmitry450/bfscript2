#include "functions.hpp"
#include "color.hpp"

string setchar(char c)
{
    string result = "[-]";
    for (int i = 0; i < (int)c; i++)
    {
        result += "+";
    }
    result += "\n";
    return result;
}

string walk(int k)
{
    string result = "";
    if (k > 0)
    {
        for (int i = 0; i < k; i++)
        {
            result += ">";
        }
    }
    if (k < 0)
    {
        for (int i = 0; i > k; i--)
        {
            result += "<";
        }
    }
    return result;
}

string change(int count)
{
    string result = "";
    if (count > 0)
    {
        for (int i = 0; i <= count; i++)
        {
            result += "+";
        }
    }
    if (count < 0)
    {
        for (int i = 0; i >= count; i--)
        {
            result += "-";
        }
    }
    return result;
}

string mov(int whereto)
{
    string result = "";
    result += walk(whereto);
    result += "[-]";
    result += walk(-whereto);
    result += "[-";
    result += walk(whereto);
    result += "+";
    result += walk(-whereto);
    result += "]";
    return result;
}

string copy(int whereto, int buffer)
{
    string result = "";
    result += walk(whereto);
    result += "[-]";
    result += walk(buffer - whereto);
    result += "[-]";
    result += walk(-buffer);
    result += "[-";
    result += walk(whereto);
    result += "+";
    result += walk(buffer - whereto);
    result += "+";
    result += walk(-buffer);
    result += "]";
    result += walk(buffer);
    result += mov(-buffer);
    return result;
}

string print(int lenght)
{
    string result = ".";
    for (int i = 0; i < abs(lenght); i++)
    {
        result += ">.";
    }
    return result;
}

string split(string what)
{
    string result = "";
    char lastc;
    if (what[0] != '\"')
    {
        cout<<WARNING_MSG("Warning: ")<<"better use '\"'\n";
    }
    for (char c: what)
    {
        if (lastc == '\\' && c == 'n')
        {
            c = '\n';
        }
        if (lastc == '\\' && c == 't')
        {
            c = '\t';
        }
        if ((c != '\"' && lastc != '\\'))
        {
            result += setchar(c);
            result += walk(1);
            result += "\n";
        }
        lastc = c;
    }
    return result;
}