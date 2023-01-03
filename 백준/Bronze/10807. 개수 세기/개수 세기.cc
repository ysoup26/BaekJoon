#include <iostream>

using namespace std;

int main()
{
    int N,Narr[100],v,v_cnt=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>Narr[i];
    }
    cin>>v;
    for(int i=0;i<N;i++)
    {
        if(v==Narr[i])
            v_cnt++;
    }
    cout<<v_cnt;

    return 0;
}