/*Quick Sort
  : 원소 하나를 피벗으로 설정하여, 피벗을 기준으로 배열을 두개로 나누면서 정렬하는 알고리즘이다.
  : 분할 정복 방법이라고도 하고, 매우 빠른 수행속도를 가지고 있다.
  : 한 배열을 반으로 나누고, 그 배열들을 또 반으로 나누기 때문에 빠른 정렬이 가능하다.
*/

#include <iostream>

using namespace std;

void list_print(int list[],int n)
{
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

void quick_sort(int list[],int start,int end)
{
    int pivot, low, high;
    if(start>=end) //시작점이 끝점보다 크거나 같다 == 배열이 1개 이하
        return;
    pivot = start;
    low = start+1;
    high = end;
    while(low<=high)
    {
        //올바른 위치에 있는 low와 high는 건너뜀
        while(low<=end && list[low]<=list[pivot])
        {
            low++;
        }
        while(high>=(start+1) && list[high]>=list[pivot])
        {
            high--;
        }
        if(low<=high) //low high 교체
        {
            int tmp = list[low];
            list[low] = list[high];
            list[high] = tmp;
        }else        //low와 high 교체 종료
        {
            //pivot과 high를 교체하여, 나눠진 배열의 중심에 pivot이 놓이도록
            int tmp = list[pivot]; 
            list[pivot] = list[high];
            list[high] = tmp;
        }
    }
    //나눠진 배열에 각각 정렬 수행
    //pivot값은 list[high]로 이동되었기 때문에 high를 이용.
    quick_sort(list,start,high-1);
    quick_sort(list,high+1,end);
}

int main(){
    int n = 5;
    int list[n] = {5, 7 ,3 ,6 ,1};
    quick_sort(list,0,4);
    list_print(list,n);
    return 0;
}