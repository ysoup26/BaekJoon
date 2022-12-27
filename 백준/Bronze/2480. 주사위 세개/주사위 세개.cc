#include <iostream>

using namespace std;

int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    if(A==B&&A==C&&B==C)//3개 동일
    {
        cout<<10000+(1000*A);
    }else{
        if(A==B||A==C)
            cout<<1000+(100*A);
        else if(B==C)
            cout<<1000+(100*B);
        else
        {
            int Max=max(A,B);
            Max=max(Max,C);
            cout<<100*Max;

        }    
    }
    return 0;
}