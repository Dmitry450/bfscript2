#include "code_generator.hpp"

string generate(vector<string> &tokens, int &i, map<string, string> &aliases, map<string, Pointer*> &pointers, 
                int &line_num, int &current_cell, bool &error)
{
    string bfcode = "";
    cout<<tokens[i]<<endl;
    if (tokens[i] == "newline")
    {
        ++line_num;
        return bfcode;
    }
    if (tokens[i] == "pointer")
    {
        ++i;
        try
        {
            pointers[tokens[i]] = new Pointer("pointer", stoi(tokens[i+1]));
            ++i;
            return bfcode;
        }
        catch(invalid_argument err)
        {
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"expected int argument 2 for 'pointer'"
                <<" (line"<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
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
                <<"alias '"<<tokens[i]<<"' is not defined (line"<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
    }
    if (tokens[i] == "bypointer")
    {
        ++i;
        Pointer *pointer = nullptr;
        try
        {
            pointer = pointers.at(tokens[i]);
        }
        catch(out_of_range)
        {
            cout<<BOLD_MSG("bfscript: code generator")<<ERROR_MSG("name error: ")<<"pointer '"<<tokens[i]
                <<"' is not defined (line"<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
        ++i;
        cout<<tokens[i]<<endl;
        if (tokens[i] == "assigment")
        {
            bfcode += go_to(current_cell, pointer->start);
            ++i;
            bfcode += setchar(tokens[i][0]);
            bfcode += go_to(pointer->start, current_cell);
            ++i;
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
            bfcode += generate(tokens, i, aliases, pointers, line_num, current_cell, error);
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
            bfcode += generate(tokens, i, aliases, pointers, line_num, current_cell, error);
            if (error) return bfcode;
        }
        try
        {
            bfcode += walk(stoi(tokens[i]));
            current_cell += stoi(tokens[i]);
            return bfcode;
        }
        catch(invalid_argument)
        {
            cout<<BOLD_MSG("bfscript2: code generator: ")<<ERROR_MSG("argument error: ")
                <<"invalid argument for 'walk' (line"<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
    }
    if (tokens[i] == "change")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, pointers, line_num, current_cell, error);
            if (error) return bfcode;
        }
        try
        {
            bfcode += change(stoi(tokens[i]));
            return bfcode;
        }
        catch(invalid_argument)
        {
            cout<<BOLD_MSG("bfscript2: code generator: ")<<ERROR_MSG("argument error: ")
                <<"invalid argument for 'change' (line"<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
    }
    if (tokens[i] == "mov")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, pointers, line_num, current_cell, error);
            if (error) return bfcode;
        }
        try
        {
            bfcode += mov(stoi(tokens[i]));
            return bfcode;
        }
        catch(invalid_argument)
        {
            cout<<BOLD_MSG("bfscript2: code generator: ")<<ERROR_MSG("argument error: ")
                <<"invalid argument for 'mov' (line"<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
    }
    if (tokens[i] == "print")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, pointers, line_num, current_cell, error);
            if (error) return bfcode;
        }
        try
        {
            bfcode += print(stoi(tokens[i]));
            return bfcode;
        }
        catch(invalid_argument)
        {
            cout<<BOLD_MSG("bfscript2: code generator: ")<<ERROR_MSG("argument error: ")
                <<"invalid argument for 'print' (line"<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
        return bfcode;
    }
    if (tokens[i] == "split")
    {
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, pointers, line_num, current_cell, error);
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
            bfcode += generate(tokens, i, aliases, pointers, line_num, current_cell, error);
            if (error) return bfcode;
        }
        ++i;
        if (tokens[i] == "loadalias")
        {
            bfcode += generate(tokens, i, aliases, pointers, line_num, current_cell, error);
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
    cout<<WARNING_MSG("Warning: ")<<"unexpected token at line "<<line_num<<": "<<BOLD_MSG(tokens[i])<<endl;
}