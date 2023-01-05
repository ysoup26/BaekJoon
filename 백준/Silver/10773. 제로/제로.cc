#include <iostream>

using namespace std;

int main()
{
    int list[100000];
    int top=0,k,input;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>input;
        if(input==0)
        {
            list[--top]=0; //마지막이 0일때 지우려는 인덱스 내용을 0으로
        }else
        {
            list[top++]=input;
        }
    }
    int sum=0;
    for(int i=0;i<top;i++)
    {
        sum+=list[i];
    }
    cout<<sum;

    return 0;
}