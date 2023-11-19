#include<iostream>
#include<fstream>
#include<cstring>
#include<string.h>
#include<string>
#include<queue>
#include<windows.h>

#define MAX 100000
using namespace std;

struct Dictionary {
	string vocalbulary;
};

struct Node {
	Dictionary data;
	Node* left;
	Node* right;
	int height;
};



void textColor(int a);
int heightNode(Node* root);
Node* createNode(Dictionary data);
void rotateLeft(Node*& root);
void rotateRight(Node*& root);
void insertData(Node*& root, Dictionary data);
void readData(Node*& root, char x);
string searchDictionary(Node* root, string search);// level order
void interfaceSystem();
void activeSystem(Node* root[]);