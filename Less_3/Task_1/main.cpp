#include <iostream>
#include <stdexcept>

class smart_array
{
private:
    int* cr_array = nullptr;
    int cr_size{};
    int arr_element{};
public:
    smart_array(const smart_array&) = delete;  // запрет копирования
    smart_array& operator=(const smart_array&) = delete; // запрет оператора присваивания
    smart_array(int size) : cr_size(size), arr_element(size) { cr_array = new int [cr_size]; };
    ~smart_array(){delete[] cr_array; };

    void add_element (int x)
    {
        if (arr_element == 0) throw std::out_of_range("Превышен размер массива");
        cr_array[cr_size - arr_element] = x;
        arr_element--;
    }

    int& get_element(int index)
    {
        if(index < 0 || index > cr_size - 1) throw std::out_of_range("Индекс вне диапазона массива");

        return cr_array[index];
    }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(4) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
