#include  <iostream>
#include <vector>
using namespace std;


struct Node;

struct bstIt{
  vector<Node*> anc;  //pointers to ancestors from tree root to self.
  void operator++();  // prefix unary operator
  int operator*();     // prefix unary operator
  bool operator!=(const bstIt);  // binary operator

  void pushAll(Node *root);
};

struct Node{
  Node *left, *right;
  int value;
  Node(){value = 0; left=right=NULL;}
  typedef bstIt iterator;
  bstIt begin();
  bstIt end();
};

int bstIt::operator*() {
  return anc.back()->value;
}

bool bstIt::operator!=(const bstIt it) {

    return (it.anc != anc);
}


void bstIt::operator++() {
    Node *tmp = anc.back();

    if( tmp->right != NULL ){
        anc.push_back(tmp->right);
        tmp = tmp->right;
        while(tmp->left != NULL){
            anc.push_back(tmp->left);
            tmp = tmp->left;
        }
        return;
    }
    else {
        anc.pop_back();
        while( anc.size()>0 && tmp->value >= anc.back()->value ){
            tmp = anc.back();
            anc.pop_back();                
        }
        return;
    }

    // if (tmp->value < anc.back()->value){
        // anc.pop_back();
        // anc.pop_back();                
    // }

    // anc.pop_back();
    // cout << "c3";
    // pushAll(tmp->right) ;
    // cout << "c4";
    return ;
}

void bstIt::pushAll(Node *root){
    while(root != NULL){
        anc.push_back(root);
        root = root->left;
    }
}

bstIt Node::begin() {
    bstIt it;
    Node *root = this;
    while(root != NULL){
        it.anc.push_back(root);
        root = root->left;
    }
    return it ;
}

bstIt Node::end() {
    bstIt it;
    // Node* root = this;
    // while(root->left != NULL){
        // it.anc.push_back(root);
        // root = root->right;
    // }
    // it.anc.push_back(root->left);
    return it ;
}

void insert(Node* &myset, int x){
    if(myset == NULL){
        myset = new Node;
        myset->left = myset->right = NULL;
        myset->value = x;
    }
    else{
        if (x >= myset->value)
            insert(myset->right, x);
        else
            insert(myset->left, x);
    }
    // cout << x<<endl;
}


int main(){
  Node* s = NULL;
  while(true){
    char input;
    cin>>input;
    if(input=='x')
      break;
    else if(input=='i'){
      int value;
      cin>>value;
      insert(s, value);
    }
    else if(input=='p'){
      if(s==NULL){
        cout<<-1<<endl;
      }
      else {
        // cout << (it !=s->end());
        // ++it;
        // cout << "p3"<<endl;
         // cout <<endl <<"..value"<<*it<<"..";
        // cout << (it !=s->end());
        
        for(Node::iterator it = s->begin(); it !=s->end(); ++it){
          cout << *it <<' ';
        }
        cout << endl;
      }
    }
  }
}