#include <iostream>
#include <stdlib.h>    
#include <map>
using namespace std;

class heap{
    double A[1000];
    int next;
public:
    heap(){ next =0; }
    bool add(int v);
    int remove();
    void bubbleup(int r);
    void trickledown(int t);
    void exchange(double &u, double &v);
private:
    int p(int i){ return  (i-1)/2;} 
    int l(int i){ return (2*i + 1);}
    int r(int i){ return (2*i + 2);}
    bool noleftchild(int i){return l(i) >= next;}
    bool norightchild(int  i){return r(i) >= next;}
};

bool heap::add(int v){
    if (next >= 1000)
        return false;
    A[next] = v;
    bubbleup(next);
    next++;
    return true;
}
 void heap::bubbleup(int r){
    while( r!=0 && A[p(r)] > A[r]){
        exchange( A[p(r)] , A[r]);
        r=p(r);
    }
}
void heap::exchange(double &u, double &v){
    double temp = u;
    u=v;
    v=temp;
}

int heap::remove(){
    if(next == 0){
        abort();
    }
    int v = A[0];
    A[0] = A[next-1];
    next --;
    trickledown(0);
    return v;
}

void heap::trickledown(int i){
    int nexti;
    if( noleftchild(i) ) return;
    if(norightchild(i)) {
        nexti=l(i);
    }
    else nexti  = A[l(i)]<A[r(i)] ? l(i):r(i);
    if( A[i] <= A[nexti] ) return;
    exchange( A[nexti], A[i] );
    trickledown(nexti);
}



int sgn(int r){
    if (r>0) return 1;
    if (r<0) return -1;
    return 0;
}
int main() {
    int n;
    cin >> n;
    double velocity[n];
    double position[n];
    for (int i=0;i<n;i++){
        cin>>position[i]>>velocity[i];
    }
    int diff_in_pos[n];
    for (int i=0;i<n;i++){
        diff_in_pos[i]=0;
    }
    double max_time = 0.0;
    int no_of_collisions=0;
    for(int i=0;i<n;i++){
        for(int j=i+1; j<n;j++){
            double dist = position[j] - position[i] - 2*abs((j-i)); // Always positive, input in ascending order
            double time = dist/(velocity[j]-velocity[i]); // for collsion V_ji should be negative. hence negative time
            if(velocity[j]-velocity[i]>=0) continue;
            time = sgn(time)*time;
            diff_in_pos[j] -= 2;
            diff_in_pos[i] +=2;
            no_of_collisions+=1;
            if (time > max_time)
                max_time = time;
        }
    }
    double new_positon[n];
    int index_of[n];
    for(int i=0; i<n; i++){
        new_positon[i] = position[i] + velocity[i]*max_time + diff_in_pos[i] ;
    }
    /* 
        for(int j=0;j<=i;j++){
            if(new_positon[j]>new_pos){
                for(int k=i;k>j;k--){
                    new_positon[k]=new_positon[k-1];    
                }
                new_positon[j]=new_pos;
                index_of[i] = j;
                break;
            }
            if(j==i){
                new_positon[j] = new_pos;
                index_of[i] = j;
            }
        }
    }
    int no_of_collisions=0;
    for(int i=0;i<n;i++){
        int new_index = index_of[i];
        int initial_balls_to_right = n-i;
        int final_balls_to_right = n - new_index;
        int no_balls_crossed = abs(final_balls_to_right - initial_balls_to_right);
        cout<<"no of balls"<<no_balls_crossed<<endl;
        no_of_collisions += no_balls_crossed;
        new_positon[new_index] = new_positon[new_index] + sgn(velocity[i])*no_balls_crossed;
    }
    //no_of_collisions /= 2;
    cout<<no_of_collisions<<endl;
    */
    for(int i=0; i<n; i++){
        //cout<<diff_in_pos[i]<<endl;
    }
    if(no_of_collisions>0){
    cout<<no_of_collisions<<endl;
    cout<<max_time<<endl;
    for(int i=0; i<n; i++){
        //cout<<new_positon[i]<<endl;
    }
    heap PosHeap;
    heap VecHeap;
    for(int i=0;i<n;i++){
        PosHeap.add(new_positon[i]);
        VecHeap.add(velocity[i]);
    }
    for(int i=0;i<n;i++){
        cout<<PosHeap.remove()<<" "<<VecHeap.remove()<<endl;
    }
}
else{cout<<-1<<endl;}
}
