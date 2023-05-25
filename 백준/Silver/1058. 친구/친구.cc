#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int f_max = 0;
char graph[50][50];
int visited[50];

//bfs: 넓은 탐색
void bfs(int x)
{
    fill_n(visited,50,0);
    
    //친구의 인덱스와 깊이
    queue<pair<int,int>> q;
    q.push({x,1});
    visited[x] = 1; 
    int f_cnt = 0;
    
    //사람 x의 2-친구 확인
    while(!q.empty())
    {
        int now_x = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(depth>2) continue; //깊이 1~2만 검사
        for(int i=0;i<N;i++)
        {
            if(graph[now_x][i] == 'Y' && visited[i] == 0)
            {
                visited[i]=1;
                f_cnt++;
                q.push({i,depth+1}); //
            }
        }
    }
    if(f_cnt > f_max)
        f_max = f_cnt;
}

int main()
{
    cin>>N;
    
    
    
    for(int i=0;i<N;i++)
    {
         for(int j=0;j<N;j++)
        {
            cin>>graph[i][j]; //N-Y로 표현한 관계들
        }
    }
    //i 사람의 2-친구수 구하기
    for(int i=0;i<N;i++)
    {
        bfs(i);
    }
    cout<<f_max;
    //graph들의 길이를 확인해서, 가장 큰 것을
    return 0;
}
