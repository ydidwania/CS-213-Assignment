#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    char op; // set this to 'P' to indicate a value / leaf node.
    string value;
    Node* L;
    Node* R;
    
    Node(char op1, Node* L, Node* R){
        this->op = op1;
        this->L = L;
        this->R = R;
    }

    Node(string value){
        this->value = value;
        this->op = 'P';
        this->L = this->R = NULL;
    }

    Node(istream &infile){
        char c = infile.get();
        if( c>='0' && c<='9' ||
            c>='a' && c<='z' ||
            c>='A' && c<='Z')
        {
                L = R = NULL;
                op = 'P';
                value = c;
        }
        else if (c=='('){
            L = new Node(infile);
            op = infile.get();
            R = new Node(infile);
            if (infile.get() != ')')
                cout << "No matching paranthesis."<<endl;
        }
        else if(c==' ') 
            return;
        else 
            cout<<"Error in input"<<endl;
    }

    string getVal() const{
    if(op=='P')
        return value;
    return ('(' + L->getVal() + op + R->getVal() + ')');
    }

    void conCan(){
        if (L!=NULL){
            L->conCan();
            R->conCan();

            if (op == '+'){
                if (L->getVal() > R->getVal()){
                    Node temp = *(new Node(""));
                    temp = *L;
                    *L = *R;
                    *R = temp;
                }
            }
        }
        return;
    }
};


int main(int argc, char* argv[]){
    filebuf fb;
    fb.open (argv[1],ios::in);
    istream is(&fb);
    Node* exp1 = new Node(is);
    exp1->conCan();
    is.ignore(1);
    Node* exp2 = new Node(is);
    exp2->conCan();
    cout<< (exp1->getVal() == exp2->getVal()) <<endl;
    
    fb.close();
    return 0;
}