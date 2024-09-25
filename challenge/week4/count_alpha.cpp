#include<iostream>
using namespace std;
int main (){
    int vowel = 0;
    int consonant = 0;
    cout << " 영소문자를 1개 입력하고 ctrl + z를 입력해 종료하세요" <<endl;
    char ch;

    while( cin >> ch ) {
        switch (ch){ // 모음 입력시 vowel 증가 아닐시 consonant 증가
            case 'a':
                ++vowel;
                break;
            case 'e':
                ++vowel;
                break;
            case 'i':
                ++vowel;
                break;
            case 'o':
                ++vowel;
                break;
            case 'u':
                ++vowel;
                break;
            default:
                ++consonant;

    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;







    }

    return 0;
}