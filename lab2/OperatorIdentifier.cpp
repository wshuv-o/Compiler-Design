#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
bool isOpr(char a){
    if(a=='+'||a=='-'||a=='*'||a=='/'||a=='%'||a=='=') return true;
    else return false;
}
int main(){
    string inp;
    int j=0;
    cin>>inp;
    char oprs[10];
    for( int i=0;i<inp.length();i++){
            if(isOpr(inp[i])){
                    oprs[j]=inp[i];
                    j=j+1;
            }
    }
    for( int i=0;i<j;i++){
        cout<<"operator"<<i+1<<":"<<oprs[i]<<endl;
    }
    return 0;
}
