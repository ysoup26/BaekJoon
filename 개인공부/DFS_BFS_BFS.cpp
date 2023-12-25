#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int x,vector<int>*graph,bool *visited)
{
    queue<int> q;
    visited[x] = true;
    q.push(x);
    while(!q.empty())
    {
        int qx = q.front();
        q.pop();
        cout<<qx<<" ";
        for(int i=0;i<graph[qx].size();i++)
        {
            int next = graph[qx][i];
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;           
            }
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
    bfs(V,graph,visited);
    return 0;
}