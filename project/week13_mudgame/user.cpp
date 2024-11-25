#include "user.h"
#include <iostream>
using namespace std;

// Magician 구현
Magician::Magician() : hp(20), item_cnt(0) {}

void Magician::IncreaseHP(int h_amount) {
    hp += h_amount;
}

void Magician::DecreaseHP(int h_amount) {
    hp -= h_amount;
}

int Magician::GetHP() const {
    return hp;
}

void Magician::IncreaseItemCnt() {
    item_cnt++;
}

void Magician::DoAttack(User& target) {
    cout << "마법 공격! (데미지: 3)" << endl;
    target.DecreaseHP(3);
}

void Magician::PrintStatus(ostream& os) const {
    os << "(현재 HP: " << hp << ", 아이템 수: " << item_cnt << ")";
}

// Warrior 구현
Warrior::Warrior() : hp(20), item_cnt(0) {}

void Warrior::IncreaseHP(int h_amount) {
    hp += h_amount;
}

void Warrior::DecreaseHP(int h_amount) {
    hp -= h_amount;
}

int Warrior::GetHP() const {
    return hp;
}

void Warrior::IncreaseItemCnt() {
    item_cnt++;
}

void Warrior::DoAttack(User& target) {
    cout << "검 공격! (데미지: 3)" << endl;
    target.DecreaseHP(3);
}

void Warrior::PrintStatus(ostream& os) const {
    os << "(현재 HP: " << hp << ", 아이템 수: " << item_cnt << ")";
}
