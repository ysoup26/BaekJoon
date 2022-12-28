#include <iostream>

using namespace std;

int N; //퇴사날은 N+1
int T_i[16];
int P_i[16];
int max_val=0;

void calProfit(int workD,int sum,int before_add)
{
    if(workD == N + 1 ) //일 끝난 다음날이 퇴사날
    {
        max_val = max(max_val, sum);
        return ;
    } 
    else if (workD > N + 1){ //일 끝나는 날이 퇴사날을 넘음
        max_val = max(max_val, sum-before_add);
        return ;
    }
    
    for ( int i = workD + T_i[workD] ; i <= N + T_i[workD] ; i++)
        calProfit(i, sum + P_i[workD] , P_i[workD]);
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>T_i[i]>>P_i[i];
    }
    for(int i=1;i<=N;i++) //일하는 날의 시작값을 넣어줌
    {
        calProfit(i,0,0);
    }
    cout<<max_val;
    return 0;
}
