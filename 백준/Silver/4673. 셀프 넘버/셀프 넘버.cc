//셀프넘버(자신의 생성자가 없는)인 숫자를 출력하기
#include <iostream>

using namespace std;

int d(int N)
{
    int n=N;
    int returnN=0;
    while(true) //뒤자리부터 더하며, 더한부분은 지움
    {
        returnN+=n%10;
        if(n/10<1)
            break;
        n/=10;
    }
    returnN+=N;
    return returnN;
}

int main()
{
    bool IsselfN=true;
    for(int i=1;i<10000;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(d(j)==i)
            {
                IsselfN=false;
                break;
            }
            IsselfN=true;
        }
        if(IsselfN)
            cout<<i<<endl;
    }
    return 0;    
}