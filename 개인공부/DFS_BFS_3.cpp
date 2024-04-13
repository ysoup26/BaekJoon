/*특정 거리의 도시 찾기

2초 256MB

문제 요약: 1~N번 까지의 도시와 M개의 단방향 도로가 있다.
           특정 도시 X로부터 출발하여 도달할 수 있는 모든 도시 중에서,
           최단 거리가 정확히 K인 도시의 번호를 출력해라.

*이때 모든 도로의 거리는 1이다.



입력: 
4 4 2 1
1 2
1 3
2 3
2 4

>>4

풀이: 특정 도시에서 시작하여 최단 거리를 구하는 것이기 때문에 bfs를 사용한다.
      dfs를 사용하면 깊은 탐색이기 때문에 탐색 과정에서 보다 긴 거리를 계산하게 됨
      한 도시에서 연결된 다른 도시를 탐색할 때 거리를 1씩 증가시키는 방식으로
      거리를 계산하게 하였음. 한단계씩 깊어지기 때문에 
      동일 단계의 거리들은 같은 가중치를 가짐

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_ 300000

using namespace std;

vector<int> graph[MAX_+1];
bool visited[MAX_+1];
int min_range[MAX_+1];

void bfs(int x)
{
    queue<int> q;
    visited[x] = true;
    q.push(x);
    int now_k = 1;
    while(!q.empty())
    {
        int qx = q.front();
        q.pop();
        for(int i=0;i<graph[qx].size();i++)
        {
            int next = graph[qx][i];
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;   
                min_range[next] = now_k;
            }
        }
        now_k++;
    }
}

//간선은 양방향, 간선이 여러개면 작은 수부터
int main()
{
    int N,M,K,X;
    cin>>N>>M>>K>>X;
    
    fill(visited,visited+N+1,false);
    for(int i=0;i<M;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
    }
    
    bfs(X);
    for(int i=1;i<=N;i++){
        if(min_range[i]==K)
            cout<<i<<"\n";
    }
    return 0;
}