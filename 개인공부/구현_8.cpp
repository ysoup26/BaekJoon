/*

1초 128MB

문제 요약: 

입력: 


풀이: 

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