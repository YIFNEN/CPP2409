#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "user.h"

using namespace std;

const int MAP_X = 5;
const int MAP_Y = 5;

bool CheckXY(int user_x, int map_x, int user_y, int map_y);
void DisplayMap(vector<vector<int>> map, int user_x, int user_y);
bool CheckGoal(vector<vector<int>> map, int user_x, int user_y);
void CheckState(vector<vector<int>> map, User& user, int user_x, int user_y);
bool CheckUser(User& user);



// 맵을 파일에서 읽어오는 함수
vector<vector<int>> LoadMapFromFile(const string& filename) {
    vector<vector<int>> map;
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("파일을 열 수 없습니다: " + filename);
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> row;
        int value;
        while (ss >> value) {
            row.push_back(value);
        }

        // 각 행의 길이가 같지 않으면 오류 처리
        if (!map.empty() && row.size() != map[0].size()) {
            throw runtime_error("맵 데이터 형식이 잘못되었습니다.");
        }

        map.push_back(row);
    }

    // 맵이 비어 있거나 잘못된 형식인 경우 오류 처리
    if (map.empty()) {
        throw runtime_error("맵 데이터가 비어 있거나 잘못되었습니다.");
    }

    return map;
}
int main() {
    vector<vector<int>> map;
    try {
        map = LoadMapFromFile("map.txt");
    }
    catch (const exception& e) {
        cerr << "오류: " << e.what() << endl;
        return 1;
    }

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
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "user.h"

using namespace std;


// 함수 선언
bool CheckXY(int user_x, int map_x, int user_y, int map_y);
void DisplayMap(vector<vector<int>> map, int user_x, int user_y);
bool CheckGoal(vector<vector<int>> map, int user_x, int user_y);
void CheckState(vector<vector<int>> map, User& user, int user_x, int user_y);
bool CheckUser(User& user);

// 맵을 파일에서 읽어오는 함수
vector<vector<int>> LoadMapFromFile(const string& filename) {
    vector<vector<int>> map;
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("파일을 열 수 없습니다: " + filename);
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> row;
        int value;

        // 한 줄씩 값을 읽어와 벡터에 추가
        while (ss >> value) {
            row.push_back(value);
        }

        // 모든 행의 길이가 동일한지 확인
        if (!map.empty() && row.size() != map[0].size()) {
            throw runtime_error("맵 데이터 형식이 잘못되었습니다.");
        }

        map.push_back(row);
    }

    // 맵 데이터가 유효한지 확인
    if (map.empty()) {
        throw runtime_error("맵 데이터가 비어 있거나 잘못되었습니다.");
    }

    return map;
}

// 메인 함수
int main() {
    vector<vector<int>> map;

    // 맵 로드 시 예외 처리
    try {
        map = LoadMapFromFile("map.txt");
    }
    catch (const exception& e) {
        cerr << "오류: " << e.what() << endl;
        return 1;
    }

    int map_rows = map.size();           // 맵의 행 크기
    int map_cols = map[0].size();        // 맵의 열 크기
    int user_x = 0, user_y = 0; // 플레이어 초기 위치

    // 직업 선택
    User* current_user = nullptr;
    cout << "직업을 선택하세요 (1: Magician, 2: Warrior): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        current_user = new Magician(); // Magician 객체 생성
    }
    else if (choice == 2) {
        current_user = new Warrior(); // Warrior 객체 생성
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

        // 입력에 따른 이동 처리
        if (user_input == "상") new_y -= 1;
        else if (user_input == "하") new_y += 1;
        else if (user_input == "좌") new_x -= 1;
        else if (user_input == "우") new_x += 1;
        else if (user_input == "지도") {
            DisplayMap(map, user_x, user_y); // 현재 지도 출력
            continue;
        }
        else if (user_input == "info") {
            cout << *current_user << endl; // 플레이어 상태 출력
            continue;
        }
        else if (user_input == "종료") break;
        else {
            cout << "잘못된 입력입니다.\n";
            continue;
        }

        // 맵 범위를 벗어나는지 확인
        if (!CheckXY(new_x, map_cols, new_y, map_rows)) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다.\n";
            continue;
        }

        // 이동 후 상태 업데이트
        user_x = new_x;
        user_y = new_y;

        // 이동 시 HP 감소
        current_user->DecreaseHP(1);
        CheckState(map, *current_user, user_x, user_y);

        // HP 확인: 0 이하이면 게임 종료
        if (!CheckUser(*current_user)) {
            cout << "HP가 0이 되어 사망했습니다. 게임 종료.\n";
            break;
        }

        DisplayMap(map, user_x, user_y); // 갱신된 지도 출력

        // 목적지 도달 여부 확인
        if (CheckGoal(map, user_x, user_y)) {
            cout << "목적지에 도달했습니다! 게임을 종료합니다.\n";
            break;
        }
    }

    delete current_user; // 동적 메모리 해제
    return 0;
}

// 맵 출력 함수
void DisplayMap(vector<vector<int>> map, int user_x, int user_y) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (i == user_y && j == user_x) {
                cout << "  U   |"; // 플레이어 위치
            }
            else {
                switch (map[i][j]) {
                case 0: cout << "      |"; break;      // 빈 공간
                case 1: cout << "아이템|"; break;      // 아이템
                case 2: cout << "  적  |"; break;      // 적
                case 3: cout << " 포션 |"; break;      // 포션
                case 4: cout << "목적지|"; break;      // 목적지
                }
            }
        }
        cout << "\n--------------------------------\n";
    }
}

// 맵 범위 확인 함수
bool CheckXY(int x, int max_x, int y, int max_y) {
    return x >= 0 && x < max_x && y >= 0 && y < max_y;
}

// 목적지 확인 함수
bool CheckGoal(vector<vector<int>> map, int x, int y) {
    return map[y][x] == 4; // 4는 목적지
}

// 현재 위치의 상태 확인
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

// 플레이어 생존 확인
bool CheckUser(User& user) {
    return user.GetHP() > 0; // HP가 0보다 크면 생존
}

bool CheckUser(User& user) {
    return user.GetHP() > 0;
}
