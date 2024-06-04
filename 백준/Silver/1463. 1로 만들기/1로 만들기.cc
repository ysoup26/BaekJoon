#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int N;
int d[1000000+1];

int make_one(int X){
    d[1] = 0;
    for(int i=2;i<=X;i++){ //bottom up 방식 d[1]부터 채워나감
        d[i] = d[i-1] + 1; // i - 1은 무조건 가능한 연산이므로, 먼저 수행 가능
        if( i%3 == 0 ){
            d[i] = min(d[i],d[i/3]+1);
        }
        if( i%2 == 0 ){
            d[i] = min(d[i],d[i/2]+1);
        }
    }
    return d[X]; 
}



int main(){
    cin>>N;
    cout<<make_one(N);
    return 0;
}