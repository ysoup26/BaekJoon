#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int x,vector<int>*graph,bool *visited)
{
    visited[x] = true;
    cout<<x<<" ";
    for(int i=0;i<graph[x].size();i++)
    {
        int next = graph[x][i];
        if(!visited[next])
        {
            dfs(next,graph,visited);
        }
    }
}

//간선은 양방향, 간선이 여러개면 작은 수부터
int main()
{
    int N,M,V;
    cin>>N>>M>>V;
    vector<int> graph[N+1];
    bool visited[N+1];
    
    fill(visited,visited+N+1,false);
    
    for(int i=0;i<M;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
        //push하면서 내부 정렬
        sort(graph[n1].begin(),graph[n1].end());
        sort(graph[n2].begin(),graph[n2].end());
    }
    dfs(V,graph,visited);
    return 0;
}