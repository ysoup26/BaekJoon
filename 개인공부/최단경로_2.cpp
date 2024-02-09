/*전보

1초 128MB

문제 요약: N개의 도시가 있다. 도시 X에서 도시 Y로 메시지를 보내려면 
           도시 X에서 도시 Y로 향하는 통로가 있어야 한다.(반대는 안된다)
           도시 C에서 최대한 많은 도시에 메시지를 보내려고 할때,
           메시지를 받을 수 있는 도시의 개수와 
           모두 메시지를 받는 데까지 걸리는 시간을 출력해라

입력: N M C
      X Y Z 조합 M개

풀이: 한 도시에서 다른 도시로 가는 것이기 때문에 다익스트라알고리즘을 사용한다.
     기존 다익스트라 코드가 실행되고 for문을 돌면서 
     INF가 아닌 노드의 개수를 카운팅하고, 노드의 dist가 가장 큰 값을 출력한다.
     (메세지는 동시에 전달되기 시작함으로, 가장 큰 dist 값이 모두 메세지를 받는 시간이다)


3 2 1
1 2 4
1 3 2

정답: 
2 4


*/

#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int d[30000+1];
vector<pair<int,int>> graph[30000+1];
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

    int cnt, max_distance;
    for(int i=1;i<=N;i++){
        if(i!=INF){
            cnt++;
            max_distance = max(max_distance,d[i]);
        }
    }
    cout<<(cnt-1)<<" "<<max_distance;
    return 0;
}