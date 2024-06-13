#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> v(N); //미리 크기를 지정하면, 직접 입력이 가능
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    vector<int> copy_v(v);
    //정렬용 배열에서 중복 제거
    sort(copy_v.begin(),copy_v.end());
    copy_v.erase(unique(copy_v.begin(),copy_v.end()),copy_v.end()); //unique함수는 중복 원소를 제거하고 그 원소들의 최종 위치를 반환함
    
    for(int i=0;i<N;i++){
        auto find_itr = lower_bound(copy_v.begin(),copy_v.end(),v[i]);
        cout<<find_itr-copy_v.begin()<<" ";

    }
    return 0;
}