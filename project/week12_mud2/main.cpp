#include <iostream>
#include <string>
#include <vector>
#include "user.h"


using namespace std; //cin에 입력이 들어가지 않는 문제가 있지만 비주얼 스튜디오에서는 잘 작동하는 것을 보니 인코딩의 문제로 추측합니다.

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
void checkState(vector<vector<int>> map, User& user, int user_x, int user_y);
bool CheckUser(User & user);

// 메인 함수
int main() {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    /*   int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                 {1, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0},
                    {0, 2, 3, 0, 0},
                    {3, 0, 0, 0, 2} };*/
    vector<vector<int>> map = { {0, 1, 2, 0, 4},
                    {1, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0},
                    {0, 2, 3, 0, 0},
                    {3, 0, 0, 0, 2} };


    // 유저의 위치를 저장할 변수
    int user_x = 0; // 가로 번호
    int user_y = 0; // 세로 번호
    User user;

    while (1) {
        //사용자에게 계속 입력받으며 루프
        cout << "HP: " << user.GetHP()<< "\n명령어를 입력하세요 (상,하,좌,우,지도,info,종료): ";
        string user_input;
        cin >> user_input;// 사용자의 입력 저장
      


        int new_x = user_x, new_y = user_y; // new_x, new_y에 기존 좌표 저장

        if (user_input == "상") new_y -= 1; // 위로 한 칸 이동
        else if (user_input == "하") new_y += 1; // 아래로 한 칸 이동
        else if (user_input == "좌") new_x -= 1; // 왼쪽으로 한 칸 이동
        else if (user_input == "우") new_x += 1;// 오른쪽으로 한 칸 이동
        else if (user_input == "지도") {// 지도 펼치기
            displayMap(map, user_x, user_y);
            continue;
        }

        else if(user_input == "info"){ //정보 명령어 추가
            cout<< user << endl;
            continue;
        }
        else if (user_input == "종료") break;
        else {
            cout << "잘못된 입력입니다.\n";
            continue;
        }

        // 좌표 유효성 체크
        if (!checkXY(new_x, mapX, new_y, mapY)) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다.\n";
            continue;
        }

        // 유효성 체크 후 유저 좌표에 반영하며 HP 감소
        user_x = new_x;
        user_y = new_y;
        user.DecreaseHP(1);  // 이동에 따른 HP 감소 반영
        checkState(map, user, user_x, user_y); // 이동한 위치의 효과에 따른 HP 반영 함수 호출

        // HP 0일 시 실패 메세지 출력 후 게임 종료
        if (CheckUser(user) != true) {
            cout << "HP가 0이 되어 사망했습니다.\n";
            break;
        }

        // 지도 보여주기 함수 호출
        displayMap(map, user_x, user_y);

        // 목적지 도달했는데 체크 함수 호출
        if (checkGoal(map, user_x, user_y)) {
            cout << " 생존을 축하합니다! 게임을 종료합니다.\n";
            break;
        }
    }
    return 0;
}

// 지도와 사용자의 현 위치 출력
void displayMap(vector<vector<int>> map, int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            }
            else {
                switch (map[i][j]) {
                case 0: cout << "      |"; break;
                case 1: cout << "아이템|"; break;
                case 2: cout << "  적  |"; break;
                case 3: cout << " 포션 |"; break;
                case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << "\n--------------------------------\n";
    }
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int x, int maxX, int y, int maxY) {
    bool checkFlag = false;
    if (x >= 0 && x < maxX && y >= 0 && y < maxY) {
        checkFlag = true;
    }
    return checkFlag;

}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>> map, int x, int y) {
    // 목적지 도착하면
    if (map[y][x] == 4) {
        return true;
    }
    return false;
}

// 현 위치의 기물 상황 체크하고, 각 경우별로 HP 갱신 함수
void checkState(vector<vector<int>> map, User& user, int x, int y) {
    switch (map[y][x]) {
    case 1: 
        cout << "쓸모 없는 아이템을 발견했습니다! 아무 일도 일어나지 않습니다!.\n"; 
        user.IncreaseitemCnt();
        break;
    case 2:
        cout << "적과 조우했습니다! 위협을 받아 HP가 2 감소합니다.\n";
        user.DecreaseHP(2);
        break;
    case 3:
        cout << "진귀한 포션을 발견했습니다. 포션을 복용해 HP가 2 증가합니다.\n";
        user.IncreaseHP(2);
        user.IncreaseitemCnt();
        break;
    }   
}

bool CheckUser(User & user){
    return(user.GetHP() > 0);
}
