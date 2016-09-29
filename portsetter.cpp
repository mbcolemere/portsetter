// Matthew Colemere - September 6, 2015 - portsetter.cpp
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <cstdlib>
using namespace std;

// Constant variables
const int MAX_PORT = 65000;

//getLang function
string getLang(string envLang) {
    string retString = envLang.substr(0,2);
    
    if (envLang == "" || envLang == "C" || envLang == "C.UTF-8") return "default";
    
    if (envLang.length() == 8) {
        string temp = envLang.substr(3,6);
        if (temp == ".UTF-8") return retString;
        else return "Error";
    }
    if (isalpha(envLang[0]) && isalpha(envLang[1])) {
        if (envLang.length() == 2) {
            return retString;
        }
        else if (envLang[2] == '_') {
            if (isalpha(envLang[3]) && isalpha(envLang[4])) {
                if (envLang.length() == 5) {
                    return retString;
                }
                else if (envLang.length() == 11) {
                    string temp2 = envLang.substr(5,6);
                    if (temp2 == ".UTF-8") return retString;
                    else return "Error";
                }
            }
        }
    }
    return "Error";
}

// Usage function prints out standard usage to be used in program
void usage(string l) {
    cout << endl;
    // outputs the portsetter.usage_en.txt file
    ifstream input;
    input.open("portsetter.usage_" + l + ".txt");
    
    if (input.fail()) {
        cout << "Could not open the usage file" << endl;
        cout << "Error";
    }
    
    char output;
    while (!input.eof()) {
        input.get(output);
        cout << output;
    }
    input.close();
    cout << endl;
}

// version function: prints out current version of program
void version() {
    string currentVer = "1.1.4a";
    cout << currentVer << endl << endl;
}

// about function: prints out snip bit of author of program 
void about(string l) {
    // outputs the portsetter.about_en.txt file
    ifstream input;
    input.open("portsetter.about_" + l + ".txt");
    
    if (input.fail()) {
        cout << "Could not open the usage file" << endl;
        cout << "Error";
    }
    
    char output;
    while (!input.eof()) {
        input.get(output);
        cout << output;
    }
    cout << endl << endl;
    input.close();
}

int main(int argc, char* args[]) {
    // find language from enviromental variables
    string temp = "";
    string lang = getLang(getenv("LANGUAGE"));
    if (lang == "Error") {
        lang = "en";
        temp = getenv("LANGUAGE");
        cout << "Bad language specification in environment variable";
        cout << " LANGUAGE=" + temp + " Using English." << endl;
    }
    else if (lang == "default") {
        lang = getLang(getenv("LC_ALL"));
        if (lang == "Error") {
            lang = "en";
            temp = getenv("LC_ALL");
            cout << "Bad language specification in environment variable";
            cout << " LC_ALL=" + temp + " Using English." << endl;
        }
        // The code to check LC_MESSAGES would be here, but LC_MESSAGES did
        // not exist in my environmental variables, so I omitted it (as it 
        // would not let me run the program otherwise. The code would be the
        // same as these others with "LC_MESSAGES" where "LANGUAGE", "LC_ALL", 
        // or "LANG" were found. Thank you.
        else if (lang == "default") {
            lang = getLang(getenv("LANG"));
            if (lang == "Error") {
                lang = "en";
                temp = getenv("LANG");
                cout << "Bad language specification in environment variable";
                cout << " LANG=" + temp + " Using English." << endl;
            }
            else if (lang == "default") lang = "en";
        }
    }
    
    // vector message with language loaded
    vector<string> msg;
    ifstream inLang("portsetter_" + lang + ".txt");
    if (inLang.fail()) {
        cout << "Missing " + lang + " translation files. Using English." << endl;
        lang = "en";
        inLang.open("portsetter_en.txt");
    }
    string line;
    while (!inLang.eof()) {
        getline(inLang, line);
        msg.push_back(line);
    }
    inLang.close();
    
    // Easy exit case of too many arguments
    if (argc > 4) {
        cout << msg[3];
        usage(lang);
        return 3;
    }
    // If nothing has been entered, there is nothing to do but return 0
    if (argc > 1) {
        // Convert the arguments to a string
        string flag(args[1]);
        // Check if the first value is a '-', otherwise it's invalid
        if (flag[0] != '-') {
            cout << msg[1];
            usage(lang);
            return 1;
        }
        // If there are two arguments, convert the second one into a string
        if (argc == 3 && (flag == "-p" || flag == "--port")) {
            string num(args[2]);
            if (num == "-e") {
                string envVar = getenv("PORT");
                if (envVar != "") {
                    for (int i=0; i<envVar.length(); ++i) {
                        if (!isdigit(envVar[i])) {
                            cout << msg[1];
                            usage(lang);
                            return 1;
                        }
                    }
                    int newNum = stoi(envVar);
                    if (newNum < 1 || newNum > MAX_PORT) {
                        cout << msg[2];
                        usage(lang);
                        return 2;
                    }
                    
                    cout << msg[4] << newNum << endl << endl;
                    usage(lang);
                    return 0;
                }
            }
            // Check that all pieces of second piece are a number
            for (int i=0; i<num.length(); ++i) {
                if (!isdigit(num[i])) {
                    cout << msg[1];
                    usage(lang);
                    return 1;
                }
            }
            int finNum = stoi(num);
            if (finNum < 1 || finNum > MAX_PORT) {
                cout << msg[2];
                usage(lang);
                return 2;
            }
            cout << msg[4] << finNum << endl;
            usage(lang);
            return 0;
        }
        // Check for -p or --port followed by -e with enviroment variable
        if (argc == 4 && (flag == "-p" || flag == "--port")) {
            string secFlag(args[2]);
            if (secFlag != "-e") {
                cout << msg[1];
                usage(lang);
                return 1;
            }
            string envVar = getenv(args[3]);
            if (envVar != "") {
                for (int i=0; i<envVar.length(); ++i) {
                    if (!isdigit(envVar[i])) {
                        cout << msg[1];
                        usage(lang);
                        return 1;
                    }
                }
                int newNum = stoi(envVar);
                if (newNum < 1 || newNum > MAX_PORT) {
                    cout << msg[2];
                    usage(lang);
                    return 2;
                }
                
                cout << msg[4] << newNum << endl;
                usage(lang);
                return 0;
            }
        }
        // Check input length
        if ((flag == "-p" || flag == "--port") && (argc != 3 || argc != 4)) {
            cout << msg[1];
            usage(lang);
            return 1;
        }
        // Check for a -v or --version
        if (flag == "-v" || flag == "--version") {
            if (argc == 2) {
                version();
                usage(lang);
                return 0;
            }
            else {
                cout << msg[1];
                usage(lang);
                return 1; 
            }
        }
        // Check for a -! or --about
        if (flag == "-!" || flag == "--about") {
            if (argc == 2) {
                about(lang);
                usage(lang);
                return 0;
            }
            else {
                cout << msg[1];
                usage(lang);
                return 1;
            }
        }
        // Check for a -h or --help entry or -?
        if (flag == "-h" || flag == "--help" || flag == "-?") {
            if (argc == 2) {
                usage(lang);
                return 0;
            }
            else {
                cout << msg[1];
                usage(lang);
                return 1;
            }
        }
        if (flag != "-h" && flag != "--help" && flag != "-p" && flag != "--port"
        && flag != "-?" && flag != "-!" && flag != "--about" && flag != "-v"
        && flag != "--version") {
            cout << msg[1];
            usage(lang);
            return 1;
        }
    }
    // If there is no input, it is not an error. Return usage and 0 as a normal response
    usage(lang);
    return 0;
}