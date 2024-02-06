/*1로 만들기

1초 128MB

문제 요약: 정수 X가 주어질 때, 사용할 수 있는 연산 4가지를 이용하여 1로 만들어야한다.
          이때 연산을 사용하는 최솟값을 구하여라

        연산4가지 
        x%5 / x%3 / x%2 / x-1

입력: X
        

풀이: 피보나치를 구현했던 것처럼 각각의 d[i]에 연산 횟수를 집어넣는다.
      d[i]를 집어넣을 때 4가지 연산이 가능한지 확인하고, 
      min을 통해 최소 연산을 집어넣는다.
      d[2]~d[X]까지 순차적으로 집어넣으면 d[X]의 최소값을 구할 수 있다.

*/


#include <iostream>
#include <algorithm>

using namespace std;

int d[30001];

int make_one(int X){
    int m;
    for(int i=2;i<=X;i++){
        d[i] = d[i-1] + 1; //d[i-1]는 d[i]보다 연산횟수가 1 적다.
        if( i%2 == 0 ){
            d[i] = min(d[i],d[i/2]+1);
        }
        if( i%3 == 0 ){
            d[i] = min(d[i],d[i/3]+1);
        }
        if( i%5 == 0 ){
            d[i] = min(d[i],d[i/5]+1);
        }
    }
    return d[X]; 
}

int main(){
    int X;
    cin>>X;
    cout<<make_one(X);
    return 0;
}