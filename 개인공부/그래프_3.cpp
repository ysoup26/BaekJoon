/*
커리큘럼

2초 128MB

문제 요약: N개의 강의가 있다. 이 강의는 선수 강의의 개념이 있어서
          강의A를 들어야 강의B를 들을 수 있는 구조이다. 
         듣고자 하는 N개의 강의 정보가 주어졌을 때,
         N개의 강의에 대하여 수강하기까지 걸리는 최소 시간을 각각 출력해라



입력: N
     강의시간 (선수 강의의 번호) -1 //선수 강의가 없는 번호는 강의 시간만 존재,
                                   //각 줄은 -1로 끝난다.

풀이: 선수 강의로 인해 강의간에 그래프가 생성되고
      그래프 흐름대로 방문하는 구조이기 때문에 위상 정렬 알고리즘을 응용한다.
      방문을 하면서 각 강의시간을 갱신한다.
    최소 강의시간을 구하는 것이지만  
    선수 강의가 있다면 반드시 들어야 하기 때문에 max함수를 이용하여 더 큰 값으로 갱신한다.

입력: 
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

정답: 
10
20
14
18
17

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> graph[20+1];
int indegrees[20+1]; //진입차수 정보에 대한 배열
int times[20+1];    //강의 시간에 대한 배열

//위상 정렬함수
void topology_sort(){
    int result[N+1];
    queue<int> q;
    //time배열을 result에 복사
    for(int i=1;i<=N;i++){
        result[i] = times[i];
    }
    //시작시, 진입차수가 0인 노드 삽입
    for(int i=1;i<=N;i++){
        if(indegrees[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        //now노드와 연결된 노드 확인
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i];
            result[next] = max(result[next],result[now]+times[next]);
            indegrees[next]-=1;
            if(indegrees[next]==0)
                q.push(next);
        }
    }
    for(int i=1;i<=N;i++){
            cout<<result[i]<<"\n";
        }
}

int main(){
    cin>>N;
    fill(indegrees,indegrees+N+1,0);
    fill(times,times+N+1,0);
    for(int i=1;i<=N;i++){
        int t_input,before_node;
        cin>>t_input>>before_node;
        times[i] = t_input;
        while(before_node!=-1){ //-1가 아니면 진입차수 증가
            indegrees[i]+=1;
            graph[before_node].push_back(i);
            cin>>before_node;
        }
    }
    topology_sort();
    return 0;
}