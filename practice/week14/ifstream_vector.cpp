#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TemptData{
    public:
    int hour;
    double temperature;
};

int main()
{
    ifstream is {"temp.txt"};
    if(!is){
        cerr << "파일 오픈에 실패하였습니다" << endl;
        exit(1);
    }
    vector <TemptData> temps;
    int hour;
    double temperature;

    while(is >> hour >> temperature){ // 두 덩어리로 나누어 저장
        temps.push_back(TemptData{hour, temperature});
        }// 파일 데이터 변수에 저장

        for(TemptData t : temps){
        cout << t.hour << "시 : 온도 " << t.temperature << endl;
        }

   return 0;
}