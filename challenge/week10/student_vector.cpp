#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> v;
    int score;
    int studentnum = 0;
    double sum = 0;

    while(true){
        cout << "성적을 입력하시오(종료는 -1) :" ;
        cin >> score;
        if(score == -1){
            break;
        }
      
         v.push_back(score);
       
    }
    for (auto& e : v){
        sum += e;
        studentnum++; 
    }

   
    cout <<"성적 평균 = " << (double)sum / v.size() ;
    cout << endl; 
    return 0;
    }
    
    




