#include <iostream>
using namespace std;

int main() {
    int N;
    string S;

    cout << "Masukkan total babak dalam 1 pertandingan:  ";
    cin >> N;

    cout <<  "Masukkan urutan pemenang setiap babak (ditulis dengan nama pemain): ";
    cin >> S;

    int poinA = 0, poinB = 0;
    int streakA = 0, streakB = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            poinA += 3;
            streakA++;
            streakB = 0;
        } 
        else if (S[i] == 'B') {
            poinB += 3;
            streakB++;
            streakA = 0;
        } 
        else { // Seri
            poinA += 1;
            poinB += 1;
            streakA = 0;
            streakB = 0;
        }

        // Bonus jika menang 3 kali berturut
        if (streakA == 3) {
            poinA += 2;
            streakA = 0;
        }
        if (streakB == 3) {
            poinB += 2;
            streakB = 0;
        }
    }

    cout << "Poin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;

    if (poinA > poinB)
        cout << "Pemenangnya adalah pemain A" << endl;
    else if (poinB > poinA)
        cout << "Pemenangnya adalah pemain B" << endl;
    else
        cout << "Hasil pertandingan Seri!" << endl;

    return 0;
}


// logika program:
// Program membaca jumlah pertandingan dan hasil setiap pertandingan dalam bentuk string.
// Setiap karakter pada string menunjukkan hasil:
// dimana 'A' berarti pemain A menang, 'B' berarti pemain B menang, dan selain itu dianggap seri.
// Program menggunakan perulangan untuk membaca setiap hasil pertandingan satu per satu.
// Jika pemain A menang, maka poin A bertambah 3 dan streak A bertambah 1, sementara streak B direset.
// Jika pemain B menang, maka poin B bertambah 3 dan streak B bertambah 1, sementara streak A direset.
// Jika hasil seri, maka kedua pemain mendapat 1 poin dan kedua streak direset.
// Program juga mengecek apakah ada pemain yang menang 3 kali berturut-turut.
// Jika pemain A mencapai 3 kemenangan berturut, maka mendapat bonus 2 poin dan streak direset. begitu juga sebaliknya berlaku untuk pemain B.
// Setelah semua pertandingan selesai, program menampilkan total poin masing-masing pemain.
// Terakhir, program membandingkan poin dan menentukan siapa pemenangnya atau apakah hasilnya seri.
