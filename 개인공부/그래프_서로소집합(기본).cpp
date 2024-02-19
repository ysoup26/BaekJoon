/*기본적인 서로소 집합 알고리즘
  : 서로소 집합 = 공통 원소가 없는 두 집합
  : union과 find라는 연산을 이용해서
    집합을 합치고, 부모 원소를 찾음

입력: 
6 4
1 4
2 3
2 4
5 6

정답: 
각 원소가 속한 집합: 1 1 1 1 5 5
부모 테이블: 1 1 2 1 5 5

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
    //union연산 E번 수행
    for(int i=1;i<=E;i++){
        int a,b;
        cin>>a>>b;
        union_parent(a,b);
    }
    //find로 각 원소가 속한 집합 출력(집합의 root노드)
    cout<<"각 원소가 속한 집합: ";
    for(int i=1;i<=V;i++){
        cout<<(find_parent(i))<<" ";
    }
    //부모 테이블 내용 출력
    cout<<"\n부모 테이블: ";
    for(int i=1;i<=V;i++){
        cout<<parent[i]<<" ";
    }
    return 0;
}