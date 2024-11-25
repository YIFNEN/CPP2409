#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

// User 인터페이스
class User {
public:
    virtual ~User() = default;
    virtual void IncreaseHP(int h_amount) = 0;
    virtual void DecreaseHP(int h_amount) = 0;
    virtual int GetHP() const = 0;
    virtual void IncreaseItemCnt() = 0;
    virtual void DoAttack(User& target) = 0;

    friend ostream& operator<<(ostream& os, const User& user) {
        user.PrintStatus(os);
        return os;
    }

protected:
    virtual void PrintStatus(ostream& os) const = 0;
};

// Magician 클래스 정의
class Magician : public User {
private:
    int hp;
    int item_cnt;

public:
    Magician();
    void IncreaseHP(int h_amount) override;
    void DecreaseHP(int h_amount) override;
    int GetHP() const override;
    void IncreaseItemCnt() override;
    void DoAttack(User& target) override;

protected:
    void PrintStatus(ostream& os) const override;
};

// Warrior 클래스 정의
class Warrior : public User {
private:
    int hp;
    int item_cnt;

public:
    Warrior();
    void IncreaseHP(int h_amount) override;
    void DecreaseHP(int h_amount) override;
    int GetHP() const override;
    void IncreaseItemCnt() override;
    void DoAttack(User& target) override;

protected:
    void PrintStatus(ostream& os) const override;
};

#endif
