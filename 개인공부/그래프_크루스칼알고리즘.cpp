/*크루스칼 알고리즘

입력: 

노드 간선
노드A 노드B 간선값
~간선만큼의 개수

7 9 
1 2 9
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25

정답: 159
각 원소가 속한 집합: 1 1 1 1 5 5
부모 테이블: 1 1 2 1 5 5

*/
#include <iostream>
#include <vector>

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

}

//특정 원소가 속한 집합을 찾기
int find_parent(int x){
    //부모 노드가 자신이 아니면
    if(parent[x]!=x){
        parent[x] find_parent(parent[x]);
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
        if(isCycle(a,b)){
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