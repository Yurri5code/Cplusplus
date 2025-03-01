#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

// Функция для ввода расширенной матрицы
float **inputMatrix(const int m,const int n) {
    auto **a = new float *[m];
    cout << "Введите расширенную матрицу:\n";
    for (int i = 0; i < m; i++) {
        a[i] = new float[n + 1];
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    return a;
}

// Функция для вывода матрицы
void outputMatrix(float **a, int m, int n) {
    for (int k1 = 0; k1 < m; k1++) {
        for (int k2 = 0; k2 <= n; k2++) {
            cout << a[k1][k2] << "\t";
        }
        cout << endl;
    }
    cout << "\n";
}

// Функция для проверки, является ли столбец нулевым
int checkNonZeroElements(const float *a,const int n) {
    for (int i = 0; i < n; i++) {
        if (fabs(a[i]) < 0.0001) {
            return 0;
        }
    }
    return 1;
}

// Функция приведения матрицы к базисному виду
float **getBasicView(float **a, int *m,const int n) {
    for (int k = 0, jm = 0; k < *m; k++) {
        if (fabs(a[k][jm]) > 0.0001) {
            for (int i = n; i >= k; i--) {
                a[k][i] /= a[k][jm];    // Получение ведущей строки
            }
            for (int i = 0; i < *m; i++) {
                if (i != k) {
                    for (int j = n; j >= k; j--) {
                        // Преобразование остальных строк матрицы и
                        // получение единичного столбца
                        a[i][j] -= a[k][j] * (a[i][k] / a[k][jm]);
                    }
                }
            }
            jm++;
            cout << k + 1 << " шаг\n";
            outputMatrix(a, *m, n);
        } else if (!checkNonZeroElements(a[k], n)) {
            for (int i = 0; i < n; i++) {
                a[k][i] = a[*m - 1][i];
            }
            (*m)--;
        }
    }
    return a;
}

// Функция для получения решения
float *getSolution(float **a, int n, const int *vec, int *kol) {
    auto *s = new float[n];
    for (int k = 0, im = 0; k < n; k++) {
        if (vec[k]) {
            s[k] = a[im++][n];
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] < 0) {
            return nullptr;
        }
    }

    (*kol)++;
    return s;
}

// Функция для проверки столбцов
int checkColumns(float **a,const int n,const int *vec) {
    for (int j = 0, im = 0; j < n; j++) {
        if (vec[j]) {
            if (std::fabs(a[im][j]) < 0.0001) {
                return 0;
            }
            im++;
        }
    }
    return 1;
}

// Функция для получения и вывода всех базисных решений
float **outputAllBasicSolutions(float **a, int m, int n, int *kol) {
    auto **solutions = new float *[1 << n];
    int *vec = new int[n];
    cout << "\n";
    for (int k = 0, l = 0; k < (1 << n); k++, l = 0) {
        // Перебор всех возможных комбинаций переменных
        for (int i = 0, temp = k; i < n; i++, l += temp % 2, temp /= 2) {
            vec[i] = temp % 2;
        }
        // Проверка, является ли базисный набор допустимым
        if (l == m && checkColumns(a, n, vec)) {
            cout << "Базисные переменные: ";
            for (int i = 0; i < n; i++) {
                if (vec[i]) {
                    cout << "x[" << i + 1 << "]\t";
                }
                cout << "\n";
                // Получение нового базисного решения
                for (int z = 0, im = 0; z < n && im < m; z++) {
                    if (vec[z]) {
                        // Получение ведущей строки
                        if (a[im][z] != 1) {
                            const float koef = a[im][z];
                            for (int j = 0; j <= n; j++) {
                                a[im][j] /= koef;
                            }
                        }
                        // Преобразование остальных строк матрицы и
                        // получение единичного столбца
                        for (int j = 0; j < m; j++) {
                            if (j != im) {
                                const float koef = a[j][i] / a[im][i];
                                for (int d = 0; d <= n; d++) {
                                    a[j][d] -= a[im][d] * koef;
                                }
                            }
                        }
                        im++;
                    }
                }
            }
            for (int k2 = 0; k2 < n; k2++) {
                cout << "x[" << k2 + 1 << "]\t";
            }
            cout << "B\n";
            outputMatrix(a, m, n);
            solutions[*kol] = getSolution(a, n, vec, kol);
        }
    }
    return solutions;
}

