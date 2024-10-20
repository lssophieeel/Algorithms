#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> findRelativeRanks(std::vector<int>& scores) {
    int n = scores.size();
    std::vector<std::pair<int, int>> indexedScores(n);

    // Pair each score with its original index
    for (int i = 0; i < n; ++i) {
        indexedScores[i] = { scores[i], i };
    }

    // Sort scores in descending order
    std::sort(indexedScores.rbegin(), indexedScores.rend());

    std::vector<std::string> result(n);

    // Assign ranks based on sorted scores
    for (int rank = 0; rank < n; ++rank) {
        int score = indexedScores[rank].first;
        int index = indexedScores[rank].second;

        if (rank == 0) {
            result[index] = "Gold Medal";
        }
        else if (rank == 1) {
            result[index] = "Silver Medal";
        }
        else if (rank == 2) {
            result[index] = "Bronze Medal";
        }
        else {
            result[index] = std::to_string(rank + 1);  // Convert rank to string
        }
    }

    return result;
}

void print(const std::vector<std::string>& ranks) {
    for (const auto& rank : ranks) {
        std::cout << rank << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> scores1 = { 5, 4, 3, 2, 1 };
    std::vector<std::string> result1 = findRelativeRanks(scores1);
    std::cout << "Ranks for scores1: ";
    print(result1);  // Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]

    std::vector<int> scores2 = { 10, 3, 8, 9, 4 };
    std::vector<std::string> result2 = findRelativeRanks(scores2);
    std::cout << "Ranks for scores2: ";
    print(result2);  // Output: ["Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"]

    return 0;
}
