
#include <iostream>
#include <vector>

using namespace std;

//깊은 탐색. 
void dfs(int x,vector<int>* graph,bool *visited)
{
    visited[x] = true;
    for(int i=0;i<graph[x].size();i++)
    {
        int next = graph[x][i];
        if(!visited[next])
        {
            dfs(next,graph,visited);
        }
    }
}

int main()
{
    int N,M,cnt;
    cin>>N>>M;
    
    vector<int> graph[N+1];
    bool visited[N+1];
    
    fill(visited,visited+N+1,false);
    
    for(int i=0;i<M;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2); //방향 없는 그래프
        graph[n2].push_back(n1);
    }
    cnt = 0;
    for(int i=1;i<=N;i++)
    {
        if(visited[i])  //방문한 정점이라면 dfs검사 x
            continue;
        dfs(i,graph,visited);
        cnt++;
    }
    cout<<cnt;
    return 0;
}
