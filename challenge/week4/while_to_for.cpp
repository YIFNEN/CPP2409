#include<iostream>
using namespace std;

int main() {    
    int userInput;

    cout << "정수를 10번 입력하세요(0을 입력하면 종료): ";
    for(int i = 0; i < 10; ++i){ // i는 10번 반복, 예시에 따라 횟수를 0부터 9까지로 출력
        cin >> userInput;
        if(userInput == 0){ // input이 0일 경우 종료
            break;
        } 
        cout << "입력값: " << userInput << " 횟수 :" <<  i << endl;//루프마다 입력값과 횟수 출력

    }

    cout<< "종료되었습니다"; // 루프 종료
    
    
    
    
    
    return 0;

}