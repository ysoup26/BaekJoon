#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s,t,t_copy;
    int s_len;
    bool flag = true;
    while(cin>>s>>t)
    {
        flag = true;
        t_copy=t;
        s_len=s.length();
        for(int i=0;i<s_len;i++)
        {
            int nowT=t_copy.find(s[i]); //검사할수록 t를 줄여감
            if(nowT>-1)
            {
                t_copy=t_copy.substr(nowT+1);
            }
            else //한번이라도 못찾았다면 아닌것
            {
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}