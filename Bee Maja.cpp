#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000;

vector<int> cord_x(SIZE+1), cord_y(SIZE+1);
int x, y = 0;
int step = 1;

void update(){
    cord_x[step] = x;
    cord_y[step] = y;
    step++;
}

void down(int n){
    while(n--){
        y++;
        update();
    }
}

void left_up(int n){
    while(n--){
        x--;
        update();
    }
}

void up(int n){
    while(n--){
        y--;
        update();
    }
}

void right_up(int n){
    while(n--){
        x++;
        y--;
        update();
    }
}

void right_down(int n){
    while(n--){
        x++;
        update();
    }
}

void left_down(int n){
    while(n--){
        x--;
        y++;
        update();
    }
}

void create(){
    update();
    down(1);
    for(int i = 1; step <= SIZE; i++){
        left_up(i);
        up(i);
        right_up(i);
        right_down(i);
        down(i+1);
        left_down(i);
    }
}

int main(){
    int num;
    create();
    while(cin >> num){
        cout << cord_x[num] << " " << cord_y[num] << endl;
    }
    return 0;
}