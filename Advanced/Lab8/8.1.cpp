#include <iostream>
#include <fstream>
#include <cstring>

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
        struct studentNode *newNode = new struct studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = *now;
        *now = newNode;
    }

    void DelNode() {
        if (*now != NULL) {
            struct studentNode *temp = *now;
            *now = (*now)->next;
            delete temp;
            printf("Deleted successfully.\n");
        } else {
            printf("No node to delete.\n");
        }
    }

    void GoNext() {
        if (*now != NULL) now = &((*now)->next);
    }

    void GoFirst() {
        now = &start;
    }

    void ShowAll() {
        struct studentNode *temp = start;
        printf("\n--- Student List ---\n");
        while (temp != NULL) {
            printf("Name: %-15s | Age: %d | Sex: %c | GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
            temp = temp->next;
        }
        printf("--------------------\n");
    }

    int FindNode(char n[]) {
        GoFirst();
        while (*now != NULL) {
            if (strcmp((*now)->name, n) == 0) return 1;
            GoNext();
        }
        return 0;
    }

    struct studentNode *NowNode() {
        return *now;
    }

    void EditNode(char n[], int a, char s, float g) {
        if (*now != NULL) {
            strcpy((*now)->name, n);
            (*now)->age = a;
            (*now)->sex = s;
            (*now)->gpa = g;
        }
    }
};



void AddData(LinkedList *ll) {
    char n[20], s;
    int a;
    float g;
    printf("Enter Name: "); scanf("%s", n);
    printf("Enter Age: "); scanf("%d", &a);
    printf("Enter Sex (M/F): "); scanf(" %c", &s);
    printf("Enter GPA: "); scanf("%f", &g);
    ll->GoFirst(); 
    ll->InsNode(n, a, s, g);
}

void EditData(LinkedList *ll) {
    char n[20];
    printf("Enter name to edit: "); scanf("%s", n);
    if (ll->FindNode(n)) {
        char newN[20], s;
        int a;
        float g;
        printf("New Name: "); scanf("%s", newN);
        printf("New Age: "); scanf("%d", &a);
        printf("New Sex: "); scanf(" %c", &s);
        printf("New GPA: "); scanf("%f", &g);
        ll->EditNode(newN, a, s, g);
    } else {
        printf("Student not found!\n");
    }
}

void FindData(LinkedList *ll) {
    char n[20];
    printf("Search Name: "); scanf("%s", n);
    if (ll->FindNode(n)) {
        struct studentNode *curr = ll->NowNode();
        printf("Found! Age: %d, Sex: %c, GPA: %.2f\n", curr->age, curr->sex, curr->gpa);
    } else {
        printf("Student not found!\n");
    }
}

void readfile(LinkedList *ll) {
    ifstream f("students.dat", ios::binary);
    if (!f) return;
    struct studentNode temp;
    while (f.read((char*)&temp, sizeof(struct studentNode) - sizeof(struct studentNode*))) {
        ll->InsNode(temp.name, temp.age, temp.sex, temp.gpa);
    }
    f.close();
}

void writefile(LinkedList *ll) {
    ofstream f("students.dat", ios::binary | ios::trunc);
    ll->GoFirst();
    while (ll->NowNode() != NULL) {
        struct studentNode *curr = ll->NowNode();
 
        f.write((char*)curr, sizeof(struct studentNode) - sizeof(struct studentNode*));
        ll->GoNext();
    }
    f.close();
}

int main() {
    LinkedList listA;
    int menu;
    readfile(&listA);

    do {
        printf("\nMenu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
        if (scanf("%d", &menu) != 1) break;

        switch (menu) {
            case 1: AddData(&listA); break;
            case 2: EditData(&listA); break;
            case 3: 
                char n[20];
                printf("Enter name to delete: "); scanf("%s", n);
                if (listA.FindNode(n)) listA.DelNode();
                else printf("Not found!\n");
                break;
            case 4: FindData(&listA); break;
            case 5: listA.ShowAll(); break;
        }
    } while (menu != 0);

    writefile(&listA);
    return 0;
}