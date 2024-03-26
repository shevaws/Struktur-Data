// C++ program to implement map container
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	map<int, string> absen;

	absen[1] = "Raka";
	absen[2] = "Andriy";
	absen[3] = "Shevchenko";

    map<int, string>::iterator itr;

	for (itr = absen.begin(); itr != absen.end(); ++itr) {
        cout << "No: " << itr->first << "\tNama: " << itr->second
             << '\n';
    }

	return 0;
}