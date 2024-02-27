/*
서로소집합은 무방향 그래프의 사이클 판별에 사용될 수 있다.

간선 관계를 확인하면서 두 집합을 합치는 과정을 수행함
->union 연산은 그래프에서의 간선과 같다

사이클 판별 알고리즘
    각 간선을 확인. 두 노드의 루트 확인
        - 루트 노드가 같다면 사이클이 발생한 것.
        - 루트 노드가 다르다면 union 수행
    모든 간선에 대해 1번 과정 반복

어떤 간선 관계인 노드들의 부모 루트가 같다면
모두 연결되어있는 사이클이 있다고 볼 수 있다.

입력: 
3 3 
1 2
1 3
2 3

정답: 
사이클이 발생했습니다.

*/

#include <iostream>
#include <vector>

using namespace std;

int V,E;
int parent[20];

//특정 원소가 속한 집합을 찾기
int find_parent(int x){
    //부모 노드가 자신이 아니면
    if(parent[x]!=x){
        parent[x] = find_parent(parent[x]);
    }
    return parent[x];
}

//두 원소가 속한 집합을 합치기
void union_parent(int a,int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a < b) //작은 원소 쪽에 합쳐짐
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    //노드와 간선 개수, 시작 노드 등을 입력받고 초기화함
    cin>>V>>E;
    //부모 테이블에서, 부모를 자기 자신으로 초기화
    for(int i=1;i<=V;i++){
        parent[i] = i;
    }
    bool IsCycle = false;

    //union연산 E번 수행
    for(int i=1;i<=E;i++){
        int a,b;
        cin>>a>>b;
        if(find_parent(a) == find_parent(b)){
            IsCycle = true;
            break;
        }          
        union_parent(a,b);
    }

    if(IsCycle)
        cout<<"사이클이 발생했습니다.";
    else
        cout<<"사이클이 발생하지 않았습니다.";
    return 0;
}