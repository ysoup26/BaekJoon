/*모험가 길드
2019 국가 교육기관 코딩 테스트

문제 요약: 다양한 수로 이루어진 배열이 있을때,
주어진 수들을 M번 더해 가장 큰 수를 만들어라.
단, 같은 인덱스를 연속해서 더할때 때 K번을 초과하면 안된다.

입력: N(배열 크기) M K
      N만큼의 숫자나열

*/

#include <iostream>

using namespace std;

int main(){

    int N,M,K;
    int sum = 0, count = 0, big_i = 0;
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

    //덧셈 수행
    //가장 큰 값으로 덧셈을 하나 K번을 넘어가면 두번째로 큰 값을 더하고 돌아옴  
    for(int i=0;i<M;i++)
    {
        if(count==K)
        {
            sum+=Narr[1];
            count = 0;
        }else{
            sum+=Narr[0];
            count++;
        }

    }
    cout<<sum;
    return 0;
}