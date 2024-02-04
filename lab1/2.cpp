
#include <iostream>

using namespace std;

int main()
{
    int maxX,minN;
    int n;
    cout<<"Enter array size:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    maxX=a[0];
    minN=a[0];
    for(int i=1;i<sizeof(a)/sizeof(int);i++){
        if(maxX<a[i]) maxX=a[i];
        if(minN>a[i]) minN=a[i];
    }
    cout<<"Max: "<<maxX<<"\n";
    cout<<"Min: "<<minN;
}
