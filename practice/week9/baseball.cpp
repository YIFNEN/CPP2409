#include <iostream>
#include <string>
using namespace std;

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수
	bool same = false;//숫자가 서로 다른지 확인하는 변수

	while (1) {
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성
		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		string numStr = to_string(randomNum);
		//자릿수 추출
		firstNum = (int)numStr[0];
		secondNum = (int)numStr[1];
		thirdNum = (int)numStr[2];

		// 모든 자리의 숫자가 다를 경우 루프 종료
		if ((firstNum != secondNum) && (secondNum != thirdNum) && (firstNum != thirdNum)) {
			same = true;
		}
		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수



		while (1) {
			// 사용자에게 세자리 수를 입력받는 코드 블록
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;
			same = false; // 모든 수가 다를 경우 true를 갖는 변수

			// 입력이 3자리 수인지 확인
			if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
			//  모든 자릿수가 다른지 확인
			string unumStr = to_string(userNumber);
			guessFirst = (int)unumStr[0];
			guessSecond = (int)unumStr[1];
			guessThird = (int)unumStr[2];
			if ((guessFirst != guessSecond) && (guessSecond != guessThird) && (guessFirst != guessThird)) {
				same = true; // 모든 숫자가 다르면 루프 종료
			}
			else {
				cout << "입력된 숫자에 중복 숫자가 있습니다. 다시 입력하세요." << endl;

			}

			if (same == true) {
				break;
			}
		}
		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		int guess[] = { guessFirst, guessSecond, guessThird };
		int answer[] = { firstNum, secondNum, thirdNum };
		// 사용자 입력을 정답과 비교
		for (int i = 0; i < 3; i++) {
			if (guess[i] == answer[i]) {
				strike++;
			}
			else if (guess[i] == answer[0] || guess[i] == answer[1] || guess[i] == answer[2]) {
				ball++;


			}
		}


		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성

		  // 스트라이크가 3개면 축하 메세지 출력 후 종료
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1; // 시도 횟수 증가

	}



	return 0;
}