void deleteMemory(float** array,const int m) {
    if(array == nullptr) {
        return;
    }
    for(int i = 0;i < m;i++) {
        delete[] array[i];
    }
    delete[] array;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int m, n;
    cout << "Введите количество уравнений: ";
    cin >> m;
    cout << "Введите количество переменных: ";
    cin >> n;

    int k = 0;
    float **a = inputMatrix(m, n);
    float **b = getBasicView(a, &m, n);
    float **c = outputAllBasicSolutions(b, m, n, &k);
    cout << "\n";

    // Вывод опорных планов и их сумм
    float maxSum = 0;
    int optimalPlanIndex = 0;
    for (int i = 0; i < k; i++) {
        float sum = 0;
        cout << "Опорный план " << i + 1 << ":\n";
        for (int j = 0; j < n; j++) {
            cout << "x[" << j + 1 << "]\t";
            cout << c[i][j] << "\n";
            sum += c[i][j];
        }

        cout << "Сумма: " << sum << "\n";
        if (sum > maxSum) {
            maxSum = sum;
            optimalPlanIndex = i;
        }
    }

    cout << "\nОптимальный план: ";
    for (int i = 0; i < n; i++) {
        cout << c[optimalPlanIndex][i] << ' ';
    }

    cout << "\nЗначение целевой функции для оптимального плана: " << maxSum;
    deleteMemory(a,m);
    deleteMemory(b,m);
    deleteMemory(c,m);

    return 0;
}


/*
1er mise a jour 

*/
#include <iostream>
#include <cmath>
#include <vector>
#include <windows.h>

using namespace std;

// Функция для ввода расширенной матрицы
vector<vector<float>> inputMatrix(int m, int n) {
    vector<vector<float>> a(m, vector<float>(n + 1));
    cout << "Введите расширенную матрицу:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == n) {
                cout << "B :";
            } else {
                cout << "X_" << j + 1 << " :";
            }
            cin >> a[i][j];
        }
    }
    return a;
}

// Функция для вывода матрицы
void outputMatrix(const vector<vector<float>>& a) {
    for (const auto& row : a) {
        for (float elem : row) {
            cout << elem << "\t\t";
        }
        cout << endl;
    }
    cout << "\n";
}

// Функция для проверки, является ли столбец нулевым
bool checkNonZeroElements(const vector<float>& a) {
    for (float elem : a) {
        if (fabs(elem) < 0.0001) {
            return false;
        }
    }
    return true;
}

// Функция приведения матрицы к базисному виду
void getBasicView(vector<vector<float>>& a, int& m, int n) {
    for (int k = 0, jm = 0; k < m; k++) {
        if (fabs(a[k][jm]) > 0.0001) {
            for (int i = n; i >= k; i--) {
                a[k][i] /= a[k][jm];    // Получение ведущей строки
            }
            for (int i = 0; i < m; i++) {
                if (i != k) {
                    for (int j = n; j >= k; j--) {
                        // Преобразование остальных строк матрицы и
                        // получение единичного столбца
                        a[i][j] -= a[k][j] * (a[i][k] / a[k][jm]);
                    }
                }
            }
            jm++;
            cout << k + 1 << " шаг\n";
            outputMatrix(a);
        } else if (!checkNonZeroElements(a[k])) {
            a.erase(a.begin() + k);
            m--;
            k--;
        }
    }
}

// Функция для получения решения
vector<float> getSolution(const vector<vector<float>>& a, int n, const vector<int>& vec, int& kol) {
    vector<float> s(n);
    for (int k = 0, im = 0; k < n; k++) {
        if (vec[k]) {
            s[k] = a[im++][n];
        }
    }

    for (float val : s) {
        if (val < 0) {
            return {};
        }
    }

    kol++;
    return s;
}

// Функция для проверки столбцов
bool checkColumns(const vector<vector<float>>& a, int n, const vector<int>& vec) {
    for (int j = 0, im = 0; j < n; j++) {
        if (vec[j]) {
            if (fabs(a[im][j]) < 0.0001) {
                return false;
            }
            im++;
        }
    }
    return true;
}

