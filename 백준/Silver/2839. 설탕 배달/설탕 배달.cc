#include <iostream>

using namespace std;

int main()
{
    int N,result=0,del5=0;
    cin>>N;
    //5를 우선시 하되, 오류가 뜨면 5를 줄여서 재계산
    while(true)
    {
        int nextN,k5,k3;
        k5=(N/5)-del5;
        nextN=N%5+(del5*5);
        if(nextN%3!=0 && k5!=0)
        {
            del5++;
            continue;
        }
        if(nextN%3!=0)
            result=-1;
        else
        {
            k3=nextN/3;
            //cout<<" "<<k5<<" "<<k3<<endl;
            result=k5+k3;
        }
        break;
    }
    cout<<result;
    return 0;
}