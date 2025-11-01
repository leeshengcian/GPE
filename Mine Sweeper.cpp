#include <bits/stdc++.h>
using namespace std;

int main(){
    int game;
    cin >> game;
    for(int i = 0; i < game; i++){
        int N;
        cin >> N;
        
        vector<string> board(N);
        vector<string> action(N);
        vector<vector<int>> result(N, vector<int>(N, 0));

        for(int i = 0; i < N; i++){
            cin >> board[i];
        }

        for(int i = 0; i < N; i++){
            cin >> action[i];
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == '*')
                    result[i][j] = -1;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(result[i][j] == -1){
                    for(int r = i-1; r <= i+1; r++){
                        for(int c = j-1; c <= j+1; c++){
                            if(r >= 0 && r < N && c >= 0 && c < N && (result[r][c] != -1))
                                result[r][c]++;
                        }
                    }
                }
            }
        }
        bool bomb = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(action[i][j] == 'x' && board[i][j] == '*'){
                    bomb = true;
                    break;
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(action[i][j] == 'x'){
                    if(result[i][j] == -1){
                        cout << '*';
                    }
                    else
                        cout << result[i][j];
                }
                else {
                    if(bomb && result[i][j] == -1)
                        cout << '*';
                    else
                        cout << '.';
                }
            }
            cout << endl;
        }
        cout << endl;

    }
}