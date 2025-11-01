#include <bits/stdc++.h>
using namespace std;

struct Node{
    map<string, Node*> children;
};

void insert(Node* root, const vector<string>& path){
    Node* current = root;

    for(const string& folder : path){
        if(current->children.find(folder) == current->children.end()){
            current->children[folder] = new Node();
        }
        current = current->children[folder];
    }
}

void print(Node* root, int level = 0){
    for(const auto& [name, child] : root->children){
        cout << string(level, ' ') << name << "\n";
        print(child, level + 1);
    }
}


int main(){
    int num;
    while (cin >> num){
        string line;
        getline(cin, line); //吃掉數字後面的換行

        Node* root = new Node();
        for(int i = 0; i < num; i++){
            string line;
            getline(cin, line);
            stringstream ss(line);

            string segment;
            vector<string> path;

            while(getline(ss, segment, '\\')){
                path.push_back(segment);
            }
            
            insert(root, path);
            // insert node
        }
        print(root);
        // print node
        cout << endl;
    }
    return 0;
}