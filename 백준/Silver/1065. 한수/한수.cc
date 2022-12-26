#include <iostream>

using namespace std;

bool IsHansu(int i)  //한수인지 검사
{
    int d=0;
    int before_d=99;
    int I=i;
    while(true) //뒤에서부터 2개씩 검사
    {
        int a1=(int)(I%100)/10; 
        int a2=I%10;
        d=a2-a1;  
        if(before_d==99)  //첫번째 검사인데
        {
            if(I/100<1)   //더 검사할게 없음(1~99)
                return true;
            before_d=d; 
        }else if(d==before_d) //한수인데
        {
            if(I/100<1)  //더 검사할게 없음(1~99)
                return true;
            before_d=d; 
        }else 
            return false;

        I/=10;
    }
}

int main()
{

    int i,input,cnt=0;
    cin>>input;
    for(i=1;i<=input;i++)
    { 
        if(IsHansu(i))
            cnt++;
    }
    cout<<cnt;
    return 0;
}