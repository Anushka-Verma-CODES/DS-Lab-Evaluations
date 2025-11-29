// #include <iostream>
// using namespace std;

// int main() {
//     cout << "Hello World" << endl;
//     cout << "This is line 1\nThis is line 2" << endl;
//     cout << "Name\tAge\tCity" << endl;
//     cout << "John\t25\tDelhi" << endl;
//     cout << "Alert sound coming...\a" << endl; // \a → Alert sound (bell)
//     cout << "Hello World\rHikj" << endl;   //\r → Moves the cursor to the beginning of the current line, so text after it overwrites the start
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     float celsius, fahrenheit;
//     cout << "Enter temperature in Celsius: ";
//     cin >> celsius;
//     fahrenheit = (9 * celsius / 5) + 32;
//     cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     cout << "FOR LOOP Variantions " << endl;

//     cout << "1. Standard for loop:" << endl;
//     for (int i = 0; i < 5; i++)
//         cout << i << " ";
//     cout << endl;

//     cout << "2. Without initialization in for construct:" << endl;
//     int i = 0;
//     for (; i < 5; i++)
//         cout << i << " ";
//     cout << endl;

//     cout << "3. Without increment in for construct:" << endl;
    
//     for (int i = 0; i < 5;) {
//         cout << i << " ";
//         i++;
//     }
//     cout << endl;

//     cout << "4. Without initialization and increment in for construct:" << endl;
//     i = 0;
//     for (; i < 5;) {
//         cout << i << " ";
//         i++;
//     }
//     cout << endl;

//     cout << "\nWHILE LOOP -->" << endl;
//     i = 0;
//     while (i < 5) {
//         cout << i << " ";
//         i++;
//     }
//     cout << endl;

//     cout << "\nDO-WHILE LOOP --->" << endl;
//     i = 0;
//     do {
//         cout << i << " ";
//         i++;
//     } while (i < 5);
//     cout << endl;

//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// struct Student {
//     string name;
//     int rollNo;
//     string degree;
//     string hostel;
//     float currentCGPA;

//     void addDetails() {
//         cout << "Enter Name: ";
//         getline(cin, name);
//         cout << "Enter Roll No: ";
//         cin >> rollNo;
//         cin.ignore();
//         cout << "Enter Degree: ";
//         getline(cin, degree);
//         cout << "Enter Hostel: ";
//         getline(cin, hostel);
//         cout << "Enter Current CGPA: ";
//         cin >> currentCGPA;
//         cin.ignore();
//     }

//     void updateDetails() {
//         cout << "\n Update All Details -->\n";
//         addDetails();
//     }

//     void updateCGPA() {
//         cout << "Enter new CGPA: ";
//         cin >> currentCGPA;
//         cin.ignore();
//     }

//     void updateHostel() {
//         cout << "Enter new Hostel: ";
//         getline(cin, hostel);
//     }

//     void displayDetails() {
//         cout << "\nStudent Details -->\n";
//         cout << "Name: " << name << endl;
//         cout << "Roll No: " << rollNo << endl;
//         cout << "Degree: " << degree << endl;
//         cout << "Hostel: " << hostel << endl;
//         cout << "Current CGPA: " << currentCGPA << endl;
//     }
// };

// int main() {
//     Student s1;
//     int choice;

//     do {
//         cout << "\nMENU -->\n";
//         cout << "1. Add Details\n";
//         cout << "2. Update All Details\n";
//         cout << "3. Update CGPA\n";
//         cout << "4. Update Hostel\n";
//         cout << "5. Display Details\n";
//         cout << "6. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
//         cin.ignore();

//         switch (choice) {
//             case 1: s1.addDetails(); break;
//             case 2: s1.updateDetails(); break;
//             case 3: s1.updateCGPA(); break;
//             case 4: s1.updateHostel(); break;
//             case 5: s1.displayDetails(); break;
//             case 6: cout << "Exiting...\n"; break;
//             default: cout << "Invalid choice.\n";
//         }
//     } while (choice != 6);

//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// class Student {
// private:
//     string name;
//     int rollNo;
//     string degree;
//     string hostel;
//     float currentCGPA;

