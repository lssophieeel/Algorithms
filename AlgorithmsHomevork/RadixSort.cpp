#include <iostream>
#include <vector>
#include <algorithm>

int getMax(const std::vector<int>& vec) {
    return *std::max_element(vec.begin(), vec.end());
}

void print(std::vector<int> vec){
    for(const auto v : vec){
        std::cout << v <<" ";
    }
    std::cout << std::endl;
}

void countSort(std::vector<int>& vec, int exp)
{
    int size = vec.size();
    std::vector<int> output(size); 
    std::vector<int> count(10, 0);

    int indx = 0;

    for (indx = 0; indx < size; ++indx){
        int digit = (vec[indx] / exp) % 10;
        count[digit]++;
    }
    print(count);

    for (indx = 1; indx < 10; ++indx){
        count[indx] += count[indx - 1];
    }
    print(count);


    for (indx = size - 1; indx >= 0; --indx) {
        int digit = (vec[indx] / exp) % 10;
        output[count[digit] - 1] = vec[indx];
        count[digit]--;
    }
    print(output);

    for (indx = 0; indx < size; ++indx){
        vec[indx] = output[indx];
    }
        
    print(vec);
}


void radixSort(std::vector<int>& vec) {
    int max = getMax(vec);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        std::cout << "\n\n";
        countSort(vec, exp);
    }
}

int main() {
    std::vector<int> vec = {78, 145, 90, 0, 49, 30, 97};

    std::cout << "unsorted array: ";
    print(vec);

    radixSort(vec);

    std::cout << "sorted array: ";
    print(vec);

    return 0;
}
