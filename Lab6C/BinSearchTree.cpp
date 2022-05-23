#include "BinSearchTree.h"

BST::BST(string key)
{
	this->key = key;
	this->left = NULL;
	this->right = NULL;
}

BST* BST::Insert(BST* root, string key)
{
	if (!root)
		return new BST(key);
	if (key < root->key)
	{
		root->left = Insert(root->left, key);
	}
	else
	{
		root->right = Insert(root->right, key);
	}
	return root;
}

void BST::ShowBST(BST* root, int space)
{
	if (root == NULL)
		return;
	space += 10;
	ShowBST(root->right, space);
	cout << endl;
	for (int i = 10; i < space; i++)
		cout << " ";
	cout << root->key << endl;
	ShowBST(root->left, space);
}

BST* BST::Search(BST* root, string key, int& amount)
{
	if (root == NULL || root->key == key)
		return root;
	if (root->key <= key)
		Search(root->right, key, amount);
	else
		Search(root->left, key, amount);
}

void BST::Count(BST* root, char letter, int& amount)
{
	if (!root)
	{
		return;
	}
	Count(root->left, letter, amount);
	setlocale(LC_ALL, "rus");
	char tempLetterL = tolower(letter);
	char tempLetterB = toupper(letter);
	if (root->key.substr(0, 1).c_str()[0] == tempLetterL || root->key.substr(0, 1).c_str()[0] == tempLetterB)
		amount++;
	setlocale(LC_ALL, "");
	Count(root->right, letter, amount);
}

void BST::FillBSTwthFile(BST*& root, string path)
{
	ifstream in(path, ios::in);
	if (!in.is_open())
	{
		cout << "Файл " << path << " не открыт!" << endl;
	}
	else
	{
		string input;
		string word;
		getline(in, input);
		int amount = 0;
		int start, end = 0;
		while ((start = input.find_first_not_of(" ", end)) != string::npos)
		{
			end = input.find(" ", start);
			int length = end - start;
			if (length == 0)
				continue;
			word = input.substr(start, length);
			if (root)
				Insert(root, word);
			else
				root = Insert(root, word);
		}
		in.close();
	}
}

void BST::DestroyTree(BST* root)
{
	if (root)
	{
		DestroyTree(root->left);
		DestroyTree(root->right);
		delete root;
	}
}
