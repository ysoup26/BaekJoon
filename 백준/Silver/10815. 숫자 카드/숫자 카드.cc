#include <iostream>
#include <algorithm>
#define MAX 500000

using namespace std;

int card[MAX];
int N;

bool binary_search(int find, int start, int end){
    int s,m,e;
    bool IsFind;
    s = start;
    e = end;
    while(true){
        if(s>e){
            IsFind = false;
            break;
        }
        m = (s+e)/2;
        if(find == card[m]){
            IsFind = true; 
            break;   
        }else if(find < card[m]){
            e = m-1;
        }else{
            s = m+1;
        }
    }
    return IsFind;
}

int main() {
    int M;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>card[i];
    }
    cin>>M;
    int check[M];
    for(int i=0;i<M;i++){
        cin>>check[i];
    }
    sort(card,card+N);
    for(int i=0;i<M;i++){
        cout<<binary_search(check[i],0,N-1)<<" ";
    }
    return 0;
}