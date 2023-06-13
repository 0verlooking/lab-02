#include <iostream>

template <typename T, int size>
class StaticArray {
private:
    T arr[size];

public:
    void set(int index, const T& value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }

    T get(int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        // Виконуємо повернення за замовчуванням у випадку недійсного індексу
        return T();
    }
};

template <typename T>
class DynamicArray {
private:
    T* arr;
    int size;

public:
    DynamicArray(int size) : size(size) {
        arr = new T[size];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void set(int index, const T& value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }

    T get(int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        // Виконуємо повернення за замовчуванням у випадку недійсного індексу
        return T();
    }
};

int main() {
    // Приклад використання шаблонного класу для статичного масиву
    StaticArray<int, 5> staticArr;
    staticArr.set(0, 10);
    staticArr.set(1, 20);
    staticArr.set(2, 30);

    std::cout << "Static array values: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << staticArr.get(i) << " ";
    }
    std::cout << std::endl;

    // Приклад використання шаблонного класу для динамічного масиву
    DynamicArray<double> dynamicArr(3);
    dynamicArr.set(0, 3.14);
    dynamicArr.set(1, 2.71);
    dynamicArr.set(2, 1.618);

    std::cout << "Dynamic array values: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << dynamicArr.get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}