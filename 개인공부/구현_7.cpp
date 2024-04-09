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


풀이: 

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = 1;
    int idx = 0;
    bool IsSame = false;
    while(idx<s.length()){
        cout<<"idx: "<<idx<<" ";
        if(s[idx] == s[idx+1]){
            //cout<<"지금과 같다 ";
            IsSame = true;
        }else if(IsSame && s[idx] != s[idx+1]){
            //cout<<"지금과 다르다. 압축 중지 ";
            answer+=(n+1);
            IsSame = false;
        }else{
            //cout<<"압축 불가 ";
            answer+=n;
        }
        idx++;
        //cout<<answer<<"\n";
    }
    return answer;
}

int main(){
    string s;
    cin>>s;
    cout<<solution(s);
    return 0;
}