#include <bits/stdc++.h>
using namespace std;

int main(){
    int row, col;
    int case_num = 0;
    while(cin >> row >> col){
        if (row == 0 && col == 0) break;

        case_num++;
        vector<string> board(row);
        vector<vector<int>> result(row, vector<int>(col, 0));


        for(int i = 0; i < row; i++){
            cin >> board[i];
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == '*')
                    result[i][j] = -1;
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(result[i][j] == -1){
                    for(int r = i-1; r <= i+1; r++){
                        for(int c = j-1; c <= j+1; c++){
                            if(r >= 0 && r < row && c >= 0 && c < col && (result[r][c] != -1)){
                                result[r][c]++;
                            }
                        }
                    }
                }
                
            }
        }
        if(case_num > 1)
            cout << endl;
        
        cout << "Field #" << case_num << ":" << endl;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(result[i][j] == -1)
                    cout << '*';
                else
                    cout << result[i][j];
            }
            cout << endl;
        }
    }
}