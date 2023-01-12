#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    int alp[26];
    cin>>S;
    for(int i=0;i<26;i++)
    {
        alp[i]=-1;
    }
    
    for(int i=0;i<S.length();i++)
    {
        for(char eng='a';eng<='z';eng++)
        {
            if(S[i]==eng&&alp[eng-'a']<0)
                alp[eng-'a']=i;
                
        }
    }
    for(int i=0;i<26;i++)
    {
        cout<<alp[i]<<" ";
    }
    return 0;
}