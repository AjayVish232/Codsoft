#include <iostream>

using namespace std;

int main()
{
    int num1,num2; // Variables to store the two numbers.
    char op;      // Variable to store the chosen operation.

    cout<<"Enter the value of First Operand:"<<" "<<endl;
    cin>>num1;
    cout<<"Enter the value of Second Operand:"<<" "<<endl;
    cin>>num2;
    cout<<"Enter the operation (+,-,*,/,%)"<<" "<<endl;
    cin>>op;
        switch(op)
    {
    case'+':
        cout<<"Result :"<<" "<<num1 + num2<<endl;
        break;
    case'-':
        cout<<"Result :"<<" "<<num2 - num1<<endl;\
        break;
    case'*':
        cout<<"Result :"<<" "<<num1 * num2<<endl;
        break;
    case'/':
        if(num2 != 0){
        cout<<"Result :"<<" "<<num1 / num2<<endl;
        }
        else{
            cout<<"No division is allowed as the number is zero."<<endl;
        }
        break;
    case'%':
        if(num2 != 0){
        cout<<"Result :"<<" "<<num1%num2<<endl;
        }
        else{
            cout<<" Modulo by zero is not allowed . "<<endl;
        }
        break;
    }
    return 0;
}
