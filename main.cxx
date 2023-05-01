#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <string>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum{0},evenSum{0};

void findOdd(ull start,ull end);
void findEven(ull start,ull end);


int main(){

    auto startTime = high_resolution_clock::now();

    ull start {0},end{1900000000};
    
    std::thread t1(findEven,start,end);
    std::thread t2(findOdd,start,end);

    t1.join();
    t2.join();
    
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout<<"OddSum : "<<oddSum<<endl<<"EvenSumm : "<<evenSum<<endl<<"Sec : "<<duration.count()/1000000<<endl;
   
    startTime = high_resolution_clock::now();

    findOdd(start,end);
    findEven(start,end);

    stopTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stopTime - startTime);
    
    cout<<"OddSum : "<<oddSum<<endl<<"EvenSumm : "<<evenSum<<endl<<"Sec : "<<duration.count()/1000000<<endl;
   

return 0;
}


void findOdd(ull start,ull end){
for(ull i=start;i<=end;++i){
    if((i & 1) == 1){
        oddSum+=i;
    }
}

}

void findEven(ull start,ull end){
for(ull i=start;i<=end;++i){
    if((i & 1) == 0){
        evenSum+=i;
    }
}

}