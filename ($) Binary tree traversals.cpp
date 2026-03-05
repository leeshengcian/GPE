#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x):
        val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<char>& preorder, vector<char>& inorder, int& index, int l, int r){
    if(l > r)
        return NULL;
    
    TreeNode* root = new TreeNode(preorder[index]);
    auto rt = find(inorder.begin(), inorder.end(), preorder[index]);
    int mid = distance(inorder.begin(), rt);

    index++;

    root->left = build(preorder, inorder, index, l, mid-1);
    root->right = build(preorder, inorder, index, mid+1, r);

    return root;
}

void print(TreeNode* root){
    if(!root)
        return;
    
    print(root->left);
    print(root->right);
    cout << root->val << " ";
}

int main(){
    int case_num;
    cin >> case_num;

    for(int i = 0; i < case_num; i++){
        int node_num;
        cin >> node_num;

        vector<char> preorder(node_num, 0);
        vector<char> inorder(node_num, 0);

        for(int i = 0; i < node_num; i++)
            cin >> preorder[i];
        for(int i = 0; i < node_num; i++)
            cin >> inorder[i];

        int index = 0;
        TreeNode* root = build(preorder, inorder, index, 0, node_num-1);
        print(root);
        cout << endl;
    }
}