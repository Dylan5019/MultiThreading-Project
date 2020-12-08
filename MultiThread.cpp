#include <iostream>
#include <algorithm>
#include <thread>
#include <time.h>
#include <ctime>


static bool s_Finished = false;


int getRandom(){
  int randNum = rand() % 100 + 1;
  return randNum;
}


void Help1(){

using namespace std::literals::chrono_literals;

std::cout << "Started thread id = " << std::this_thread::get_id() << "\n";

  int v1 = 0;
  int v2 = 1;

  for (int i = 0; i<50; i++){
  v1 = getRandom();
  v2 = getRandom();
  std::cout << "min(" << v1 << ", "<< v2 <<")==" << std::min(v1,v2) << '\n';
  //std::this_thread::sleep_for(1s);
  }


  
}


void Help2(){

using namespace std::literals::chrono_literals;

std::cout << "Started thread id = " << std::this_thread::get_id() << "\n";


  int v1 = 0;
  int v2 = 1;

  for (int i = 0; i<50; i++){
  v1 = getRandom();
  v2 = getRandom();
  std::cout << "min(" << v1 << ", "<< v2 <<")==" << std::min(v1,v2) << '\n';
  std::this_thread::sleep_for(1s);
  }
  
}


void Solo(){

using namespace std::literals::chrono_literals;

std::cout << "Started thread id = " << std::this_thread::get_id() << "\n";

  int v1 = 0;
  int v2 = 1;

  for (int i = 0; i<100; i++){
  v1 = getRandom();
  v2 = getRandom();
  std::cout << "min(" << v1 << ", "<< v2 <<")==" << std::min(v1,v2) << '\n';
  std::this_thread::sleep_for(1s);
  }
  
}




int main(){

std::cout << "Finding the minimum number between two randomly generated numbers, 100 times\n";

std::cout << "Press enter to see single thread";
std::cin.get();


std::cout << "One Thread Doing the Work\n";
  std::time_t start = time(0);
  std::thread solo(Solo);
  solo.join();
  std::time_t end = time(0);
  int elapsed = end - start;
  std::cout << "Elapsed Time: " << elapsed << "\n\n\n";
  

  std::cout << "Press enter to see two threads\n";
  std::cin.get();

  std::time_t begin = time(0);
  std::thread worker(Help1);
  std::thread worker2(Help2);
  worker.join();
  worker2.join();
  std::time_t end2 = time(0);
  int elapsed2 = end2 - begin;
  std::cout << "Elapsed Time: " << elapsed2 << "\n";
  
  
  
  std::cout << "Finished";

  return 0;
}