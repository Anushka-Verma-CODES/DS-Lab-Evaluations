#include <iostream>
using namespace std;

/* 
   1) SELECTION SORT

#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[minIdx])
                minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    selectionSort(a, n);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

*/

/* 
   2) INSERTION SORT

#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    insertionSort(a, n);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

*/

/* 
   3) BUBBLE SORT

#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    bubbleSort(a, n);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

*/

/* 
   4) MERGE SORT

#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l+i];
    for (int i = 0; i < n2; i++) R[i] = a[m+1+i];

    int i=0, j=0, k=l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    mergeSort(a, 0, n-1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

*/

/* 
   5) QUICK SORT

#include <iostream>
using namespace std;

int partitionFunc(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int pi = partitionFunc(a, l, r);
        quickSort(a, l, pi-1);
        quickSort(a, pi+1, r);
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    quickSort(a, 0, n-1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

*/

/* 
   6) IMPROVED SELECTION SORT 
      (find BOTH min and max each pass)

#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n-1;

    while (left < right) {
        int minIdx = left;
        int maxIdx = left;

        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIdx]) minIdx = i;
            if (a[i] > a[maxIdx]) maxIdx = i;
        }

        swap(a[left], a[minIdx]);

        if (maxIdx == left) maxIdx = minIdx;

        swap(a[right], a[maxIdx]);

        left++;
        right--;
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    improvedSelectionSort(a, n);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

*/

int main() { return 0; }
