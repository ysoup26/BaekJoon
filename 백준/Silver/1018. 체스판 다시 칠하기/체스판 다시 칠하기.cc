#include <iostream>

using namespace std;

string map[50];

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

//
//간과한 것: 시작점을 기준으로 체스판을 색칠했을때보다, 반대색으로 색칠했을때 값이 더 작을 수 있음
//->>즉 시작이 흑일때 백일때 각각 구해서 비교하고 최소값을 갱신해야된다.
//구현 상에서는 홀수 짝수방식을 사용했으나 블로그를 참고하여 문자끼리 직접 대응하게 함(흑백 or 백흑의 결과는 고정되있기 때문)
int WB_check(int start_x,int start_y){
    int result = 0;
    for(int x = 0;x<8;x++){
        for(int y = 0;y<8;y++){
            if(map[x+start_x][y+start_y] != WB[x][y]){
                result++;
            }
        }
    }
    return result;
}

int BW_check(int start_x,int start_y){
    int result = 0;
    for(int x = 0;x<8;x++){
        for(int y = 0;y<8;y++){
            if(map[x+start_x][y+start_y] != BW[x][y]){
                result++;
            }
        }
    }
    return result;
}

int main(){
    int N,M;
    cin>>N>>M;
    int min_result = 64; // 8x8보드를 모두 바꾸는 최대값
    for(int x=0;x<N;x++){
        cin>>map[x];
    }
    for(int x=0;x<=N-8;x++){ //새로운 체스판이 될 수 있는 모든 경우를 따짐(브루트포스)
        for(int y=0;y<=M-8;y++){
            int v = min(WB_check(x,y),BW_check(x,y));
            if(v<min_result)
                min_result = v;
                
        }
    }
    cout<<min_result;
    return 0;
}