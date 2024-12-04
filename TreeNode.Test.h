//Сапожников Юрий ИВТ-22
#pragma once

#include <cassert>
#include "TreeNode.Class.h"
#include "TreeNode.Modul.h"

using namespace std;

void testcheck() {

    BinTreeNode<int> testtree(10);
    testtree.popbtn(5);
    testtree.popbtn(20);
    testtree.popbtn(7);
    testtree.popbtn(35);
    BinSearchNode<int> testtrees(10);
    testtrees.popbsn(5);
    testtrees.popbsn(20);
    testtrees.popbsn(7);
    testtrees.popbsn(35);

    assert(testtree.depth() == 3);
    assert(testtree.countNodes() == 5);

    testtree.deleteTree();
    assert(testtree.isEmpty() == true);

    assert(testtree.depth() == -1);
    assert(testtree.countNodes() == 0);

    assert(testtrees.depth() == 3);
    assert(testtrees.countNodes() == 5);

    assert(testtrees.successor(10) == 20);
    assert(testtrees.successor(5) == 7);
    assert(testtrees.successor(20) == 35);
    assert(testtrees.successor(7) == 10);
    //assert(testtrees.successor(35) == 35);

    assert(testtrees.search(10) == 10); 
    assert(testtrees.search(11) == -1);
    assert(testtrees.searchbool(10) == true);
    assert(testtrees.searchbool(11) == false);

    testtrees.del(7);
    testtrees.del(35);
    //testtrees.del(10);

    testtrees.deleteTree();
    assert(testtrees.isEmpty() == true);
}