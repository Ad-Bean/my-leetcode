#include <bits/stdc++.h>
using namespace std;
#include <omp.h>
typedef long long ll;
typedef pair<int, int> pii;

/* 
  g++ openmp.cpp -o openmp -fopenmp -O3
*/

int main() {
#pragma omp parallel
  { cout << "Hello, world!" << endl; }
}