#include <iostream>
using namespace std;
#include <cmath>
#include <time.h>

int size_x = 5;
int size_y = 6;
int random_int(int a, int b) {
    return rand() % b + a;
}
void draw_float_double_array(double** arr, int size_x, int size_y) {
    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            cout << arr[y][x] << "\t";
        }
        cout << endl;
    }
}

double** read_double_arr(double** arr, int size_x, int size_y, const char* promt = "") {
    int x, y;

    for (y = 0; y < size_y; y++)
        for (x = 0; x < size_x; x++) {
                arr[y][x] = random_int(-20, 50);
        }

    return arr;
}

double** create_arr(int size_x, int size_y) {
    double** arr = (double**)malloc(size_y * sizeof(double*));
    for (int i = 0; i < size_y; i++) {
        arr[i] = (double*)malloc(size_x * sizeof(double));
    }

    return arr;
}
void get_pos_avg_arr(double** arr, int s_x, int s_y, int* r_x, int* r_y,int* count = 0, int* max = 0,double* avg = 0) {

    double sum = 0;
    double average = 0;
    int cnt = 0;
    int max_neg = 0;
    for (int y = 0; y < s_y; y++) {
        for (int x = 0; x < s_x; x++) {
            if (arr[y][x] < 0) {
                cnt++;
            }
        }
    }
    for (int y = 0; y < s_y; y++) {
        for (int x = 0; x < s_x; x++) {
            if (arr[y][x] < 0 && arr[y][x] < max_neg) {
                max_neg = arr[y][x];
            }
        }
    }
    for (int y = 0; y < s_y; y++) {
        for (int x = 0; x < s_x; x++) 
        {
            sum += arr[y][x];
        }
    }
    average = sum / 30;

    *count = cnt;
    *max = max_neg;
    *avg = average;
    

}


int main() {
    setlocale(LC_ALL, "ru");
    double** A = read_double_arr(create_arr(size_x, size_y), size_x, size_y, "A");
    double** B = read_double_arr(create_arr(size_x, size_y), size_x, size_y, "B");

    int x, y, count = 0, max = 0;
    double avg = 0;

    // выводим массив
    cout << "A" << endl;
    draw_float_double_array(A, size_x, size_y);

    get_pos_avg_arr(A, size_x, size_y, &x, &y,&count,&max,&avg);
    cout << "Кол-во отрицательных = " << count << endl;
    cout << "Максимальное отрицательное = " << max << endl;
    cout << "Среднее арифметическое число = " << avg;
    cout << "B" << endl;
    draw_float_double_array(B, size_x, size_y);
    get_pos_avg_arr(B, size_x, size_y, &x, &y, &count, &max, &avg);
    cout << "Кол-во отрицательных = " << count << endl;
    cout << "Максимальное отрицательное = " << max << endl;
    cout << "Среднее арифметическое число = " << avg;


    return 0;
}