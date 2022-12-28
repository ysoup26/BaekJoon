#include <iostream>

using namespace std;

void fibo(int N,int N_i,int F_1,int F_2)
{
    //cout<<N<<N_i<<F_1<<F_2<<endl;
    if(N==0 ||N==1) //0, 1은 자기자신 그대로
    {
        cout<<N;
        return;
    }else if(N==N_i) //같으면 N번째 출력하고 종료
    {
        cout<<F_1+F_2;
        return;
    }else
    {
        int F=F_1+F_2;
        F_1=F_2;
        F_2=F;
        N_i++;
        fibo(N,N_i,F_1,F_2);
    }
}

int main()
{
    int N;
    cin>>N;
    fibo(N,2,0,1); //2번째부터 시작함
    return 0;
}