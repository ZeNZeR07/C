#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
protected:
    struct studentNode *start;
    struct studentNode **now;

public:
    LinkedList() {
        start = NULL;
        now = &start;
    }

    ~LinkedList() {
        struct studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            delete temp;
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        struct studentNode *newNode = new studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = start;
        start = newNode;
        now = &start;
    }

    void DelNode() {
        if (start == NULL || *now == NULL) return;
        struct studentNode *temp = *now;
        *now = temp->next;
        delete temp;
    }

    void GoNext() {
        if (*now != NULL) {
            now = &((*now)->next);
        }
    }

    virtual void ShowNode() {
        if (*now != NULL) {
            cout << (*now)->name << " " << (*now)->age << " " << (*now)->sex << " " << fixed << setprecision(2) << (*now)->gpa << endl;
        }
    }
};

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = &start;
    }

    virtual void ShowNode() {
        struct studentNode *temp = start;
        while (temp != NULL) {
            cout << temp->name;
            if (temp->next != NULL) {
                cout << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}