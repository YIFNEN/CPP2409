#include<iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];
    int maxages[maxPeople];
    int minages[maxPeople];
    


    cout << maxPeople << "명의 회원 정보를 입력해주세요" << endl;
    for (int i = 0; i< maxPeople; i++){
        cout << "사람" << i+1 <<"의 이름: ";
        cin >> names[i];
        cout << "사람" << i+1 <<"의 나이: ";
        cin >> ages[i];        
    }

    while(true){
        int j = 0; int k =0;
        int choice;
        cout << "메뉴를 선택하세요: 1. 연장자 출력 2. 가장 젊은이 출력 3. 종료 ";
        cin >> choice;

        if (choice == 3){
            break;
        }

        int max = 0; //연장자 찾기
             for (int i = 1; i< maxPeople; i++){
                if(ages[i] > ages[max]){
                    max = i;
                }
             }

        int min = 0; //막내 찾기
             for (int i = 1; i< maxPeople; i++){
                if(ages[i] < ages[min]){
                    min = i;
                }
             }
             // 막내 연장자 인덱스 저장
        for (int i = 0; i< maxPeople; i++){    
            if(ages[i] == ages[max]){
                maxages[j] = i ;
                j++;                
            }
            if(ages[i] == ages[min]){
                minages[k] = i ;
                k++;                
            }
        }


        switch(choice)
        {
        case 1 :
        {cout << "연장자 출력을 선택했습니다. " << endl;
         //cout << "연장자: "<<  names[max] << endl;
         for (int i = 0; i < j; i++){
                        cout << "연장자:" << i << names[maxages[i]] << endl;
         }
         break;
        }

        case 2 :
        {cout << "막내 출력을 선택했습니다. " << endl;
         //cout << "막내: "<<  names[min] << endl;
         for (int i = 0; i < k; i++){

            cout << "막내:" << i << names[minages[i]] << endl;
         }
         break;
        }

        case 3 :
        {cout << "프로그램을 종료합니다. " << endl;
         break;
        }

        default :
        {cout << "잘못된 선택입니다. " << endl;
         break;
        }
        }
    }


    return 0;
}

