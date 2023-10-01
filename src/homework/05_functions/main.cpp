#include <iostream>
#include "func.h"

using std::cout;
using std::cin;

int main() {
    int choice;

    do {
        cout << "Menu:" << '\n';
        cout << "1- Get GC Content" << '\n';
        cout << "2- Get DNA Complement" << '\n';
        cout << "3- Exit" << '\n';
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string dna;
            cout << "Enter a DNA string: ";
            cin >> dna;

            double gc_content = get_gc_content(dna);
            cout << "GC Content: " << gc_content << '\n';
        } else if (choice == 2) {
            string dna;
            cout << "Enter a DNA string: ";
            cin >> dna;

            string complemented_dna = get_dna_complement(dna);
            cout << "Complement: " << complemented_dna << '\n';
        } else if (choice != 3) {
            cout << "Invalid choice. Please select a valid option." << '\n';
        }
    } while (choice != 3);

    return 0;
}





