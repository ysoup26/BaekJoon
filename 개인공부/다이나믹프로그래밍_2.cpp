/*개미 전사
1초 128MB

문제 요약: 일렬로 나열된 식량 창고에서 일부 식량 창고를 선택해 약탈하려고 한다.
           인접한 식량 창고를 선택하면 발각된다고 할 때, 얻을 수 있는
           식량의 최대값을 구해라

입력: N
      N개의 식량값들
        

풀이: 2가지 경우를 고려하면 된다. 
      1) (i)창고+ (i-2)창고
      2) (i-1)창고
      둘 중에 큰 것을 선택해서 d배열에 집어넣는다.
      

*/


#include <iostream>
#include <algorithm>

using namespace std;

int d[100];
int arr[100];

int main(){
    int N;
    cin>>N;
    //입력
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr[i] = tmp;
    }
    //계산 
    d[0] = arr[0];
    d[1] = arr[1];
    for(int i=2;i<N;i++){
        d[i] = max(d[i-1],d[i-2]+array[i]);
    }
    cout<<d[N-1];
    return 0;
}