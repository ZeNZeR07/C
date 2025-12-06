#include <stdio.h>
#include <stdlib.h>

/* ฟังก์ชันสำหรับรับค่าขนาดของเมทริกซ์และสมาชิกทั้งหมด */
int *GetMatrix(int *rowCountPtr, int *colCountPtr) {
    int inputRows;
    int inputCols;
    int scanStatus;
    int elementIndex;
    int totalElements;
    int *matrixData;

    *rowCountPtr = 0;
    *colCountPtr = 0;
    matrixData = NULL;

    /* รับค่าแถวและคอลัมน์จากผู้ใช้ */
    printf("Enter rows and cols: ");
    scanStatus = scanf("%d %d", &inputRows, &inputCols);

    /* ตรวจสอบความถูกต้องของข้อมูลเข้า */
    if (scanStatus != 2 || inputRows <= 0 || inputCols <= 0) {
        return NULL;
    }

    totalElements = inputRows * inputCols;

    /* จองหน่วยความจำตามจำนวนสมาชิกของเมทริกซ์ */
    matrixData = (int *)malloc(totalElements * sizeof(int));
    if (matrixData == NULL) {
        return NULL;
    }

    /* รับค่าของสมาชิกแต่ละตำแหน่ง */
    elementIndex = 0;
    while (elementIndex < totalElements) {
        printf("value[%d] = ", elementIndex);
        scanStatus = scanf("%d", &matrixData[elementIndex]);

        /* หากอ่านค่าผิดให้หยุด */
        if (scanStatus != 1) {
            break;
        }

        elementIndex = elementIndex + 1;
    }

    *rowCountPtr = inputRows;
    *colCountPtr = inputCols;

    return matrixData;
}

/* ตรวจสอบว่าเมทริกซ์พร้อมใช้งานหรือไม่ */
int IsValidMatrix(int *matrixData, int rowCount, int colCount) {
    if (matrixData == NULL) {
        return 0;
    }
    if (rowCount <= 0) {
        return 0;
    }
    if (colCount <= 0) {
        return 0;
    }
    return 1;
}

/* แสดงผลเมทริกซ์ตามรูปแบบแถวและคอลัมน์ */
void PrintMatrix(int *matrixData, int rowCount, int colCount) {
    int rowIndex;
    int colIndex;
    int position;

    rowIndex = 0;
    while (rowIndex < rowCount) {
        colIndex = 0;

        while (colIndex < colCount) {
            position = rowIndex * colCount + colIndex;
            printf("%d ", matrixData[position]);
            colIndex = colIndex + 1;
        }

        printf("\n");
        rowIndex = rowIndex + 1;
    }
}

/* คืนหน่วยความจำของเมทริกซ์ */
void FreeMatrix(int **matrixPtr) {
    if (*matrixPtr != NULL) {
        free(*matrixPtr);
        *matrixPtr = NULL;
    }
}

int main(void) {
    int *matrixData;
    int rowCount;
    int colCount;

    /* เรียกฟังก์ชันรับเมทริกซ์จากผู้ใช้ */
    matrixData = GetMatrix(&rowCount, &colCount);

    /* ตรวจสอบข้อมูลก่อนใช้เพื่อความปลอดภัย */
    if (!IsValidMatrix(matrixData, rowCount, colCount)) {
        printf("No valid matrix.\n");
        FreeMatrix(&matrixData);
        return 1;
    }

    /* แสดงผล */
    printf("\n--- Matrix ---\n");
    PrintMatrix(matrixData, rowCount, colCount);

    /* คืนหน่วยความจำ */
    FreeMatrix(&matrixData);

    return 0;
}
