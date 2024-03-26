#include <iostream>
using namespace std;
// Main program
int main()
{
    char op;
    float num1, num2;

    //Meminta pengguna untuk memasukkan operator: +, -, *, /
    cout << "Masukkan operator (+, -, *, /): ";
    // It allows user to enter operator i.e. +, -, *, /
    cin >> op;

    //Meminta pengguna untuk memasukkan operand
    cout << "Masukkan 2 angka: ";
    // It allow user to enter the operands
    cin >> num1 >> num2;

    // Switch statement begins
    switch (op)
    {
    // If user enter +
    case '+':
        cout << "Hasil penjumlahan: " << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << "Hasil pengurangan: " << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << "Hasil perkalian: " << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << "Hasil pembagian: " << num1 / num2;
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}

