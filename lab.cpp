#include<iostream>
#include<cstdlib>
#include<vector>
#include <algorithm>

int divide(std::vector<int>& arr, int lowest, int highest){    
    int pivot = arr[highest];   
    int i = lowest - 1;

    for (int j = lowest; j < highest; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[highest]);    
    return i + 1;
}

int randomDivide(std::vector<int>& arr, int lowest, int highest) {  //the function for randomized pivot element 
    int random = lowest + rand() % (highest - lowest);
    std::swap(arr[random], arr[highest]);
    return divide(arr, lowest, highest);
}

void quickSort(std::vector<int>& arr, int lowest, int highest) {  //dividing the array into two sub-arrays
    if (lowest < highest) {
        int pivotal = randomDivide(arr, lowest, highest);  //index pivot element

        quickSort(arr, lowest, pivotal - 1);  //separated sorting 
        quickSort(arr, pivotal + 1, highest); 
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
}


void bubbleSort(std::vector<int>& arr) {     //for Bubble Sort
    
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);   //shifting elements
            }
        }
    }
}



void counting_sort(std::vector<int>& arr, int max_value) {
    std::vector<int> count(max_value + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    std::vector<int> sorted_arr(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        sorted_arr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    arr = sorted_arr;
}

int main() {  
    
    /*Quick Sort*/

    int number1 = 0;
    std::cout << "Введите размер вектора (Quick Sort) " << std::endl;
    std::cin >> number1;
    std::vector<int> arr(number1);
    for (int i = 0; i < number1; i++) {
        std::cout << " Введите число: "<< std::endl;
        std::cin >> arr[i];
    }
    
    quickSort(arr, 0, number1 - 1);
    std::cout << "Отсортированный массив: " << std::endl;
    printArray(arr);

    /*Bubble Sort*/

    int number2;
    std::cout << "Введите размер вектора(Bubble Sort) " << std::endl;
    std::cin >> number2;
    std::vector<int> arr1(number2);
    std::cout << "Введите элементы вектора" << std::endl;
    for (int i = 0; i < number2; i++) {
        std::cin >> arr1[i];
    }

    bubbleSort(arr1);

    std::cout << "Отсортированный массив: " << std::endl;
    for (int i = 0; i < number2; i++) {
        std::cout << arr1[i] << std::endl; 
    }
    

    /*Counting  Sort*/

    std::vector<int> arr3;
    int size;
    std::cout << "Введите размер вектора(Counting Sort): ";
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        int num;
        std::cout << "Введите число: ";
        std::cin >> num;
        arr3.push_back(num);
    }
    
    counting_sort(arr3,  * std::max_element(arr3.begin(), arr3.end()));
    std::cout << "Отсортированный массив: " << std::endl;
    for (int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << std::endl;
    }
    return 0;
    
}
