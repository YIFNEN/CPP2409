#include <iostream>
using namespace std;

class Time{
private:
    int hour;
    int minute;

public:
    Time(int h, int m);
    void Print(){
        cout << hour << ":" << minute <<endl;
    }

    int GetHour(){
        return hour;
    }
    int Getminute(){
        return minute;
    }
    void SetHour(int h){ hour = h;}
    void SetMinute(int m){minute = m;}
};


Time::Time(int h, int m) { // 외부작성
hour = h;
minute = m;
}


int main(){
    Time a(0,0);
    a.SetHour(6);
    a.SetMinute(30);
    a.Print();
    return 0;
}

