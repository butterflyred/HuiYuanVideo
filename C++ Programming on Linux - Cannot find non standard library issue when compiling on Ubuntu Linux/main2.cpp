#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <array>
#include <vector>

using namespace std;

int main() {
    std::vector<int> myVec;
    srand(time(NULL));
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for(int i = 0;i < 100000;i++)
    {   
        myVec.push_back(rand()%100 + 1);
    }
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::milliseconds exec = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "myInt running time is " << exec.count() << "ms" << endl;
    

    return 0;
}