#include <iostream>
#include <vector>

using namespace std;

int T,M,N,K;
int graph[50][50];
int visited[50][50];

//상하좌우 (N,M)
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

//dfs:깊은 탐색
void dfs(int x,int y)
{
    int nextX,nextY;
    for(int i=0;i<4;i++)
    {
        nextX = x+dx[i];
        nextY = y+dy[i];
        //graph를 넘어가면 확인 x - 배열 접근 확인
        if( nextX<0 || nextY<0 || nextX>=N || nextY>=M)
            continue;
        if(graph[nextX][nextY]==1 && !visited[nextX][nextY])
        {
            visited[nextX][nextY] = 1;
            dfs(nextX,nextY);
        }
    }
}

int main()
{
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int cnt=0;
        cin>>M>>N>>K;
        fill_n(&graph[0][0],50*50,0);
        fill_n(&visited[0][0],50*50,0);
        
        
        //배추-1 없음-0
        for(int i=0; i<K; i++){
            int x,y;
            cin>>x>>y;
            graph[y][x]=1;
        }
        /*//입력 확인용
        cout<<"\n";
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                //배추가 있고, 방문안함
                if(graph[i][j]==1 && !visited[i][j])
                {
                    visited[i][j] = 1;
                    dfs(i,j); //dfs로 인접 배추들 방문
                    cnt++;
                }
                
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
