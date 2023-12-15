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
      명령의 개수를 알지 못하기 때문에 입력처리가 필요하다.
*/

#include <iostream>

using namespace std;

//L,R,U,D
int moveXY[4][2]={
     {0,-1},{0,1},{-1,0},{1,0}
};

int guide2idx(string c){
    if(c.compare("L")==0)
        return 0;
    else if(c.compare("R")==0)
        return 1;
    else if(c.compare("U")==0)
        return 2;
    else
        return 3;
}

int main(){
    int N,x,y;
    cin>>N;
    x = y = 1;
    while(!cin.eof()) /*eof의 값은 -1이기 때문에 char로 입력받으면 문제 발생(-1을 입력으로 취급하여 한번 더 실행됨)*/
    {
        string g_c;
        int g_i;
        int next_x,next_y;
        cin>>g_c;
        g_i = guide2idx(g_c);
        next_x = x + moveXY[g_i][0];
        next_y = y + moveXY[g_i][1];
        if(next_x<1 || next_x>N || next_y<1 || next_y>N)
            continue; 
        x = next_x;
        y = next_y;
    }
    cout<<"("<<x<<", "<<y<<")";
    return 0;
}