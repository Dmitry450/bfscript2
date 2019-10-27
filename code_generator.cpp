#include "code_generator.hpp"

string generate(vector<string> &tokens, int &i, map<string, string> &aliases, map<string, Pointer*> &pointers, 
                int &line_num, int &current_cell, bool &error)
{
    string bfcode = "";
    if (tokens[i] == "newline")
    {
        ++line_num;
        return bfcode;
    }
    if (tokens[i] == "read")
    {
        return ",";
    }
    if (tokens[i] == "reads")
    {
        string come_back;
        int lenght;
        try
        {
            ++i;
            lenght = stoi(tokens[i]);
        }
        catch(invalid_argument)
        {
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument for 'reads'"
                <<" (line "<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
        for (int i = 0; i < lenght; i++)
        {
            bfcode += ",>";
            come_back += "<";
        }
        return bfcode + "\n" + come_back + "\n";
    }
    if (tokens[i] == "sub")
    {
        int p1, p2, resultpos;
        ++i;
        if (tokens[i] == "loadpointer")
        {
            try
            {
                ++i;
                p1 = pointers[tokens[i]]->start;
            }
            catch(out_of_range)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 1 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        else
        {
            try
            {
                ++i;
                p1 = stoi(tokens[i]);
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 1 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        ++i;
        if (tokens[i] == "loadpointer")
        {
            try
            {
                ++i;
                p2 = pointers[tokens[i]]->start;
            }
            catch(out_of_range)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 2 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        else
        {
            try
            {
                ++i;
                p2 = stoi(tokens[i]);
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 2 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        ++i;
        if (tokens[i] == "loadpointer")
        {
            try
            {
                ++i;
                resultpos = pointers[tokens[i]]->start;
            }
            catch(out_of_range)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 3 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        else
        {
            try
            {
                ++i;
                resultpos = stoi(tokens[i]);
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 3 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        return sub(p1, p2, resultpos, current_cell);
    }
    if (tokens[i] == "sum")
    {
        int p1, p2, resultpos;
        ++i;
        if (tokens[i] == "loadpointer")
        {
            try
            {
                ++i;
                p1 = pointers[tokens[i]]->start;
            }
            catch(out_of_range)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 1 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        else
        {
            try
            {
                ++i;
                p1 = stoi(tokens[i]);
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 1 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        ++i;
        if (tokens[i] == "loadpointer")
        {
            try
            {
                ++i;
                p2 = pointers[tokens[i]]->start;
            }
            catch(out_of_range)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 2 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        else
        {
            try
            {
                ++i;
                p2 = stoi(tokens[i]);
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 2 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        ++i;
        if (tokens[i] == "loadpointer")
        {
            try
            {
                ++i;
                resultpos = pointers[tokens[i]]->start;
            }
            catch(out_of_range)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 3 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        else
        {
            try
            {
                ++i;
                resultpos = stoi(tokens[i]);
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument 3 for 'sum'"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        return sum(p1, p2, resultpos, current_cell);
    }
    if (tokens[i] == "putchar")
    {
        return ".";
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
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument for 'pointer'"
                <<" (line "<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
    }
    if (tokens[i] == "array")
    {
        ++i;
        try
        {
            pointers[tokens[i]] = new Pointer("array", stoi(tokens[i+1]), stoi(tokens[i+1]) + stoi(tokens[i+2]));
            ++i;
            ++i;
            return bfcode;
        }
        catch(invalid_argument err)
        {
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")<<"invalid argument(s) for 'array'"
                <<" (line "<<line_num<<")\n";
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
                <<"alias '"<<tokens[i]<<"' is not defined (line "<<line_num<<")\n";
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
                <<"' is not defined (line "<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
        ++i;
        if (tokens[i] == "assigment")
        {
            bfcode += go_to(current_cell, pointer->start);
            ++i;
            bfcode += setchar(tokens[i][0]);
            bfcode += go_to(pointer->start, current_cell);
            return bfcode;
        }
        if (tokens[i] == "clear")
        {
            bfcode += go_to(current_cell, pointer->start);
            ++i;
            bfcode += "[-]\n";
            bfcode += go_to(pointer->start, current_cell);
            return bfcode;
        }
        if (tokens[i] == "add")
        {
            bfcode += go_to(current_cell, pointer->start);
            ++i;
            try
            {
                bfcode += change(stoi(tokens[i]));
                bfcode += go_to(pointer->start, current_cell);
                return bfcode;
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")
                    <<"invalid argument for pointer's 'add' (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        if (tokens[i] == "sub")
        {
            bfcode += go_to(current_cell, pointer->start);
            ++i;
            try
            {
                bfcode += change(-stoi(tokens[i]));
                bfcode += go_to(pointer->start, current_cell);
                return bfcode;
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")
                    <<"invalid argument for pointer's 'sub' (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
    }
    if (tokens[i] == "byarray")
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
                <<"' is not defined (line "<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
        ++i;
        int at;
        try
        {
            at = pointer->start + stoi(tokens[i]);
            if (at > pointer->end || at < pointer->start)
            {
                cout<<BOLD_MSG("bfscript: code generator")<<ERROR_MSG("out of range error: ")<<"array index out of range"
                    <<" (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        catch(invalid_argument)
        {
            cout<<BOLD_MSG("bfscript: code generator")<<ERROR_MSG("argument error: ")<<"invalid argument for 'byarray'"
                <<" (line "<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
        ++i;
        if (tokens[i] == "assigment")
        {
            bfcode += go_to(current_cell, at);
            ++i;
            bfcode += setchar(tokens[i][0]);
            bfcode += go_to(at, current_cell);
            return bfcode;
        }
        if (tokens[i] == "clear")
        {
            bfcode += go_to(current_cell, at);
            ++i;
            bfcode += "[-]\n";
            bfcode += go_to(at, current_cell);
            return bfcode;
        }
        if (tokens[i] == "add")
        {
            bfcode += go_to(current_cell, at);
            ++i;
            try
            {
                bfcode += change(stoi(tokens[i]));
                bfcode += go_to(at, current_cell);
                return bfcode;
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")
                    <<"invalid argument for pointer's 'add' (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        if (tokens[i] == "sub")
        {
            bfcode += go_to(current_cell, at);
            ++i;
            try
            {
                bfcode += change(-stoi(tokens[i]));
                bfcode += go_to(at, current_cell);
                return bfcode;
            }
            catch (invalid_argument)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")
                    <<"invalid argument for pointer's 'sub' (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
    }
    if (tokens[i] == "goto")
    {
        ++i;
        int at;
        bool ploaded = false;
        if (tokens[i] == "loadpointer")
        {
            try
            {
                ++i;
                ploaded = true;
                at = pointers.at(tokens[i])->start;
            }
            catch(out_of_range)
            {
                cout<<BOLD_MSG("bfscript: code generator")<<ERROR_MSG("name error: ")<<"pointer '"<<tokens[i]
                    <<"' is not defined (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        try
        {
            if (!ploaded) at = stoi(tokens[i]);
            go_to(current_cell, at);
            current_cell = stoi(tokens[i]);
        }
        catch(invalid_argument)
        {
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")
                <<"invalid argument for 'goto' (line "<<line_num<<")\n";
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
                <<"invalid argument for 'walk' (line "<<line_num<<")\n";
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
                <<"invalid argument for 'change' (line "<<line_num<<")\n";
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
                <<"invalid argument for 'mov' (line "<<line_num<<")\n";
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
                <<"invalid argument for 'print' (line "<<line_num<<")\n";
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
        string arg1, arg2;
        if (tokens[i] == "loadalias")
        {
            ++i;
            try
            {
                arg1 = aliases[tokens[i]];
            }
            catch(out_of_range)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("name error: ")
                    <<"alias '"<<tokens[i]<<"' is not defined (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        ++i;
        if (tokens[i] == "loadalias")
        {
            ++i;
            try
            {
                arg1 = aliases[tokens[i]];
            }
            catch(out_of_range)
            {
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("name error: ")
                    <<"alias '"<<tokens[i]<<"' is not defined (line "<<line_num<<")\n";
                cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
                error = true;
                return bfcode;
            }
        }
        try
        {
            bfcode += copy(stoi(arg1), stoi(arg2));
        }
        catch(invalid_argument)
        {
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("argument error: ")
                <<"invalid argument(s) for 'copy' (line "<<line_num<<")\n";
            cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
            error = true;
            return bfcode;
        }
        return bfcode;
    }
    cout<<ERROR_MSG("Error: ")<<"unexpected token at line "<<line_num<<": "<<BOLD_MSG(tokens[i])<<endl;
    cout<<BOLD_MSG("bfscript: code generator: ")<<ERROR_MSG("code generating terminated")<<endl;
    error = true;
    return bfcode;
}