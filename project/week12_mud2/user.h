#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User {
private:
    int hp, item_cnt; // snake_case 적용

public:
    User();
    virtual ~User() = default;
    void IncreaseHP(int h_amount);
    void DecreaseHP(int h_amount);
    int GetHP();
    void IncreaseItemCnt();
    virtual void DoAttack(User& target);

    friend ostream& operator<<(ostream& os, const User& v) {
        os << "(현재 HP는 {" << v.hp << "}이고, 먹은 아이템은 총{" << v.item_cnt << "}개 입니다.)" << endl;
        return os;
    }
};

// Magician 클래스 정의
class Magician : public User {
public:
    void DoAttack(User& target) override; // 마법 공격
};

// Warrior 클래스 정의
class Warrior : public User {
public:
    void DoAttack(User& target) override; // 검 공격
};

#endif
