#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[25][25];
int visited[25][25];
int N,danzi;
vector<int> total_danzi;


void dfs(int x,int y){
    //접근 가능한 좌표인지 확인
    if(map[x][y] == 0|| visited[x][y]==1 || x<0 || x>=N || y<0 || y>=N ){
        return;
    }
    visited[x][y] = 1;
    danzi++;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
    return;
}

int main() {
    cin>>N;
    //map과 visited 값 삽입
    for(int x=0;x<N;x++){
        string in;
        cin>>in;
        for(int y=0;y<N;y++){
            map[x][y] = in[y]-'0';
            visited[x][y] = 0;
        }
    } 
    //입력 확인
    /*for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            cout<<map[x][y]<<" ";
        }
        cout<<"\n";
    } */
    //방문할 수 있는 좌표 찾기
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            if(map[x][y] == 1 && visited[x][y] == 0){
                danzi = 0;
                dfs(x,y);
                total_danzi.push_back(danzi);
            }
        }
    } 
    //최종 출력
    sort(total_danzi.begin(),total_danzi.end());
    cout<<total_danzi.size()<<"\n";
    for(int i=0;i<total_danzi.size();i++){
        cout<<total_danzi[i]<<"\n";
    }
    return 0;
}