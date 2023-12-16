/*시각

2초 128MB

문제 요약: 정수 N이 입력되면 00시 00분 00초 ~ N시 59분 59초까지 검사를 한다.
           저 시간 중 3이 하나라도 포함되있으면 숫자를 센다.

입력: N

풀이: 시간이 넉넉하기때문에 완전 탐색도 가능하다.
      시, 분, 초에 대한 3중 for문을 이용하여 구현하고,
      while문으로 모든 자리수를 검사하는 함수를 통해 3을 찾을 수 있게 하였다.
*/

#include <iostream>

using namespace std;

bool find3(int n)
{
    while(n/10>0 || n > 0) //1~9사이의 값은 첫번째 조건문에서 무시되기 때문에 조건을 추가해줌
    {
        if(n%10 == 3)
            return true;
        n/=10; //한자리씩 검사
    }
    return false;
}

int main() {
    int N,cnt=0;
    cin>>N;ㅎ
    for(int h=0;h<N+1;h++){
        for(int m=0;m<60;m++){
            for(int s=0;s<60;s++){
                if(find3(h)||find3(m)||find3(s)){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}