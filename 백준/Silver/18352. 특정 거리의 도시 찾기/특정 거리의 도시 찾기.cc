#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

vector<int> graph[300000+1];
bool visited[300000+1];
int min_dist[300000+1];
vector<int> K_idx_vector;

int N,M,K,X;


void dijktra(int start){
    queue<int> q;
    min_dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i];
            int cost = min_dist[now]+1;
            if(min_dist[next] > cost){
                min_dist[next] = cost;
                q.push(next);
            }
        }
    }

}

int main(){
    cin>>N>>M>>K>>X;
    //간선 입력
    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    fill(visited+1,visited+N+1,false);
    fill(min_dist+1,min_dist+N+1,INF);
    dijktra(X);
    int Is_K = false;
    for(int i=1;i<=N;i++){
        //cout<<min_dist[i]<<" ";
        if(min_dist[i]==K){
            cout<<i<<"\n";
            Is_K = true;
        }
    }
    if(!Is_K)
        cout<<-1;
}