#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
            free(temp);
        }
    }

    void InsNode(char studentName[], int studentAge, char studentSex, float studentGpa) {
        struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
        if (newNode != NULL) {
            strcpy(newNode->name, studentName);
            newNode->age = studentAge;
            newNode->sex = studentSex;
            newNode->gpa = studentGpa;
            newNode->next = *now;
            *now = newNode;
        }
    }


    void DelNode() {
        if (*now != NULL) {
            struct studentNode *temp = *now;
            *now = (*now)->next;
            free(temp);
            printf("--- Data deleted successfully ---\n");
        } else {
            printf("--- Error: No data to delete ---\n");
        }
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
            printf("%-20s %-5d %-5c %-5.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
            temp = temp->next;
        }
    }

    
    int FindNode(char searchName[]) {
        GoFirst();
        while (*now != NULL) {
            if (strcmp((*now)->name, searchName) == 0) {
                return 1; // พบข้อมูล
            }
            GoNext();
        }
        return 0; 
    }

    struct studentNode *NowNode() {
        return *now;
    }

    void EditNode(char newName[], int newAge, char newSex, float newGpa) {
        if (*now != NULL) {
            strcpy((*now)->name, newName);
            (*now)->age = newAge;
            (*now)->sex = newSex;
            (*now)->gpa = newGpa;
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
        printf("Enter New Sex (M/F): ");
        scanf(" %c", &newSex);
        printf("Enter New GPA: ");
        scanf("%f", &newGpa);

        list->EditNode(newName, newAge, newSex, newGpa);
        printf("--- Update Complete ---\n");
    } else {
        printf("--- Student not found ---\n");
    }
}

void FindData(LinkedList *list) {
    char searchName[20];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    if (list->FindNode(searchName)) {
        struct studentNode *current = list->NowNode();
        printf("Result -> Age: %d, Sex: %c, GPA: %.2f\n", current->age, current->sex, current->gpa);
    } else {
        printf("--- Student not found ---\n");
    }
}

void readfile(LinkedList *list) {
    FILE *filePtr = fopen("students.dat", "rb");
    if (filePtr == NULL) return;

    struct studentNode temp;
    size_t dataSize = sizeof(struct studentNode) - sizeof(struct studentNode*);
    
    while (fread(&temp, dataSize, 1, filePtr) == 1) {
        list->InsNode(temp.name, temp.age, temp.sex, temp.gpa);
    }
    fclose(filePtr);
}

void writefile(LinkedList *list) {
    FILE *filePtr = fopen("students.dat", "wb");
    if (filePtr == NULL) return;

    list->GoFirst();
    size_t dataSize = sizeof(struct studentNode) - sizeof(struct studentNode*);
    
    while (list->NowNode() != NULL) {
        struct studentNode *current = list->NowNode();
        fwrite(current, dataSize, 1, filePtr);
        list->GoNext();
    }
    fclose(filePtr);
}

int main() {
    LinkedList listA;
    int menuSelection = -1;

    readfile(&listA);

    while (menuSelection != 0) {
        printf("\n======= STUDENT MANAGEMENT =======\n");
        printf("(1) Add Data\n(2) Edit Data\n(3) Delete Data\n");
        printf("(4) Find Data\n(5) Show All\n(0) Exit\n");
        printf("Select Menu: ");
        
        if (scanf("%d", &menuSelection) != 1) break;

        switch (menuSelection) {
            case 1: AddData(&listA); break;
            case 2: EditData(&listA); break;
            case 3: 
                char deleteName[20];
                printf("Enter name to delete: ");
                scanf("%s", deleteName);
                if (listA.FindNode(deleteName)) listA.DelNode();
                else printf("--- Student not found ---\n");
                break;
            case 4: FindData(&listA); break;
            case 5: listA.ShowAll(); break;
        }
    }

    writefile(&listA);
    printf("--- Data saved. Goodbye! ---\n");
    return 0;
}