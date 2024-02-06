/*최단경로 중 다익스트라 알고리즘
  : 현재 기준 최소 노드를 선택하고, 
    연결되는 노드의 최소값을 함께 갱신시킴

입력: 
6 11
1 
1 2 2
1 3 5
1 4 1
2 3 3
2 4 2
3 2 3
3 6 5
4 3 3
4 5 1
5 3 1
5 6 2

정답: 
0 2 3 1 2 4


*/

#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

bool visited[100+1];
int dist[100+1];
vector<pair<int,int>> graph[100+1];
int N,M;

void print_node_dist(){
    for(int i=1;i<=N;i++){
        cout<<dist[i]<<" ";
    }
}

int get_min_node(){
    int min_node;
    int min_dist = INF;
    for(int i=1;i<=N;i++){
        if(min_dist > dist[i] && !visited[i])
        {
            min_dist = dist[i];
            min_node = i;
        }
    }
    return min_node;
}

void dijkstra(int start){
    priority_queue<pair<int,int>> PQ;
    PQ.push(make_pair(0,start));
    dist[start] = 0;
    while(PQ.empty()==0){
        int cost = -PQ.top().first; //최소힙 사용을 위해 음수를 붙임()
        int node = PQ.top().second;
        PQ.pop();
        for(int i=0;i<graph[node].size();i++){
            int next_node = graph[node][i].first;
            int next_dist = graph[node][i].second;
            if(dist[next_node] > cost + next_dist){
                dist[next_node] = cost + next_dist;
                PQ.push(make_pair(-dist[next_node],next_node));
            }
        }
    }
}

int main(){
    //노드와 간선 개수, 시작 노드 등을 입력받고 초기화함
    int start;
    cin>>N>>M>>start;
    fill(visited,visited+101,false);
    fill(dist,dist+101,INF);
    for(int i=1;i<=M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    //다익스트라 알고리즘 실행
    dijkstra(start);
    //각 거리 출력
    print_node_dist();
    return 0;
}