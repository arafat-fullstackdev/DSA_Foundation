#include<bits/stdc++.h>
using namespace std;

struct myTime{
   
  void add_time(){
    time++;
  }
   int time;
  
}
int main(){
    myTime data;
    data.time = 2038;
    printf("Year: %d\n", data.time);
    data.add_time();
    printf("Year : %d\n", data.time);

    return 0;
} 

