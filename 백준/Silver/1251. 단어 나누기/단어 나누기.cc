#include <iostream>
#include <string>
using namespace std;
string reverse(string s)
{
    string rev_result=""; 
    for(int i=s.length()-1;i>=0;i--)
    {
        rev_result+=s[i];
    }
    return rev_result;
}
 
int main()
{
    string input,fast_str="~"; //~는 아스키코드에서 가장 큰 값
    cin>>input;
    //모든경우의 단어를 생성할때까지
    for(int i=1;i<input.length()-1;i++) //첫번째 단어분리 idx, 뒤에 두개는 남겨두어야함
    {
        string s_1,s_2,s_3,s;
        for(int j=i+1;j<input.length();j++)//두번째 단어분리 idx
        {
            //substr(시작idx,길이)
            s_1=reverse(input.substr(0,i));
            s_2=reverse(input.substr(i,j-i));
            s_3=reverse(input.substr(j));
            s=s_1+s_2+s_3;
            //cout<<"s: "<<s<<":"<<s_1<<","<<s_2<<","<<s_3<<"\n";
            if(s<fast_str)
                fast_str=s;
        }
    }
    cout<<fast_str;
    return 0;
}