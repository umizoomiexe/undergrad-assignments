#include "minFunc.h"
#include <iostream>

using namespace std; 

const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) {
        return nullptr;
    }

    if (arrSize == 1) {
        return &arr[0];
    }

    const int *restMin = min(arr + 1, arrSize - 1);

    if (*restMin < arr[0]) {
        return restMin;
    } else {
        return &arr[0];
    }
}