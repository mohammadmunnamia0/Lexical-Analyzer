#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

// Define C/C++ keywords
const unordered_set<string> keywords = {
    "int", "float", "char", "double", "if", "else", "while", "for", "return", "void",
    "break", "continue", "switch", "case", "default", "struct", "typedef", "sizeof",
    "do", "const", "goto", "static", "enum", "union", "extern", "volatile", "long",
    "short", "unsigned", "signed", "auto", "register", "namespace", "using", "include", "std", "cout", "cin"
};

// Define token types
enum TokenType {
    KEYWORD, IDENTIFIER, NUMBER, OPERATOR, PUNCTUATION, STRING_LITERAL, UNKNOWN
};

// Token structure
struct Token {
    string value;
    TokenType type;
};

// Function to check if a string is a keyword
bool isKeyword(const string& word) {
    return keywords.find(word) != keywords.end();
}

// Function to classify a character as operator or punctuation
bool isOperator(char c) {
    return string("+-*/%=&|!<>^~").find(c) != string::npos;
}

bool isPunctuation(char c) {
    return string("(){}[];,\"#").find(c) != string::npos;
}

// Lexical Analyzer Function
vector<Token> lexicalAnalyzer(const string& code) {
    vector<Token> tokens;
    string current;
    int i = 0;

    while (i < code.size()) {
        char ch = code[i];

        // Skip whitespace
        if (isspace(ch)) {
            i++;
            continue;
        }

        // Keywords and Identifiers
        if (isalpha(ch) || ch == '_') {
            current.clear();
            while (isalnum(code[i]) || code[i] == '_') {
                current += code[i++];
            }
            tokens.push_back({current, isKeyword(current) ? KEYWORD : IDENTIFIER});
        }
        // Numbers
        else if (isdigit(ch)) {
            current.clear();
            while (isdigit(code[i]) || code[i] == '.') {
                current += code[i++];
            }
            tokens.push_back({current, NUMBER});
        }
        // Strings
        else if (ch == '"') {
            current.clear();
            current += ch;
            i++;
            while (i < code.size() && code[i] != '"') {
                current += code[i++];
            }
            current += code[i++];  // Include the closing "
            tokens.push_back({current, STRING_LITERAL});
        }
        // Operators
        else if (isOperator(ch)) {
            current.clear();
            current += ch;
            if (isOperator(code[i + 1])) {  // Check for multi-character operators
                current += code[++i];
            }
            tokens.push_back({current, OPERATOR});
            i++;
        }
        // Punctuation
        else if (isPunctuation(ch)) {
            tokens.push_back({string(1, ch), PUNCTUATION});
            i++;
        }
        // Unknown character
        else {
            tokens.push_back({string(1, ch), UNKNOWN});
            i++;
        }
    }
    return tokens;
}

// Function to display tokens
void displayTokens(const vector<Token>& tokens) {
    for (const auto& token : tokens) {
        cout << "Token: " << token.value << ", Type: ";
        switch (token.type) {
            case KEYWORD: cout << "Keyword"; break;
            case IDENTIFIER: cout << "Identifier"; break;
            case NUMBER: cout << "Number"; break;
            case OPERATOR: cout << "Operator"; break;
            case PUNCTUATION: cout << "Punctuation"; break;
            case STRING_LITERAL: cout << "String Literal"; break;
            default: cout << "Unknown";
        }
        cout << endl;
    }
}

// Main Function
int main() {
    cout << "Enter C/C++ code (end with an empty line):" << endl;
    string code, line;
    
    // Allow user to input code
  while (true) {
    getline(cin, line);
    if (line.empty()) break;  // End input on an empty line
    code += line + "\n";
}


    // Uncomment the following lines to debug with a hardcoded example
    /*
   code = R"(
    #include <iostream>
    using namespace std;

    int main() {
        cout << "Hello World!";
        return 0;
    }
)";

    */

    vector<Token> tokens = lexicalAnalyzer(code);
    cout << "\nTokens Identified:\n";
    displayTokens(tokens);
    return 0;
}
