#include <bits/stdc++.h>
using namespace std;

int main(){
    int case_num;
    cin >> case_num;
    for(int i = 0; i < case_num; i++){
        int row, col, test;
        cin >> row >> col >> test;
        
        vector<vector<char>> map(row, vector<char>(col));
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                cin >> map[r][c];
            }
        }
        cout << row << " " << col << " " << test << endl;
        for(int t = 0; t < test; t++){
            int r,c;
            cin >> r >> c;

            int height = min(r, row - 1 - r);
            int width = min(c, col - 1 - c);
            int maxSqHalf = min(height, width);

            int maxSquare = 0;
            bool isSquare = true;
            
            for(int side = 1; side <= maxSqHalf; side++){
                for(int i = r - side; i <= r + side; i++){
                    for(int j = c - side; j <= c + side; j++){
                        if(map[i][j] != map[r][c]){
                            isSquare = false;
                            break;
                        }
                    }
                }

                if(!isSquare)
                    break;

                if(isSquare)
                    maxSquare++;
            }

            cout << maxSquare * 2 + 1 << endl;
        }
    }
}