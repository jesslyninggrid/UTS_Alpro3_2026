#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    int keluar;

    cout << "Masukkan kode parkir digital (10 digit): ";
    cin >> kode;

    cout << "Masukkan jam keluar (format HHMM): ";
    cin >> keluar;

    string jenis;
    int tarif_awal = 0, tarif_lanjut = 0;

    if (kode.substr(0,2) == "10") {
        jenis = "Mobil";
        tarif_awal = 5000;
        tarif_lanjut = 3000;
    } 
    else if (kode.substr(0,2) == "20") {
        jenis = "Motor";
        tarif_awal = 3000;
        tarif_lanjut = 2000;
    } 
    else if (kode.substr(0,2) == "30") {
        jenis = "Bus";
        tarif_awal = 10000;
        tarif_lanjut = 7000;
    } 
    else {
        cout << "Kode kendaraan tidak valid." << endl;
        return 0;
    }

    // Ambil waktu masuk dari kode (digit ke 3 sampai 6)
    int masuk = stoi(kode.substr(2,4));

    int jam_masuk = masuk / 100;
    int menit_masuk = masuk % 100;

    int jam_keluar = keluar / 100;
    int menit_keluar = keluar % 100;

    // Ubah ke menit agar mudah dihitung
    int total_masuk = jam_masuk * 60 + menit_masuk;
    int total_keluar = jam_keluar * 60 + menit_keluar;
    
    // Hitung selisih waktu
    int selisih = total_keluar - total_masuk;

    // Hitung durasi (dibulatkan ke atas)
    int durasi = selisih / 60;

    if (selisih % 60 != 0) {
        durasi++;
    }

    // Hitung biaya
    int biaya = tarif_awal;

    if (durasi > 1) {
        biaya += (durasi - 1) * tarif_lanjut;
    }

    cout << "\n--- Ringkasan Parkir ---" << endl;
    cout << "Jenis kendaraan: " << jenis << endl;
    cout << "Waktu masuk: " << jam_masuk << ":" << menit_masuk << endl;
    cout << "Waktu keluar: " << jam_keluar << ":" << menit_keluar << endl;
    cout << "Durasi parkir: " << durasi << " jam" << endl;
    cout << "Lokasi parkir: " << kode.substr(6,4) << endl;
    cout << "Total biaya: Rp " << biaya << endl;

    return 0;
}


// Algoritma program: 
// Program ini meminta pengguna memasukkan kode parkir digital yang terdiri dari 10 digit serta waktu keluar dalam format HHMM.
// Program kemudian membaca 2 digit pertama dari kode untuk menentukan jenis kendaraan, yaitu 10 untuk mobil, 20 untuk motor, dan 30 untuk bus.
// Setelah jenis kendaraan diketahui, program menentukan tarif parkir, yaitu tarif awal untuk jam pertama dan tarif tambahan untuk setiap jam berikutnya.
// Selanjutnya program mengambil waktu masuk dari kode parkir, yaitu dari digit ke-3 sampai ke-6, lalu memisahkannya menjadi jam dan menit.
// Waktu keluar yang dimasukkan pengguna juga dipisahkan menjadi jam dan menit.
// Agar perhitungan lebih mudah, waktu masuk dan waktu keluar diubah ke dalam satuan menit.
// Program kemudian menghitung selisih waktu antara keluar dan masuk untuk mendapatkan durasi parkir.
// Durasi tersebut dibagi 60 untuk mengubahnya menjadi jam.
// Jika hasil durasi kurang dari atau sama dengan nol, maka dianggap minimal 1 jam.
// Biaya parkir dihitung dengan menggunakan tarif awal untuk jam pertama.
// Jika durasi lebih dari 1 jam, maka jam berikutnya akan dikenakan tarif tambahan sesuai jenis kendaraan.
// Terakhir, program menampilkan jenis kendaraan, waktu masuk, waktu keluar, durasi parkir, lokasi parkir dari kode, dan total biaya yang harus dibayar.
// Kesimpulannya, program ini membaca kode parkir, menentukan jenis kendaraan, menghitung lama parkir, dan menentukan biaya berdasarkan durasi tersebut.
