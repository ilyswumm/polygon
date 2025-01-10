//решение полным перебором
#include <iostream>
#include <vector>
#include <algorithm>

int knapsackRecursive(int capacity, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (weights[n - 1] > capacity) {
        return knapsackRecursive(capacity, weights, values, n - 1);
    } else {
        return std::max(values[n - 1] + knapsackRecursive(capacity - weights[n - 1], weights, values, n - 1),
                   knapsackRecursive(capacity, weights, values, n - 1));
    }
}

void printTestResult(int test_number, int expected_value, int actual_value) {
    std::cout << "Test " << test_number << ": ";
    if (actual_value == expected_value) {
        std::cout << "Passed! ";
    } else {
        std::cout << "Failed! Expected " << expected_value << ", got " << actual_value << ". ";
    }
    std::cout << "Max Value: " << actual_value << std::endl;
}

int main() {
    // Тестовые случаи

    // Тест 1: Простой случай
    std::vector<int> weights1 = {10, 20, 30};
    std::vector<int> values1 = {60, 100, 120};
    int capacity1 = 50;
    int n1 = weights1.size();
    int expected_value1 = 220;
    int actual_value1 = knapsackRecursive(capacity1, weights1, values1, n1);
    printTestResult(1, expected_value1, actual_value1);

    // Тест 2: Рюкзак не может вместить ничего
    std::vector<int> weights2 = {10, 20, 30};
    std::vector<int> values2 = {60, 100, 120};
    int capacity2 = 5;
    int n2 = weights2.size();
    int expected_value2 = 0;
    int actual_value2 = knapsackRecursive(capacity2, weights2, values2, n2);
    printTestResult(2, expected_value2, actual_value2);

    // Тест 3: Один предмет подходит
    std::vector<int> weights3 = {10, 20, 30};
    std::vector<int> values3 = {60, 100, 120};
    int capacity3 = 10;
     int n3 = weights3.size();
    int expected_value3 = 60;
    int actual_value3 = knapsackRecursive(capacity3, weights3, values3, n3);
    printTestResult(3, expected_value3, actual_value3);

    // Тест 4: Все предметы помещаются
    std::vector<int> weights4 = {10, 20, 30};
    std::vector<int> values4 = {60, 100, 120};
    int capacity4 = 100;
    int n4 = weights4.size();
    int expected_value4 = 280;
    int actual_value4 = knapsackRecursive(capacity4, weights4, values4, n4);
    printTestResult(4, expected_value4, actual_value4);

   // Тест 5: Больше предметов
    std::vector<int> weights5 = {1, 2, 3, 4, 5};
    std::vector<int> values5 = {10, 5, 15, 7, 6};
    int capacity5 = 10;
    int n5 = weights5.size();
    int expected_value5 = 37;
    int actual_value5 = knapsackRecursive(capacity5, weights5, values5, n5);
    printTestResult(5, expected_value5, actual_value5);

     // Тест 6: Пример, где жадный алгоритм может дать неоптимальный результат
    std::vector<int> weights6 = {10, 20, 30, 40};
    std::vector<int> values6 = {60, 100, 120, 140};
    int capacity6 = 60;
    int n6 = weights6.size();
    int expected_value6 = 260; 
    int actual_value6 = knapsackRecursive(capacity6, weights6, values6, n6);
    printTestResult(6, expected_value6, actual_value6);
    


    return 0;
}