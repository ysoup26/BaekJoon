#include <iostream>

using namespace std;

int main(){
    //문자열 입력
    string s;
    int s_len;
    bool isPalin;
    cin>>s;
    s_len = s.length();
    isPalin = true;
    //for문을 돌며 양쪽 끝의 값 비교
    for(int i = 0;i<s_len/2;i++){
        //동일하지 않으면 팰린드롬x break
        if(s[i] != s[s_len-1-i]){ // s의 마지막 인덱스는 s길이보다 1 작기에
            isPalin = false;
            break;
        }
    }
    cout<<isPalin;
    
    return 0;
}
