/*곱하기 혹은 더하기

문제 요약: 숫자 0~9로만 이루어진 문자열 S가 있다.
          왼쪽~오른쪽에서 하나씩 확인하며 숫자 사이에 x나 + 연산자를 넣는다
          이러한 방법으로 만들 수 있는 가장 큰 수를 구해라.
          해당 문제에선 사칙연산의 연산 순서가 적용되지 않고
          무조건 왼쪽에서 오른쪽이다.

입력: 숫자로 이루어진 문자열S

02984
576

풀이: 대부분의 경우 x연산을 하는 것이 이득일 것이기 때문에
      +연산이 이득이 될 수 있는 맨 앞부분 연산에서만 체크를 해준다.
      한쪽이 0이거나 1일때는 +가 이득이다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){ 
    int result=0;
    string S;
    cin>>S;
    int first = S[0]-'0';
    int second = S[1]-'0';
    if(first<=1|second<=1)
        result = (first+second);
    else
        result = (first*second);
    for(int i=2;i<S.length();i++){
        result*=(S[i]-'0')
    }
    cout<<result;
    return 0;
}