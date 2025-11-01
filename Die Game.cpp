#include <bits/stdc++.h>
using namespace std;

int tmp;
vector<int> die = {1, 2, 3, 4, 5, 6};

void to_north(){
    tmp = die[0];
    die[0] = die[4];
    die[4] = die[5];
    die[5] = die[1];
    die[1] = tmp;
}

void to_south(){
    tmp = die[0];
    die[0] = die[1];
    die[1] = die[5];
    die[5] = die[4];
    die[4] = tmp;
}

void to_west(){
    tmp = die[0];
    die[0] = die[3];
    die[3] = die[5];
    die[5] = die[2];
    die[2] = tmp;
}

void to_east(){
    tmp = die[0];
    die[0] = die[2];
    die[2] = die[5];
    die[5] = die[3];
    die[3] = tmp;
}

int main(){
    int step;
    while(cin >> step && step){
        string move;
        die = {1, 2, 3, 4, 5, 6};
        for(int i = 0; i < step; i++){
            cin >> move;
            if(move == "north")
                to_north();
            else if(move == "south")
                to_south();
            else if(move == "west")
                to_west();
            else if(move == "east")
                to_east();
        }
        cout << die[0] << endl;
    }
}