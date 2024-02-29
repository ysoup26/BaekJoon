/*
팀 결성

2초 128MB

문제 요약: 0~N번의 학생이 있다. 
          처음에는 모든 학생이 서로 다른팀으로 구분되지만
          선생님의 "팀 합치기 연산"과 "같은 팀 여부 확인"으로
          팀이 생성되고 확인된다. 
          선생님이 M개의 연산을 수행했을때, 
          "같은 팀 여부 확인" 연산은 그 결과를 출력한다.

        팀 합치기 연산: 0
        같은 팀 여부 확인: 1

입력: N M
      v a b (v: 연산 명, a: 학생a, b: 학생b) 가 M번 반복

풀이: 서로소 집합 코드를 응용하여 학생들을 합치고, 부모 노드가 같은지 확인한다.

입력: 
7 8
0 1 3
1 1 7
0 7 6
1 7 1 
0 3 7
0 4 2
0 1 1
1 1 1

정답: 
NO
NO
YES

*/

#include <iostream>

using namespace std;

int N,M;
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
    cin>>N>>M;
    //부모 테이블에서, 부모를 자기 자신으로 초기화
    for(int i=0;i<=N;i++){
        parent[i] = i;
    }
    //입력에 따른 2가지 연산 수행
    for(int i=0;i<M;i++){
        int v,a,b;
        cin>>v>>a>>b;
        if(v==0){
            union_parent(a,b);
        }else{
            if(find_parent(a)==find_parent(b))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}