#include <iostream>

using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int A[N][M];
    int B[N][M];
    int C[N][M];
    //A배열
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int tmp;
            cin>>tmp;
            A[i][j] = tmp;
        }    
    }
    //B배열
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int tmp;
            cin>>tmp;
            B[i][j] = tmp;
        }    
    }
    //C배열
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            C[i][j] = A[i][j] + B[i][j];
        }    
    }
    //C배열 출력
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<C[i][j]<<" ";
        }    
        cout<<"\n";
    }
    return 0;
}
