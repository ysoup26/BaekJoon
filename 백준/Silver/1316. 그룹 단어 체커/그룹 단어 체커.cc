
#include <iostream>

using namespace std;

int main()
{
    int N;
    int cnt=0;
    bool isGroup;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string word;
        cin>>word;
        if(word.length()==1)
        {
            cnt++;
            continue;
        }
        for(int j=0;j<word.length()-1;j++)
        {
            if(word[j]==word[j+1]) //자기 뒤와 같음
            {
                isGroup=true; //전체가 그룹단어인 경우(검증)
                continue; 
            }
            else //자신과 다름->그 뒤에 자신과 같은게 있는지
            {
                string check=word.substr(j+1);
                if(check.find(word[j])!=-1)
                {
                    isGroup=false;
                    break;
                }
                else
                    isGroup=true;
            }
        }
        if(isGroup)
            cnt++;
        
    }
    cout<<cnt<<endl;
    return 0;
}
