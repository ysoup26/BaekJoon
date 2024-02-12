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

int d[100+1];
vector<pair<int,int>> graph[100+1];
int N,M;

void print_node_dist(){
    for(int i=1;i<=N;i++){
        cout<<d[i]<<" ";
    }
}

void dijkstra(int start){
    priority_queue<pair<int,int>> PQ;
    PQ.push(make_pair(0,start));
    d[start] = 0;
    while(PQ.empty()==0){
        int dist = -PQ.top().first; //최소힙 사용을 위해 음수를 붙임()
        int now = PQ.top().second;
        PQ.pop();
        if(d[now] < dist) //현재의 노드 cost보다 크다면 무시
            continue;
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            int cost = dist + graph[now][i].second;
            if(d[next] > cost){
                d[next] = cost;
                PQ.push(make_pair(-d[next],next));
            }
        }
    }
}

int main(){
    //노드와 간선 개수, 시작 노드 등을 입력받고 초기화함
    int start;
    cin>>N>>M>>start;
    fill(d,d+101,INF);
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