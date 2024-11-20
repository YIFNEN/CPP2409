#include "user.h"
#include <iostream>
using namespace std;

User::User() { // 생성자에서 체력을 20으로 초기화
    hp = 20;
    item_cnt = 0;
}

void User::IncreaseHP(int h_amount) {
    hp += h_amount;
}

void User::DecreaseHP(int h_amount) {
    hp -= h_amount;
}

int User::GetHP() {
    return hp;
}

void User::IncreaseItemCnt() {
    item_cnt++;
}

void User::DoAttack(User& target) {
    cout << "공격하고 싶지만 무기가 없습니다!" << endl;
}

void Magician::DoAttack(User& target) {
    cout << "마법 사용! (데미지: 3)" << endl;
    target.DecreaseHP(3);
}

void Warrior::DoAttack(User& target) {
    cout << "베기 사용! (데미지: 3)" << endl;
    target.DecreaseHP(3);
}