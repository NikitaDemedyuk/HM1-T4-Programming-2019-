//
//  main.cpp
//  Task4-HW1
//
//  Created by Никита on 11/18/19.
//

#include <iostream>
#include <vector>

std::vector <int> deleteElem(std::vector <int> &array, int element) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] % element == 0) {
            array.erase(array.begin() + i);
            i--;
        }
    }
    return array;
}

void print(std::vector <int> &array) {
    std::cout << "\nArray:\n";
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";
}

bool testFuncDeleteElem(std::vector <int> &array, std::vector <int> &testArray) {
    bool flag = true;
    if (array.size() != testArray.size()) {
        flag = false;
    } else {
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] != testArray[i]) {
                flag = false;
            }
        }
    }
    return flag;
}


int main() {
    int size;
    std::cout << "Size of array = ";
    std::cin >> size;

    std::vector <int> array;
    
    std::cout << "\nEnter the elements: \n";
    for (int i = 0, value = {}; i < size; i++) {
        std::cout << "array [" << i << "] = ";
        std::cin >> value;
        array.push_back(value);
    }
    print(array);
    
    std::vector <int> finalArray = deleteElem(array, 3);
    print(finalArray);
    
    std::vector <int> testArray1 = {28, 9, -6, 23, 52, 33, 54, 75, 3, 45, 66, 21, 34, 55, 22, 12, -12, 44};
    testArray1 = deleteElem(testArray1, 3);
    
    std::vector <int> testArray2 = {28, 23, 52, 34, 55, 22, 44};
    
    if (testFuncDeleteElem(testArray1, testArray2)) {
        std::cout << "Correct work!\n\n";
    } else {
        std::cout << "Not correct work.\n\n";
    }
    
    return 0;
}
    
