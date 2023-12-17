/*게임 개발

1초 128MB

문제 요약: 캐릭터는 매뉴얼대로 NxM맵을 돌아다닐 수 있다.
          캐릭터가 정지했을때, 캐릭터가 방문한 칸 수를 출력한다.
          (매뉴얼)
          1. 현재 방향을 기준으로 왼쪽 방향으로 회전하며 갈 곳을 정한다.
          2. 캐릭터의 왼쪽 방향에 갈 수 있다면 왼쪽 방향 회전, 한칸 전진
                                 갈 수 없다면 왼쪽 방향 회전만.
          3. 네방향 모두 갈 수 없으면 방향을 고정한 상태로 한 칸 뒤로 or 정지

입력: N M
     좌표A 좌표B 방향
     NxM의 맵정보를 한줄씩

풀이: 매뉴얼을 구현하는 방식으로 문제를 푼다. 
      특정 과정을 반복하기때문에 while문 안에서 매뉴얼이 수행되고,
      visited 배열로 체크한 칸은 이후에 갈 수 없도록 처리해준다.
      if문을 적절히 사용하여 매뉴얼을 구현한다.
*/

#include <iostream>

using namespace std;
//북동남서
int dXY[4][2]={
    {-1,0},{0,1},{1,0},{0,-1}
};

int d_left(int d)
{
    d-=1;
    if(d<0)
        d*=-1;
    d=d%4;
    return d;    
}

int main() {
    int N,M,x,y,d;
    cin>>N>>M>>x>>y>>d;
    int MAP[N][M];
    int visited[N][M];
    int cnt = 1;
    //맵 입력
    for(int n=0;n<N;n++)
    {
        for(int m=0;m<M;m++)
        {
            int tmp;
            cin>>tmp;
            MAP[n][m] = tmp;
            visited[n][m] = 0;
        }
    }
    int d_cnt,next_x,next_y;
    while(true)
    {
        if(d_cnt==4)  //3. 네 방향 모두 갈 수 없을 때
        {
            next_x = x-dXY[d][0];
            next_y = y-dXY[d][1];
            //3-1.한칸 뒤로 갈 수 있으면 뒤로 가고 다시 1번부터
            if(visited[next_x][next_y]==0 && MAP[next_x][next_y]==0)
            {
                x = next_x;
                y = next_y;
                cnt++;
                d_cnt=0;
            }else//3-2.종료
                break;
        }
        //1. 왼쪽 방향 회전
        d = d_left(d);
        next_x = x + dXY[d][0];
        next_y = y + dXY[d][1];
        //2-1. 한칸 전진 가능. 방향 회전 횟수 0으로 초기화
        if(visited[next_x][next_y]==0 && MAP[next_x][next_y]==0)
        {
            visited[next_x][next_y] = 1;
            x = next_x;
            y = next_y;
            d_cnt=0;
            cnt++;
            continue;
        }
        d_cnt++;
    }
    cout<<cnt;
    return 0;
}