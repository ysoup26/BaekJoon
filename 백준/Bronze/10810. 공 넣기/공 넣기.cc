#include <iostream>

using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int basket[N+1];
    fill(basket+1,basket+1+N,0); //범위 0으로 초기화
    //바구니 채우기
    for(int m=0;m<M;m++)
    {
        int i,j,k;
        cin>>i>>j>>k;
        for(;i<=j;i++){
            basket[i] = k;
        }
            
    }
    //바구니 출력
    for(int n=1;n<=N;n++){
        cout<<basket[n]<<" ";
    }
    return 0;
}