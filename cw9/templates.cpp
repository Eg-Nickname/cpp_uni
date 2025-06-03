#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <numeric>
#include <ostream>
#include <stdexcept>
#include <tuple>
#include <vector>
// definicja funkcji szablonowej
template <typename Container>
std::tuple<typename Container::value_type, typename Container::value_type,
           typename Container::value_type>
minmax_sum(const Container& container) {
    using T = typename Container::value_type; // typ przechowywany w kontenerze
    if (container.empty()) {
        throw std::length_error("Empty container");
    }
    T min = *std::min_element(container.begin(), container.end());
    T max = *std::max_element(container.begin(), container.end());
    T sum =
        std::accumulate(container.begin(), container.end(), static_cast<T>(0));
    return std::tuple(min, max, sum);
}
// Test function
int main() {
    std::vector<int> vec = {3, 1, 7, 4, 5};
    std::list<float> lst = {2.5, 3.1, 0.9, 6.2};
    std::array<double, 4> arr = {8.0, -1.5, 2.2, 3.3};
    std::vector<int> vec_empty{};
    // test funkcji szablonowej
    try {
        auto [vec_min, vec_max, vec_sum] = minmax_sum(vec);
        std::println(std::cout, "Vector min: {} max: {}, sum: {}", vec_min,
                     vec_max, vec_sum);
    } catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        auto [lst_min, lst_max, lst_sum] = minmax_sum(lst);
        std::println(std::cout, "List min: {} max: {}, sum: {}", lst_min,
                     lst_max, lst_sum);
    } catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        auto [arr_min, arr_max, arr_sum] = minmax_sum(arr);
        std::println(std::cout, "Array min: {} max: {}, sum: {}", arr_min,
                     arr_max, arr_sum);
    } catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        auto [arr_min, arr_max, arr_sum] = minmax_sum(vec_empty);
        std::println(std::cout, "Array min: {} max: {}, sum: {}", arr_min,
                     arr_max, arr_sum);
    } catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}