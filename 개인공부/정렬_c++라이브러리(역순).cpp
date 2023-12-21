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
    int n = 5;
    int list[n] = {5, 7 ,3 ,6 ,1};
    sort(list,list+n); //sort함수: 배열시작과 배열시작+개수
    reverse(list,list+n);
    list_print(list,n);
    return 0;
}