#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>board(4,vector<int>(4,0));
bool win = false,lose = false;
void printboard(){
    for(int i = 0;i<4;i++){
        cout << "\n";
        for(int j = 0;j<4;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
bool valcheck(string val){
    int i = val[0] - '0',ii = val[1] - '0',num = val[2] - '0';
    if(i >= 0 && i <= 3 && ii >= 0 && ii <= 3 && num >= 1 && num <= 4){
        if(board[i][ii] == 0){
            board[i][ii] = num;
        }
        else{
            cout << "The index is already filled\n";
            return false;
        }
        return true;
    }
    return false;
}
bool minisudoku(){
    for(int i = 0;i<4;i++){
        vector<int>s(5,0);
        for(int j = 0;j<4;j++){
            if(board[i][j]){
                s[board[i][j]]++;
                if(s[board[i][j]] > 1){
                    lose = true;
                    cout << "You filled the wrong value\n";
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    board[0][0] = 1;
    board[0][3] = 4;
    board[1][1] = 2;
    board[1][2] = 3;
    board[2][1] = 4;
    board[2][2] = 1;
    board[3][0] = 3;
    board[3][3] = 2;
    cout << "Print initial sudoku board\n";
    printboard();
    cout << "Lets lay out intial rules of the game\n";
    cout << "Each row and col contains unique elements\n";
    cout << "To enter any value in any empty cell place the cells address as 10 or 20 followed by the value 4,i.e. the value at the index 104.\n104 places in the second row first cell 4.\n";

    // _________________________
    // |    1|     |     |    4|
    // |_____|_____|_____|_____|
    // |     |   2 |    3|     |
    // |_____|_____|_____|_____|
    // |     |   4 |    1|     |
    // |_____|_____|_____|_____|
    // |    3|     |     |    2|
    // |_____|_____|_____|_____|
    string val = "";
    while(!win){
        bool f = true;
        while(f){
            cout << "Enter val to be inserted with Cell number\n";
            cin >> val;
            if(!valcheck(val)){
                cout << "Enter range values like 0th based index value for cell and value between 1 to 4 for insertion value and the cells which are empty\n";
            }
            else{
                f = false;
            }
        }
        if(minisudoku()){
            win = true;
            f = false;
        }
        if(lose){
            cout << "GAME OVER ,YOU LOSE\n";
            return 0;
        }
        printboard();
    }
    cout << "GAME OVER ,YOU WON\n";
    return 0;
}
