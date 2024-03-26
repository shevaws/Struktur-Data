#include <iostream>
#include <string>

using namespace std;

class Class {
public:             
    int absen;
    string nama;
    string kelas;
};

struct
{
    string tipe;
}Tp;


int main(int argc, char const *argv[])
{
    Class Obj;

    Obj.absen = 12;
    Obj.nama = "Raka Andriy Shevchenko";
    Obj.kelas = "IF - 11 - B";
    Tp.tipe = "motor";

    cout << "Mahasiswa " << Obj.nama << " dengan absen " << Obj.absen << " kelas " << Obj.kelas << " berangkat ke kampus menggunakan " << Tp.tipe << endl;

    return 0;
}