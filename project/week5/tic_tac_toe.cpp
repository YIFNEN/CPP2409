#include<iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x;
    int y;//사용자 입력 좌표 저장

    //보드판 초기화

    for(int i = 0; i < numCell; i++) {
         for(int k = 0; k < numCell; k++){
            board[i][k] = ' ';
         }
         }
    
    int k = 0; // 1.누구 차례인지 체크하기 위한 변수
    char currentUser = 'X';
    
    //게임 시작

    while(true){

        // 차례 확인 인원수 변동시 변동
        switch(k % 2){
        case 0:{
            cout << "첫번째 유저(X)의 차례입니다";
            currentUser = 'X';
            break;
        }

         case 1:{
            cout << "두번째 유저(Y)의 차례입니다";
            currentUser = 'O';
            break;
        }
        }

        //2.좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin>> x >> y;

        //3. 좌표 유효성 체크
        if (x >= numCell || y >= numCell){
            cout << x << ", " << y << ":";
            cout <<"x와 y 둘 중 하나가 칸을 벗어납니다" << endl;
            continue;
        }
        if(board[x][y] != ' '){
            cout << x << ", "<< y << ": 이미 돌이 차있습니다" << endl;
            continue;
        }
        //4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

    //5. 현재 보드 판 출력
    for (int i = 0; i < numCell; i++){
        cout << "---|---|---"<< endl;
        for(int j = 0; j < numCell; j++){
            cout << board[i][j];
            if(j == numCell - 1){
                break;
            }
            cout << "  |";
        }
        cout << endl;
    }
    cout << "---|---|---" << endl;
    k++;

    //6. 승리조건 판별
    bool isWin = false;
    char symbol[3] = {'X', 'O'};//모든 사용자에 대해 승리 조건 충족 확인 및 승리시 루프 탈출

    for (char n : symbol){
        for(int i = 0; i < numCell; i++){
        if(board[i][0]== n && board[i][1]== n && board[i][2]== n){ // 가로 승리
        cout<< "user "<< n <<" 이 승리했습니다!";
        isWin = true;
        break;
        }
        else if(board[0][i]== n && board[1][i]== n && board[2][i]== n){// 세로 승리
        cout<< "user "<< n <<" 이 승리했습니다!";
        isWin = true;
        break;
        }
        }
        if(board[0][0]== n && board[1][1]== n && board[2][2]== n){ // \대각선 승리 
        cout<< "user "<< n <<" 이 승리했습니다!";
        isWin = true;
        break;
        }
        else if(board[0][2]== n && board[1][1]== n && board[2][0]== n){// /대각선 승리
        cout<< "user "<< n <<" 이 승리했습니다!";
        isWin = true;
        break;
        }
    }
    if (isWin){// 승리 후 종료
        break;
    }
    

    //7. 다 찼을 경우 종료 판별
    int endcount = 0;

    for (int i = 0; i < numCell; i++){
        for(int j = 0; j < numCell; j++){
            if(board[i][j] != ' '){
                endcount++;
            }
        }
        }

    if(endcount == (numCell)*(numCell)){
        cout << "모든칸이 다 찼습니다. 종료합니다" << endl;
        break;
    }

    }
    return 0;
}