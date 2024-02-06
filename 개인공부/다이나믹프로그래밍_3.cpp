/*바닥 공사
1초 128MB

문제 요약: 세로 2, 가로 N의 직사각형 바닥이 있다.
          이 바닥을 1x2, 2x1, 2x2 덮개를 이용해 채우려고한다.
          채울 수 있는 모든 경우의 수를 구해라.

입력: N
        

풀이: 2개의 경우가 나온다
      1) 2x1칸을 채워야 할 때 -> 1가지 방법만
      2) 2x2칸을 채워야 할 때 -> 2가지 방법만
      점화식: a(i) = a(i-1) + 2 * a(i-2)

*/


#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
//int arr[100];

int main(){
    int N;
    cin>>N;
    //입력
    d[1] = 1;
    d[2] = 3;
    for(int i=3;i<=N;i++){
        d[i] = (d[i-1]+d[i-2]*2) % 796796;
    }
    cout<<d[N];
    return 0;
}