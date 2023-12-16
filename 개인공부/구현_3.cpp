/*왕실의 나이트

1초 128MB

문제 요약: 8x8 지도에서 나이트는 특정 방법으로만 이동할 수 있다.
          수평으로 두칸 수직으로 한칸 or 수직으로 두칸 수평으로 한칸.
          특정 좌표가 주어질때, 그 좌표에서 이동할 수 있는 경우의 수를 구한다. 

입력: xy좌표(a1)

풀이: 최대 경우의 수는 8개 이므로, for문을 통해 이동 위치를 검사한다.
      이동 위치가 지도를 벗어나면 카운트 하지 않는다.
*/

#include <iostream>

using namespace std;

int moveArr[8][2]={
    {2,1},{2,-1},{-2,1},{-2,-1},
    {1,2},{1,-2},{-1,2},{-1,-2}
};

int main() {
    string xy;
    int x,y,cnt=0;
    cin>>xy;
    x = xy[0]-'a';
    y = xy[1]-'1';
    for(int i=0;i<8;i++)
    {
        int moveX = x+ moveArr[i][0];
        int moveY = y+ moveArr[i][1];
        if(moveX<0 || moveX>8 || moveY<0 || moveY>8)
            continue;
        cnt++;
    }
    cout<<cnt;
    return 0;
}