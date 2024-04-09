/*문자열 압축

1초 128MB

문제 요약: 문자열을 n개 이상의 단위로 잘라서 문자열을 압축시키려고 한다.
          문자열 s가 주어졌을 때, 압축하여 표현한 문자열 중 가장 짧은 길이를 출력해라

예시: aabbacc -> 2a2ba2c 로 압축
      abcabcdede -> abcab2de or 2abcdede 로 압축할 수 있고 후자가 더 짧음

주의: 한 문자열을 압축할 때, 여러 단위를 혼합할 수  없다
      n=3일때는 3개씩만 나눌 수 있음

입력: 
aabbaccc -> 7
ababcdcdababcdcd -> 9
abcabcdede -> 8
abcabcabcabcdededededede ->14
xababcdcdababcdcd -> 17

풀이: 압축하여 표현한 문자열 중 가장 짧은 길이를 출력해야하기 때문에
      n을 변화시키는 for문과 n을 이용하여 문자열을 압축하는 while문으로 구현했다.
      while문에서는 n으로 분리된 문자열들을 비교하여 같다면 압축, 
      같지 않다면 다음 문자열로 넘어가는 방식으로 작동하도록 하였다.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//두 문자열을 비교하는 함수, 인덱스 슬라이싱과 비교를 한번에
bool same_check(string s, int idx,int n){
    string s1="",s2="";
    if(idx+n>=s.length()) //s2가 s를 오버하는 범위를 갖는다면 잘못된 접근
    {    
        return false;
    }
    for(int i=0;i<n;i++){
        s1+=s[idx+i];
        s2+=s[idx+i+n];
    }
    if(s1 == s2)
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;
    for(int n=s.length()/2;n>0;n--){
        //cout<<"단위: "<<n;
        int idx = 0;
        bool IsSame = false;
        int n_answer = 0;
        while(true){
            if(idx>=s.length()) //idx가 문자열을 넘어서면 종료, 
            {                   //idx를 n만큼 증가시키기 때문에 넘어간 부분만큼 빼줌
                n_answer-=(idx-s.length());     
                break;
            }
            if(same_check(s,idx,n)){
                IsSame = true;
            }else if(IsSame && !same_check(s,idx,n)){
                n_answer+=(n+1);
                IsSame = false;
            }else{
                n_answer+=n;
            }
            idx+=n;
        }
        //cout<<" 결과비교:"<<answer<<" "<<n_answer<<"\n";
        if(answer == 0)
            answer = n_answer;
        if(n_answer<answer)
            answer = n_answer;
    }
    return answer;
}

int main(){
    string s;
    cin>>s;
    cout<<solution(s);
    return 0;
}