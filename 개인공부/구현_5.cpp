/*럭키 스트레이트

1초 128MB

문제 요약: 럭키 스트레이트 기술을 사용하려고 하는데 특정 조건이 필요하다.
          점수 N을 자릿수 기준으로 반으로 나눈다
          왼쪽의 합과 오른쪽의 합이 같다면 럭키 스트레이트를 사용할 수 있다.

입력: 
123402
>>LUCKY
7755
>>READY

풀이: 

*/

#include <iostream>

using namespace std;


int main() {
    string s;
    cin>>s;
    int left=0,right=0;
    int middle = s.length()/2;
    for(int i=0;i<middle;i++){
        int l = s[i]-'0';
        int r = s[i+middle]-'0';
        cout<<l<<" "<<r<<"\n";
        left+=l;
        right+=r;
    }
    if(left==right)
        cout<<"LUCKY";
    else
        cout<<"READY";
    return 0;
}