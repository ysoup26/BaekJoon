#include <iostream>

using namespace std;

bool is666(int n){
    int cnt666 = 0;
    while(n/10>0){
        int last = n%10;
        if(last == 6) //해당 자리수에서 6찾음
            cnt666++;
        else          //cnt666초기화. 다시 찾기 시작
            cnt666 = 0;
        if(cnt666==3) //3개를 찾았으면 탈출
            break;
        n/=10;
    }
    if(n == 6)   //맨 앞자리가 6인경우 체크
            cnt666++;
    if(cnt666 == 3)
        return true;
    return false;
}

int main(){
    int N, result,cnt;
    result = 666;
    cnt = 1;
    cin>>N;
    while(true){
        if(N == cnt) // n번째 666을 찾으면 종료
            break;
        result++;
        if(is666(result)) //현재 숫자가 666을 가지고 있는지 확인
            cnt++;
    }
    cout<<result;
    return 0;
}