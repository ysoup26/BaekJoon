/*모험가 길드

문제 요약: N명의 모험가가 있고, 각 모험가들은 공포도를 가지고 있다.
          이들로 그룹을 짜야하는데, 어떤 모험가의 공포도가 X라면
          이 모험가는 X명으로 이루어진 팀에 소속되어야 한다.
          최대 몇 개의 모험가 그룹을 만들 수 있는가?

입력: N(모험가 수) 
      N명의 모험가에 대한 공포도
5
2 3 1 2 2

풀이: 공포도가 큰 모험가 순서대로 팀을 배정하여 
      공포도가 큰 모험가가 배제되지 않도록 그룹을 짠다.
      모험가들의 공포도를 정렬하고, 전체 모험가수 - I번째 모험가의 공포도를 하여
      그룹을 카운트한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){ 
    int N;
    cin>>N;
    int peoples[N];
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        peoples[i] = tmp;
    }
    sort(peoples,peoples+N);
    int total = N;
    int group = 0;
    int index = 0;
    while(total>0&&index<N){
        if(total>=peoples[index])
        {
            total-=peoples[index];
            group++;
        }
        index++;


    }
    cout<<group;
    return 0;
}