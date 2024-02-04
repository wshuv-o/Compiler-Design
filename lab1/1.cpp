#include <iostream>

using namespace std;

int main()
{
    float sum=0;
    int n;
    cout<<"Enter array size:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        sum+=a[i];
    }
    float avg=sum/(sizeof(a)/sizeof(int));
    cout<<"Average: "<<avg;
    return 0;
}


