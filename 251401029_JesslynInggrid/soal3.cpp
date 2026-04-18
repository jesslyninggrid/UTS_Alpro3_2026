#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;

    // Ambil bagian kode
    string kode_hari = kode.substr(0,2);
    string kode_pelanggan = kode.substr(2,2);
    int jumlah = stoi(kode.substr(4,4)) * 100000;

    string hari, pelanggan;
    int poin_per100 = 0;

    if (kode_hari == "01") {
        hari = "Hari Kerja";
    } 
    else if (kode_hari == "02") {
        hari = "Akhir Pekan";
    } 
    else if (kode_hari == "03") {
        hari = "Hari Libur Nasional";
    } 
    else {
        cout << "Kode hari tidak valid." << endl;
        return 0;
    }

    // Tentukan jenis pelanggan
    if (kode_pelanggan == "01") {
        pelanggan = "Biasa";
    } 
    else if (kode_pelanggan == "02") {
        pelanggan = "Silver";
    } 
    else if (kode_pelanggan == "03") {
        pelanggan = "Gold";
    } 
    else {
        cout << "Kode pelanggan tidak valid." << endl;
        return 0;
    }

    // Tentukan poin per 100 ribu berdasarkan klasifikasi
    if (hari == "Hari Kerja") {
        if (pelanggan == "Biasa") poin_per100 = 1;
        else if (pelanggan == "Silver") poin_per100 = 2;
        else if (pelanggan == "Gold") poin_per100 = 3;
    } 
    else if (hari == "Akhir Pekan") {
        if (pelanggan == "Biasa") poin_per100 = 2;
        else if (pelanggan == "Silver") poin_per100 = 3;
        else if (pelanggan == "Gold") poin_per100 = 5;
    } 
    else if (hari == "Hari Libur Nasional") {
        if (pelanggan == "Biasa") poin_per100 = 3;
        else if (pelanggan == "Silver") poin_per100 = 5;
        else if (pelanggan == "Gold") poin_per100 = 7;
    }

    int jumlah_unit = jumlah / 100000; // balikkan total belanjaan ke dalam digit 
    int total_poin = jumlah_unit * poin_per100; // Hitung total poin

    cout << "Jenis Hari: " << hari << endl;
    cout << "Jenis Pelanggan: " << pelanggan << endl;
    cout << "Jumlah Belanja: Rp " << jumlah << endl;
    cout << "Total Poin: " << total_poin << endl;

    return 0;
}


// logika program:
// Program meminta pengguna memasukkan kode transaksi 8 digit.
// lalu program mengambil 2 digit pertama (dengan formula substr) untuk menentukan jenis hari.
// selanjutnya program mengambil 2 digit berikutnya untuk menentukan jenis planggan.
// Program mengambil 4 digit terakhir untuk menentukan jumlah blanja yg jumlah belanjaan nya sudah dibagi dengan satuan seratus ribu,
// lalu dikalikan 100000 agar ditampilkan di output dalam  bentuk rupiah.
// Program menentukan poin berdasarkan kombinasi hari dan jenis pelanggan.
// Jumlah belanja dibagi 100000 lagi untuk mengetahui berapa unit perhitungan poin.
// Total akhir poin dihitung dengan mengalikan jumlah unit dengan poin per 100ribu yang sudah dihitung berdasarkan jenis pelanggan dan hari dia belanja.
// Program menampilkan jenis hari, jenis pelanggan, jumlah belanja, dan total poin.