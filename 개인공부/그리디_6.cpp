/*문자열 뒤집기

문제 요약: 0과 1로 이루어진 문자열이 있다.
          이 문자열의 숫자를 뒤집어 모두 같게 만드려고 한다.
          연속된 숫자는 한번에 뒤집을 수 있을 때,
          문자열을 모두 같게 만드는 최소 횟수를 출력하시오.

입력: 숫자로 이루어진 문자열S

0001100
1

풀이: 최소 횟수를 구하려면 연속된 숫자 덩어리의 개수를 구하면된다
      0과 1의 연속된 숫자 덩어리를 구하고 작은 것을 출력한다.
      for문을 통해 문자열 앞부터 끝까지 탐색하는 방법을 사용하고
      이전 숫자를 기억하여 다를 때는 덩어리 카운트를 증가시킨다.
*/

#include <iostream>

using namespace std;

int main(){ 
    string s;
    cin>>s;

    char before, now;
    int cnt_01[2]={0,0};
    before = s[0];
    cnt_01[(before)-'0']++;
    for(int i=1;i<s.length();i++){
        now = s[i];
        if(before!=now)
        {
            cnt_01[(now)-'0']++;
            before = now;
        }
    }   
    cout<<min(cnt_01[0],cnt_01[1]);
    return 0;
}