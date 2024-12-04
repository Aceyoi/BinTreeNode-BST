//Сапожников Юрий ИВТ-22
#pragma once

#include<exception>
#include <iostream>
#include <vector>
#include "TreeNode.Modul.h"
#include "TreeNode.Class.h"


using namespace std;

//Шаблонный класс итератора для BST дерева
template <typename T>
class BSTIterator {
protected:
    /// флажок, показывающий, достиг ли итератор конца списка
    int iterationComplete;
    TreeNode<T>* stack;  // Стек для хранения узлов дерева
    TreeNode<T>* current;  // Текущий узел итерации

};