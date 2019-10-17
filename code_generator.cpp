#include "code_generator.hpp"

string generate(vector<string> &tokens, int &i, map<string, string> &aliases, int &line_num, bool &error)
{
    string bfcode = "";
    if (tokens[i] == "newline")
    {
        ++line_num;
        ++i;
        return bfcode;
    }
    if (tokens[i] == "loadalias")
    {
        try
        {
            ++i;
            tokens[i] = aliases.at(tokens[i]);
            return bfcode;
        }
        catch(out_of_range)
        {
            cout<<BOLD_MSG("bfscript2: code generator: ")<<ERROR_MSG("name error: ")
                <<"name "<<tokens[i]<<" is not defined (line"<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
    }
    if (tokens[i] == "alias")
    {
        ++i;
        aliases[tokens[i]] = tokens[i+1];
        ++i;
        return bfcode;
    }
    if (tokens[i] == "setchar")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, line_num, error);
            if (error) return bfcode;
        }
        bfcode += setchar(tokens[i][0]);
        return bfcode;
    }
    if (tokens[i] == "walk")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, line_num, error);
            if (error) return bfcode;
        }
        bfcode += walk(stoi(tokens[i]));
        return bfcode;
    }
    if (tokens[i] == "change")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, line_num, error);
            if (error) return bfcode;
        }
        bfcode += change(stoi(tokens[i]));
        return bfcode;
    }
    if (tokens[i] == "mov")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, line_num, error);
            if (error) return bfcode;
        }
        bfcode += mov(stoi(tokens[i]));
        return bfcode;
    }
    if (tokens[i] == "print")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, line_num, error);
            if (error) return bfcode;
        }
        bfcode += print(stoi(tokens[i]));
        return bfcode;
    }
    if (tokens[i] == "split")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, line_num, error);
            if (error) return bfcode;
        }
        bfcode += split(tokens[i]);
        return bfcode;
    }
    if (tokens[i] == "copy")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, line_num, error);
            if (error) return bfcode;
        }
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, line_num, error);
            if (error) return bfcode;
        }
        try
        {
            bfcode += copy(stoi(tokens[i]), stoi(tokens[i+1]));
        }
        catch(invalid_argument)
        {
            cout<<BOLD_MSG("bfscript2: code generator: ")<<ERROR_MSG("argument error: ")
                <<"invalid argument(s) for 'copy' (line"<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
        return bfcode;
    }
    cout<<WARNING_MSG("Warning: ")<<"unexpected token at line "<<line_num<<endl;
}