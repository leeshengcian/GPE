#include <bits/stdc++.h>
using namespace std;

bool isNum(const string& str){
    for(auto s: str){
        if(!isdigit(s)){
            return false;
        }
    }
    return true;
}

int main(){
    string line;

    while(getline(cin, line)){
        if(line[0] == '.')
            break;
        vector<string> list;
        stringstream ss(line);
        string tmp;
        while(ss >> tmp){
            list.push_back(tmp);
        }

        reverse(list.begin(), list.end());  // important!
        stack<int> st_int;
        bool error = false;

        for(auto st : list){
            if(isNum(st)){
                st_int.push(stoi(st));
            }
            else{
                int a, b;  // when encounter operator, get two numbers for operation
                if(st == "+"){
                    if(st_int.empty()){ error = true; break; }
                    else{ a = st_int.top(); st_int.pop(); }
                    if(st_int.empty()){ error = true; break; }
                    else{ b = st_int.top(); st_int.pop();}
                    st_int.push(a+b);
                }
                else if(st == "-"){
                    if(st_int.empty()){ error = true; break; }
                    else{ a = st_int.top(); st_int.pop(); }
                    if(st_int.empty()){ error = true; break; }
                    else{ b = st_int.top(); st_int.pop();}
                    st_int.push(a-b);
                }
                else if(st == "*"){
                    if(st_int.empty()){ error = true; break; }
                    else{ a = st_int.top(); st_int.pop(); }
                    if(st_int.empty()){ error = true; break; }
                    else{ b = st_int.top(); st_int.pop();}
                    st_int.push(a*b);
                }
                else if(st == "/"){
                    if(st_int.empty()){ error = true; break; }
                    else{ a = st_int.top(); st_int.pop(); }
                    if(st_int.empty()){ error = true; break; }
                    else{ b = st_int.top(); st_int.pop();}
                    st_int.push(a/b);
                }
                else if(st == "%"){
                    if(st_int.empty()){ error = true; break; }
                    else{ a = st_int.top(); st_int.pop(); }
                    if(st_int.empty()){ error = true; break; }
                    else{ b = st_int.top(); st_int.pop();}
                    st_int.push(a%b);
                }
            }
        }

        if(error || st_int.size() != 1){
            cout << "illegal" << endl;
        }
        else{
            cout << st_int.top() << endl;
        }
    }
}

// 思路：getline 讀取輸入字串，存入 vector<string> list
// reverse(list.begin(), list.end())
// 逐一讀取翻轉字串列，先判斷是否為數字，若為數字，push to stack
// 若為符號，先檢查 stack 是否為空，若為空代表錯誤，若不為空，pop top element as a，接著再檢查是否為空，若不為空，pop top element as b
// push a ex b to stack
// 最終輸出 stack top