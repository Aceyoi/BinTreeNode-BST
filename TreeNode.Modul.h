//Сапожников Юрий ИВТ-22
#pragma once

#include<exception>
#include <iostream>
#include <vector>
#include "TreeNode.Class.h"

using namespace std;

template<typename T>
void printmass(vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


