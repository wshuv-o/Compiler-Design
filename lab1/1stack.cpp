#include <iostream>
using namespace std;
class Stack{
    private:
    int num;
    int* arr;
    int top=0;
    int Size;
    public:
    initiate_Stack(int stacksize){
        arr=new int[stacksize];
        Size=stacksize;
    }
    void push(int n)
    {
        arr[top++]=n;
    }
    int pop()
    {
        return arr[top--];
    }
    void print()
    {
        for( int i=0; i<Size;i++){
            cout<<arr[i];
        }
    }
};
int main()
{
    Stack s;
    s.initiate_Stack(5);
    s.push(3);
    s.push(6);
    s.print();
}
