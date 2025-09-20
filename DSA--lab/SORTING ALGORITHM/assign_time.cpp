#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

int main() {
    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 100; i++){};

    // End the timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

    return 0;
}