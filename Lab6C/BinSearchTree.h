#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

struct BST
{
	string key;
	BST* left;
	BST* right;
	BST(string key = string(1, (char)0));
	BST* Insert(BST* root, string key);
	void ShowBST(BST* root, int space = 0);
	BST* Search(BST* root, string key, int& amount);
	void Count(BST* root, char letter, int& amount);
	void FillBSTwthFile(BST*& root, string path);
	void DestroyTree(BST* root);
};
