#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// تابع دریافت ماتریس از کاربر
vector<vector<int>> getMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "anasor matris ra vared konid:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// تابع چاپ ماتریس
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// تابع ضرب ماتریس‌ها
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows1 = mat1.size(), cols1 = mat1[0].size();
    int rows2 = mat2.size(), cols2 = mat2[0].size();
    if (cols1 != rows2) {
        cout << "zarb matris ha momken nist!\n";
        return {};
    }
    vector<vector<int>> result(rows1, vector<int>(cols2, 0));
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

// تابع جمع ماتریس‌ها
vector<vector<int>> addMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows = mat1.size(), cols = mat1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

// تابع تفریق ماتریس‌ها
vector<vector<int>> subtractMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows = mat1.size(), cols = mat1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return result;
}

// تابع ضرب یک عدد در ماتریس
vector<vector<int>> scalarMultiply(const vector<vector<int>>& matrix, int scalar) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

// تابع جستجوی یک درایه در ماتریس
pair<int, int> findElement(const vector<vector<int>>& matrix, int element) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == element) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // اگر عنصر پیدا نشد
}

// تابع ویرایش یک درایه مشخص
void editElement(vector<vector<int>>& matrix, int i, int j, int newValue) {
    if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size()) {
        matrix[i][j] = newValue;
    } else {
        cout << "mogheiat na moetabar!\n";
    }
}

// تابع جمع عناصر سطرها
vector<int> sumRows(const vector<vector<int>>& matrix) {
    vector<int> sums;
    for (const auto& row : matrix) {
        int sum = 0;
        for (int val : row) {
            sum += val;
        }
        sums.push_back(sum);
    }
    return sums;
}

// تابع جمع عناصر ستون‌ها
vector<int> sumColumns(const vector<vector<int>>& matrix) {
    vector<int> sums(matrix[0].size(), 0);
    for (const auto& row : matrix) {
        for (int j = 0; j < row.size(); j++) {
            sums[j] += row[j];
        }
    }
    return sums;
}

// تابع جمع عناصر قطر اصلی
int sumDiagonal(const vector<vector<int>>& matrix) {
    int sum = 0;
    for (int i = 0; i < matrix.size(); i++) {
        sum += matrix[i][i];
    }
    return sum;
}

// تابع شمارش درایه‌های صفر
int countZeros(const vector<vector<int>>& matrix) {
    int count = 0;
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == 0) count++;
        }
    }
    return count;
}

// تابع تشخیص نوع ماتریس
string matrixType(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    bool isUpper = true, isLower = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j && matrix[i][j] != 0) isUpper = false;
            if (i < j && matrix[i][j] != 0) isLower = false;
        }
    }
    if (isUpper) return "bala mosalasi";
    if (isLower) return "paeen mosalasi";
    return "hich kodam";
}

// تابع سورت کردن ماتریس (مرتب‌سازی سطری)
void sortMatrix(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        sort(row.begin(), row.end());
    }
}

// تابع باینری سرچ روی یک سطر مشخص
int binarySearch(const vector<int>& row, int target) {
    int left = 0, right = row.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (row[mid] == target) return mid;
        if (row[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // اگر عنصر پیدا نشد
}

int main() {
    int rows, cols;
    cout << "tedad satr ha va sotun haye matris aval ra vared konid: ";
    cin >> rows >> cols;
    vector<vector<int>> mat1 = getMatrix(rows, cols);

    cout << "tedad satr ha va sotun haye matris dovom ra vared konid: ";
    cin >> rows >> cols;
    vector<vector<int>> mat2 = getMatrix(rows, cols);

    cout << "matris aval:\n";
    printMatrix(mat1);
    cout << "matris dovom:\n";
    printMatrix(mat2);

    vector<vector<int>> result = multiplyMatrices(mat1, mat2);
    cout << "hasel zarb matris ha:\n";
    printMatrix(result);

    result = addMatrices(mat1, mat2);
    cout << "hasel jame matris ha:\n";
    printMatrix(result);

    result = subtractMatrices(mat1, mat2);
    cout << "hasel tafrigh matris ha:\n";
    printMatrix(result);

    int scalar = 2;
    result = scalarMultiply(mat1, scalar);
    cout << "hasel zarb matris aval dar dovom " << scalar << ":\n";
    printMatrix(result);

    int element = 5;
    pair<int, int> pos = findElement(mat1, element);
    if (pos.first != -1) {
        cout << "onsor " << element << " dar mogheiat (" << pos.first << ", " << pos.second << ") yaft shod.\n";
    } else {
        cout << "onsor " << element << " یافت نشد.\n";
    }

    editElement(mat1, 0, 0, 10);
    cout << "matris aval pas az virayesh:\n";
    printMatrix(mat1);

    vector<int> rowSums = sumRows(mat1);
    cout << "jame satr ha :\n";
    for (int sum : rowSums) {
        cout << sum << " ";
    }
    cout << endl;

    vector<int> colSums = sumColumns(mat1);
    cout << "jame sotun ha:\n";
    for (int sum : colSums) {
        cout << sum << " ";
    }
    cout << endl;

    int diagonalSum = sumDiagonal(mat1);
    cout << "jame anasor ghotre asly: " << diagonalSum << endl;

    int zeroCount = countZeros(mat1);
    cout << "tedad draye hay sefr: " << zeroCount << endl;

    string type = matrixType(mat1);
    cout << "noe matris : " << type << endl;

    // سورت کردن ماتریس
    sortMatrix(mat1);
    cout << "matris aval pas az moratab sazi:\n";
    printMatrix(mat1);

    // باینری سرچ روی یک سطر مشخص
    int rowIndex = 0; // سطر اول
    int target = 10;  // عدد مورد جستجو
    int index = binarySearch(mat1[rowIndex], target);
    if (index != -1) {
        cout << "onsor  " << target << " dar satr " << rowIndex << " v sotun  " << index << " yaft shod.\n";
    } else {
        cout << "onsor  " << target << " dar satr " << rowIndex << " yaft nashod .\n";
    }

    return 0;
}
