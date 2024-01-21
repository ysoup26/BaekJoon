#include <iostream>

using namespace std;

int basket[101];

void reverse_basket(int start,int end){
    int cnt = (end-start+1)/2;
    for(int i=0;i<cnt;i++){
        int tmp = basket[start+i];
        basket[start+i] = basket[end-i];
        basket[end-i] = tmp;
    }
    
}

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        basket[i] = i;
    }
    for(int i=1;i<=M;i++){
        int s,e;
        cin>>s>>e;
        reverse_basket(s,e);
    }
    for(int i=1;i<=N;i++){
        cout<<basket[i]<<" ";
    }
    return 0;
}