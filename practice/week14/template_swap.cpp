#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<typename T>
void SwapValues(T& x, T&y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;

}

int main()
{
    int x = 100, y = 200;
    SwapValues(x, y); // x, y가 모두 int 타입- OK!
    cout << x << " " << y << endl;

    string s1 = "This is a first string";
    string s2 = "This is a second string";
    SwapValues(s1, s2);
    cout << s1 << " " << s2 << endl;
    return 0;

}