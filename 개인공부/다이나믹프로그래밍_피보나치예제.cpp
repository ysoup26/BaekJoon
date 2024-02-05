/*다이나믹 프로그래밍
  : 큰 문제를 해결하기 위해 작은 문제를 호출하는 방식이며, 탑 다운 방식이라고도 함
  : 문제를 효율적으로 해결하는 방법이며, 중복된 연산을 줄여준다.

  피보나치 예제로 탑 다운 방식과 보텀 업 방식을 비교해본다.
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