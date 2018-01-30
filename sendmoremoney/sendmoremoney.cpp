#include <iostream>
#include <map>
using namespace std;

string a,b,c;
string letters;
int successful = 0;
int relation[8];

int give_relation(char c){
    for(int i=0;i<8;i++){
        if(letters[i]==c)
            return relation[i];
    }
}
bool valid_so_far(int k, int num){
    if (letters[k] == a[0] || letters[k] == b[0] || letters[k] == c[0] )
        if (num == 0)
            return false;
    for(int i=0;i<k;i++){
        if (relation[i] == num)
            return false;
    }
    
    //cout<<"in valid"<<k<<endl;
    return true;
    
    /*
    for(map<char, int >::const_iterator it = mapping.begin();
    it != mapping.end(); ++it)
{
    if (it->second == num) return false;
}
return true;
*/
}

int number(string num)
{
    
    if (num==a){
        return (relation[0]*1000 + relation[1]*100 + relation[2]*10 + relation[3]);
    }
    if(num==b){
        return (relation[4]*1000 + relation[5]*100 + relation[6]*10 + relation[1]);
    }
    if(num==c){
        return (relation[4]*10000 + relation[5]*1000 + relation[2]*100 + relation[1]*10 + relation[7]);
    }
    
    /*
    int result=0;
    for(int i=0; i<num.length();i++){
        result = result*10 + give_relation(num[i]);
    }
    return result;
    */
}
bool check_sum() {
    //cout<<"in check_sum"<<endl;
    return (number(a) + number(b) == number(c));
}



void print_map(){
    //cout<<endl;
    for(int i=0; i<8; i++)
{
    cout << letters[i] << '=' << relation[i]<< "\n";
}
}

void recurse(int k){
    //cout<<k<<'\t';
    if (k==letters.length()){
        //cout<< "bye";
        if (check_sum()){
            //cout<<"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH"<<endl;
            print_map();
            //cout<<"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH"<<endl;
            successful = 1;
            return;
        }
    }
    else{

    //print_map(mapping);
    char letter = letters[k];
    //cout<<k<<'\t';
    //cout<<k<<'\t';
    //cout<<endl;
    for(int i=0; i<10; i++){
        
        //cout<<val<id_so_far(mapping,k)<<endl;
        //cout<<"";
        //if(k==3){cout<<k<<'\t'; print_map(mapping);}
        if(valid_so_far(k, i)){
            relation[k] = i;
            //mapping[letter] = i;
            //cout<<k<<'\t';
            //cout<<"here vlaid"<<k<<'\t'<<i<<endl;
            recurse(k+1);
            if(successful==1)
                break;
        }
    }
}

}


int main () {

    //cout << "enter the three words"<<endl;
    //cin >>a>>b>>c;
    //int relation[8];
    a="SEND";
    b="MORE";
    c="MONEY";
    //cout<<a[0];
    string str = a+b+c;
    //for(int i=0;i<str.length();i++){
    //    if (letters.find(str[i]) == string::npos){
    //        letters += str[i];
    //    }
    //}
    //mapping['s'] = 5;
    //mapping['q'] = 23;
    //cout<< letters<< endl;
    letters="SENDMORY";
    recurse(0);
    //print_map(mapping);


}
