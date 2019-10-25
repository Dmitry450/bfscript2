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

string go_to(int current_cell, int where)
{
    string result = "";
    if (current_cell < where)
    {
        for (int i = current_cell; i < where; i++)
        {
            result += ">";
        }
    }
    if (current_cell > where)
    {
        for (int i = current_cell; i > where; i--)
        {
            result += "<";
        }
    }
    result += "\n";
    return result;
}

string copyto(int current_cell, int whereto, int buffer)
{
    int copy_whereto, copy_buffer;
    copy_whereto = whereto - current_cell;
    copy_buffer = buffer - current_cell;
    return copy(copy_whereto, copy_buffer);
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
    result += walk(-buffer);
    return result;
}

string print(int lenght)
{
    string result = ".";
    string come_back = "";
    for (int i = 0; i < abs(lenght); i++)
    {
        result += ">.";
        come_back += "<";
    }
    result += "\n";
    result += come_back;
    result += "\n";
    return result;
}

string split(string what)
{
    string result = "";
    string come_back = "";
    char lastc;
    if (what[0] != '\"')
    {
        cout<<WARNING_MSG("Warning: ")<<"better use '\"'\n";
    }
    for (char c: what)
    {
        if (c == '\"' && lastc != '\\')
        {
            continue;
        }
        if (c == '\\' && lastc != '\\')
        {
            lastc = c;
            continue;
        }
        if (lastc == '\\' && c == 'n')
        {
            c = '\n';
        }
        else if (lastc == '\\' && c == 't')
        {
            c = '\t';
        }
        result += setchar(c);
        result += ">";
        come_back += "<";
        result += "\n";
        lastc = c;
    }
    return result + come_back + "\n";
}

string sum (int p1, int p2, int resultpos, int current_cell)
{
    string result = "";

    result += go_to(current_cell, 0);
    result += "[-]"; // Clear buffer
    result += go_to(0, current_cell);

    result += go_to(current_cell, p1);
    result += "[-";
    result += go_to(p1, resultpos);
    result += "+";
    result += go_to(resultpos, 0);
    result += "+";
    result += go_to(0, p1);
    result += "]"; // Move value from p1 to buffer and result cell

    result += go_to(p1, 0);
    result += "[-";
    result += go_to(0, p1);
    result += "+";
    result += go_to(p1, 0);
    result += "]"; // Return value from buffer to p1
    
    result += go_to(0, p2);
    result += "[-";
    result += go_to(p2, resultpos);
    result += "+";
    result += go_to(resultpos, 0);
    result += "+";
    result += go_to(0, p2);
    result += "]"; // Move value from p2 to buffer and add to result cell

    result += go_to(p2, 0);
    result += "[-";
    result += go_to(0, p2);
    result += "+";
    result += go_to(p2, 0);
    result += "]"; // Return value from buffer to p2

    result += go_to(0, current_cell); // Come back

    return result;
}

string sub (int p1, int p2, int resultpos, int current_cell)
{
    string result = "";

    result += go_to(current_cell, 0);
    result += "[-]"; // Clear buffer
    result += go_to(0, current_cell);

    result += go_to(current_cell, p1);
    result += "[-";
    result += go_to(p1, resultpos);
    result += "+";
    result += go_to(resultpos, 0);
    result += "+";
    result += go_to(0, p1);
    result += "]"; // Move value from p1 to buffer and result cell

    result += go_to(p1, 0);
    result += "[-";
    result += go_to(0, p1);
    result += "+";
    result += go_to(p1, 0);
    result += "]"; // Return value from buffer to p1
    
    result += go_to(0, p2);
    result += "[-";
    result += go_to(p2, resultpos);
    result += "-";
    result += go_to(resultpos, 0);
    result += "+";
    result += go_to(0, p2);
    result += "]"; // Move value from p2 to buffer and sub from result cell

    result += go_to(p2, 0);
    result += "[-";
    result += go_to(0, p2);
    result += "+";
    result += go_to(p2, 0);
    result += "]"; // Return value from buffer to p2

    result += go_to(0, current_cell); // Come back

    return result;
}