// Функция для получения и вывода всех базисных решений
vector<vector<float>> outputAllBasicSolutions(vector<vector<float>>& a, int m, int n, int& kol) {
    vector<vector<float>> solutions;
    vector<int> vec(n);
    cout << "\n";
    for (int k = 0, l = 0; k < (1 << n); k++, l = 0) {
        // Перебор всех возможных комбинаций переменных
        for (int i = 0, temp = k; i < n; i++, l += temp % 2, temp /= 2) {
            vec[i] = temp % 2;
        }
        // Проверка, является ли базисный набор допустимым
        if (l == m && checkColumns(a, n, vec)) {
            cout << "Базисные переменные: ";
            for (int i = 0; i < n; i++) {
                if (vec[i]) {
                    cout << "x[" << i + 1 << "]\t";
                }
            }
            cout << "\n";
            // Получение нового базисного решения
            for (int z = 0, im = 0; z < n && im < m; z++) {
                if (vec[z]) {
                    // Получение ведущей строки
                    if (a[im][z] != 1) {
                        const float koef = a[im][z];
                        for (int j = 0; j <= n; j++) {
                            a[im][j] /= koef;
                        }
                    }
                    // Преобразование остальных строк матрицы и
                    // получение единичного столбца
                    for (int j = 0; j < m; j++) {
                        if (j != im) {
                            const float koef = a[j][z] / a[im][z];
                            for (int d = 0; d <= n; d++) {
                                a[j][d] -= a[im][d] * koef;
                            }
                        }
                    }
                    im++;
                }
            }
            outputMatrix(a);
            vector<float> solution = getSolution(a, n, vec, kol);
            if (!solution.empty()) {
                solutions.push_back(solution);
            }
        }
    }
    return solutions;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int m, n;
    cout << "Введите количество уравнений: ";
    cin >> m;
    cout << "Введите количество переменных: ";
    cin >> n;

    int k = 0;
    vector<vector<float>> a = inputMatrix(m, n);
    getBasicView(a, m, n);
    vector<vector<float>> c = outputAllBasicSolutions(a, m, n, k);

    // Вывод опорных планов и их сумм
    float maxSum = 0;
    int optimalPlanIndex = 0;
    for (int i = 0; i < k; i++) {
        float sum = 0;
        cout << "Опорный план " << i + 1 << ":\n";
        for (int j = 0; j < n; j++) {
            cout << "x[" << j + 1 << "]\t\t" << c[i][j] << "\n";
            sum += c[i][j];
        }

        cout << "Сумма: " << sum << "\n";
        if (sum > maxSum) {
            maxSum = sum;
            optimalPlanIndex = i;
        }
    }

    cout << "\nОптимальный план: ";
    for (int i = 0; i < n; i++) {
        cout << c[optimalPlanIndex][i] << ' ';
    }

    cout << "\nЗначение целевой функции для оптимального плана: " << maxSum;

    return 0;
}
//mise a jour du code en une meilleure version qui respecte l'affichage et donne une meilleure visibilete 
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <windows.h>

using namespace std;

// Функция для ввода расширенной матрицы
vector<vector<float>> inputMatrix(int m, int n) {
    vector<vector<float>> a(m, vector<float>(n + 1));
    cout << "Введите расширенную матрицу:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == n) {
                cout << "B :";
            } else {
                cout << "X_" << j + 1 << " :";
            }
            cin >> a[i][j];
        }
    }
    return a;
}

// Функция для вывода матрицы
void outputMatrix(const vector<vector<float>>& a) {
    for (const auto& row : a) {
        for (float elem : row) {
            cout << setw(10) << elem << "\t";
        }
        cout << endl;
    }
    cout << "\n";
}

// Функция для проверки, является ли столбец нулевым
bool checkNonZeroElements(const vector<float>& a) {
    for (float elem : a) {
        if (fabs(elem) < 0.0001) {
            return false;
        }
    }
    return true;
}

