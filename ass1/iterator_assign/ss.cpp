#include<iostream>
#include<vector>

using namespace std; 


struct Node;

struct bstIt{
  vector<Node*> anc;  //pointers to ancestors from tree root to self.
  void operator++();  // prefix unary operator
  int operator*();    // prefix unary operator
  bool operator!=(const bstIt);  // binary operator
};

struct Node{
  Node *left, *right;
  int value;
  Node(){value = 0; left=right=NULL;}
  typedef bstIt iterator;
  bstIt begin();
  bstIt end();
  
};


int bstIt::operator*(){
  return anc.back()->value;
}

bool bstIt::operator!=(const bstIt it){
  return (anc != it.anc);
}

void bstIt::operator++(){
  Node *tmp = anc.back();

    // If right subtree exists,
    // push back the entire left tree of the right child
    // Else pop back until you reach a node which is a left child.
    if( tmp->right != NULL ){
        anc.push_back(tmp->right);
        tmp = tmp->right;
        while(tmp->left != NULL){
            anc.push_back(tmp->left);
            tmp = tmp->left;
        }
    }
    else {
        anc.pop_back();
        while( anc.size()>0 && tmp->value >= anc.back()->value ){
            tmp = anc.back();
            anc.pop_back();                
        }
    }
    return;
}

void insert(Node* &myset, int x){
 if(myset == NULL){
   myset = new Node;
   myset->left = myset->right = NULL;
   myset->value = x;
 }
 else{
   if(x == myset->value) 
     return;
   else if(x <= myset->value)
     insert(myset->left, x);
   else
     insert(myset->right, x);
 }
}

bstIt Node::begin(){
  bstIt it;
    Node *root = this;
    while(root != NULL){
        it.anc.push_back(root);
        root = root->left;
    }
    return it ;
}

bstIt Node::end(){
  //Empty bstIt
  bstIt temp;
  return temp;
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
        //for(Node::iterator it = s->begin(); it !=s->end(); ++it){
        //  cout << *it <<' ';
        //}
         Node::iterator it = s->begin();
         cout<< (it!=s->end()) ;
         cout<<*it;
         ++it;
         cout<< (it!=s->end()) ;
         cout<<"he";
         cout<<endl<<*it;
         cout<<"he";
         
         ++it;
        cout<<endl<<*it;
      }
    }
  }
}
