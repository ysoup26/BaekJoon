/*위상정렬
    방향 그래프의 모든 노드를 방향성에 거스르지 않도록 순서대로 나열.
    

    알고리즘
    1. 진입차수가 0인 노드를 큐에 넣느다
    2. 큐가 빌 때까지 아래를 반복한다
        -큐에서 원소를 꺼내서, 해당 노드에 출발하는 간선을 그래프에서 제거
        -새롭게 진입차수가 0이 된 노드를 큐에 넣는다.


입력: 
7 8
1 2
1 5
2 3 
2 6
3 4
4 7
5 6
6 4


정답: 
1 2 5 3 6 4 7

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph;
int indegree[20+1]; //진입차수 정보에 대한 배열

int main(){
    int N,M;
    cin>>N>>M;
    fill(indegree,indegree+M,0);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]+=1;
    }
    
    return 0;
}