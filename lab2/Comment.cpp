#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
void isComment(string s)
{
    int i=s.find("\\\\");
    int j=s.find("\\\*");

    if(i!=-1) {cout<<"Single line Comment Found \n"<<s.substr(i, s.length()-i);}
    //else cout<<s.find("\\\*");
    if(j!=-1) cout<<"Multiline Comment Found \n"<<s.substr(s.find("\\\*"), s.length()-s.find("\\\*"));
    //cout<<"Multiline Comment Found \n"<< s.find("*\\");

}
int main(){
    string inp;
    getline(cin, inp, 'e');
    isComment(inp);

    return 0;
}
