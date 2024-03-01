/*
도시 분할 계획

2초 256MB

문제 요약: 어떤 마을은 N개의 집과 그 집들을 연결하는 M개의 길로 이루어져있다.
          마을이 크고, 길마다 유지비가 있기 때문에
          마을을 2개의 분리된 마을로 나누면서, 유지비를 최소로 하고싶다.
          최소 유지비를 출력한다.


입력: N M
      a b d ( a: 집a, b: 집b, d: 유지비) 가 M번 반복

풀이: 최소의 유지비를 찾아야하는 문제이기 때문에 크루스칼 알고리즘을 이용한다.
     최소 신장 트리를 찾고, 가장 비용이 큰 간선을 제거하면 
     최소 신장 트리가 2개의 부분 그래프로 나눠진다고 할 수 있다.

입력: 
7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1 
6 5 3
4 5 3
6 7 4

정답: 
8

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V,E;
int parent[20];

class Edge{
    public: 
        int node[2];
        int dist;
        Edge(int a,int b,int dist){
            this->node[0] = a;
            this->node[1] = b;
            this->dist = dist;
        }
        bool operator<(Edge &edge){
            return this->dist < edge.dist;
        }
        void print_member(){
            cout<<this->node[0]<<" "<<this->node[1]<<" "<<this->dist<<"\n";
        }
};

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

bool isCycle(int a,int b)
{
    if(find_parent(a) == find_parent(b))
        return true;
    else    
        return false;
}

int main(){
    cin>>V>>E;
    vector<Edge> edges;
    int sum = 0;
    int big = 0; //가장 비용이 큰 간선(정렬 되었기때문에 edges의 마지막)
    //부모 테이블에서, 부모를 자기 자신으로 초기화
    for(int i=1;i<=V;i++){
        parent[i] = i;
    }
    //간선 정보를 입력 받음
    for(int i=0;i<E;i++){
        int a,b,dist;
        cin>>a>>b>>dist;
        edges.push_back(Edge(a,b,dist));
    }
    //오름차순 정렬
    sort(edges.begin(),edges.end());
    //낮은 비용의 간선부터 연결 수행
    for(int i=0;i<edges.size();i++){
        int a = edges[i].node[0];
        int b = edges[i].node[1];
        int d = edges[i].dist;
        //사이클이 없다면 노드 연결
        if(!isCycle(a,b))
        {
            sum+=d;
            big = d;
            union_parent(a,b);
        }
    }
    cout<<(sum-big);
    return 0;
}