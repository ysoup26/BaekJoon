#include <iostream>

using namespace std;

int main(){
    int Arr[9][9];
    //주의: 모든 값이 같은 경우, max값이 0인 경우를 고려해야함
    int max_v = -1;
    int max_i = 1;
    int max_j = 1;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>Arr[i][j];
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(Arr[i][j] > max_v){
                max_i = i;
                max_j = j;
                max_v = Arr[i][j];
            }
        }
    }
    cout<<max_v<<"\n"<<max_i+1<<" "<<max_j+1; 
    return 0;
}