

#include <iostream>
#include <set>
#include <vector>

std::vector<int> divingBoardLengths(int shortLength, int longLength, int K) {
    std::set<int> lengths;

    // If K is 0, no boards are used, thus no length
    if (K == 0) return {};

    // Generate all possible lengths
    for (int i = 0; i <= K; ++i) {
        int length = i * shortLength + (K - i) * longLength;
        lengths.insert(length);
    }

    // Convert set to vector
    std::vector<int> result(lengths.begin(), lengths.end());
    return result;
}

int main() {
    int shortLength = 1;
    int longLength = 2;
    int K = 3;

    std::vector<int> lengths = divingBoardLengths(shortLength, longLength, K);

    std::cout << "Possible lengths of the diving board are:\n";
    for (int length : lengths) {
        std::cout << length << " ";
    }
    std::cout << std::endl;

    return 0;
}
