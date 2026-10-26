
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& a) {
    int n = a.size();

    if (n <= 1)
        return;

    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; i++) {
        int index = static_cast<int>(n * a[i]);
        if (index >= n)
            index = n - 1;

        buckets[index].push_back(a[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (float value : buckets[i]) {
            a[k++] = value;
        }
    }
}

int main() {
    int n;

    cout << "Enter number of elements (0 to 1): ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid size";
        return 0;
    }

    vector<float> a(n);

    cout << "Enter elements in the range [0, 1]: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] < 0.0f || a[i] > 1.0f) {
            cout << "Invalid input";
            return 0;
        }
    }

    bucketSort(a);

    cout << "Sorted array: ";
    for (float x : a)
        cout << x << " ";

    cout << endl;
    return 0;
}
