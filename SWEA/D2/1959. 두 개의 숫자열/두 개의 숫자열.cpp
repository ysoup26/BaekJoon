/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    /*배열의 위치를 이동시켜 연산하는 방식을 인덱스에 가중치를 주어 계산하는 방식으로 구현하고자 함.
       둘 중 짧은 배열은 인덱스 변화가 없고, 긴 배열은 한번 검사할때마다 가중치를 1씩 증가시켜서 시작점이 달라지게함
       해당 동작을 위해서 더 긴 배열을 알고 있어야 하고, 종료후 가중치도 한쪽에 주되 어느정도 일반화 시켜야 했다.
       동작은 하지만 코드가 깔끔하진 않다. */
	for(test_case = 1; test_case <= T; ++test_case)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N,M;
        int A[20],B[20]; //최대 20의 배열
        int max = 0;
        int move_count, min_i;
        cin>>N>>M;
        //배열값 삽입
        for(int i=0;i<N;i++)
        {
            int v;
            cin>>v;
            A[i] = v;
        }
        for(int i=0;i<M;i++)
        {
            int v;
            cin>>v;
            B[i] = v;
        }
        
        //긴 배열 확인 및 연산횟수 계산
        bool N_IsBig = (N>M) ?  true : false;
        if(N_IsBig)
        {
            move_count = N-M+1;
            min_i = M;
        }else 
        {
            move_count = M-N+1;
            min_i = N;
        }
        int add_A = 0, add_B = 0;
        for(int c=0;c<move_count;c++)
        {
            int sum = 0;
            for(int i=0;i<min_i;i++)
            {
                sum+=(A[i+add_A] * B[i+add_B]);
            }
            //한쪽만 가중치를 1 증가시키고 싶음
            if(N_IsBig)
                add_A++;	
            else
                add_B++;
            if(sum>max)
                max = sum;
        }
        cout<<"#"<<test_case<<" "<<max<<endl;
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}