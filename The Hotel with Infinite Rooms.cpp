#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll start_mem, day;
    while(cin >> start_mem >> day){
        ll group_size = start_mem;
        while(day > group_size){
            day -= group_size;
            group_size++;
        }
        cout << group_size << endl;
    }
}
