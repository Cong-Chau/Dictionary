#include"Header.h"


int main() {
    Node* root[26];
    for (int i = 0; i < 26; i++) {
        root[i] = NULL;
    }
    int j = 0;
    for (char i = 'A'; i <= 'Z'; i++) {
        readData(root[j], i);
        j++;
    }

    activeSystem(root);
    system("pause");
    return 0;
}