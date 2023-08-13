#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> outerVector;

    // Create a vector that you want to push into the outer vector
    std::vector<int> innerVector = {1, 2, 3, 4, 5};

    // Push the inner vector into the outer vector
    outerVector.push_back(innerVector);

    // You can add more vectors in a similar way
    std::vector<int> anotherInnerVector = {6, 7, 8, 9, 10};
    outerVector.push_back(anotherInnerVector);

    // Print the content of the outer vector
    for (const auto& inner : outerVector) {
        for (int num : inner) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
