#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

// User 인터페이스 정의: 사용자 역할의 기본 클래스로, 
// HP 증가/감소, 공격 등의 행동을 위한 순수 가상 함수 선언
class User {
public:
    virtual ~User() = default;

    // HP 증가 함수
    virtual void IncreaseHP(int h_amount) = 0;

    // HP 감소 함수
    virtual void DecreaseHP(int h_amount) = 0;

    // 현재 HP를 반환하는 함수
    virtual int GetHP() const = 0;

    // 아이템 수 증가 함수
    virtual void IncreaseItemCnt() = 0;

    // 대상에게 공격을 가하는 함수
    virtual void DoAttack(User& target) = 0;

    // 출력 연산자 오버로딩: 사용자 상태 출력
    friend ostream& operator<<(ostream& os, const User& user) {
        user.PrintStatus(os);
        return os;
    }

protected:
    // 사용자 상태를 출력하는 순수 가상 함수
    virtual void PrintStatus(ostream& os) const = 0;
};

// Magician 클래스 정의: User 인터페이스를 구현
class Magician : public User {
private:
    int hp;        // HP 값
    int item_cnt;  // 아이템 개수

public:
    Magician(); // 생성자
    void IncreaseHP(int h_amount) override; // HP 증가
    void DecreaseHP(int h_amount) override; // HP 감소
    int GetHP() const override;             // 현재 HP 반환
    void IncreaseItemCnt() override;        // 아이템 수 증가
    void DoAttack(User& target) override;   // 공격 행동

protected:
    void PrintStatus(ostream& os) const override; // 상태 출력
};

// Warrior 클래스 정의: User 인터페이스를 구현
class Warrior : public User {
private:
    int hp;        // HP 값
    int item_cnt;  // 아이템 개수

public:
    Warrior(); // 생성자
    void IncreaseHP(int h_amount) override; // HP 증가
    void DecreaseHP(int h_amount) override; // HP 감소
    int GetHP() const override;             // 현재 HP 반환
    void IncreaseItemCnt() override;        // 아이템 수 증가
    void DoAttack(User& target) override;   // 공격 행동

protected:
    void PrintStatus(ostream& os) const override; // 상태 출력
};

#endif
