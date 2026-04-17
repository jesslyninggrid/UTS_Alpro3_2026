#include <iostream>
#include <string>
using namespace std;

int main() {
    string kartu;
    cout << "Masukkan nomor kartu digital: ";
    cin >> kartu;

    int panjang = kartu.length();
    string tipe = "";

    if (panjang == 14 && kartu.substr(0,2) == "65") {
        tipe = "NUSANTARA";
    } 
    else if (panjang == 16 && (kartu.substr(0,2) == "77" || kartu.substr(0,2) == "78")) {
        tipe = "GARUDA";
    } 
    else if (panjang == 15 && kartu.substr(0,2) == "91") {
        tipe = "MERDEKA";
    } 
    else {
        cout << "Nomor kartu tidak dikenali." << endl;
        return 0;
    }

    cout << "Tipe kartu: " << tipe << endl;

    int total = 0;

    for (int i = panjang - 1; i >= 0; i--) {
        int digit = kartu[i] - '0'; 

        int posisi = panjang - i; 

        if (posisi % 2 == 0) {
            digit *= 2;

            if (digit > 9) {
                digit = digit / 10 + digit % 10;
            }
        }

        total += digit; 
    }

    if (total % 10 == 0) {
        cout << "Nomor kartu VALID." << endl;
    } else {
        cout << "Nomor kartu TIDAK VALID." << endl;
    }

    return 0;
}

// Penjelasan:
// Program membaca nomor kartu.
// Menentukan tipe kartu berdasarkan dari panjang dan awalan digit yang di input.
// Lalu melakukan validasi kartu :
//    - Mulai membaca digit dari kanan ke kiri
//    - Setiap digit diubah dari karakter ke angka 
// yang dimana setiap digit ke-2 (ataupun genap) dikali dengan 2.
// Jika hasil perkalian tsb lebih dari 9, maka akan dijumlahkan digit pertama dan kedua.
// lalu total semua digit dijumlahkan dari awal.
// Jika total jumlah digit tsb habis dibagi 10, maka kartu valid.
// dan sebaliknya jika tidak maka kartu termasuk tidak valid.