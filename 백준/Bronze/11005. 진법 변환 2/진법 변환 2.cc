#include <iostream>
#include <string>

using namespace std;

int A_ = 'A'-10;

char int2alpa(int a){
    char result;
    if(a>=10 && a<= 35)
        result = 'A'-10 + a;
    else
        result = '0' + a;
    return result;
}

int main() {
    int N,B;
    cin>>N>>B;
    string result = "";
    //while문을 돌면서 N을 B로 계속 나누면서 진법 변환을 한자리씩 수행
    while(N>=B){ //진법 수보다 N이 작으면 종료
        int remain = N%B;
        result = int2alpa(remain) + result;
        N/=B;
    }
    //맨 첫번째 값은 위의 계산에서 제외되었기에 추가
    result = int2alpa(N) + result;
    cout<<result;
    return 0;
}