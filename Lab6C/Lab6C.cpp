#include <iostream>
#include "BinSearchTree.h"
#include "Header.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BST Tree, *root = NULL;
    CreateAndFillFile("input.txt");
    Tree.FillBSTwthFile(root, "input.txt");
    Tree.ShowBST(root);
    cout << endl;
    int amount = 0;
    char letter = ' ';
    GetLetter(&letter);
    Tree.Count(root, letter, amount);
    cout << "Количество слов с указанной первой буквой: " << amount;
    Tree.DestroyTree(root);
}