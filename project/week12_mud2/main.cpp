#include <iostream>
#include <string>
#include <vector>
#include "user.h"


using namespace std; //cin에 입력이 들어가지 않는 문제가 있지만 비주얼 스튜디오에서는 잘 작동하는 것을 보니 인코딩의 문제로 추측합니다.

const int MAP_X = 5;
const int MAP_Y = 5;

// 사용자 정의 함수
bool CheckXY(int user_x, int map_x, int user_y, int map_y);
void DisplayMap(vector<vector<int>> map, int warrior_x, int warrior_y, int magician_x, int magician_y);
bool CheckGoal(vector<vector<int>> map, int user_x, int user_y);
void CheckState(vector<vector<int>> map, User& user, int user_x, int user_y);
bool CheckUser(User& user);

// 메인 함수
int main() {
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    int warrior_x = 0, warrior_y = 0;
    int magician_x = 1, magician_y = 0;

    Magician magician;
    Warrior warrior;

    User* current_user = &magician;

    while (true) {
        cout << "현재 플레이어: ";
        if (current_user == &magician) {
            cout << "Magician";
        }
        else {
            cout << "Warrior";
        }
        cout << endl;

        cout << "HP: " << current_user->GetHP()
            << "\n명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
        string user_input;
        cin >> user_input;

        int* current_x = (current_user == &warrior) ? &warrior_x : &magician_x;
        int* current_y = (current_user == &warrior) ? &warrior_y : &magician_y;

        int new_x = *current_x, new_y = *current_y;

        if (user_input == "상") new_y -= 1;
        else if (user_input == "하") new_y += 1;
        else if (user_input == "좌") new_x -= 1;
        else if (user_input == "우") new_x += 1;
        else if (user_input == "지도") {
            DisplayMap(map, warrior_x, warrior_y, magician_x, magician_y);
            continue;
        }
        else if (user_input == "info") {
            cout << *current_user << endl;
            continue;
        }
        else if (user_input == "공격") {
            if (current_user == &magician) {
                magician.DoAttack(warrior);
                cout << "Warrior의 HP: " << warrior.GetHP() << endl;
            }
            else {
                warrior.DoAttack(magician);
                cout << "Magician의 HP: " << magician.GetHP() << endl;
            }
        }
        else if (user_input == "종료") break;
        else {
            cout << "잘못된 입력입니다.\n";
            continue;
        }

        if (!CheckXY(new_x, MAP_X, new_y, MAP_Y)) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다.\n";
            continue;
        }

        *current_x = new_x;
        *current_y = new_y;
        current_user->DecreaseHP(1);
        CheckState(map, *current_user, *current_x, *current_y);

        if (!CheckUser(*current_user)) {
            cout << "HP가 0이 되어 사망했습니다.\n";
            break;
        }

        DisplayMap(map, warrior_x, warrior_y, magician_x, magician_y);

        if (CheckGoal(map, *current_x, *current_y)) {
            cout << "생존을 축하합니다! 게임을 종료합니다.\n";
            break;
        }

        if (current_user == &magician) {
            current_user = &warrior;
        }
        else {
            current_user = &magician;
        }

    }
    return 0;
}

// 지도와 사용자의 현 위치 출력
void DisplayMap(vector<vector<int>> map, int warrior_x, int warrior_y, int magician_x, int magician_y) {
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            if (i == warrior_y && j == warrior_x && i == magician_y && j == magician_x) {
                cout << " WM   |";
            }
            else if (i == warrior_y && j == warrior_x) {
                cout << "  W   |";
            }
            else if (i == magician_y && j == magician_x) {
                cout << "  M   |";
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
bool CheckXY(int x, int max_x, int y, int max_y) {
    return x >= 0 && x < max_x && y >= 0 && y < max_y;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool CheckGoal(vector<vector<int>> map, int x, int y) {
    return map[y][x] == 4;
}

// 현 위치의 기물 상황 체크
void CheckState(vector<vector<int>> map, User& user, int x, int y) {
    switch (map[y][x]) {
    case 1:
        cout << "쓸모 없는 아이템을 발견했습니다! 아무 일도 일어나지 않습니다!.\n";
        user.IncreaseItemCnt();
        break;
    case 2:
        cout << "적과 조우했습니다! 위협을 받아 HP가 2 감소합니다.\n";
        user.DecreaseHP(2);
        break;
    case 3:
        cout << "진귀한 포션을 발견했습니다. 포션을 복용해 HP가 2 증가합니다.\n";
        user.IncreaseHP(2);
        user.IncreaseItemCnt();
        break;
    }
}

bool CheckUser(User& user) {
    return user.GetHP() > 0;
}
