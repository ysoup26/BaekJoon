#include <iostream>

using namespace std;

//float coins[4] = {0.25,0.1,0.05,0.01};
int coins[4] = {25,10,5,1};
int coins_N[4] = {0,0,0,0};


int main(){
    int T;
    cin>>T;
    for(int test_case = 0;test_case<T;test_case++){
        float money;
        int c_idx;
        cin>>money;
        //money/=100; // 1달러 기준으로 입력받았기 때문에 센트 단위로 변경
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