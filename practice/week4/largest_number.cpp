#include<iostream>
using namespace std;


int main() {
    int a,b,c, largest;
    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    if(a >= b && a >= c) // 가장 큰 알파벳을 찾는 게 아니라 수만 찾으면 되므로 조건을 넓힘
        largest = a;

    else if (b >= a && b >= c)
        largest = b;

    else
        largest = c;


    cout << "가장 큰 정수는" << largest << endl;
    return 0;
}