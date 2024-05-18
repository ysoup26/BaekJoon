#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

int N,M;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs(int X,int Y){
    visited[X][Y] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(X,Y));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <1 || nx >N || ny <1 || ny >M){
                continue;
            }else if(map[nx][ny] == 0 || visited[nx][ny]){
                continue;
            }else{
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
                map[nx][ny] = map[x][y] + 1; 
            }   
        }
    }
    return map[N][M];
}

int main(){
    cin>>N>>M;
    for(int x=1;x<=N;x++){
        string input_;
        cin>>input_;
        for(int y=1;y<=M;y++){
           map[x][y] = input_[y-1]-'0';
           visited[x][y] = false;
        }
    }
    cout<<bfs(1,1);
    return 0;
}