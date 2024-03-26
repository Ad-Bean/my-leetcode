#include <iostream>
#include <random>
using namespace std;

int main() {
  mt19937 gen{random_device{}()};  // mt19937, random_device 是一个 class
  uniform_int_distribution<> dist(1, 10);
  int rand_num = dist(gen);
  cout << "rand_num: " << rand_num << endl;
  return 0;
}