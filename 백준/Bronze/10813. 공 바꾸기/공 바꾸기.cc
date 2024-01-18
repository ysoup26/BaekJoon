#include <iostream>

using namespace std;

int basket[101];

int main(){
    int N,M;
    cin>>N>>M;
    for(int n=1;n<=N;n++){
        basket[n] = n;
    }
    for(int m=1;m<=M;m++){
        int i,j,tmp;
        cin>>i>>j;
        tmp = basket[i];
        basket[i] = basket[j];
        basket[j] = tmp;
    }
    for(int n=1;n<=N;n++){
        cout<<basket[n]<<" ";
    }
    return 0;
}