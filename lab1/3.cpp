#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    char* fname;
    char* lname;
    char* fullName;
    string f,l;
    getline(cin, f);
    getline(cin, l);
    fname = new char[f.length() + 1];
    strcpy(fname, f.c_str());
    lname = new char[l.length() + 1];
    strcpy(lname, l.c_str());
    fullName = new char[f.length() + 1+l.length() + 1];
    fullName=fname;
for(int j=0, i=l.length() ;i<(f.length() + 1+l.length() + 1);i++, j++){
    fullName[i]=lname[j];
}
cout<<fullName;
    return 0;
}
