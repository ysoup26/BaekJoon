/*숫자 카드 게임
2019 국가 교육기관 코딩 테스트

시간제한 1초. 메모리 제한 128MB

문제 요약: 카드가 N x M 형태로 놓여있다.
           한 행(N)을 선택하고, 그 행 중에 가장 숫자가 낮은 카드를 선택한다.
           그 카드는 다른 행에서 선택했을 때보다 커야한다.
           즉, 행에선 최소이되 다른 행의 최소보단 큰 카드를 골라야한다.
           

입력: N M
      N_1의 M들
      N_2의 M들...

풀이: 입력받은 카드 배열을 행마다 오름차순으로 정렬한다.
      각 행의 0번째 인덱스를 비교하여 큰 값을 출력한다.
*/
#include <iostream>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    int card[N][M];
    //배열 입력
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
        {
            int tmp;
            cin>>tmp;
            card[i][j] = tmp;
        }
    }
    //중첩 for문 정렬
    for(int n=0;n<N;n++)
    {
        for(int i=0;i<M-1;i++){
            for(int j=i;j<M;j++)
            {
                if(card[n][i]>card[n][j])
                {
                    int tmp = card[n][i];
                    card[n][i] = card[n][j];
                    card[n][j] = tmp;
                }
            }
        }
    }
    int max = 0;
    //값 비교
    for(int n=0;n<N;n++)
    {
        if(card[n][0]>max)
            max = card[n][0];
    }
    cout<<max;
    
    return 0;
}