#include<iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{ 
    float money;
    cout << "가진 돈은? ";
    cin >> money;
    float price;
    cout << "사탕 가격은? ";
    cin >> price;
    float candynum, charge;
    candynum = floor (money / price);
    charge = money - candynum * price;
    
    cout << "현재 가지고 있는 돈:"<< money << endl;
    cout <<"캔디의 가격"<< price << endl;
    cout <<"최대로 살 수 있는 캔디"<< candynum << endl;
    cout <<"캔디 구입 후 남은 돈"<< charge << endl;
}