/*1로 만들기

1초 128MB

문제 요약: N개의 부품 중에서, 손님이 M개의 부품이 있는지 확인을 부탁했다.
          모두 있다면 yes 아니면 no

입력: 
        N
        N개의 숫자들
        M
        M개의 숫자들
        5
        8 3 7 9 2
        3
        5 7 9

풀이: 이진탐색을 활용한다. 
      N개 숫자들을 정렬하고, M개의 숫자들을 각각 이진탐색해서 확인한다.
*/


#include <iostream>
#include <algorithm>

using namespace std;

int d[100];

int f_topdown(int n)
{
    if(n == 1 || n == 2)
        return n;
    if(d[n] != 0)
        return d[n];
    d[n] = f_topdown(n-1) + f_topdown(n-2);
    return d[n];
}

int f_bottom(int n){
    d[1] = 1;
    d[2] = 2;
    for(int i=3;i<=n;i++){
        d[i] = d[i-1] + d[i-2];
    }
    return d[n];
}

int main(){
    int n;
    cin>>n;
    cout<<f_topdown(n)<<"\n";
    cout<<f_bottom(n);
    return 0;
}