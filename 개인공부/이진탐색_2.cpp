/*부품 찾기

1초 128MB

문제 요약: N개의 부품 중에서, 손님이 M개의 부품이 있는지 확인을 부탁했다.
          모두 있다면 yes 아니면 no

입력: 
        N
        N개의 숫자들
        M
        M개의 숫자들
        5
        8 3 7 9 2
        3
        5 7 9

풀이: 이진탐색을 활용한다. 
      N개 숫자들을 정렬하고, M개의 숫자들을 각각 이진탐색해서 확인한다.
*/


#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int arr[],int f,int start,int end) //탐색 배열,탐색 값 , 시작점, 끝점
{
    if(start > end)
        return -1;
    int m = (start+end)/2;
    if(arr[m] == f) //f를 찾았다면 종료
        return m;
    else if(arr[m] > f)  //f보다 중간점 값이 큼
            return binary_search(arr,f,start,m-1);
    else
        return binary_search(arr,f,m+1,end);
};

int main(){
    int N,M;
    cin>>N;
    int Narr[N];
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        Narr[i] = tmp;
    }
    //정렬
    sort(Narr,Narr+N);
    cin>>M;
    for(int i=0;i<M;i++)
    {
        int find_v;
        cin>>find_v;
        if(binary_search(Narr,find_v,0,N-1) > -1)
            cout<<"yes ";
        else
            cout<<"no ";
    }
    return 0;
}