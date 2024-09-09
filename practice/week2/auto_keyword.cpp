#include<iostream>
using namespace std;

auto add(int x, int y) // 덧셈 계산
{
    return x + y;

}

int main(){
    auto sum = add(5 ,6);
    cout << sum;
    return 0;
}