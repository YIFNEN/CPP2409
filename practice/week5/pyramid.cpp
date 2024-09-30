#include<iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까?(5~100):";
    cin >> floor;
    for (int i = 0; i<floor ; i++){
        for(int j =  i ; j < floor - 1 ; j++){
            cout << "S";
        }
        for (int k = 1; k < 2*(i+1) ; k++){

            cout << "*";
        }
        cout << endl;
    }

    return 0;
}