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

풀이: 0인 칸을 찾아서 dfs로 탐색을 시작하고, 
더 이상 탐색할 것이 없으면 얼음틀 개수를 증가시킨다.
0인 칸을 찾는 것은 2중 for문을 이용한 완전 탐색. 
연산을 줄이기 위해서 직전 시작점을 기억해서 거기부터 탐색한다.

후기: dfs 방식을 잠깐 까먹어서 함수 구현 방향이 이상하게 흘러갔었다.
     dfs는 재귀함수 방식임을 확인하고 수정하여 문제를 풀었다.
*/


#include <iostream>
#include <algorithm>

using namespace std;

int map[1000][1000];
bool visited[1000][1000];
int N,M;

//right, down
int go[2][2] = {
    {0,1},{1,0}
};

void dfs(int startX,int startY){
    visited[startX][startY] = true;
    cout<<"visited: "<<startX<<","<<startY<<"\n";
    for(int i=0;i<2;i++){
        int nextX,nextY;
        nextX = startX + go[i][0];
        nextY = startY + go[i][1];
        //범위를 안 벗어났고 자신의 오른쪽&아래쪽에 방문 가능
        if(nextX<N && nextY<M && map[nextX][nextY]==0 && !visited[nextX][nextY]){
            dfs(nextX,nextY);
        }
    }
    
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
    int startX = 0, startY = 0;
    while(true){
        //시작 칸 탐색
        bool isIce = false;
        for(int x=startX;x<N && !isIce;x++){
            for(int y=0;y<M;y++){
                if(map[x][y] == 0 && !visited[x][y])
                {
                    isIce = true;
                    startX = x;
                    startY = y;
                    break;
                }
            }
        }
        //시작 칸 탐색 for문이 종료되었는데 isIce가 false이다 >> 검사할 수 있는 얼음칸이 없다.
        if(!isIce){
            break;
        }
        dfs(startX,startY);
        cnt++;
        
    }
    cout<<cnt;
    return 0;
}