//решение динамическим программированием
#include <iostream>
#include <vector>
#include <algorithm>

// Функция для решения задачи о рюкзаке методом динамического программирования
int knapsackDynamic(int capacity, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    // Создаем таблицу dp для хранения промежуточных результатов
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // Если вес текущего предмета меньше или равен текущей вместимости рюкзака,
            // то выбираем максимум между включением и исключением текущего предмета
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // Иначе (если текущий предмет не помещается) берем предыдущее значение
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    // Максимальное значение будет в последней ячейке dp
    return dp[n][capacity];
}

// Функция для вывода результатов теста
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
    int expected_value1 = 220;
    int actual_value1 = knapsackDynamic(capacity1, weights1, values1);
    printTestResult(1, expected_value1, actual_value1);

    // Тест 2: Рюкзак не может вместить ничего
    std::vector<int> weights2 = {10, 20, 30};
    std::vector<int> values2 = {60, 100, 120};
    int capacity2 = 5;
    int expected_value2 = 0;
    int actual_value2 = knapsackDynamic(capacity2, weights2, values2);
    printTestResult(2, expected_value2, actual_value2);
    
    // Тест 3: Один предмет подходит
    std::vector<int> weights3 = {10, 20, 30};
    std::vector<int> values3 = {60, 100, 120};
    int capacity3 = 10;
    int expected_value3 = 60;
     int actual_value3 = knapsackDynamic(capacity3, weights3, values3);
    printTestResult(3, expected_value3, actual_value3);

   // Тест 4: Все предметы помещаются
    std::vector<int> weights4 = {10, 20, 30};
    std::vector<int> values4 = {60, 100, 120};
    int capacity4 = 100;
    int expected_value4 = 280;
     int actual_value4 = knapsackDynamic(capacity4, weights4, values4);
    printTestResult(4, expected_value4, actual_value4);
    
     // Тест 5: Больше предметов
    std::vector<int> weights5 = {1, 2, 3, 4, 5};
    std::vector<int> values5 = {10, 5, 15, 7, 6};
    int capacity5 = 10;
    int expected_value5 = 36;
    int actual_value5 = knapsackDynamic(capacity5, weights5, values5);
    printTestResult(5, expected_value5, actual_value5);
     
    // Тест 6: Большой вес предметов
    std::vector<int> weights6 = {100, 200, 300};
    std::vector<int> values6 = {60, 100, 120};
    int capacity6 = 400;
    int expected_value6 = 220;
    int actual_value6 = knapsackDynamic(capacity6, weights6, values6);
      printTestResult(6, expected_value6, actual_value6);

    return 0;
}