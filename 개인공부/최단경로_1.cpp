/*미래도시

1초 128MB

문제 요약: 방문 판매원 A는 1번 회사에서 출발해서 K번 회사에 들른 후, X번 회사에 가려고한다.
          한 회사에서 다른 회사로 이동하는 시간이 무조건 1이라고 할 때
          1번 회사->K번 회사->X번 회사로 가는 최단 시간을 출력해라.

입력: N M
      M개의 X와 K조합들
      X K

풀이: 중점인 K번을 이용하는 플로이드 워셜로 풀 수 있는 문제이다.
      기본에 작성된 플로이드 워셜 코드를 일부 수정해서 풀었다.


5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5

정답: 
3


*/

#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;


int main(){
    //노드와 간선 개수, 시작 노드 등을 입력받고 초기화함
    int N,M,X,K;
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
        int a,b;
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    //플로이드 워셜 알고리즘 
    for(int k=1;k<=N;k++){
        for(int a=1;a<=N;a++){
            for(int b=1;b<=N;b++){
                graph[a][b] = min(graph[a][b],graph[a][k]+graph[k][b]);
            }
        }
    }
    cin>>X>>K;
    //결과 출력
    int dist = graph[1][K]+graph[K][X];
    if(dist >=INF)
        cout<<"-1";
    else
        cout<<dist;
    return 0;
}