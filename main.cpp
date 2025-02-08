#include <iostream>
#include <algorithm>
using namespace std;

// تابع دریافت ماتریس از کاربر
void getMatrix(int matrix[][100], int rows, int cols) {
    cout << "anasor matris ra vared konid:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// تابع چاپ ماتریس
void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// تابع ضرب ماتریس‌ها
void multiplyMatrices(int mat1[][100], int mat2[][100], int result[][100], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "zarb matris ha momken nist!\n";
        return;
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// تابع جمع ماتریس‌ها
void addMatrices(int mat1[][100], int mat2[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// تابع تفریق ماتریس‌ها
void subtractMatrices(int mat1[][100], int mat2[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// تابع ضرب یک عدد در ماتریس
void scalarMultiply(int matrix[][100], int result[][100], int rows, int cols, int scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

// تابع جستجوی یک درایه در ماتریس
pair<int, int> findElement(int matrix[][100], int rows, int cols, int element) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == element) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // اگر عنصر پیدا نشد
}

// تابع ویرایش یک درایه مشخص
void editElement(int matrix[][100], int rows, int cols, int i, int j, int newValue) {
    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        matrix[i][j] = newValue;
    } else {
        cout << "mogheiat na moetabar!\n";
    }
}

// تابع جمع عناصر سطرها
void sumRows(int matrix[][100], int rows, int cols, int rowSums[]) {
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < cols; j++) {
            rowSums[i] += matrix[i][j];
        }
    }
}

// تابع جمع عناصر ستون‌ها
void sumColumns(int matrix[][100], int rows, int cols, int colSums[]) {
    for (int j = 0; j < cols; j++) {
        colSums[j] = 0;
        for (int i = 0; i < rows; i++) {
            colSums[j] += matrix[i][j];
        }
    }
}

// تابع جمع عناصر قطر اصلی
int sumDiagonal(int matrix[][100], int rows) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

// تابع شمارش درایه‌های صفر
int countZeros(int matrix[][100], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) count++;
        }
    }
    return count;
}

// تابع تشخیص نوع ماتریس
string matrixType(int matrix[][100], int rows, int cols) {
    bool isUpper = true, isLower = true;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j && matrix[i][j] != 0) isUpper = false;
            if (i < j && matrix[i][j] != 0) isLower = false;
        }
    }
    if (isUpper) return "bala mosalasi";
    if (isLower) return "paeen masalasi";
    return "hich kodam ";
}

// تابع سورت کردن ماتریس (مرتب‌سازی سطری)
void sortMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        sort(matrix[i], matrix[i] + cols);
    }
}

// تابع باینری سرچ روی یک سطر مشخص
int binarySearch(int row[], int cols, int target) {
    int left = 0, right = cols - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (row[mid] == target) return mid;
        if (row[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // اگر عنصر پیدا نشد
}

int main() {
    int rows1, cols1, rows2, cols2;
    cout << "tedad satr ha va sotun hay matris aval ra vared konid: ";
    cin >> rows1 >> cols1;
    int mat1[100][100];
    getMatrix(mat1, rows1, cols1);

    cout << "tedad satr ha va sotun hay matris dovom ra vared konid: ";
    cin >> rows2 >> cols2;
    int mat2[100][100];
    getMatrix(mat2, rows2, cols2);

    cout << "matris aval:\n";
    printMatrix(mat1, rows1, cols1);
    cout << "matris dovom:\n";
    printMatrix(mat2, rows2, cols2);

    int result[100][100];
    multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);
    cout << "ahesl zarb matris ha:\n";
    printMatrix(result, rows1, cols2);

    addMatrices(mat1, mat2, result, rows1, cols1);
    cout << "hasel game matris ha:\n";
    printMatrix(result, rows1, cols1);

    subtractMatrices(mat1, mat2, result, rows1, cols1);
    cout << "hasel taghrigh matris ha:\n";
    printMatrix(result, rows1, cols1);

    int scalar = 2;
    scalarMultiply(mat1, result, rows1, cols1, scalar);
    cout << "hasel zarb matris aval dar dovom  " << scalar << ":\n";
    printMatrix(result, rows1, cols1);

    int element = 5;
    pair<int, int> pos = findElement(mat1, rows1, cols1, element);
    if (pos.first != -1) {
        cout << "onsor " << element << " dar mogheiat (" << pos.first << ", " << pos.second << ") yaft nashod .\n";
    } else {
        cout << "onsor " << element << " yaft nashod .\n";
    }

    editElement(mat1, rows1, cols1, 0, 0, 10);
    cout << "matris aval pas az virayesh:\n";
    printMatrix(mat1, rows1, cols1);

    int rowSums[100];
    sumRows(mat1, rows1, cols1, rowSums);
    cout << "game satr ha :\n";
    for (int i = 0; i < rows1; i++) {
        cout << rowSums[i] << " ";
    }
    cout << endl;

    int colSums[100];
    sumColumns(mat1, rows1, cols1, colSums);
    cout << "game sotun ha:\n";
    for (int j = 0; j < cols1; j++) {
        cout << colSums[j] << " ";
    }
    cout << endl;

    int diagonalSum = sumDiagonal(mat1, rows1);
    cout << "game anasor ghotre asli: " << diagonalSum << endl;

    int zeroCount = countZeros(mat1, rows1, cols1);
    cout << "tedad draye hay sefr : " << zeroCount << endl;

    string type = matrixType(mat1, rows1, cols1);
    cout << "noe matris : " << type << endl;

    // سورت کردن ماتریس
    sortMatrix(mat1, rows1, cols1);
    cout << "matris aval pas az moratab sazi:\n";
    printMatrix(mat1, rows1, cols1);

    // باینری سرچ روی یک سطر مشخص
    int rowIndex = 0; // سطر اول
    int target = 10;  // عدد مورد جستجو
    int index = binarySearch(mat1[rowIndex], cols1, target);
    if (index != -1) {
        cout << "onsor " << target << " dar satr " << rowIndex << " va sotun  " << index << " yaft nashod.\n";
    } else {
        cout << "onsor " << target << " dar satr " << rowIndex << " yaft nashod .\n";
    }

    return 0;
}
