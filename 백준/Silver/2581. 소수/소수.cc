#include <iostream>
#include <cmath>
using namespace std;

int M,N;
int primeNum[10001];

void printSumAndMin()
{
    int min=0;
    int sum=0;
    int first=0;
    if(M<2)   //M이 1인경우 초기화되지 않은 값에 접근하니 
        M=2;
    for(int i=M;i<=N;i++)
    {
        if(primeNum[i]!=0) //소수인 값들만
        {
            if(min==0)
            {
                min=primeNum[i];  
            }
            sum+=primeNum[i];
            //cout<<primeNum[i]<<"\n";
        }
    }
    if(min==0)
        cout<<-1;
    else
        cout<<sum<<'\n'<<min;
    
    
}

void primeNumber()
{
    cin>>M>>N;
    int number=N;
    //초기화
    //시간복잡도는?
    for(int i=2;i<=number;i++)
    {
        primeNum[i]=i;
    }
    for(int i=2;i<=sqrt(number);i++)
    {
        if(primeNum[i]==0)
            continue;
        for(int j=i*i;j<=number;j+=i)
            primeNum[j]=0;
    }
    printSumAndMin();
};



int main()
{
    primeNumber();  
    return 0;
}