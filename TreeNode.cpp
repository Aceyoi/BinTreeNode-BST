//Сапожников Юрий ИВТ-22

#include <iostream>
#include <cassert>
#include <vector>
#include "TreeNode.Class.h"
#include "TreeNode.Modul.h"
#include "TreeNode.Test.h"
#include "TreeNode.ClassIterator.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    testcheck();

    cout << "BinTreeNode===========================================================================" << endl;
    BinTreeNode<int> tree(10);  // Создаем корень двоичного дерева с значением 10
    tree.popbtn(5);
    tree.popbtn(20);
    tree.popbtn(7);
    tree.popbtn(35);

    tree.printTree();
    cout << endl << "Глубина дерева: " << tree.depth() << endl;
    cout << "Количество узлов: " << tree.countNodes() << endl;
    cout << endl << "Обход LRN: ";
    tree.traversePostOrder();
    cout << endl << "Обход NLR: ";
    tree.traversePreOrder();
    cout << endl << "Обход LNR: ";
    tree.traverseInOrder();
    cout << endl;
    tree.deleteTree();
    cout << "BinSearchNode==========================================================================="<< endl;
    BinSearchNode<int> trees(10);  // Создаем корень двоичного дерева с значением 10
    trees.popbsn(5);
    trees.popbsn(20);
    trees.popbsn(7);
    trees.popbsn(35);

    trees.printTree();
    cout << endl << "Поиск следующего наибольшего после 7 : " << trees.successor(7) << endl;
    cout << endl << "Поиск следующего наибольшего после 10 : " << trees.successor(10) << endl;
    cout << endl << "Глубина дерева: " << trees.depth() << endl;
    cout << "Количество узлов: " << trees.countNodes() << endl;
    cout << endl << "Обход LRN: ";
    trees.traversePostOrder();
    cout << endl << "Обход NLR: ";
    trees.traversePreOrder();
    cout << endl << "Обход LNR: ";
    trees.traverseInOrder();

    cout << endl << "Находим элемент 7: " << trees.search(7) << endl;
    cout << "Удаляем элемент 7: " << endl;
    trees.del(7);

    trees.printTree();
    cout << endl;
    cout << "===========================================================================" << endl;
    vector<int> array;
    trees.TreeArray(array);
    cout << "Массив построенный на дереве: ";

    printmass(array);

    return 0;
}


//Вид дерева
//              root(10)
//            /         \
//           /           \
//          /             \
//       LNode(5)         RNode(20)
//       /    \            /   \
//      /      \          /     \
//     /        \        /       \
//  LNode(3)  RNode(7) LNode(15) RNode(30)
//
// Строгое(Совершенное)