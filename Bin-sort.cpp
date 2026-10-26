
#include <iostream>
#include <vector>
using namespace std;

void binSort(vector<int>& a) {
    if (a.empty())
        return;

    int maxValue = a[0];

    for (int x : a) {
        if (x < 0) {
            cout << "Negative numbers are not supported";
            return;
        }

        if (x > maxValue)
            maxValue = x;
    }

    vector<int> bins(maxValue + 1, 0);

    for (int x : a)
        bins[x]++;

    int index = 0;

    for (int i = 0; i <= maxValue; i++) {
        while (bins[i] > 0) {
            a[index++] = i;
            bins[i]--;
        }
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid size";
        return 0;
    }

    vector<int> a(n);

    cout << "Enter non-negative integers: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] < 0) {
            cout << "Negative numbers are not supported";
            return 0;
        }
    }

    binSort(a);

    cout << "Sorted array: ";
    for (int x : a)
        cout << x << " ";

    cout << endl;
    return 0;
}
