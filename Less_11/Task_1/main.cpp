#include <iostream>
#include <vector>

template<class T>
void move_vectors(T& vec1, T& vec2) {
    vec2 = std::move(vec1);

}

int main(){
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vectors(one, two);
    for (const auto& n : two) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    for (auto n : one) {
        std::cout << n << " ";
    }
}