/*두 배열의 원소 교체

2초 128MB

문제 요약:

입력: 두 개의 배열 A와 B가 있다.
      최대 K번 바꿔치기 연산을 수행해서, 배열 A의 원소의 합이 최대가 되어야한다.

풀이: 원소의 합이 최대가 되려면, K만큼 바꿔치기를 할 때,
      큰 원소순으로 가져오면 된다. 
      그러기 위해서 배열 A는 오름차순으로, 배열 B는 내림차순으로 정렬하고,
      같은 인덱스끼리 비교를 통해 바꿔치기를 수행한다.
*/


#include <iostream>
#include <algorithm>

using namespace std;

void list_print(int list[],int n)
{
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

int main()
{
    int N,K,sum=0;
    cin>>N>>K;
    int A[N],B[N];
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        A[i] = tmp;
    }
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        B[i] = tmp;
    }
    //정렬
    sort(A,A+N);
    sort(B,B+N);
    reverse(B,B+N);
    for(int i=0;i<K;i++)
    {
        if(A[i]<B[i])
        {
            int tmp = A[i];
            A[i] = B[i];
            B[i] = tmp;
        }else
            break;
    }
    //sum계산
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
    }
    cout<<sum;
    return 0;
}