#include <iostream>
#include <vector>
#include <list>
#include <chrono>

using namespace std::chrono;

// Función para medir el tiempo necesario para insertar elementos al principio de un vector y una lista
int durationCheck() {
    const int NUM_OPERATIONS = 100000;

    std::vector<int> vec;
    std::list<int> lst;

    // Mida el tiempo necesario para insertar elementos al principio de una lista
    auto start = high_resolution_clock::now();
    for (int i = 0; i < NUM_OPERATIONS; ++i) {
        lst.push_front(i);
    }
    auto stop = high_resolution_clock::now();
    auto duration_list = duration_cast<milliseconds>(stop - start);
    std::cout << "List time: " << duration_list.count() << " ms\n";

    // Mida el tiempo necesario para insertar elementos al principio de un vector
    start = high_resolution_clock::now();
    for (int i = 0; i < NUM_OPERATIONS; ++i) {
        vec.insert(vec.begin(), i);
    }
    stop = high_resolution_clock::now();
    auto duration_vector = duration_cast<milliseconds>(stop - start);
    std::cout << "Vector time: " << duration_vector.count() << " ms\n";

    return 0;
}

// Función para medir el tamaño de un vector y una lista
int sizeCheck() {
    const int NUM_ELEMENTS = 100000;  // Number of elements

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        vec.push_back(i);
        lst.push_back(i);
    }

    //Calcular el tamaño de un vector
    std::cout << "Size of std::vector: " << sizeof(std::vector<int>) + (sizeof(int) * vec.capacity()) << " bytes\n";

    // Calcular el tamaño de una lista
    std::cout << "Size of std::list: " << sizeof(std::list<int>) + (sizeof(int) + 2 * sizeof(void*)) * lst.size() << " bytes\n";

    return 0;
};

int main() {
    sizeCheck();
    durationCheck();

    return 0;
}
