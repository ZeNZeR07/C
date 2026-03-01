#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char studentName[20];
    int studentAge;
    char studentSex;
    float studentGpa;
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
            free(temp);
        }
    }

    void InsNode(char name[], int age, char sex, float gpa) {
        struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
        if (newNode != NULL) {
            strcpy(newNode->studentName, name);
            newNode->studentAge = age;
            newNode->studentSex = sex;
            newNode->studentGpa = gpa;
            newNode->next = *now;
            *now = newNode;
        }
    }

    void DelNode() {
        if (*now == NULL) {
            printf("--- Data not found ---\n");
            return;
        }
        struct studentNode *temp = *now;
        *now = (*now)->next;
        free(temp);
        printf("--- Success: Data deleted ---\n");
    }

    void GoNext() {
        if (*now != NULL) {
            now = &((*now)->next);
        }
    }

    void GoFirst() {
        now = &start;
    }

    void ShowAll() {
        struct studentNode *temp = start;
        printf("\n%-20s %-5s %-5s %-5s\n", "NAME", "AGE", "SEX", "GPA");
        printf("----------------------------------------\n");
        while (temp != NULL) {
            printf("%-20s %-5d %-5c %-5.2f\n", 
                temp->studentName, temp->studentAge, temp->studentSex, temp->studentGpa);
            temp = temp->next;
        }
    }

    int FindNode(char searchName[]) {
        GoFirst();
        while (*now != NULL) {
            if (strcmp((*now)->studentName, searchName) == 0) {
                return 1;
            }
            GoNext();
        }
        return 0;
    }

    struct studentNode *NowNode() {
        return *now;
    }

    void EditNode(char name[], int age, char sex, float gpa) {
        if (*now != NULL) {
            strcpy((*now)->studentName, name);
            (*now)->studentAge = age;
            (*now)->studentSex = sex;
            (*now)->studentGpa = gpa;
        }
    }
};


void AddData(LinkedList *list) {
    char inputName[20], inputSex;
    int inputAge;
    float inputGpa;
    printf("Enter Student Name: ");
    scanf("%s", inputName);
    printf("Enter Age: ");
    scanf("%d", &inputAge);
    printf("Enter Sex (M/F): ");
    scanf(" %c", &inputSex);
    printf("Enter GPA: ");
    scanf("%f", &inputGpa);
    list->GoFirst();
    list->InsNode(inputName, inputAge, inputSex, inputGpa);
}

void EditData(LinkedList *list) {
    char searchName[20];
    printf("Enter name to edit: ");
    scanf("%s", searchName);
    if (list->FindNode(searchName)) {
        char newName[20], newSex;
        int newAge;
        float newGpa;
        printf("Enter New Name: ");
        scanf("%s", newName);
        printf("Enter New Age: ");
        scanf("%d", &newAge);
        printf("Enter New Sex: ");
        scanf(" %c", &newSex);
        printf("Enter New GPA: ");
        scanf("%f", &newGpa);
        list->EditNode(newName, newAge, newSex, newGpa);
    } else {
        printf("--- Error: Student not found ---\n");
    }
}

void readfile(LinkedList *list) {
    FILE *fileHandle = fopen("students.dat", "rb");
    if (fileHandle == NULL) {
        return;
    }
    struct studentNode temp;
    size_t sizeToRead = sizeof(struct studentNode) - sizeof(struct studentNode*);
    while (fread(&temp, sizeToRead, 1, fileHandle) == 1) {
        list->InsNode(temp.studentName, temp.studentAge, temp.studentSex, temp.studentGpa);
    }
    fclose(fileHandle);
}

void writefile(LinkedList *list) {
    FILE *fileHandle = fopen("students.dat", "wb");
    if (fileHandle == NULL) {
        return;
    }
    list->GoFirst();
    size_t sizeToWrite = sizeof(struct studentNode) - sizeof(struct studentNode*);
    while (list->NowNode() != NULL) {
        struct studentNode *current = list->NowNode();
        fwrite(current, sizeToWrite, 1, fileHandle);
        list->GoNext();
    }
    fclose(fileHandle);
}

int main() {
    LinkedList listA;
    int menuChoice = -1;
    readfile(&listA);
    while (menuChoice != 0) {
        printf("\n--- MENU ---\n(1) Add (2) Edit (3) Delete (4) Search (5) Show All (0) Exit\n");
        printf("Select: ");
        if (scanf("%d", &menuChoice) != 1) {
            break;
        }
        if (menuChoice == 1) {
            AddData(&listA);
        } else if (menuChoice == 2) {
            EditData(&listA);
        } else if (menuChoice == 3) {
            char delName[20];
            printf("Enter name to delete: ");
            scanf("%s", delName);
            if (listA.FindNode(delName)) listA.DelNode();
        } else if (menuChoice == 4) {
            char findName[20];
            printf("Enter name: ");
            scanf("%s", findName);
            if (listA.FindNode(findName)) printf("Found Student!\n");
        } else if (menuChoice == 5) {
            listA.ShowAll();
        }
    }
    writefile(&listA);
    return 0;
}