//решение жадным алгоритмом
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Item {
    int weight;
    int value;
    double value_per_weight;
};

// Функция для сравнения предметов по отношению ценности к весу
bool compareItems(const Item& a, const Item& b) {
    return a.value_per_weight > b.value_per_weight;
}

// Функция для решения задачи о рюкзаке жадным алгоритмом
double knapsackGreedy(int capacity, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    std::vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].value_per_weight = static_cast<double>(values[i]) / weights[i];
    }

    // Сортируем предметы по убыванию отношения ценности к весу
    std::sort(items.begin(), items.end(), compareItems);

    double total_value = 0.0;
    int current_weight = 0;

    // Выбираем предметы, начиная с наиболее "выгодных"
    for (const auto& item : items) {
        if (current_weight + item.weight <= capacity) {
            total_value += item.value;
            current_weight += item.weight;
        } else {
            // Если предмет не помещается целиком, берем часть предмета
            int remaining_capacity = capacity - current_weight;
            total_value += item.value_per_weight * remaining_capacity;
            break; // Рюкзак заполнен
        }
    }
    return total_value;
}

// Функция для вывода результатов теста
void printTestResult(int test_number, double expected_value, double actual_value) {
    std::cout << "Test " << test_number << ": ";
    std::cout << std::fixed << std::setprecision(2);
    if (std::abs(actual_value - expected_value) < 0.001) {
        std::cout << "Passed! ";
    } else {
        std::cout << "Failed! Expected " << expected_value << ", got " << actual_value << ". ";
    }
     std::cout << "Max Value: " << actual_value << std::endl;
}

int main() {
    // Тестовые случаи

    // Тест 1: Простой случай (точное решение жадным алгоритмом)
    std::vector<int> weights1 = {10, 20, 30};
    std::vector<int> values1 = {60, 100, 120};
    int capacity1 = 50;
    double expected_value1 = 220.0;
    double actual_value1 = knapsackGreedy(capacity1, weights1, values1);
    printTestResult(1, expected_value1, actual_value1);

   // Тест 2: Рюкзак не может вместить ничего
    std::vector<int> weights2 = {10, 20, 30};
    std::vector<int> values2 = {60, 100, 120};
    int capacity2 = 5;
    double expected_value2 = 0.0;
     double actual_value2 = knapsackGreedy(capacity2, weights2, values2);
    printTestResult(2, expected_value2, actual_value2);

    // Тест 3: Один предмет подходит (точное решение жадным алгоритмом)
    std::vector<int> weights3 = {10, 20, 30};
    std::vector<int> values3 = {60, 100, 120};
    int capacity3 = 10;
    double expected_value3 = 60.0;
     double actual_value3 = knapsackGreedy(capacity3, weights3, values3);
    printTestResult(3, expected_value3, actual_value3);

    // Тест 4: Все предметы помещаются (точное решение жадным алгоритмом)
    std::vector<int> weights4 = {10, 20, 30};
    std::vector<int> values4 = {60, 100, 120};
    int capacity4 = 100;
    double expected_value4 = 280.0;
    double actual_value4 = knapsackGreedy(capacity4, weights4, values4);
    printTestResult(4, expected_value4, actual_value4);

    // Тест 5: Случай, где жадный алгоритм не дает оптимальный результат (но все равно приемлемый)
    std::vector<int> weights5 = {10, 20, 30, 40};
    std::vector<int> values5 = {60, 100, 120, 140};
    int capacity5 = 60;
    double expected_value5 = 260.0;
    double actual_value5 = knapsackGreedy(capacity5, weights5, values5);
    printTestResult(5, expected_value5, actual_value5);
    
     // Тест 6: Больше предметов
    std::vector<int> weights6 = {1, 2, 3, 4, 5};
    std::vector<int> values6 = {10, 5, 15, 7, 6};
    int capacity6 = 10;
    double expected_value6 = 36.0;
    double actual_value6 = knapsackGreedy(capacity6, weights6, values6);
      printTestResult(6, expected_value6, actual_value6);

    return 0;
}