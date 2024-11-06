#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> v;
    for(int i = 0; i < 10; i++){ // v에 원소 추가
        v.push_back(i);
    }
    cout <<"현재의 v = ";
        for (auto& e : v)
        cout << e << " ";
    cout << endl; //추가 원소 출력

    cout << "삭제 요소 = ";
    // 벡터가 공백이 될 때까지 pop_back() 호출
    while (v.empty() != true) {
    cout << v.back() << " "; //원소 삭제 및 출력
    v.pop_back();
    }
    cout << endl; return 0;
    }

