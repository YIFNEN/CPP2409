#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
int hp = 20; // ü�� 20���� ����
// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int& hp, int user_x, int user_y);

// ���� �Լ�
int main() {
    // 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                    {1, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0},
                    {0, 2, 3, 0, 0},
                    {3, 0, 0, 0, 2} };


    // ������ ��ġ�� ������ ����
    int user_x = 0; // ���� ��ȣ
    int user_y = 0; // ���� ��ȣ

    while (1) {
        //����ڿ��� ��� �Է¹����� ����
        cout << "HP: " << hp << "\n��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
        string user_input = "";
        cin >> user_input;// ������� �Է� ����

        int new_x = user_x, new_y = user_y; // new_x, new_y�� ���� ��ǥ ����

        if (user_input == "��") new_y -= 1; // ���� �� ĭ �̵�
        else if (user_input == "��") new_y += 1; // �Ʒ��� �� ĭ �̵�
        else if (user_input == "��") new_x -= 1; // �������� �� ĭ �̵�
        else if (user_input == "��") new_x += 1;// ���������� �� ĭ �̵�
        else if (user_input == "����") {// ���� ��ġ��
            displayMap(map, user_x, user_y);
            continue;
        }
        else if (user_input == "����") break;
        else {
            cout << "�߸��� �Է��Դϴ�.\n";
            continue;
        }

        // ��ǥ ��ȿ�� üũ
        if (!checkXY(new_x, mapX, new_y, mapY)) {
            cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�.\n";
            continue;
        }

        // ��ȿ�� üũ �� ���� ��ǥ�� �ݿ��ϸ� HP ����
        user_x = new_x;
        user_y = new_y;
        hp -= 1;  // �̵��� ���� HP ���� �ݿ�
        checkState(map, hp, user_x, user_y); // �̵��� ��ġ�� ȿ���� ���� HP �ݿ� �Լ� ȣ��

        // HP 0�� �� ���� �޼��� ��� �� ���� ����
        if (hp <= 0) {
            cout << "HP�� 0�� �Ǿ� ����߽��ϴ�.\n";
            break;
        }

        // ���� �����ֱ� �Լ� ȣ��
        displayMap(map, user_x, user_y);

        // ������ �����ߴµ� üũ �Լ� ȣ��
        if (checkGoal(map, user_x, user_y)) {
            cout << " ������ �����մϴ�! ������ �����մϴ�.\n";
            break;
        }
    }
    return 0;
}

// ������ ������� �� ��ġ ���
void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            }
            else {
                switch (map[i][j]) {
                case 0: cout << "      |"; break;
                case 1: cout << "������|"; break;
                case 2: cout << "  ��  |"; break;
                case 3: cout << " ���� |"; break;
                case 4: cout << "������|"; break;
                }
            }
        }
        cout << "\n--------------------------------\n";
    }
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int x, int maxX, int y, int maxY) {
    bool checkFlag = false;
    if (x >= 0 && x < maxX && y >= 0 && y < maxY) {
        checkFlag = true;
    }
    return checkFlag;

}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int x, int y) {
    // ������ �����ϸ�
    if (map[y][x] == 4) {
        return true;
    }
    return false;
}

// �� ��ġ�� �⹰ ��Ȳ üũ�ϰ�, �� ��캰�� HP ���� �Լ�
void checkState(int map[][mapX], int& hp, int x, int y) {
    switch (map[y][x]) {
    case 1: cout << "���� ���� �������� �߰��߽��ϴ�! �ƹ� �ϵ� �Ͼ�� �ʽ��ϴ�!.\n"; break;
    case 2:
        cout << "���� �����߽��ϴ�! ������ �޾� HP�� 2 �����մϴ�.\n";
        hp -= 2;
        break;
    case 3:
        cout << "������ ������ �߰��߽��ϴ�. ������ ������ HP�� 2 �����մϴ�.\n";
        hp += 2;
        break;
    }
}
