//Сапожников Юрий ИВТ-22
#pragma once

#include<exception>
#include <iostream>
#include <vector>
#include "TreeNode.Modul.h"

using namespace std;

//Шаблонный класс узела дерева
template<typename T>
class TreeNode {  //Название класса
protected:
    T value;            // Хранимое значение узла                                                              
    TreeNode<T>* left;  // Указатель на левую ветку
    TreeNode<T>* right; // Указатель на правую ветку

    ///Конструктор без параметров
    TreeNode() {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    //Конструктор с одним параметрами
    // val - Корень дерева
    TreeNode(T val) {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    //Конструктор с параметрами
    // val - Корень дерева
    // left - Указатель на левую ветку
    // right - Указатель на правую ветку
    TreeNode(T val, TreeNode<T>* left, TreeNode<T>* right) {
        this->value = val;
        this->left = left;
        this->right = right;
    }
public:
    // Вспомогательная функция для отображения дерева (Симметричный обход)
    void printTree(int level = 0) const {
        if (right != nullptr) {
            right->printTree(level + 1);  // Рекурсивный вывод правого поддерева
        }
        for (int i = 0; i < level; ++i) {
            cout << "    ";  // Отступ для уровня дерева
        }
        cout << value << endl;  // Вывод значения узла
        if (left != nullptr) {
            left->printTree(level + 1);  // Рекурсивный вывод левого поддерева
        }
    }

    // Удаление всех узлов
    void deleteTree() {
        if (left != nullptr) {
            left->deleteTree();  // Рекурсивное удаление левого поддерева        
            delete left;
            left = nullptr;
        }
        if (right != nullptr) {
            right->deleteTree();  // Рекурсивное удаление правого поддерева
            delete right;
            right = nullptr;
        }
        if (left == nullptr && right == nullptr) {
            value = 0;
        }
    }

    // Симметричный обход (LNR) // Вывод в виде массива
    void traverseInOrder() {
        if (left != nullptr) {
            left->traverseInOrder();  // Левая часть
        }
        cout << value << " ";  // Вывод
        if (right != nullptr) {
            right->traverseInOrder();  // Правая часть
        }
    }

    // Прямой обход (NLR) // Вывод в виде массива
    void traversePreOrder() {
        cout << value << " ";  // Вывод значения текущего узла
        if (left != nullptr) {
            left->traversePreOrder();  // Рекурсивный обход левого поддерева
        }
        if (right != nullptr) {
            right->traversePreOrder();  // Рекурсивный обход правого поддерева
        }
    }

    // Обратный обход (LRN) // Вывод в виде массива
    void traversePostOrder() {
        if (left != nullptr) {
            left->traversePostOrder();  // Левая часть
        }
        if (right != nullptr) {
            right->traversePostOrder();  // Правая часть
        }
        cout << value << " ";  // Вывод
    }

    // Подсчёт количества узлов в дереве  
    int countNodes() {
        int count = 1;  // Считаем корень
        if (left != nullptr) {
            count += left->countNodes();  // Подсчёт в левой части
        }
        if (right != nullptr) {
            count += right->countNodes();  // Подсчёт в правой части
        }
        return count;
    }

    // Определение глубины дерева
    int depth() {
        int leftDepth = left ? left->depth() : 0;
        int rightDepth = right ? right->depth() : 0;
        return 1 + max(leftDepth, rightDepth);
    }

    // Поверхностное копирование
    TreeNode<T>* easycopy() {
        return this;
    }

    // Глубокое копирование
    TreeNode<T>* deepcopy() {
        TreeNode<T>* newTreeNode = new TreeNode<T>(value);  // Копируем значение текущего узла        
        if (left != nullptr) {
            newTreeNode->left = left->deepcopy();  // Рекурсивно копируем левое поддерево
        }
        if (right != nullptr) {
            newTreeNode->right = right->deepcopy();  // Рекурсивно копируем правое поддерево
        }
        return newTreeNode;
    }

    // Метод для заполнения вектора значениями дерева в порядке LNR (In-order обход)
    void TreeArray(vector<T>& arr) const {
        if (left != nullptr) {
            left->TreeArray(arr);  // Рекурсивный обход левого поддерева
        }
        arr.push_back(value);  // Добавляем значение текущего узла
        if (right != nullptr) {
            right->TreeArray(arr);  // Рекурсивный обход правого поддерева
        }
    }
};    
   


//// Функция для добавления узлов в массив
//template<typename T>
//void fillArrayInOrder(TreeNode<T>* root, vector<T>* arr) {
//    if (root->left != nullptr) {
//        fillArrayInOrder(root->left, arr);
//    }
//    arr.push_back(root->value);
//    if (root->right != nullptr) {
//        fillArrayInOrder(root->right, arr);
//    }

//Шаблонный класс узела двоичного дерева
template<typename T>
class BinTreeNode : public TreeNode<T> {  //Название класса
public:

    //Конструктор с одним параметрами
    // val - Корень дерева
    BinTreeNode(T val){
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    // Вставка значения в дерево  
    void popbtn(T val) {
        if (this->left == nullptr) {
            this->left = new BinTreeNode<T>(val);  // Вставляем в левую ветку
        }
        else {
        if (this->right == nullptr) {
            this->right = new BinTreeNode<T>(val);  // Вставляем в правую ветку
        }
        else {
            static_cast<BinTreeNode<T>*>(this->left)->popbtn(val);
        }}
    }
};

//Шаблонный класс узела дерева поиска
template<typename T>
class BinSearchNode : public TreeNode<T> {  //Название класса
public:

    //Конструктор с одним параметрами
    // val - Корень дерева
    BinSearchNode(T val) {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    // Вставка значения в дерево поиска                                                               
    void popbsn(T val) {
        if (val < this->value) {  // Если значение меньше текущего, идем в левую ветку
            if (this->left == nullptr) {
                this->left = new BinSearchNode<T>(val);  // Вставляем в левую ветку, если она пуста
            }
            else {
                static_cast<BinSearchNode<T>*>(this->left)->popbsn(val);  // Рекурсивная вставка в левое поддерево
            }
        }
        else 
            if (val > this->value) {  // Если значение больше текущего, идем в правую ветку
            if (this->right == nullptr) {
                this->right = new BinSearchNode<T>(val);  // Вставляем в правую ветку, если она пуста
            }
            else {
                static_cast<BinSearchNode<T>*>(this->right)->popbsn(val);  // Рекурсивная вставка в правое поддерево
            }
        }
    }

    // Метод для поиска значения в дереве поиска
    T search(T val) {
        // Сравнение значения с текущим узлом
        if (val == this->value) {
            return this->value;  // Значение найдено
        }
        if (val < this->value && this->left != nullptr) {
            // Если значение меньше, то ищем в левом поддереве
            return static_cast<BinSearchNode<T>*>(this->left)->search(val);  // Поиск в левом поддереве        }
        }
        if (val > this->value && this->right != nullptr) {
            // Если значение больше, то ищем в правом поддереве
            return static_cast<BinSearchNode<T>*>(this->right)->search(val);  // Поиск в правом поддереве        }
        }
    return -1;
    }

    // Метод для проверки поиска значения в дереве поиска
    bool searchbool(T val) {
        // Сравнение значения с текущим узлом
        if (val == this->value) {
            return true;  // Значение найдено
        }
        if (val < this->value && this->left != nullptr) {
            // Если значение меньше, то ищем в левом поддереве
            return static_cast<BinSearchNode<T>*>(this->left)->search(val);  // Поиск в левом поддереве        }
        }
        if (val > this->value && this->right != nullptr) {
            // Если значение больше, то ищем в правом поддереве
            return static_cast<BinSearchNode<T>*>(this->right)->search(val);  // Поиск в правом поддереве        }
        }
        return false;
    }

    // Удаление
    void del(T val) {
        if (search(val) == -1) {
        cout << endl << "Не найденно число для удаления" << endl; // Нулевой случай: удаляемый элемент отсутствует
        }
        else {

        }
    }
};

//Шаблонный класс узела авл дерева
template<typename T>
class AVLTreeNode : public TreeNode<T> {  //Название класса
public:
    int height;

    //Конструктор с одним параметрами
    // val - Корень дерева
    AVLTreeNode(T val) {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    // Получение высоты узла
    int getHeight(TreeNode<T>* node) {
        return node == nullptr ? 0 : static_cast<AVLTreeNode<T>*>(node)->height;
    }

    // Получение баланса узла
    int getBalance() {
        return getHeight(this->left) - getHeight(this->right);
    }

    // Поворот вправо
    AVLTreeNode<T>* rotateRight() {
        AVLTreeNode<T>* newRoot = static_cast<AVLTreeNode<T>*>(this->left);
        this->left = newRoot->right;
        newRoot->right = this;

        this->updateHeight();
        newRoot->updateHeight();

        return newRoot;
    }

    // Поворот влево
    AVLTreeNode<T>* rotateLeft() {
        AVLTreeNode<T>* newRoot = static_cast<AVLTreeNode<T>*>(this->right);
        this->right = newRoot->left;
        newRoot->left = this;

        this->updateHeight();
        newRoot->updateHeight();

        return newRoot;
    }

    // Обновление высоты узла
    void updateHeight() {
        this->height = 1 + std::max(getHeight(this->left), getHeight(this->right));
    }

    // Вставка значения с балансировкой
    AVLTreeNode<T>* insert(T val) {
        // Обычная вставка как в дереве поиска
        if (val < this->value) {
            if (this->left == nullptr) {
                this->left = new AVLTreeNode<T>(val);
            }
            else {
                this->left = static_cast<AVLTreeNode<T>*>(this->left)->insert(val);
            }
        }
        else if (val > this->value) {
            if (this->right == nullptr) {
                this->right = new AVLTreeNode<T>(val);
            }
            else {
                this->right = static_cast<AVLTreeNode<T>*>(this->right)->insert(val);
            }
        }

        // Обновление высоты текущего узла
        updateHeight();

        // Балансировка
        int balance = getBalance();

        // Левый тяжелый случай
        if (balance > 1 && val < static_cast<AVLTreeNode<T>*>(this->left)->value) {
            return rotateRight();
        }

        // Правый тяжелый случай
        if (balance < -1 && val > static_cast<AVLTreeNode<T>*>(this->right)->value) {
            return rotateLeft();
        }

        // Лево-правый случай
        if (balance > 1 && val > static_cast<AVLTreeNode<T>*>(this->left)->value) {
            this->left = static_cast<AVLTreeNode<T>*>(this->left)->rotateLeft();
            return rotateRight();
        }

        // Право-левый случай
        if (balance < -1 && val < static_cast<AVLTreeNode<T>*>(this->right)->value) {
            this->right = static_cast<AVLTreeNode<T>*>(this->right)->rotateRight();
            return rotateLeft();
        }

        return this;
    }
};