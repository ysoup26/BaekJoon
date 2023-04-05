#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main()
{
    int N,sum=0;
    cin>>N;
    vector <int> a,b;
    for(int i=0;i<N;i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    for(int i=0;i<N;i++)
    {
        int t;
        cin>>t;
        b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0;i<N;i++)
    {
        sum+=(a[i]*b[N-i-1]);
    }
    cout<<sum;
    return 0;
}
