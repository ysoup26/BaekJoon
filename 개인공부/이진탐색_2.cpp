/*떡볶이 떡 만들기

2초 128MB

문제 요약:  떡볶이 떡 절단기가 있다. 높이 H를 지정하면 떡을 자르고, 잘린 부분은 손님에게 준다.
            손님이 요청한 길이(M)가 있을 때, 높이 H의 최대값을 구해라
            (손님의 요청을 들어드리면서, 본인의 이득을 취하기 위해)

입력: 
        H M
        H개의 떡 길이
        4 6 
        19 15 10 17

풀이: 최적의 높이를 구하는 데에 이진탐색을 적용한다.
      (이진 탐색이 없다면 0~1억까지 길이를 계산해야함)
      0 ~ 가장 긴 떡의 길이 사이에 중간점을 잡고, 중간점을 이동시키면서 최적값을 찾는다.
      중간점을 이동시키고 계산했을때, 원하는 값보다 크다면 중간점을 높여야한다.
*/


#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int Narr[N];
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        Narr[i] = tmp;
    }
    //정렬
    sort(Narr,Narr+N);
    int s,m,e,result_H;
    s = 0;
    e = Narr[N-1];
    while(true){
        //시작점과 끝점이 교차되면 종료: 답이 없음
        if(s > e)
        {
            result_H = -1;
            break;
        }
        m = (s+e)/2;
        int sum = 0;
        for(int i=0;i<N;i++){
            if(Narr[i]-m>0)
                sum += (Narr[i]-m); 
        }
        if(sum == M) //자른 떡의 합이 손님 요구와 동일(정답)
        {
            result_H = m;
            break;
        }else if(sum > M)  //자른 떡의 합이 손님 요구보다 큼(시작점을 증가시켜 중점도 증가)
            s = m+1;
        else  //자른 떡의 합이 손님 요구보다 작음(끝점을 감소시켜 중점도 낮춤)
            e = m-1;
    }

    cout<<result_H;
    return 0;
}