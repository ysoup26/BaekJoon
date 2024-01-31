/*이진탐색
  : 정렬된 데이터에서 중간점을 달리하며 탐색하는 방식
  : 시작점, 중간점, 끝점이 있다. 중간점은 (시작+중간)/2
  : 중간점의 값과 찾는 값이 같다면 종료, 아니라면 끝점을 중간점으로 하여
    새롭게 계산한다.
  : 반복문으로 구현해봄
*/

#include <iostream>
#include <string>

using namespace std;

int binary_search(int arr[],int f,int start,int end) //탐색 배열,탐색 값 , 시작점, 끝점
{
    int f_idx;
    int s,m,e;
    s = start;
    e = end;
    while(true){
        //시작점과 끝점이 교차되면 종료
        if(s > e)
        {
            f_idx = -1;
            break;
        }
        m = (s+e)/2;
        if(arr[m] == f) //f를 찾았다면 종료
        {
            f_idx = m;
            break;
        }else if(arr[m] > f)  //f보다 중간점 값이 큼
            e = m-1;
        else//f보다 중간점 값이 큼
            s = m+1;
    }
    return f_idx;
    
};

int main(){
    int n = 10; //원소 개수
    int f = 7; //찾으려는 값
    int arr[n] = {1,3,5,7,9,11,13,15,17,19};
    cout<<binary_search(arr,f,0,n-1)+1; //출력할 땐 시작점0을 1로 바꿈
    return 0;
}