//     // Private helper to avoid repeating code
//     void getInput() {
//         cout << "Enter Name: ";
//         getline(cin, name);
//         cout << "Enter Roll No: ";
//         cin >> rollNo;
//         cin.ignore();
//         cout << "Enter Degree: ";
//         getline(cin, degree);
//         cout << "Enter Hostel: ";
//         getline(cin, hostel);
//         cout << "Enter Current CGPA: ";
//         cin >> currentCGPA;
//         cin.ignore();
//     }

// public:
//     void addDetails() {
//         getInput();
//     }

//     void updateDetails() {
//         cout << "\n--- Update All Details ---\n";
//         getInput();
//     }

//     void updateCGPA() {
//         cout << "Enter new CGPA: ";
//         cin >> currentCGPA;
//         cin.ignore();
//     }

//     void updateHostel() {
//         cout << "Enter new Hostel: ";
//         getline(cin, hostel);
//     }

//     void displayDetails() {
//         cout << "\n--- Student Details ---\n";
//         cout << "Name: " << name << endl;
//         cout << "Roll No: " << rollNo << endl;
//         cout << "Degree: " << degree << endl;
//         cout << "Hostel: " << hostel << endl;
//         cout << "Current CGPA: " << currentCGPA << endl;
//     }
// };

// int main() {
//     Student s1;
//     int choice;
   
//         cout << "\n--- MENU ---\n";
//         cout << "1. Add Details\n";
//         cout << "2. Update All Details\n";
//         cout << "3. Update CGPA\n";
//         cout << "4. Update Hostel\n";
//         cout << "5. Display Details\n";
//         cout << "6. Exit\n";
//         cout << "Enter your choice: ";
//         do {
//         cin >> choice;
//         cin.ignore();

//         switch (choice) {
//             case 1: s1.addDetails(); break;
//             case 2: s1.updateDetails(); break;
//             case 3: s1.updateCGPA(); break;
//             case 4: s1.updateHostel(); break;
//             case 5: s1.displayDetails(); break;
//             case 6: cout << "Exiting...\n"; break;
//             default: cout << "Invalid choice.\n";
//         }
//     } while (choice != 6);

//     return 0;
// }


// #include <iostream>
// using namespace std;

// class Demo {
// private:
//     void privateFunction() {
//         cout << "This is a PRIVATE function.\n";
//     }

// public:
//     void publicFunction() {
//         cout << "This is a PUBLIC function.\n";
//         cout << "Now calling the PRIVATE function from inside public function:\n";
//         privateFunction();
//     }
// };

// int main() {
//     Demo obj;
//     obj.publicFunction();
//     return 0;
// }
// // The private function cannot be called directly from main, it can only be accessed through a public function.


// #include <iostream>
// using namespace std;

// class Complex {
// private:
//     float real, imaginary;

// public:
//     void set(float r, float i) {
//         real = r;
//         imaginary = i;
//     }

//     void display() {
//         cout << real << " + " << imaginary << "i" << endl;
//     }

//     Complex sum(Complex c) {
//         Complex temp;
//         temp.real = real + c.real;
//         temp.imaginary = imaginary + c.imaginary;
//         return temp;
//     }
// };

// int main() {
//     Complex c1, c2, c3;
//     c1.set(3.5, 2.5);
//     c2.set(1.6, 4.2);
//     c3 = c1.sum(c2);
//     cout << "First complex number: ";
//     c1.display();
//     cout << "Second complex number: ";
//     c2.display();
//     cout << "Sum: ";
//     c3.display();
//     return 0;
// }



// #include <iostream>
// using namespace std;

// namespace first {
//     int num = 10;
//     void display() {
//         cout << "Namespace first: num = " << num << endl;
//     }
// }

// namespace second {
//     int num = 20;
//     void display() {
//         cout << "Namespace second: num = " << num << endl;
//     }
// }

// int main() {
//     first::display();
//     second::display();
//     cout << "Access first::num = " << first::num << endl;
//     cout << "Access second::num = " << second::num << endl;
//     return 0;
// }
