#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int max_w = 0;
    int rope[N];
    //입력
    for(int i=0;i<N;i++){
        cin>>rope[i];
    }
    sort(rope,rope+N); //오름차 정렬
    //가장 긴 로프부터 계산
    //로프 병렬 연결시, 고르게 나눠갖기 때문에 가장 짧은 로프를 기준으로 하게 된다
    //짧은 로프 * k를 하게 되면 중량 값이 나오게 됨
    int k=1;
    for(int i=N-1;i>=0;i--){
        int now_w = rope[i]*k;
        if(now_w > max_w)
            max_w = now_w;
        k++;
    }
    cout<<max_w;
    return 0;
}