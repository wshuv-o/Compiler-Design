#include<iostream>
#include<string>
using namespace std;
bool isVariable(string s)
{
    bool a=true;
    if((int(s[0])>=65&&int(s[0])<=90)||(int(s[0])>=97&&int(s[0])<=122)||s[0]=='_'){
        a=true;
    }else{
        a=false;
        cout<<"!!Special Character at the begining!!";
        return a;
    }
    for(int i=0; i<s.size(); i++){
        if((int(s[i])>=32&&int(s[i])<=47)||(int(s[i])>=58&&int(s[i])<=64)){
            a= false;
            cout<<"!!Special Character within the variable name!!";
            return a;
          }
    }
    return a;
}
int main(){
    string str;
    char a='a';
    cin>>str;
    if(isVariable(str)) cout<<"Valid  variable";
}
