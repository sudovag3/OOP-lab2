#include <stdlib.h>
#include <time.h>
#include <iostream>

class MyArray
{
    private:
    int *arr;
    int size;
    public:
    MyArray(int sz)
    {
        arr = new int[sz];
        size = sz;
    }

    MyArray(const MyArray &ma)
    {
        size = ma.size;
        arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = ma.arr[i];
        }
    }

    int getSize(){
        return size;
    }

    void fillWithUserInput() {
        for(int i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }

    void fillWithRandomNumbers(int min, int max) {
        srand(time(NULL));
        for(int i = 0; i < size; i++) {
            arr[i] = min + (rand() % (max - min + 1));
        }
    }

    int& operator()(int i) {
        return arr[i];
    }

    ~MyArray() {
        delete [] arr;
    }
};


void printMyArray(MyArray arr) {
    for(int i = 0; i < arr.getSize(); i++) {
        std::cout << arr(i) << " ";
    }
    std::cout << std::endl;
}

// Конструктор копирования необходим в данном случае, чтобы гарантировать, 
// что новый объект MyArray, созданный путем копирования существующего, 
// будет иметь собственное независимое выделение памяти. Если конструктор 
// копирования не определён, будет использован конструктор копирования 
// по умолчанию, который просто копирует значения переменных 
// исходного объекта в новый объект, в результате чего оба объекта будут 
// использовать одно и то же выделение памяти. В итоге, при удалении одного из
// объектов появляется висячий указатель

int main() {
    MyArray arr1(5);
    arr1.fillWithRandomNumbers(1, 10);
    std::cout << "arr1: ";
    printMyArray(arr1);

    MyArray arr2 = arr1;
    std::cout << "arr2: ";
    printMyArray(arr2);

    return 0;
}