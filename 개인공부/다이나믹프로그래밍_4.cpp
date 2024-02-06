/*효율적인 화폐구성
1초 128MB

문제 요약: N가지 종류의 화폐를 이용해서 M원을 만들어야 한다.
          단 최소한의 화폐를 사용해야 하며, 그 화폐 개수를 출력한다.

입력: N M
      N개의 숫자들
    2 15
    2
    3
        

풀이: 현 금액의 최소 화폐 개수를 구하려면 이전 화폐 정보를 이용하면 된다.
      최소 금액부터 순차적으로 화폐 개수를 갱신하는데, 화폐 종류별로 for문을 돌려서
      최종적으로 최소 개수가 저장되게 한다.
      ex) 15원의 최소개수를 알고싶으면 13(15-2)의 최소개수 or 12(15-3)의 최소개수중 더 작은 값을 선택하면 된다

*/


#include <iostream>
#include <algorithm>

using namespace std;

int d[10001];
int arr[101];

int main(){
    int N,M;
    cin>>N>>M;
    //입력
    for(int i=1;i<=N;i++){
        int tmp;
        cin>>tmp;
        arr[i] = tmp;
    }
    //이전 금액의 화폐 개수를 이용하기 때문에 Max금액보다 큰 10001로 초기화
    for(int i=1;i<=M;i++)
        d[i] = 10001;
    sort(arr,arr+N);
    
    //계산: 각 화폐들을 이용해서 배열 d를 갱신한다.
    for(int i=1;i<=N;i++){
        for(int j=arr[i];j<=M;j++){
            if(d[j-arr[i] != 10001])  //이전 값이 10001이라면 현 화폐로 계산할 수 없는 값
                d[j] = min(d[j],d[j-arr[i]]+1);
        }
    }
    if(d[M] == 10001)
        cout<<-1;
    else
        cout<<d[M];
    return 0;
}