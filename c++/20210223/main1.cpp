#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <array>
using namespace std;
int main(int argc, const char** argv) {
    // int myInt[100000];
    std::array<int,100000> myArr;
    // std::vector<int> myVec;
    srand(time(NULL));
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for(int i = 0;i < 100000;i++)
    {   
        myArr[i] = rand()%100 + 1;
    }
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::milliseconds exec = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "myInt running time is " << exec.count() << "ms" << endl;

    return 0;
}