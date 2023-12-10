/*큰 수의 법칙 -심화-
2019 국가 교육기관 코딩 테스트

문제 요약: 다양한 수로 이루어진 배열이 있을때,
주어진 수들을 M번 더해 가장 큰 수를 만들어라.
단, 같은 인덱스를 연속해서 더할때 때 K번을 초과하면 안된다.

입력: N(배열 크기) M K
      N만큼의 숫자나열

심화: N의 값이 매우 커서 for문을 사용하면 시간오버가 되는 경우

풀이: 가장 큰 수를 만들되, K번 초과하면 안된다는 조건때문에 [9 9 9 8]. 이런식의 수열이 반복된다.
     이를 이용하여 반복되는 수열의 합을 곱하는 방식으로 연산을 줄인다
      M/(K+1)을 하면 몇 번 곱해야되는지 알 수 있고, 나누어떨어지지 않는 경우를 고려하여 
      M%(K+1)도 체크한다.
      >>최종 수식 (f*K+s)*fs_quotient + (f*fs_remainder)
*/

#include <iostream>

using namespace std;

int main(){

    int N,M,K;
    int sum = 0;
    int f,s;
    cin>>N>>M>>K;
    int Narr[N];
    
    //배열 입력
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        Narr[i] = tmp;
    }
    //배열 내림차 정렬
    for(int i=0;i<N-1;i++)
    {
        for(int j=i;j<N;j++)
        {
            if(Narr[i]<Narr[j])
            {
                int tmp = Narr[i];
                Narr[i] = Narr[j];
                Narr[j] = tmp;
            }
        }
    }
    
    f = Narr[0];
    s = Narr[1];
    
    //덧셈
    int fs_quotient = M/(K+1);
    int fs_remainder = M%(K+1);
    sum = (f*K+s)*fs_quotient + (f*fs_remainder);
    cout<<sum;
    return 0;
}