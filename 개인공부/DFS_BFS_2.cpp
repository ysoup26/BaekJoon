/*미로 탈출

1초 128MB

문제 요약: N x M 크기의 미로가 있다. 
(1,1)에서 시작해서 (N,M) 출구에 도착하는 최소 칸의 개수를 구해라
개수에는 시작 칸과 마지막 칸을 모두 포함한다.

괴물 있: 0 / 괴물 없: 1

입력: N x M의 미로 정보. N이 줄, M이 칸

5 6
101010
111111
000001
111111
111111

풀이: 최소칸, 미로 문제기 때문에 넓게 탐색하는 bfs방식이 더 효율적이다.
dfs는 출구가 아닌쪽을 계산할 가능성?

후기: 
*/


#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[200][200];
bool visited[200][200];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int N,M,cnt;


int bfs(int X,int Y){
    visited[X][Y] = true;
    map[X][Y] = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(X,Y));
    while(!q.empty()){
        //하나 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //그 위치 기준으로 4방향 탐색
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //조건(벗어남, 0임)에 맞지 않는 방향은 continue;
            if(nx<0 || nx>N || ny<0 || ny>M)
                continue;
            else if(map[nx][ny] == 0)
                continue;
            {
                map[nx][ny] = map[x][y] + 1;
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return map[N-1][M-1];
}

int main()
{
    cin>>N>>M;
    //입력
    for(int i=0;i<N;i++)
    {
        string tmp;
        cin>>tmp; //string으로 입력받아서 인덱스로 분리
        for(int j=0;j<M;j++)
        {
            map[i][j] = tmp[j]-'0';
            visited[i][j] = false;
        }
    }
    //(1,1)부터 미로 탈출 -> 배열은 (0,0)부터
    cout<<bfs(0,0);
    return 0;
}