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
    //시작노드를 방문처리하고, 연결된 정점의 거리를 업데이트
    visited[start] = true;
    dist[start] = 0;
    for(int j=0;j<graph[start].size();j++){
        pair<int,int> p =graph[start][j];
        dist[p.first] = p.second;
    }
    //시작노드를 제외한 노드들에 방문함
    for(int i=2;i<=N;i++){
        //연결된 정점 중, 비용이 가장 적게드는 정점을 선택한다.
        int now_node = get_min_node();
        visited[now_node] = true;
        //갱신될 수 있는 정점의 거리를 갱신한다
        for(int j=0;j<graph[now_node].size();j++){
            pair<int,int> p =graph[now_node][j];
            int next_node = p.first;
            int next_dist = p.second;
            int cost = dist[now_node] + next_dist;
            if(dist[next_node] > cost){
                dist[next_node] = cost;
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