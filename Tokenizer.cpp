#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

bool isStringLiteral(char* str){
    return (str[0]=='"' && str[strlen(str) - 1]=='"');
}

bool isPreprocessorDirective(char* str){
    const char* keywords[]={"#include", "<iostream> ", "#define","#ifdef", "#ifndef", "#endif","#if", "#elif", "#else","<iostream>","<string>","<vector>","<algorithm>","<fstream>","<cmath>","<iomanip>","<cstdlib>","<ctime>","<map>"};
    int numKeywords=sizeof(keywords) / sizeof(keywords[0]);
    for (int i=0; i < numKeywords; i++){
        if (strcmp(str, keywords[i])==0)
            return true;
    }
    return false;
}

bool isPunctuator(char ch)
{
    if (ch ==','||ch ==';'||ch =='('||ch ==')'||ch =='['||ch ==']'|| ch=='{' || ch=='}')
        return true;
    return false;
}

bool isOperator(char ch){
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='>' || ch=='<' || ch =='=' || ch=='|' || ch=='&' || ch=='%')
        return true;
    return false;
}

bool isIdentifier(char* str){
    if (!isalpha(str[0]) && str[0] != '_')
        return false;
    if(strcmp(str, "itn")==0)
        return false;
    int len=strlen(str);
    for (int i=0; i < len; i++){
        if (!isalnum(str[i]) && str[i] != '_')
            return false;
    }
    return true;
}


bool isKeyword(char *str){
    const char* keywords[]={"if","using", "std", "else", "while", "do", "break", "continue", "return", "char", "case", "long", "short", "typedef", "switch", "unsigned",
                               "void", "static", "struct", "sizeof", "volatile", "enum", "const", "union", "extern", "bool", "main", "cout","int", "namespace"};
    int numKeywords=sizeof(keywords) / sizeof(keywords[0]);
    for (int i=0; i < numKeywords; i++){
        if (strcmp(str, keywords[i])==0)
            return true;
    }
    return false;
}

bool isDigit(char* str){
    int len=strlen(str), numDecimal=0;
    if (len==0)
        return false;
    for (int i=0; i < len; i++){
        if (numDecimal > 1 && str[i]=='.')
            return false;
        else if (numDecimal <= 1 && str[i]=='.')
            numDecimal++;
        else if (!isdigit(str[i]))
            return false;
    }
    return true;
}

char* subString(char* realStr, int l, int r){
    char* str=(char*) malloc(sizeof(char) * (r - l + 2));
    for (int i=l; i <= r; i++)
        str[i - l]=realStr[i];
    str[r - l + 1]='\0';
    return str;
}

void Tokenizer(char* str){
    int left=0, right=0;
    int len=strlen(str);
    while (right <= len){
        if (!isPunctuator(str[right]) && !isspace(str[right])){
            right++;
        } else if ((isPunctuator(str[right]) || isspace(str[right])) && left==right){
            if (isOperator(str[right])){
                cout << str[right] << "\t\t\tToken is an operator" << endl;
            } else if (isPunctuator(str[right])){
                cout << str[right] << "\t\t\tToken is a punctuator" << endl;
            }
            right++;
            left=right;
        } else if ((isPunctuator(str[right]) || isspace(str[right])) && left!=right||(right==len && left!=right)){
            char* sub=subString(str, left, right - 1);
            if (isKeyword(sub)){
                cout << sub << "\t\t\tToken is a keyword" << endl;
            } else if (isDigit(sub)){
                cout << sub << "\t\t\tToken is number" << endl;
            } else if (isIdentifier(sub)){
                cout << sub << "\t\t\tToken is an identifier" << endl;
            } else if (isStringLiteral(sub)){
                cout << sub << "\t\tToken is string literal" << endl;
            } else if (isPreprocessorDirective(sub)){
                cout << sub << "\t\t\tToken is a preprocessor directive" << endl;
            } else if (isOperator(sub[0])){
                cout << sub << "\t\t\tToken is an operator" << endl;
            } else {
                cout << sub << "\t\t\tToken is invalid" << endl;
            }
            left=right;
        }
    }
}


int main(){
        char* stream=new char[128];

    cout << string(50, '-') << endl;
    cout << "Lexeme\t\t\t\tToken" << endl;
    cout << string(50, '-') << endl;
    ifstream MyReadFile("lex_input.txt");
    if (!MyReadFile.is_open()){
        cerr << "Failed to open the file." << endl;
        return 1;
    }
    string line;
    while(getline(MyReadFile, line))
     {
        char* str=new char[line.length() + 1];
        strcpy(str, line.c_str());
        Tokenizer(str);
        delete[] str;
    }
    MyReadFile.close();
    return 0;
}
