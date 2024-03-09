/*모험가 길드

문제 요약: N명의 모험가가 있고, 각 모험가들은 공포도를 가지고 있다.
          이들로 그룹을 짜야하는데, 어떤 모험가의 공포도가 X라면
          이 모험가는 X명으로 이루어진 팀에 소속되어야 한다.
          최대 몇 개의 모험가 그룹을 만들 수 있는가?

입력: N(모험가 수) 
      N명의 모험가에 대한 공포도
5
2 3 1 2 2

풀이: 공포도가 큰 모험가 기준으로 팀을 배정하여 
      공포도가 큰 모험가가 배제되지 않도록 그룹을 짠다.
      모험가들의 공포도를 정렬하고, 
      기준 모험가 = 기준 모험가 + 기준 모험가의 공포도
      를 통해 그룹 수를 카운트한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){ 
    int N;
    cin>>N;
    int p[N];
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        p[i] = tmp;
    }
    sort(p,p+N);
    reverse(p,p+N);
    int group = 0;
    int p_i = 0;
    while(true){
        int now_fear =  p[p_i];
        if((now_fear+p_i)>N) //다음 모험가의 번호가 N을 넘어서면 이 그룹은 유효하지 않다. break
            break;
        group++;
        p_i+=now_fear;
    }
    cout<<group;
    return 0;
}