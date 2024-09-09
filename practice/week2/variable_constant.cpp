#include<iostream>
#define PI 3.1459265359 //상수 설정 1
using namespace std;

int main(){
    int income = 1000;
    const double Tax_Rate = 0.25; // 상수 설정 2
    income = income - Tax_Rate * income;

    double x = 100;
    x = x*PI;
    cout << x << endl;
    return 0;

}