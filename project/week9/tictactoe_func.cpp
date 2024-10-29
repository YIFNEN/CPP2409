#include <iostream>
using namespace std;
const int numCell = 3; // 보드판의 가로 세로 길이
char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열

int isValid(int x, int y) {//좌표의 유효성을 확인하는 함수
	int checkinvalid = 1;
	if (x >= numCell || y >= numCell || x < 0 || y < 0) {// 좌표 범위를 벗어날때
		cout << x << ", " << y << ": x와 y 둘 중 하나가 칸을 벗어납니다" << endl;
		checkinvalid = 0;
	}

	if (board[x][y] != ' ') { // 좌표범위의 입력값이 중복될때
		cout << x << ", " << y << ": 이미 돌이 차있습니다" << endl;
		checkinvalid = 0;
	}

	return checkinvalid;// 유효하다면 1, 유효하지 않다면 0 반환
}

int checkWin(char currentUser) { // 승리 조건을 확인하는 함수
	char n = currentUser; //현재 플레이어 받는 변수
	int Win = 0;
	int winCount = 0; //대각선 확인 카운트
	int winCountR = 0;//역대각선 확인 카운트

	for (int i = 0; i < numCell; i++) {
		if (board[i][0] == n && board[i][1] == n && board[i][2] == n) { // 가로 승리
			cout << "가로에 모두 돌이 놓였습니다!!";
			Win = 1;              //모든 승리 조건을 출력하기 위해 break를 쓰지 않음
		}
		if (board[0][i] == n && board[1][i] == n && board[2][i] == n) { // 세로 승리
			cout << "세로에 모두 돌이 놓였습니다!!";
			Win = 1;
		}
	}

	for (int i = 0; i < numCell; i++) {
		if (board[i][i] == currentUser) { // numCell의 사이즈만큼 순회하며 대각선 좌표에 얼마나 현재 플레이어의 돌이 놓였는지 확인 
			winCount += 1;
			if (winCount == numCell) {
				cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
				Win = 1;
			}
		}
		if (board[i][numCell - 1 - i] == currentUser) {//numCell의 사이즈만큼 순회하며 역대각선 좌표에 얼마나 현재 플레이어의 돌이 놓였는지 확인 
			winCountR += 1;
			if (winCountR == numCell) {
				cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
				Win = 1;
			}
		}
	}
	return Win; // 조건을 하나라도 만족했다면 1 반환
}

int main() {
	// 게임을 진행하는 데 필요한 변수 선언


	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:
			currentUser = 'O';
			break;
		case 2:
			cout << "세번째 유저(H)의 차례입니다";
			currentUser = 'H';
			break;
		}

		cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";


		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		if (isValid(x, y) == 1) {
			board[x][y] = currentUser;
		}
		else {
			continue;
		}

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i = 0; i < numCell; i++) {
			for (int k = 0; k < numCell - 1; k++)
			{
				cout << "---|"; //가로줄 작업
			}
			cout << "---" << endl; //가로줄 마무리

			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |"; //세로줄 numCell -1개 출력
			}
			cout << endl;
		}





		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
		// 6.1. 가로/세로 돌 체크하기



		// 6.2. 대각선을 체크하기
		// TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
		// HINT: for 문


		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (checkWin(currentUser)) { // 승리 여부
			cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}