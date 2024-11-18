#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User {
    private:
        int hp, itemCnt;

    public:                  
        User();
        void IncreaseHP(int Hamount);
        void DecreaseHP(int Hamount);
        int GetHP();
        void IncreaseitemCnt();
        friend ostream& operator<<(ostream& os, const User& v){
         os << "(현재 HP는 {" << v.hp << "}이고, 먹은 아이템은 총{" << v.itemCnt << "}개 입니다." << endl;
return os;   
        }
       
};


#endif
