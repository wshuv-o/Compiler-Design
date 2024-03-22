#include<iostream>
#include<string>
using namespace std;

bool isVariable(string s) {
    if(s.empty()) {
        cout << "Invalid\n!!Empty string!!" << endl;
        return false;
    }
    
    if(!((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z') || s[0] == '_')) {
        cout << "Invalid\n!!Special Character at the beginning!!" << endl;
        return false;
    }
    
    for(int i = 0; i < s.size(); i++) {
        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_')) {
            cout << "Invalid\n!!Special Character within the variable name!!" << endl;
            return false;
        }
    }
    
    return true;
}

int main() {
    string str;
    cout << "Enter a variable name: ";
    getline(cin, str);
    
    if(isVariable(str))
        cout << "Valid variable" << endl;
    return 0;
}
