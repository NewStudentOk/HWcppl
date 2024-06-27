#include <iostream>
#include <vector>
#include <algorithm>

class Num_counter {
    std::vector<int> vec {4, 1, 3, 6, 25, 54};
public:
    Num_counter() = default;;
    int k = 0;

    void in_vec() {
        std::cout << "[IN]: ";
        std::for_each(vec.begin(), vec.end(), [](const int n) { std::cout << n << ' '; });
    }

    struct Sum {
        Sum() { sum = 0; }

        void operator()(int n) {
            if (n % 3 == 0) {
                sum += n;
                count++;
            }
        }

        int sum;
        int count = 0;
    };

    void get_sum() {
        Sum s = std::for_each(vec.begin(), vec.end(), Sum());
        std::cout << "\n[OUT]: get_sum() = " << s.sum << " ";
    }

    void get_count() {
        Sum s = std::for_each(vec.begin(), vec.end(), Sum());
        std::cout << "\n[OUT]: get_count() = " << s.count << " ";
    }

    ~Num_counter() {
        vec.clear();
    }
};

int main() {
    Num_counter numc;
    numc.in_vec();
    numc.get_sum();
    numc.get_count();
    return 0;
}
