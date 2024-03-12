/*만들 수 없는 금액 ** 

문제 요약: N개의 값이 주어진다.
          이것들로 특정 금액을 만들 수 있는데
          만들 수 없는 최소 금액을 출력해라.

입력: 

5
3 2 1 1 9

8

풀이: 값을 오름차 정렬하고, 만들 수 있는 금액을 증가시켜 나가며
      만들 수 없는 금액(target)을 찾는다.
      target을 증가시키는 과정에서 
      N개 중 어떤 값 x가 target보다 크다면
      target을 만들 수 없음을 의미하니 종료한다.
     
     target = target+x;
     이 식을 사용할 수 있는 이유는
     N[0]~N[x-1]의 조합으로 target을 만들 수 있기 때문에
     다음 tartget으로 넘어가는 것
     
*/

#include <iostream>

using namespace std;

int main(){ 
    int N,target;
    cin>>N;
    int Narr[N];
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        Narr[i] = tmp;
    }
    sort(Narr,Narr+N);
    target=1;
    for(int i=0;i<N;i++){
        int x = Narr[i];
        if(target<x)
            break;
        target+=x;
    }
    cout<<target;
    return 0;
}