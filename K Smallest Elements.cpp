
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSelect(vector<int>& a, int low, int high, int k) {
    if (low >= high)
        return;

    int p = partition(a, low, high);

    if (p == k - 1)
        return;
    else if (p > k - 1)
        quickSelect(a, low, p - 1, k);
    else
        quickSelect(a, p + 1, high, k);
}

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size";
        return 0;
    }

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter k: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid k";
        return 0;
    }

    quickSelect(a, 0, n - 1, k);
    sort(a.begin(), a.begin() + k);

    cout << "K smallest elements: ";
    for (int i = 0; i < k; i++)
        cout << a[i] << " ";

    cout << endl;
    return 0;
}
