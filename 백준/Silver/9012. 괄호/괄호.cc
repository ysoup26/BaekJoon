#include <iostream>
#include <stack>

using namespace std;

int main(){
    int N;
    cin>>N;
    for(int test_case = 0;test_case<N;test_case++){
        string s;
        bool isVPS = true;
        cin>>s;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            //cout<<s[i]<<" ";
            if(s[i] == '('){ 
                st.push(s[i]);
            }else if(st.empty() && s[i] == ')'){  // st가 비어있는데 이번 입력이 )라면 VPS가 될 수 없음
                isVPS = false;
                break;
            }else{
                char top = st.top();
                if(top  == '(') //짝이 맞다면
                    st.pop();
                else{
                    isVPS = false;
                    break;
                }
            }
            
        }
        if(!st.empty()) //st가 비어있지 않다면 짝을 맞추지 못한 문자열이 있는것
            isVPS = false;
        if(isVPS)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}