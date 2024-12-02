#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream is {"numbers.txt"};
    if(!is){
        cerr << "파일 오픈에 실패하였습니다" << endl;
        exit(1);
    }
    int number;
    while(is){
        is >> number;// 파일 데이터 변수에 저장
        cout << number << " ";

}    return 0;
}