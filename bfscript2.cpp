#include "includes.hpp"
#include "functions.hpp"
#include "color.hpp"
#include "code_generator.hpp"

using namespace std;

#define IS_SPECIAL_CHARACTER(c) (c == ' ' || c == '(' || c == ')' || c == ',' || c == '\"' || c == ';' || c == '\"')

struct Flags
{
public:
    bool valid; // Input files were given
    string invalid_reason;

    bool help;
    string ifile;
    string ofile;
    Flags(int argc, char** argv)
    {
        help = false;
        valid = true;
        if (argc == 1)
        {
            valid = false;
            invalid_reason = "no input files\n";
        }
        else if (argc == 2)
        {
            if ((string)argv[1] == "-h" || (string)argv[1] == "--help")
            {
                help = true;
            }
            else
            {
                ifile = argv[1];
                ofile = "out.bf";
            }
        }
        else if (argc == 3)
        {
            if ((string)argv[1] == "-o")
            {
                valid = false;
                invalid_reason = "no input files\n"; // Last argument is output file
            }
            else
            {
                if ((string)argv[1] == "-h" || (string)argv[1] == "--help" || (string)argv[2] == "-h" || (string)argv[2] == "--help")
                {
                    help = true;
                }
                else
                {
                    valid = false;
                    invalid_reason = "invalid usage of translator\ntry bfscript -h or bfscript --help\n";
                }
            }
        }
        else if (argc == 4)
        {
            if ((string)argv[1] == "-o")
            {
                ofile = argv[2];
                ifile = argv[3];
            }
            else
            {
                if ((string)argv[2] == "-o")
                {
                    ofile = argv[3];
                    ifile = argv[1];
                }
                else
                {
                    valid = false;
                    invalid_reason = "invalid usage of translator\ntry bfscript -h or bfscript --help\n";
                }
            }
        }
    }
};

int main(int argc, char** argv)
{
    Flags flags(argc, argv);
    if (!flags.valid)
    {
        cout<<BOLD_MSG("bfscript: ")<<ERROR_MSG("fatal error: ")<<flags.invalid_reason;
        cout<<"translation terminated\n";
        return -1;
    }
    if (flags.help)
    {
        std::cout<<"Usage: bfscript [options] file\n"<<
                   "Examples:\n\n"<<
                   "bfscript file.bfs\n"<<
                   "# That command will translate file.bfs, and will write result in out.bf\n\n"<<
                   "bfscript file.bfs -o file.bf\n"<<
                   "# That command will translate file.bfs, and will write result in file.bf\n";
        return 0;
    }
    else
    {
        ifstream ifile(flags.ifile);
        if (!ifile.is_open())
        {
            cout<<BOLD_MSG("bfscript: ")<<ERROR_MSG("error: ")<<"input file not found\n";
            cout<<BOLD_MSG("bfscript: ")<<ERROR_MSG("fatal error: ")<<"no input files\n";
            cout<<"translation terminated\n";
            return -1;
        }
        string line;
        int line_num = 0;
        bool in_string = false;
        int current_cell = 0;
        string ident = "";
        string bfcode = "";
        vector<string> tokens;
        bool funcdef = false;
        int func_depth = 0;
        map<string, string> aliases;
        string current_operator = "";

        // Generating tokens
        while (getline(ifile, line))
        {
            ++line_num;
            if (in_string)
            {
                cout<<BOLD_MSG("bfscript: lexer: ")<<ERROR_MSG("error: ")<<"string on line "<<line_num-1<<" is not closed\n";
                cout<<BOLD_MSG("bfscript: lexer: ")<<"lexing analysis terminated\n";
                cout<<"translation terminated\n";
                return -2;
            }
            for (char c: line)
            {
                if (c == '#' && !in_string)
                {
                    break; // Comment
                }
                if (c == '$' && !in_string)
                {
                    tokens.push_back((string)"loadalias");
                    ident = "";
                    continue;
                }
                if (!IS_SPECIAL_CHARACTER(c) || (in_string && !(c == '\"')))
                {
                    ident.push_back(c);
                }
                else if (c == '\"')
                {
                    ident.push_back(c);
                    if (!in_string)
                    {
                        in_string = true;
                    }
                    else
                    {
                        in_string = false;
                        tokens.push_back(ident);
                        ident = "";
                    }
                }
                else
                {
                    tokens.push_back(ident);
                    ident = "";
                }
            }
            tokens.push_back((string)"newline");
        }
        tokens.push_back(ident); // I'm not know why, but last ident isn't pushing
        vector<string> tmp;
        for (int j = 0; j < tokens.size(); j++)
        {
            if (tokens[j] != "")
            {
                tmp.push_back(tokens[j]);
            }
        } // Deleting void strings
        for (auto s: tmp)
        {
            cout<<s<<endl; // Nice debug
        }//*/
        tokens = tmp;
        cout<<BOLD_MSG("bfscript: lexer: ")<<GOOD_MSG("lexing analisys finished\n");
        int i = 0;
        line_num = 0;
        bool error = false;
        for (i; i < tokens.size(); i++)
        {
            bfcode += generate(tokens, i, aliases, line_num, error);
            if (error)
            {
                return -3;
            }
            ++i;
        }
        cout<<BOLD_MSG("bfscript: code generator: ")<<GOOD_MSG("code generating finished")<<endl;
        ofstream ofile(flags.ofile);
        ofile<<bfcode;
    }
    return 0;
}