// Функция приведения матрицы к базисному виду
void getBasicView(vector<vector<float>>& a, int& m, int n) {
    for (int k = 0, jm = 0; k < m; k++) {
        if (fabs(a[k][jm]) > 0.0001) {
            for (int i = n; i >= k; i--) {
                a[k][i] /= a[k][jm];    // Получение ведущей строки
            }
            for (int i = 0; i < m; i++) {
                if (i != k) {
                    for (int j = n; j >= k; j--) {
                        // Преобразование остальных строк матрицы и
                        // получение единичного столбца
                        a[i][j] -= a[k][j] * (a[i][k] / a[k][jm]);
                    }
                }
            }
            jm++;
            cout << k + 1 << " шаг\n";
            outputMatrix(a);
        } else if (!checkNonZeroElements(a[k])) {
            a.erase(a.begin() + k);
            m--;
            k--;
        }
    }
}

// Функция для получения решения
vector<float> getSolution(const vector<vector<float>>& a, int n, const vector<int>& vec, int& kol) {
    vector<float> s(n);
    for (int k = 0, im = 0; k < n; k++) {
        if (vec[k]) {
            s[k] = a[im++][n];
        }
    }

    for (float val : s) {
        if (val < 0) {
            return {};
        }
    }

    kol++;
    return s;
}

// Функция для проверки столбцов
bool checkColumns(const vector<vector<float>>& a, int n, const vector<int>& vec) {
    for (int j = 0, im = 0; j < n; j++) {
        if (vec[j]) {
            if (fabs(a[im][j]) < 0.0001) {
                return false;
            }
            im++;
        }
    }
    return true;
}

// Функция для получения и вывода всех базисных решений
vector<vector<float>> outputAllBasicSolutions(vector<vector<float>>& a, int m, int n, int& kol) {
    vector<vector<float>> solutions;
    vector<int> vec(n);
    cout << "\n";
    for (int k = 0, l = 0; k < (1 << n); k++, l = 0) {
        // Перебор всех возможных комбинаций переменных
        for (int i = 0, temp = k; i < n; i++, l += temp % 2, temp /= 2) {
            vec[i] = temp % 2;
        }
        // Проверка, является ли базисный набор допустимым
        if (l == m && checkColumns(a, n, vec)) {
            cout << "Базисные переменные: ";
            for (int i = 0; i < n; i++) {
                if (vec[i]) {
                    cout << "x[" << i + 1 << "]\t";
                }
            }
            cout << "\n";
            // Получение нового базисного решения
            for (int z = 0, im = 0; z < n && im < m; z++) {
                if (vec[z]) {
                    // Получение ведущей строки
                    if (a[im][z] != 1) {
                        const float koef = a[im][z];
                        for (int j = 0; j <= n; j++) {
                            a[im][j] /= koef;
                        }
                    }
                    // Преобразование остальных строк матрицы и
                    // получение единичного столбца
                    for (int j = 0; j < m; j++) {
                        if (j != im) {
                            const float koef = a[j][z] / a[im][z];
                            for (int d = 0; d <= n; d++) {
                                a[j][d] -= a[im][d] * koef;
                            }
                        }
                    }
                    im++;
                }
            }
            outputMatrix(a);
            vector<float> solution = getSolution(a, n, vec, kol);
            if (!solution.empty()) {
                solutions.push_back(solution);
            }
        }
    }
    return solutions;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int m, n;
    cout << "Введите количество уравнений: ";
    cin >> m;
    cout << "Введите количество переменных: ";
    cin >> n;

    int k = 0;
    vector<vector<float>> a = inputMatrix(m, n);
    getBasicView(a, m, n);
    vector<vector<float>> c = outputAllBasicSolutions(a, m, n, k);

    // Вывод опорных планов и их сумм
    float maxSum = 0;
    int optimalPlanIndex = 0;
    for (int i = 0; i < k; i++) {
        float sum = 0;
        cout << "Опорный план " << i + 1 << ":\n";
        for (int j = 0; j < n; j++) {
            cout << "x[" << j + 1 << "]\t\t" << setw(10) << c[i][j] << "\n";
            sum += c[i][j];
        }

        cout << "Сумма: " << sum << "\n";
        if (sum > maxSum) {
            maxSum = sum;
            optimalPlanIndex = i;
        }
    }

    cout << "\nОптимальный план: ";
    for (int i = 0; i < n; i++) {
        cout << c[optimalPlanIndex][i] << ' ';
    }

    cout << "\nЗначение целевой функции для оптимального плана: " << maxSum;

    return 0;
}

