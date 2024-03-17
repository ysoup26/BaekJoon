/*무지의 먹방 라이브 ** 

문제 요약: 무지는 TV 먹방 라이브를 하려는데 몇가지 차별점을 두었다.

    -N개의 음식을 1~N 순서대로 먹방(N후에는 다시 1)
    -1초씩만 그 음식을 섭취하고 다음으로 넘어감
    -N초후에 방송이 잠시 중단되었다가 정상화됨
    ->이때 방송 중단 후 몇번째 음식을 섭취하면 되는지?

(기본 코드가 제공되는 문제이다.)

입력: N초후에 방송 중단이라는 상황이 들어갔지만
     방송 중단동안은 음식을 섭취하지 않기 때문에
     이 문제는 N초일때 몇번째 음식을 섭취해야하는가를 묻는 것과 같다.
     
    (간단하게 푸는 방식)
     for문을 통해 0~N초 동안 음식 섭취에 대한
     동작을 수행하는 방식으로 정답을 출력하면 된다.
    주의할 점: 섭취 종료시점이 헷갈릴 수 있다.
               N초가 되었을 땐 N번째 음식을 섭취한 후이다. (N-1)~(N)초사이에 음식을 섭취했으므로
               즉, 출력해야하는 것은 N+1번째 음식이다.

입력 예시가 없어서 하드코딩 방식을 사용함


풀이: 
     
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int food_n = food_times.size();
    int next_food=0;
    bool isNext=false;
    //시간을 증가시키며 음식 섭취
    for(int t=0;t<k;t++){
        food_times[next_food]--;
        next_food = ((next_food+1)%food_n);
        //다음 섭취할 음식을 정하기(0인 음식은 제외시키기 위함)
        //음식 벡터의 길이만큼 검사했는데 찾지못하고 for문이 종료된다면
        //다음 음식이 없다는 것이므로 -1을 출력하게함
        isNext = false;
        for(int i=0;i<food_n;i++){
            if(food_times[next_food]!=0){
                isNext = true;
                break;
            }   
            next_food = ((next_food+1)%food_n);
        }
        if(!isNext){
            next_food = -2;
            break;
        }
    }
    answer = next_food+1; //위 계산에선 시작인덱스가 0이었기 때문에 
    return answer;
}

int main(){
    vector<int> food_times;
    food_times.push_back(3);
    food_times.push_back(1);
    food_times.push_back(2);
    long long k = 5;
    printf("%d",solution(food_times,k));
    return 0;
}