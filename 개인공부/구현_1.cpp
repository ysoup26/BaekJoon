/*상하좌우

1초 128MB

문제 요약: NxN 공간에서 상하좌우로 한칸씩 이동할 수 있는데,
          계획서에서 어떻게 이동할지 L,R,U,D로 알려준다.
          계획서대로 이동한 최종 위치(좌표)를 출력한다.
          단, 계획서대로 이동중에 공간을 벗어난다면 그 명령은 무시한다.          

입력: N
      R L R R ...(개수는 정해지지않음)

풀이: for문을 돌면서 명령이 없을때까지 이동한다.
      이동한 좌표가 공간을 벗어나면 continue로 무효시킨다.
      명령의 개수를 알지 못하기 때문에 cin.eof를 이용한 입력처리가 필요하다.
*/

#include <iostream>

using namespace std;

//L,R,U,D
//{x,y} 수평방향으로 y값이 변경되고, 수직방향으로 x값이 변경된다.
int moveXY[4][2]={
     {0,-1},{0,1},{-1,0},{1,0}
};

int guide2idx(char c){
    if(c=='L')
        return 0;
    else if(c=='R')
        return 1;
    else if(c=='U')
        return 2;
    else
        return 3;
}

int main(){
    int N,x,y;
    cin>>N;
    x = y = 1;
    while(!cin.eof())
    {
        char g_c,g_i;
        int next_x,next_y;
        cin>>g_c;
        g_i = guide2idx(g_c);
        next_x = x + moveXY[g_i][0];
        next_y = y + moveXY[g_i][1];
        if(next_x>0 && next_x>N+1 && next_y>0 && next_y>N+1)
            continue;
        x = next_x;
        y = next_y;
    }
    cout<<"("<<x<<", "<<y<<")";
    return 0;
}