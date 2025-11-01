#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int>;


int maps[40][40][40];
int used[40][40][40];
int D[40][40][40];
int a, b, c, d, e, f;
int lev, row, col;

bool inside(int x, int y, int z){
    if(x < row && x >= 0 && y < col && y >= 0 && z < lev && z >= 0){
        return true;
    }
    else
        return false;
}

int BFS(){
    memset(used, 0, sizeof(used));
    memset(D, -1, sizeof(D));
    queue<T> q;
    q.emplace(a, b, c);
    used[a][b][c] = 1; //
    D[a][b][c] = 0;
    while(!q.empty()){
        auto [i, j, k] = q.front();
        q.pop(); //
        if(inside(i+1, j, k) && maps[i+1][j][k] && !used[i+1][j][k]){
            used[i+1][j][k] = 1;
            D[i+1][j][k] = D[i][j][k] + 1;
            q.emplace(i+1, j, k);
        }
        if(inside(i-1, j, k) && maps[i-1][j][k] && !used[i-1][j][k]){
            used[i-1][j][k] = 1;
            D[i-1][j][k] = D[i][j][k] + 1;
            q.emplace(i-1, j, k);
        }
        if(inside(i, j+1, k) && maps[i][j+1][k] && !used[i][j+1][k]){
            used[i][j+1][k] = 1;
            D[i][j+1][k] = D[i][j][k] + 1;
            q.emplace(i, j+1, k);
        }
        if(inside(i, j-1, k) && maps[i][j-1][k] && !used[i][j-1][k]){
            used[i][j-1][k] = 1;
            D[i][j-1][k] = D[i][j][k] + 1;
            q.emplace(i, j-1, k);
        }
        if(inside(i, j, k+1) && maps[i][j][k+1] && !used[i][j][k+1]){
            used[i][j][k+1] = 1;
            D[i][j][k+1] = D[i][j][k] + 1;
            q.emplace(i, j, k+1);
        }
        if(inside(i, j, k-1) && maps[i][j][k-1] && !used[i][j][k-1]){
            used[i][j][k-1] = 1;
            D[i][j][k-1] = D[i][j][k] + 1;
            q.emplace(i, j, k-1);
        }
    }
    return D[d][e][f];
}

int main(){
    while(cin >> lev >> row >> col){
        if(!lev && !row && !col)
            break;
        memset(maps, 0, sizeof(maps));
        for(int k = 0; k < lev; k++){
            for(int i = 0; i < row; i++){
                string line;
                cin >> line;
                for(int j = 0; j < col; j++){
                    char ch = line[j];
                    if(ch == 'S'){
                        a = i; b = j; c = k;
                    }
                    if(ch == 'E'){
                        d = i; e = j; f = k;
                    }
                    if(ch != '#'){
                        maps[i][j][k] = 1;
                    }
                }
            }
        }

        int ans = BFS();
        if(ans == -1){
            cout << "Trapped!" << endl;
        }
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;
    }
    return 0;
}