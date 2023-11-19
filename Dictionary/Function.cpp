#include"Header.h"

void textColor(int a) {
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, a);
}

int heightNode(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(heightNode(root->left), heightNode(root->right));
}

Node* createNode(Dictionary data) {
    Node* tmp = new Node{ data, NULL,  NULL ,  1 };
    return tmp;
}


void rotateLeft(Node*& root) {
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;
}

void rotateRight(Node*& root) {
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;
}

void insertData(Node*& root, Dictionary data) {
    Node* tmp = new Node;
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    if (root == NULL)
        root = tmp;
    else {
        if (data.vocalbulary < root->data.vocalbulary) {
            // Duyet qua trai de them phan tu x
            insertData(root->left, data);
        }
        else if (data.vocalbulary > root->data.vocalbulary) {
            // Duyet qua phai de them phan tu x
            insertData(root->right, data);
        }
        else
            return;
    }
    int balance = heightNode(root->left) - heightNode(root->right);
    if (balance > 1) {          // left
        Node* left = root->left;
        int balanceChild = heightNode(left->left) - heightNode(left->right);
        if (balanceChild < 0) {// left-right
            rotateLeft(root->left);
            rotateRight(root);
        }
        else
            rotateRight(root);
    }
    else if (balance < -1) {    // right
        Node* right = root->right;
        int balanceChild = heightNode(right->left) - heightNode(right->right);
        if (balanceChild > 0) { // left-right
            rotateRight(root->right);
            rotateLeft(root);
        }
        else
            rotateLeft(root);
        balance = heightNode(root->left) - heightNode(root->right);
    }
}

void readData(Node*& root,char x) {
    ifstream input("Dictionary.txt", ios::in);
    int i = 1;
    if (input.is_open()) {
        //      for(int j=0;j<10;j++){
        while (!input.eof()) {
            Dictionary tmp;
            getline(input, tmp.vocalbulary);
            if (tmp.vocalbulary.length() != 0) {
                if (tmp.vocalbulary[0] == x) {
                    cout << i++ << ".\t" << tmp.vocalbulary << endl;
                    insertData(root, tmp);
                }
            }
        }
        /*system("cls");
        cout << "\n\n\tTHE DATA HAS BEEN UPLOADED SUCCESS\n\n\t";
        system("pause");*/


    }
    else
        cout << "\nError\n";
}


string searchDictionary(Node* root, string search) {// level order
    queue<Node*> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node* tmp = queue.front();
        if (search == tmp->data.vocalbulary) {
            //// chua hoan thien /////
            return tmp->data.vocalbulary;
        }
        queue.pop();
        if (tmp->left != NULL) {
            queue.push(tmp->left);
        }
        if (tmp->right != NULL) {
            queue.push(tmp->right);
        }
    }
    return { "Can't find a word" };
}

void interfaceSystem() {
    textColor(243);
    cout << "============================================" << endl;
    cout << "=                                          =" << endl;
    cout << "=                                          =" << endl;
    cout << "=         WELLCOME TO MY DICTIONARY        =" << endl;
    cout << "=                                          =" << endl;
    cout << "=                                          =" << endl;
    cout << "============================================" << endl;
    textColor(7);
}

void activeSystem(Node*root[]) {
    while (1) {
        system("cls");
        interfaceSystem();
        cout << "\n=================== Menu ===================";
        cout << "\n  0. Quit.";
        cout << "\n  1. Look up mean of the word.";
        cout << "\n  2. Add a word to the dictionary.";
        cout << "\n  3. Edit the meaning of a word.";
        cout << "\n  4. Remove a word.";
        cout << "\n  5. Export Dictionary.";  
        cout << "\n============================================";
        int choose;
        cout << "\n\nChon: "; cin >> choose;
        switch (choose) {
        case 0: {
            return;
        }
        case 1: {
            string keyword;
            cout << "Keyword: ";
            cin.ignore();
            getline(cin, keyword);
            int local = keyword[0] - 65;
            string results = searchDictionary(root[local], keyword);
            cout << endl << results << endl;
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            system("pause");
            system("cls");
            break;
        }
        default: {
            cout << "\n\tYOUR CHOOSE IS INVALID!!!";
            cout << "\n\t  PLEASE CHOOSE AGAIN\n\n\t";
            system("pause");
        }
        }
    }
}