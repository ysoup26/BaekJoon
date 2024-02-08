/*최단경로 중 플로이드 워셜
  : 출발 노드와 도착 노드 사이에 중점 노드를 이용한다.
    중점 노드를 매번 다르게 하여 값을 구하고 최소일때 갱신한다.

입력: 
n
m
m개의 a,b,c (출발 노드, 도착노드, 비용)

4
7
1 2 4
1 4 6
2 1 3
2 3 7
3 1 5
3 4 4
4 3 2

정답: 
0 4 8 6
3 0 7 9
5 9 0 4
7 11 2 0


*/

#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;


int main(){
    //노드와 간선 개수, 시작 노드 등을 입력받고 초기화함
    int N,M;
    cin>>N>>M;
    int graph[N+1][N+1];
    //초기상태를 모두 INF로 초기화
    for(int a=1;a<=N;a++){
        for(int b=1;b<=N;b++){
                graph[a][b]=INF;
        }
    }
    //자기 자신에게 가는 비용은 0으로
    for(int a=1;a<=N;a++){
        for(int b=1;b<=N;b++){
            if(a==b)
                graph[a][b]=0;
        }
    }
    //각 간선에 대한 정보를 입력받음
    for(int i=1;i<=M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b] = c;
    }
    //플로이드 워셜 알고리즘 
    for(int k=1;k<=N;k++){
        for(int a=1;a<=N;a++){
            for(int b=1;b<=N;b++){
                graph[a][b] = min(graph[a][b],graph[a][k]+graph[k][b]);
            }
        }
    }
    //결과 출력
    for(int a=1;a<=N;a++){
        for(int b=1;b<=N;b++){
            if(graph[a][b] == INF)
                cout<<"INF";
            else
                cout<<graph[a][b];
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}