//���������� ���� ���-22
#pragma once

#include<exception>
#include <iostream>
#include <vector>
#include "TreeNode.Modul.h"

using namespace std;

//��������� ����� ����� ������
template<typename T>
class TreeNode {  //�������� ������
protected:
    T value;            // �������� �������� ����                                                              
    TreeNode<T>* left;  // ��������� �� ����� �����
    TreeNode<T>* right; // ��������� �� ������ �����

    ///����������� ��� ����������
    TreeNode() {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    //����������� � ����� �����������
    // val - ������ ������
    TreeNode(T val) {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    //����������� � �����������
    // val - ������ ������
    // left - ��������� �� ����� �����
    // right - ��������� �� ������ �����
    TreeNode(T val, TreeNode<T>* left, TreeNode<T>* right) {
        this->value = val;
        this->left = left;
        this->right = right;
    }
public:
    // ��������������� ������� ��� ����������� ������ (������������ �����)
    void printTree(int level = 0) const {
        if (right != nullptr) {
            right->printTree(level + 1);  // ����������� ����� ������� ���������
        }
        for (int i = 0; i < level; ++i) {
            cout << "    ";  // ������ ��� ������ ������
        }
        cout << value << endl;  // ����� �������� ����
        if (left != nullptr) {
            left->printTree(level + 1);  // ����������� ����� ������ ���������
        }
    }

    // �������� ���� �����
    void deleteTree() {
        if (left != nullptr) {
            left->deleteTree();  // ����������� �������� ������ ���������        
            delete left;
            left = nullptr;
        }
        if (right != nullptr) {
            right->deleteTree();  // ����������� �������� ������� ���������
            delete right;
            right = nullptr;
        }
        if (left == nullptr && right == nullptr) {
            value = 0;
        }
    }

    // ������������ ����� (LNR) // ����� � ���� �������
    void traverseInOrder() {
        if (left != nullptr) {
            left->traverseInOrder();  // ����� �����
        }
        cout << value << " ";  // �����
        if (right != nullptr) {
            right->traverseInOrder();  // ������ �����
        }
    }

    // ������ ����� (NLR) // ����� � ���� �������
    void traversePreOrder() {
        cout << value << " ";  // ����� �������� �������� ����
        if (left != nullptr) {
            left->traversePreOrder();  // ����������� ����� ������ ���������
        }
        if (right != nullptr) {
            right->traversePreOrder();  // ����������� ����� ������� ���������
        }
    }

    // �������� ����� (LRN) // ����� � ���� �������
    void traversePostOrder() {
        if (left != nullptr) {
            left->traversePostOrder();  // ����� �����
        }
        if (right != nullptr) {
            right->traversePostOrder();  // ������ �����
        }
        cout << value << " ";  // �����
    }

    // ������� ���������� ����� � ������  
    int countNodes() {
        int count = 1;  // ������� ������
        if (left != nullptr) {
            count += left->countNodes();  // ������� � ����� �����
        }
        if (right != nullptr) {
            count += right->countNodes();  // ������� � ������ �����
        }
        return count;
    }

    // ����������� ������� ������
    int depth() {
        int leftDepth = left ? left->depth() : 0;
        int rightDepth = right ? right->depth() : 0;
        return 1 + max(leftDepth, rightDepth);
    }

    // ������������� �����������
    TreeNode<T>* easycopy() {
        return this;
    }

    // �������� �����������
    TreeNode<T>* deepcopy() {
        TreeNode<T>* newTreeNode = new TreeNode<T>(value);  // �������� �������� �������� ����        
        if (left != nullptr) {
            newTreeNode->left = left->deepcopy();  // ���������� �������� ����� ���������
        }
        if (right != nullptr) {
            newTreeNode->right = right->deepcopy();  // ���������� �������� ������ ���������
        }
        return newTreeNode;
    }

    // ����� ��� ���������� ������� ���������� ������ � ������� LNR (In-order �����)
    void TreeArray(vector<T>& arr) const {
        if (left != nullptr) {
            left->TreeArray(arr);  // ����������� ����� ������ ���������
        }
        arr.push_back(value);  // ��������� �������� �������� ����
        if (right != nullptr) {
            right->TreeArray(arr);  // ����������� ����� ������� ���������
        }
    }
};    
   


//// ������� ��� ���������� ����� � ������
//template<typename T>
//void fillArrayInOrder(TreeNode<T>* root, vector<T>* arr) {
//    if (root->left != nullptr) {
//        fillArrayInOrder(root->left, arr);
//    }
//    arr.push_back(root->value);
//    if (root->right != nullptr) {
//        fillArrayInOrder(root->right, arr);
//    }

//��������� ����� ����� ��������� ������
template<typename T>
class BinTreeNode : public TreeNode<T> {  //�������� ������
public:

    //����������� � ����� �����������
    // val - ������ ������
    BinTreeNode(T val){
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    // ������� �������� � ������  
    void popbtn(T val) {
        if (this->left == nullptr) {
            this->left = new BinTreeNode<T>(val);  // ��������� � ����� �����
        }
        else {
        if (this->right == nullptr) {
            this->right = new BinTreeNode<T>(val);  // ��������� � ������ �����
        }
        else {
            static_cast<BinTreeNode<T>*>(this->left)->popbtn(val);
        }}
    }
};

//��������� ����� ����� ������ ������
template<typename T>
class BinSearchNode : public TreeNode<T> {  //�������� ������
public:

    //����������� � ����� �����������
    // val - ������ ������
    BinSearchNode(T val) {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    // ������� �������� � ������ ������                                                               
    void popbsn(T val) {
        if (val < this->value) {  // ���� �������� ������ ��������, ���� � ����� �����
            if (this->left == nullptr) {
                this->left = new BinSearchNode<T>(val);  // ��������� � ����� �����, ���� ��� �����
            }
            else {
                static_cast<BinSearchNode<T>*>(this->left)->popbsn(val);  // ����������� ������� � ����� ���������
            }
        }
        else 
            if (val > this->value) {  // ���� �������� ������ ��������, ���� � ������ �����
            if (this->right == nullptr) {
                this->right = new BinSearchNode<T>(val);  // ��������� � ������ �����, ���� ��� �����
            }
            else {
                static_cast<BinSearchNode<T>*>(this->right)->popbsn(val);  // ����������� ������� � ������ ���������
            }
        }
    }

    // ����� ��� ������ �������� � ������ ������
    T search(T val) {
        // ��������� �������� � ������� �����
        if (val == this->value) {
            return this->value;  // �������� �������
        }
        if (val < this->value && this->left != nullptr) {
            // ���� �������� ������, �� ���� � ����� ���������
            return static_cast<BinSearchNode<T>*>(this->left)->search(val);  // ����� � ����� ���������        }
        }
        if (val > this->value && this->right != nullptr) {
            // ���� �������� ������, �� ���� � ������ ���������
            return static_cast<BinSearchNode<T>*>(this->right)->search(val);  // ����� � ������ ���������        }
        }
    return -1;
    }

    // ����� ��� �������� ������ �������� � ������ ������
    bool searchbool(T val) {
        // ��������� �������� � ������� �����
        if (val == this->value) {
            return true;  // �������� �������
        }
        if (val < this->value && this->left != nullptr) {
            // ���� �������� ������, �� ���� � ����� ���������
            return static_cast<BinSearchNode<T>*>(this->left)->search(val);  // ����� � ����� ���������        }
        }
        if (val > this->value && this->right != nullptr) {
            // ���� �������� ������, �� ���� � ������ ���������
            return static_cast<BinSearchNode<T>*>(this->right)->search(val);  // ����� � ������ ���������        }
        }
        return false;
    }















    // ��������
    void del(T val) {
        if (search(val) == -1) {
        cout << endl << "�� �������� ����� ��� ��������" << endl; // ������� ������: ��������� ������� �����������
        }
        else {

        }
    }
};
