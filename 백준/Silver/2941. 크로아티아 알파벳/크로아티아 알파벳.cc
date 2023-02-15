
#include <iostream>

using namespace std;

int main()
{
    string input;
    string cro[]={"c=","c-","dz=","d-","lj","nj","s=","z="};//8
    int cnt=0,index=0;
    bool isCro;
    
    cin>>input;
    while(index<input.length()) //마지막 단어까지 검사하고 while 탈출
    {
        string check=input.substr(index,3);//세글자를 잘라서(dz=때문) 확인
        for(int i=0;i<8;i++)
        {
            if(check.find(cro[i])!=-1)
            {
                index+=cro[i].length();
                cnt++;
                isCro=true;
                break;
            }else  
                isCro=false;
        }
        if(!isCro) //크로아티아가 아님. 알파벳 한개.
        {
            index++;
            cnt++;
        }
        
    }
    cout<<cnt<<endl;
    return 0;
}
