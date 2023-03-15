#include <iostream>

int main()
{
    long N;
    std::cin>>N;
    std::cout<<N*(N-1)*(N-2)/6<<'\n'<<3;
    //nC_3.
    //3개의 중첩for문 때문에 N*N-1*N-2가 되고. 6은 수학적으로 접근하거나 시행착오로 구할 수 있음.
    return 0;
}