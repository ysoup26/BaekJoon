#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int x,y;
    int max=(5000/3)+((5000%3)/5);
    int max_remain=((5000%3)%5);
    int least=max;
    if(N<3)
    {
        cout<<-1; return 0;
    }
    for(int i=N/5;i>=0;i--)
    {
        int xy;
        x=i;
        y=(N-i*5)/3;
        if(5*x+3*y==N&&x+y<least)
    	    least=x+y;
    }
     //합이 최대와 같을때 or least가 한번도 변경되지 않았을때
    if(least==max&&max_remain!=0)
        cout<<-1;
    else
        cout<<least;
    
    return 0;
}
