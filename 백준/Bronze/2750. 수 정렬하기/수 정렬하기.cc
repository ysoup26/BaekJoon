#include <iostream>

using namespace std;

void selection_sort(int list[],int N){
    //마지막 인덱스 전까지
    for(int i=0;i<N-1;i++){
        int min_idx = i;
        for(int j=i+1;j<N;j++){
            if(list[min_idx]>list[j])    
                min_idx = j;
        }
        if(min_idx!=i)
        {
            int tmp = list[i];
            list[i] = list[min_idx];
            list[min_idx] = tmp;
        }
    }
}

int main(){
    int N;
    int list[1000];
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        list[i] = tmp;
    }
    selection_sort(list,N);
    for(int i=0;i<N;i++){
        cout<<list[i]<<"\n";
    }
    return 0;
}