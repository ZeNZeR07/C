#include <stdio.h>
#include <string.h>

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
        struct studentNode *p = start;
        while (p != NULL) {
            struct studentNode *nxt = p->next;
            delete p;
            p = nxt;
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        struct studentNode *nn = new studentNode;
        strcpy(nn->name, n);
        nn->age = a;
        nn->sex = s;
        nn->gpa = g;
        nn->next = start;
        start = nn;
        now = &start;
    }

    void DelNode() {
        if (start == NULL || *now == NULL) return;
        struct studentNode *p = *now;
        *now = p->next;
        delete p;
    }

    void GoNext() {
        if (*now != NULL) {
            now = &((*now)->next);
        }
    }

    virtual void ShowNode() {
        if (*now != NULL) {
            printf("%s %d %c %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
        }
    }
};

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = &start;
    }

    virtual void ShowNode() {
        struct studentNode *p = start;
        while (p != NULL) {
            printf("%s", p->name);
            if (p->next != NULL) {
                printf(" ");
            }
            p = p->next;
        }
        printf("\n");
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