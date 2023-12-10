/*1이 될 때까지
2018 E 기업 알고리즘 대회

시간제한 1초. 메모리 제한 128MB

문제 요약: 어떤 수 N은 아래 2가지 과정중 하나를 선택할 수 있다.
        1. N-1 
        2. N/K
        N이 1이 될 때까지 과정을 반복하며, 1이 되면 연산을 한 횟수를 출력한다.
        그 연산은 최소 횟수어야 된다. 
           

입력: N K

풀이: 나누는 것이 숫자를 크게 줄일 수 있으므로, 나누어 떨어지지 않을때만 빼기 1을 한다.
      1이 나오면 카운트를 종료한다.
*/
#include <iostream>

using namespace std;

int main()
{
    int N,K,count=0;
    cin>>N>>K;
    while(N!=1)
    {
        if(N%k==0)
        {
            N/=K;
        }else
            N-=1;
        count++;
    }

    cout<<count;
    
    return 0;
}