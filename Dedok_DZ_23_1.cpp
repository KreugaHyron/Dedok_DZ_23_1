#include <iostream>
using namespace std;
const int ARRAY_SIZE = 20;
void shuffleArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int randomIndex = rand() % size;
        swap(arr[i], arr[randomIndex]);
    }
}
int generateRandomNumber() {
    return rand() % 20 + 1; 
}
int findPosition(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
void customSort(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = i; j > start && arr[j] > arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
    for (int i = end; i < ARRAY_SIZE - 1; i++) {
        for (int j = i; j > end && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    int arr[ARRAY_SIZE]{};
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }
    shuffleArray(arr, ARRAY_SIZE);

    cout << "Исходный массив:" << "\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    int randomNum = generateRandomNumber();
    cout << "Случайное число: " << randomNum << "\n";

    int position = findPosition(arr, ARRAY_SIZE, randomNum);
    if (position != -1) {
        customSort(arr, 0, position);
        customSort(arr, position + 1, ARRAY_SIZE);

        cout << "Отсортированный массив:" << "\n";
        for (int i = 0; i < ARRAY_SIZE; i++) {
            std::cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "Случайное число не найдено в массиве." << "\n";
    }
}

