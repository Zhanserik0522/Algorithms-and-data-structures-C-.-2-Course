#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class fib {
public:
    long long fib1, fib2;
};

class A {
public:
    long long a1, a2, a3, a4;
};


fib Fib; 
A matrix;

const long long md = (1e9 + 7);
long long mod(long long a) {
    return a % md;
}

A exp_2_on_2(A a, A b) {
    long long b1 = mod(a.a1 * b.a1 + a.a2 * b.a3);
    long long b2 = mod(a.a1 * b.a2 + a.a2 * b.a4);
    long long b3 = mod(a.a3 * b.a1 + a.a4 * b.a3);
    long long b4 = mod(a.a3 * b.a2 + a.a4 * b.a4);

    return { b1, b2, b3, b4 };
}

fib exp_1_on_2(A a, fib b) {
    long long b1 = mod(b.fib1 * a.a1 + b.fib2 * a.a3);
    long long b2 = mod(b.fib1 * a.a2 + b.fib2 * a.a4);

    return { b1 ,b2 };
}


A exponentiation_of_matrix(A a, long long n){
    if (n == 0) return { 1, 0, 0, 1 };
    if (n == 1) return { 0, 1, 1, 1 };

    A f = exponentiation_of_matrix(a, n / 2);


    return exp_2_on_2(f, exp_2_on_2(f, exponentiation_of_matrix(a, n % 2)));


}


bool compareItems(const vector<int>& a, const vector<int>& b) {
    return (double)a[1] / a[0] > (double)b[1] / b[0];
}
vector<vector<int>> fill_box(vector<vector<int>>& items, int weight) {
    sort(items.begin(), items.end(), compareItems);
    vector<vector<int>> ans_box;

    for (const vector<int>& item : items) {
        if (item[0] <= weight) {
            ans_box.push_back(item);
            weight -= item[0];
        }
    }

    return ans_box;
}

int main() {
    vector<vector<int>> items = { {5, 10}, {3, 8}, {4, 7}, {2, 5} }; // пара -  вес, стоимость
    int weight = 9;
    vector<vector<int>> result = fill_box(items, weight);

    for (const vector<int>& item : result) {
        cout << "Вес: " << item[0] << ", Стоимость: " << item[1] << endl;
    }

    long long n;
    cin >> n;

    Fib.fib1 = 0; Fib.fib2 = 1;
    matrix.a1 = 1, matrix.a2 = 1, matrix.a3 = 1, matrix.a4 = 0;

    matrix = exponentiation_of_matrix(matrix, n);

    Fib = exp_1_on_2(matrix, Fib);

    cout << Fib.fib1;
    return 0;
}
