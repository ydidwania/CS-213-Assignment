#include  <iostream>
#include <vector>
using namespace std;


struct Node{
    int value;
    Node* left;
    Node* right;
    Node(){value = 0; left=right=NULL;}
    Node(int v){ value=v; left=right=NULL;}

};

int height(Node* root){
    if (root==NULL)
        return 0;
    int h = height(root->left) + 1;
    int h1 = height(root->right) + 1;

    return  ((h>h1)? h:h1) ; 
}

void kDistanceVectorRecurse(Node* root, vector<int>& v, int k){
    if (root == NULL)
        return;
    v[k] += (root->left != NULL) + (root->right != NULL);
    kDistanceVectorRecurse(root->left, v, k+1);
    kDistanceVectorRecurse(root->right, v, k+1);
    return;
}

vector<int> DistanceVector(Node* root){
    vector<int> v (height(root), 0);
    
    
    kDistanceVectorRecurse(root, v, 1);
    return v;
}


int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->left = new Node(21);
    root->right->right = new Node(23);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->right = new Node(15);
    root->left->right->left = new Node(10);
    vector<int> v = DistanceVector(root);
    for (int i =0; i<v.size(); i++){
        cout<<i<<"\t"<<v[i]<<endl;
    }
}