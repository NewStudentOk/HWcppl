#include <iostream>
#include <vector>

template<typename Type>
Type pow(Type n) {
    n *= n;
    return n;
}

template<typename V>
void powV (std::vector<V> &v) {
    {
        for (auto& i : v) {
            i = pow(i);
        }
    }
}


int main() {
    int n = 5;
    std::vector<int> v = {-1, 4, 8};

    std::cout << "[IN]: " << n;
    std::cout << "\n[OUT]: " << pow(n) << std::endl;
    std::cout << "[IN]: ";
    for (auto& i : v) {
        std::cout << i;
        if (i != v[v.size() - 1])
            std::cout << ", ";
    }
    std::cout << "\n[OUT]: ";
    powV(v);
    for (auto& i:v) {
        std::cout << i;
        if (i != v[v.size() - 1])
            std::cout << ", ";
    }

    return 0;
}
