#include<iostream>
#include<string>
using namespace std;

string toLowerStr(string str){ 
    for(char&c : str){ //str내를 참조자기반 매개변수로 순회하며 소문자로 변경
        c = tolower(c);
    }
    return str;
}

string toUpperStr(string str){
     for(char&c : str){ //str내를 참조자기반 매개변수로 순회하며 대문자로 변경
        c = toupper(c);
    }
    return str;
}
int calcHammingDist(string s1, string s2){
    int count = 0;
    for(int i = 0; i <s1.length(); i++ ){
            s2 = toUpperStr(s2); //문자열을 모두 대문자로 변경
            s1 = toUpperStr(s1);
            if(s1[i] != s2[i]){ // 비교하며 해밍 거리 계산
                count += 1;
            }
        }
    return count;//해밍 거리 반환
}

int main(){
    while (true){
    string s1, s2;
    
    
    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;

    if(s1.length() != s2.length()){//길이가 다른 오류 발생시 while문의 처음으로 돌아감.
        cout << "오류: 길이가 다름" << endl;
    }
    else {
        int count = calcHammingDist(s1, s2); //같은 길이의 문자열을 입력했을 경우 해밍 거리 출력 후 루프 탈출출
        cout << "해밍 거리는" << count << endl;
        break;
    }
    }


    return 0;
}