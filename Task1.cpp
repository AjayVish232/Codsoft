#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand((unsigned int) time(NULL));
    // num is shortform used for number
    int num = (rand() % 1000 ) + 1;
    // 0 - 999 + 1 ---> 1 - 1000
    int Guess = 0;

    do
    {
        cout<<"Enter Guess(1 - 1000): ";
        cin>>Guess;

        if(Guess > num)
            cout<<"Guess lower!"<<endl;
        else if (Guess < num)
            cout<<"Guess higher!"<<endl;
        else
            cout<<"You won!"<<endl;
    } while (Guess != num);

    return 0;
}
