#include <bits/stdc++.h>
using namespace std;

int main(){
    int dict, job;
    cin >> dict >> job;

    map<string, int> dictionary;
    string noun;
    int price;

    for(int i = 0; i < dict; i++){
        cin >> noun >> price;
        dictionary[noun] = price;
    }

    string line;
    getline(cin, line);  // 清空輸入空一行

    for(int j = 0; j < job; j++){
        int value = 0;
        while(getline(cin, line)){
            if(line == '.')
                break;
            stringstream ss(line);
            while(ss >> noun){
                if(dictionary.count(noun)){
                    value += dictionary[noun];
                }
            }
        }
        cout << value << endl;
    }
    return 0;
}