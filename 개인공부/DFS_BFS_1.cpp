/*음료수 얼려 먹기

1초 128MB

문제 요약: N x M 크기의 얼음틀로부터 생성되는 아이스크림의 개수를 구한다.
           0: 구멍이 뚫림 1: 칸막이 

입력: N x M의 얼음틀 정보. N이 줄, M이 칸

0 0 1 1 0
0 0 0 1 1
1 1 1 1 1
0 0 0 0 0

풀이: 

*/


#include <iostream>
#include <algorithm>

using namespace std;

void list_print(int list[],int n)
{
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}


int main()
{
    int N,M,cnt;
    cin>>N>>M;
    int ice[N][M];
    bool visited[N][M];
    fill(visited,visited+N*M,false);
    //입력
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int tmp;
            cin>>tmp;
            ice[i][j] = tmp;
        }
    }
    dfs(ice,&cnt);
    //list_print(list,n);
    return 0;
}