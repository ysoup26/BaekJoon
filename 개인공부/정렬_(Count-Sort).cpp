/*Selection Sort(계수 정렬)
  : 모든 데이터가 양의 정수일때 적용할 수 있는, 빠른 정렬 알고리즘이다.
  : 0~최대값까지 담을 수 있는 배열을 이용하는 방식으로,
    이 배열에 데이터의 개수들을 담고 순서대로 출력한다.
  : 시간복잡도는 O(N+K)이다. N은 데이터의 개수. K는 데이터의 최대값
*/

#include <iostream>

using namespace std;

void list_print(int list[],int n)
{
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

void count_sort(int list[],int n)
{
    int m = list[0];
    //최대값 탐색. 계수 배열 선언을 위해
    for(int i=1;i<n;i++)
        if(list[i]>m)
            m = list[i];
    int count_list[m+1] = {0,};
    //list를 읽으며 각 수의 갯수를 count_list에 저장함
    for(int i=0;i<n;i++)
        count_list[list[i]]++;
    //0부터 최대값까지 출력하면 정렬이 되었다고 볼 수 있음
    for(int i=0;i<=m;i++)
    {
        if(count_list[i]!=0)
        {
            for(int j=0;j<count_list[i];j++)
            {
                cout<<i<<" ";
            }
        }
    }
}

int main(){
    int n = 5;
    int list[n] = {5, 7 ,3 ,6 ,1};
    count_sort(list,n);
    return 0;
}