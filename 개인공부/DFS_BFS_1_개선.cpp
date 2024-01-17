/*음료수 얼려 먹기

1초 128MB

문제 요약: N x M 크기의 얼음틀로부터 생성되는 아이스크림의 개수를 구한다.
           0: 구멍이 뚫림 1: 칸막이 

입력: N x M의 얼음틀 정보. N이 줄, M이 칸

4 5
0 0 1 1 0
0 0 0 1 1
1 1 1 1 1
0 0 0 0 0

풀이: (0,0)부터 dfs 탐색을 시작한다.
더 이상 탐색할 것이 없으면 얼음틀 개수를 증가시킨다.
재귀함수임을 살려서 범위와 방문이 옳지 않으면 false
옳으면 dfs 탐색을 이어나간다.

후기: 기존 풀이 방식이 복잡하고 필요없는 부분이 많아서
더 좋은 코드를 적용해보았다.
*/


#include <iostream>
#include <algorithm>

using namespace std;

int map[1000][1000];
bool visited[1000][1000];
int N,M;

bool dfs(int x,int y){
    //범위를 벗어남
    if(x<0 || x>=N || y<0 || y>=M){
        return false;
    }
    //이미 방문함
    if(visited[x][y]==true || map[x][y]==1){
        return false;
    }
    visited[x][y] = true;
    //상하좌우 4방향 탐색
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
    return true;
};


int main()
{
    int cnt;
    cin>>N>>M;
    //입력
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int tmp;
            cin>>tmp;
            map[i][j] = tmp;
            visited[i][j] = false;
        }
    }
    //얼음틀 계산
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            if(dfs(x,y))
            {
                cnt++;
            }
        }

    }
    cout<<cnt;
    return 0;
}