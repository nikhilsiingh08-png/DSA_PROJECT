
#include <iostream>
#include <vector>
using namespace std;

int getMax(const vector<int>& a) {
    int mx = a[0];

    for (int x : a) {
        if (x > mx)
            mx = x;
    }

    return mx;
}

void countingSort(vector<int>& a, int exp) {
    int n = a.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(vector<int>& a) {
    if (a.empty())
        return;

    int mx = getMax(a);

    for (int exp = 1; mx / exp > 0; exp *= 10) {
        countingSort(a, exp);
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

    cout << "Enter non-negative elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] < 0) {
            cout << "Negative numbers are not supported";
            return 0;
        }
    }

    radixSort(a);

    cout << "Sorted array: ";
    for (int x : a)
        cout << x << " ";

    cout << endl;
    return 0;
}
