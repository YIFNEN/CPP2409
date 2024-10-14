#include<iostream>
using namespace std;
void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 100, b = 200;
    cout << "a=" << a << "b="<< b << endl;
    swap(a,b);
    cout << "a=" << a << "b="<< b << endl;
    return 0;
}