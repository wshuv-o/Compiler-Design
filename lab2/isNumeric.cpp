#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
bool isNum(char* a){
    int c=atoi(a);
    if(c>=1&&c<=9) return true;
}
int main(){
    string inp;
    string decesion="Numeric Constant";
    cin>>inp;
    char cs=inp[0];
    for( int i=0;i<inp.length();i++){
            if(!isNum(&cs)&&cs!='.'&&cs!='-'&&cs!='0'){
                decesion="Not Numeric";
                break;
            }
        cs=inp[i];
    }
    cout<<decesion;
    return 0;
}
