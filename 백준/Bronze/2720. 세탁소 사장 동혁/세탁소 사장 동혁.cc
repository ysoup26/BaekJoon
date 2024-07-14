#include <iostream>

using namespace std;

int coins[4] = {25,10,5,1};
int coins_N[4] = {0,0,0,0};

//1달러 기준으로 입력받았기 때문에 동전들도 그에 맞춰 *100을 해준다
//실수 단위로 작성했을땐 "틀렸습니다" -> 실수로 나눗셈을 하며 오차가 발생하는듯
int main(){
    int T;
    cin>>T;
    for(int test_case = 0;test_case<T;test_case++){
        float money;
        int c_idx;
        cin>>money;
        c_idx = 0;
        while(c_idx<4){ // 동전 단위를 감소시키며 계산
            int coin_N = money/coins[c_idx];
            coins_N[c_idx] = coin_N;
            money = money - (coins[c_idx]*coin_N);
            c_idx++;
        }
        for(int i=0;i<4;i++){
            cout<<coins_N[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}