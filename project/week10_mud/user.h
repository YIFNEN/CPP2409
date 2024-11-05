#ifndef USER_H
#define USER_H

class User {
    private:
        int hp;

    public:                  
        User();
        void IncreaseHP(int Hamount);
        void DecreaseHP(int Hamount);
        int GetHP();    
};


#endif
