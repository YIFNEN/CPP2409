#include<iostream>
using namespace std;


int main() {
    int a,b,c, largest;
    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    if(a >= b){
        if(a >= c){
            largest = a;
        }
        else
            largest = c;
    }
    // 이중 조건문으로  A가 가장 클 경우와 C A B순으로 클 경우를 거름

    else if (b >= c)
        largest = b;
        
    // 남은 경우의 수 중 B가 가장 클 경우를 제외하면 C B A 순으로 클 경우만 남는다. 
    else
        largest = c;


    cout << "가장 큰 정수는" << largest << endl;
    return 0;
}