#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::multimap<int, char, std::greater<>> revers(std::map<char, int>& m) {

    std::multimap<int, char, std::greater<>> mm;
    std::map<char, int, std::greater<>> ::iterator it;

    for (it = m.begin(); it != m.end(); it++) {
        mm.insert(std::make_pair(it->second, it->first));
    }
    return mm;
}

int main(int argc, char** argv) {

    std::string str{ "Hello world!!" };
    std::map<char, int> m;

    auto count {
            [&](char ch) { m[ch]++; }
    };

    std::for_each(std::begin(str), std::end(str), count);
    std::multimap<int, char, std::greater<>> mm = revers(m);

    std::cout << "[IN]: " << str << std::endl;
    std::cout << "[OUT]: " << std::endl;
    for (const auto& var : mm) {
        std::cout << var.second << ": " << var.first << std::endl;
    }
    return 0;
}

