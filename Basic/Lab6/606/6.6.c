#include <stdio.h>
#define SIZE 5

// 1. Function Prototype (การประกาศต้นแบบฟังก์ชัน)
// ต้องประกาศไว้ก่อน main() เพื่อให้ main() รู้จักฟังก์ชันนี้แม้ว่าตัวฟังก์ชันจะอยู่ข้างล่าง
int calculate_net_balance(int trans_array[], int size, int *status_ptr);

int main() {
    int transactions[SIZE];
    int net_balance;
    int finance_status;
    int i;

    // 1. การรับข้อมูล (Input)
    printf("Enter %d transactions (Income +, Expense -):\\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("Transaction #d: ", i + 1);
        scanf("%d", &transactions[i]);
    }
    
    // 2. การเรียกใช้ Function
    // เรียกใช้ calculate_net_balance
    net_balance = calculate_net_balance(transactions, SIZE, &finance_status);


    // 3. การแสดงผลลัพธ์ (Output/Report)
    printf("\n--- PERSONAL FINANCE REPORT ---\n");
    printf("Transactions Recorded: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", transactions[i]);
    }
    printf("\n");
    
    printf("Net Balance: %d\n", net_balance);
    
    printf("Status: ");
    if (finance_status == 1) {
        printf("PROFIT\n");
    } else {
        printf("LOSS\n");
    }
    
    return 0;
}

// 2. Function Definition (นิยามฟังก์ชัน) ถูกย้ายมาอยู่ด้านล่าง main()
int calculate_net_balance(int trans_array[], int size, int *status_ptr) {
    int net_balance = 0;

    // คำนวณยอดคงเหลือสุทธิ
    for (int i = 0; i < size; i++) {
        net_balance += trans_array[i];
    }
    
    // กำหนดสถานะทางการเงิน (Call by Reference)
    if (net_balance >= 0) {
        *status_ptr = 1; // สถานะ Profit
    } else {
        *status_ptr = 0; // สถานะ Loss
    }
    
    return net_balance;
}