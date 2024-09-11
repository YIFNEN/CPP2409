#include<iostream>
#include <string>
using namespace std;

int main()
{
    float Ftemp = 0.0;
    float Ctemp = 0.0;
    cout << "화씨 온도: ";
    cin >> Ftemp;
    Ctemp = (5.0 / 9.0) * (Ftemp-32.0);

    cout << "섭씨 온도:"<< Ctemp << endl;
    return 0;
}3333