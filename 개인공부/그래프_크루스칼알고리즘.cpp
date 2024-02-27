/*크루스칼 알고리즘

입력: 

노드 간선
노드A 노드B 간선값
~간선만큼의 개수

7 9 
1 2 29
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25

정답: 159

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
        //사이클이 없다면 노드 연결
        if(!isCycle(edges[i].node[0],edges[i].node[1]))
        {
            sum+=edges[i].dist;
            union_parent(edges[i].node[0],edges[i].node[1]);
        }
    }
    cout<<sum;
    return 0;
}