#include <iostream>
using namespace std;

int main() {
    int n, x;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the highest degree: ";
    cin >> n;
    int a[n + 1];
    cout << "Enter coefficients of the polynomial:" << endl;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    int p = a[n], i = n;
    while (i >= 1) {
        p = p * x + a[i - 1];
        i--;
    }
    cout << "Result: " << p << endl;
    return 0;
}
