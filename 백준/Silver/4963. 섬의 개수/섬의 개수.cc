// 대각선까지 방문 시켜야하는게 특징이었던 dfs문제

#include <iostream>

using namespace std;

int map[50][50];
bool visited[50][50];

int dfs(int x,int y,int h,int w){
    if(visited[x][y] || map[x][y] == 0){
        return 0;
    }
    if(x < 0 || x >= h || y < 0 || y >= w)
    {
        return 0;
    }
    visited[x][y] = true;
    //4방향 탐색
    dfs(x-1,y,h,w);
    dfs(x,y-1,h,w);
    dfs(x+1,y,h,w);
    dfs(x,y+1,h,w);
    //대각선도 고려
    dfs(x-1,y-1,h,w);
    dfs(x-1,y+1,h,w);
    dfs(x+1,y-1,h,w);
    dfs(x+1,y+1,h,w);
    return 1;
}

int main(){
    while(!cin.eof()){
        int w,h,result;
        cin>>w>>h;
        result = 0;
        if( w == 0 && h == 0)
            break;
        for(int x=0;x<h;x++){
            for(int y=0;y<w;y++){
                cin>>map[x][y];
                visited[x][y] = false;
            }
        }
        for(int x=0;x<h;x++){
            for(int y=0;y<w;y++){
                if(dfs(x,y,h,w)){
                    result++;
                }
            }
        }
        cout<<result<<"\n";
    }
    return 0;
}