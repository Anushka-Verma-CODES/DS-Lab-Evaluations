// //one
// #include <iostream>
// using namespace std;

// #define MAX 100

// int arr[MAX];
// int n = 0;

// void createArray() {
//     cout << "Enter number of elements: ";
//     cin >> n;
//     if (n > MAX) {
//         cout << "Enter number < " << MAX << endl;
//         n = 0;
//         return;
//     }
//     cout << "Enter the elements:\n";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
// }

// void displayArray() {
//     if (n == 0) {
//         cout << "Array is empty\n";
//         return;
//     }
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void insertElement() {
//     if (n == MAX) {
//         cout << "Array full\n";
//         return;
//     }
//     int pos, val;
//     cout << "Enter position: ";
//     cin >> pos;
//     cout << "Enter value: ";
//     cin >> val;
//     if (pos < 1 || pos > n + 1) {
//         cout << "Invalid position\n";
//         return;
//     }
//     for (int i = n; i >= pos; i--) {
//         arr[i] = arr[i - 1];
//     }
//     arr[pos - 1] = val;
//     n++;
// }

// void deleteElement() {
//     if (n == 0) {
//         cout << "Nothing to delete\n";
//         return;
//     }
//     int pos;
//     cout << "Enter position: ";
//     cin >> pos;
//     if (pos < 1 || pos > n) {
//         cout << "Invalid position\n";
//         return;
//     }
//     for (int i = pos - 1; i < n - 1; i++) {
//         arr[i] = arr[i + 1];
//     }
//     n--;
// }

// void linearSearch() {
//     if (n == 0) {
//         cout << "Array is empty\n";
//         return;
//     }
//     int key;
//     cout << "Enter value to search: ";
//     cin >> key;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == key) {
//             cout << "Found at position " << i + 1 << endl;
//             return;
//         }
//     }
//     cout << "Not found\n";
// }

// int main() {
//     int ch;
//     do {
//         cout << "\n1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
//         cout << "Enter choice: ";
//         cin >> ch;
//         switch (ch) {
//             case 1: createArray(); break;
//             case 2: displayArray(); break;
//             case 3: insertElement(); break;
//             case 4: deleteElement(); break;
//             case 5: linearSearch(); break;
//             case 6: cout << "Bye!\n"; break;
//             default: cout << "Wrong choice\n";
//         }
//     } while (ch != 6);
// }

// //two
// #include <iostream>
// using namespace std;

// int main() {
//     int arr[100], n;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] == arr[j]) {
//                 for (int k = j; k < n - 1; k++) {
//                     arr[k] = arr[k + 1];
//                 }
//                 n--;
//                 j--; 
//             }
//         }
//     }

//     cout << "Array after removing duplicates: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// //three
// #include <iostream>
// using namespace std;

// int main() 
// { 
// int i; 
// int arr[5] = {1}; 
// for (i = 0; i < 5; i++) 
// printf("%d \t",arr[i]); 
// return 0; 
// }
// // Output: 1 0 0 0 0


// //four
// // #include <iostream>
// // using namespace std;

// // int main() {
// //     int arr[100], n;
// //     cout << "Enter number of elements: ";
// //     cin >> n;

// //     cout << "Enter elements: ";
// //     for (int i = 0; i < n; i++) {
// //         cin >> arr[i];
// //     }

// //     for (int i = 0; i < n / 2; i++) {
// //         int temp = arr[i];
// //         arr[i] = arr[n - i - 1];
// //         arr[n - i - 1] = temp;
// //     }

// //     cout << "Reversed array: ";
// //     for (int i = 0; i < n; i++) {
// //         cout << arr[i] << " ";
// //     }
// //     cout << endl;
// // }


// #include <iostream>
// using namespace std;

// int main() {
//     int a[10][10], b[10][10], c[10][10];
//     int r1, c1, r2, c2;

//     cout << "Enter rows and columns of first matrix: ";
//     cin >> r1 >> c1;
//     cout << "Enter rows and columns of second matrix: ";
//     cin >> r2 >> c2;

//     if (c1 != r2) {
//         cout << "Matrix multiplication not possible.\n";
//         return 0;
//     }

//     cout << "Enter elements of first matrix:\n";
//     for (int i = 0; i < r1; i++)
//         for (int j = 0; j < c1; j++)
//             cin >> a[i][j];

//     cout << "Enter elements of second matrix:\n";
//     for (int i = 0; i < r2; i++)
//         for (int j = 0; j < c2; j++)
//             cin >> b[i][j];

//     for (int i = 0; i < r1; i++) {
//         for (int j = 0; j < c2; j++) {
//             c[i][j] = 0;
//             for (int k = 0; k < c1; k++) {
//                 c[i][j] += a[i][k] * b[k][j];
//             }
//         }
//     }

//     cout << "Resultant matrix:\n";
//     for (int i = 0; i < r1; i++) {
//         for (int j = 0; j < c2; j++) {
//             cout << c[i][j] << " ";
//         }
//         cout << endl;
//     }
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int a[10][10], trans[10][10];
//     int r, c;

//     cout << "Enter rows and columns: ";
//     cin >> r >> c;

//     cout << "Enter matrix elements:\n";
//     for (int i = 0; i < r; i++)
//         for (int j = 0; j < c; j++)
//             cin >> a[i][j];

//     for (int i = 0; i < r; i++)
//         for (int j = 0; j < c; j++)
//             trans[j][i] = a[i][j];

//     cout << "Transpose of matrix:\n";
//     for (int i = 0; i < c; i++) {
//         for (int j = 0; j < r; j++) {
//             cout << trans[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// //five
#include <iostream>
using namespace std;

int main() {
    int a[10][10], r, c;

    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nSum of each row:\n";
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) {
            sum += a[i][j];
        }
        cout << "Row " << i + 1 << ": " << sum << endl;
    }

    cout << "\nSum of each column:\n";
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) {
            sum += a[i][j];
        }
        cout << "Column " << j + 1 << ": " << sum << endl;
    }

    return 0;
}
