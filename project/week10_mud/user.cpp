#include "user.h"

User::User(){ //생성자에서 체력을 20으로 초기화
    hp = 20;
    }
void User:: IncreaseHP(int Hamount){
    hp += Hamount;
}
void User:: DecreaseHP(int Hamount){
    hp -= Hamount;
}
int User:: GetHP(){
    return hp;
}