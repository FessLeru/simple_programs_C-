/*
Задача 1:

Задан список чисел и число k. Выпишите функцию, которая вернет True если сумма любых двух чисел из списка равна k.
Например, для списка [12, 6, 3, 13] и k равного 18, должно вернуться True, поскольку 12 + 6 = 18.
*/

#include <iostream>
using namespace std;


bool Check(int* arr, const int &size, int &value, int &index) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value && i != index) return true;
    }
    return false;
}


int main()
{
    int arr[] = { 12, 6, 3, 5 };
    const int SIZE = sizeof(arr) / sizeof(arr[0]);
    int check[SIZE] = {};
    int res;
    cin >> res;
    for (int i = 0; i < SIZE; ++i) {
        check[i] = res - arr[i];
        if (Check(arr, SIZE, check[i], i)) {
            cout << "True" << endl;
            break;
        }
    }
}
