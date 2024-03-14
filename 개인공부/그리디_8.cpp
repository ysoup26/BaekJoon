/*볼링골 고르기 ** 

문제 요약: A와 B가 볼링을 치고 있다.
          공의 개수와 최대 무게가 주어질때,
          두 사람이 고를 수 있는 볼링공 번호의 조합을 구하시오.
          이때 서로 다른 볼링골을 골라야한다.
          -무게만 같고 서로 다른 공이 존재할 수 있다.
          -순서는 상관 없다.
입력: 

5 3
1 3 2 3 2

8

풀이: 경우의 수를 구해야하는데, 순서는 상관없고 
      무게가 같은 볼링골만 체크하며 구하면 된다.
      for문을 돌면서 두 공을 비교하고, 같은 값이라면 
      값을 증가시키지 않는다.
     
*/

#include <iostream>

using namespace std;

int main(){ 
    int N,M,cnt;
    cin>>N>>M;
    int balls[N];
    cnt = 0;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        balls[i] = tmp;
    }
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(balls[i]!=balls[j])
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}