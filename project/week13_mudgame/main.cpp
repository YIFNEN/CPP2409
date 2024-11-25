#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

const int MAP_X = 5;
const int MAP_Y = 5;

bool CheckXY(int user_x, int map_x, int user_y, int map_y);
void DisplayMap(vector<vector<int>> map, int user_x, int user_y);
bool CheckGoal(vector<vector<int>> map, int user_x, int user_y);
void CheckState(vector<vector<int>> map, User& user, int user_x, int user_y);
bool CheckUser(User& user);

int main() {
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    int user_x = 0, user_y = 0;

    // 직업 선택
    User* current_user = nullptr;
    cout << "직업을 선택하세요 (1: Magician, 2: Warrior): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        current_user = new Magician();
    }
    else if (choice == 2) {
        current_user = new Warrior();
    }
    else {
        cout << "잘못된 선택입니다. 종료합니다." << endl;
        return 0;
    }

    while (true) {
        cout << "현재 플레이어 상태: " << *current_user << endl;

        cout << "명령어를 입력하세요 (상,하,좌,우,지도,info, 종료): ";
        string user_input;
        cin >> user_input;

        int new_x = user_x, new_y = user_y;

        if (user_input == "상") new_y -= 1;
        else if (user_input == "하") new_y += 1;
        else if (user_input == "좌") new_x -= 1;
        else if (user_input == "우") new_x += 1;
        else if (user_input == "지도") {
            DisplayMap(map, user_x, user_y);
            continue;
        }
        else if (user_input == "info") {
            cout << *current_user << endl;
            continue;
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

        user_x = new_x;
        user_y = new_y;
        current_user->DecreaseHP(1);
        CheckState(map, *current_user, user_x, user_y);

        if (!CheckUser(*current_user)) {
            cout << "HP가 0이 되어 사망했습니다. 게임 종료.\n";
            break;
        }

        DisplayMap(map, user_x, user_y);

        if (CheckGoal(map, user_x, user_y)) {
            cout << "목적지에 도달했습니다! 게임을 종료합니다.\n";
            break;
        }
    }

    delete current_user;
    return 0;
}

// 지도 출력
void DisplayMap(vector<vector<int>> map, int user_x, int user_y) {
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            if (i == user_y && j == user_x) {
                cout << "  U   |";
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

bool CheckXY(int x, int max_x, int y, int max_y) {
    return x >= 0 && x < max_x && y >= 0 && y < max_y;
}

bool CheckGoal(vector<vector<int>> map, int x, int y) {
    return map[y][x] == 4;
}

void CheckState(vector<vector<int>> map, User& user, int x, int y) {
    switch (map[y][x]) {
    case 1:
        cout << "아이템 발견! 아무 일도 일어나지 않습니다.\n";
        user.IncreaseItemCnt();
        break;
    case 2:
        cout << "적과 조우했습니다! HP가 2 감소합니다.\n";
        user.DecreaseHP(2);
        break;
    case 3:
        cout << "포션을 발견했습니다. HP가 2 증가합니다.\n";
        user.IncreaseHP(2);
        user.IncreaseItemCnt();
        break;
    }
}

bool CheckUser(User& user) {
    return user.GetHP() > 0;
}
