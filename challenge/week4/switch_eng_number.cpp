#include<iostream>
using namespace std;

int main() {
    int number;
    cout << "양수를 입력하시오:";
    cin >> number; // if문의 조건을 case로 변경
    switch(number){
        case 0:
            cout<< "zero" << endl;
            break;
        case 1:
             cout<< "one" << endl;
            break;
        default:
            cout << "many" << endl;
            break;
    }
    return 0;

}