#include "user.h"
#include <iostream>
using namespace std;

// Magician 클래스의 생성자: HP를 20으로 초기화, 아이템 개수를 0으로 설정
Magician::Magician() : hp(20), item_cnt(0) {}

// HP 증가 함수
void Magician::IncreaseHP(int h_amount) {
    hp += h_amount;
}

// HP 감소 함수
void Magician::DecreaseHP(int h_amount) {
    hp -= h_amount;
}

// 현재 HP 반환 함수
int Magician::GetHP() const {
    return hp;
}

// 아이템 수 증가 함수
void Magician::IncreaseItemCnt() {
    item_cnt++;
}

// 공격 행동: 대상에게 3의 데미지를 가함
void Magician::DoAttack(User& target) {
    cout << "마법 공격! (데미지: 3)" << endl;
    target.DecreaseHP(3);
}

// 상태 출력 함수
void Magician::PrintStatus(ostream& os) const {
    os << "(현재 HP: " << hp << ", 아이템 수: " << item_cnt << ")";
}

// Warrior 클래스의 생성자: HP를 20으로 초기화, 아이템 개수를 0으로 설정
Warrior::Warrior() : hp(20), item_cnt(0) {}

// HP 증가 함수
void Warrior::IncreaseHP(int h_amount) {
    hp += h_amount;
}

// HP 감소 함수
void Warrior::DecreaseHP(int h_amount) {
    hp -= h_amount;
}

// 현재 HP 반환 함수
int Warrior::GetHP() const {
    return hp;
}

// 아이템 수 증가 함수
void Warrior::IncreaseItemCnt() {
    item_cnt++;
}

// 공격 행동: 대상에게 3의 데미지를 가함
void Warrior::DoAttack(User& target) {
    cout << "검 공격! (데미지: 3)" << endl;
    target.DecreaseHP(3);
}

// 상태 출력 함수
void Warrior::PrintStatus(ostream& os) const {
    os << "(현재 HP: " << hp << ", 아이템 수: " << item_cnt << ")";
}
