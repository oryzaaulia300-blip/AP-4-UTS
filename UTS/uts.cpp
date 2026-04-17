#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    system("cls");

    int jamMulai, menitMulai, jamSelesai, menitSelesai;
    int totalMulai, totalSelesai, totalMenit;
    int lamaJam, sisaMenit;
    int jumlahJam, tarifPerJam, denda, totalTagihan;
    int kategori;

    cout << "======================================" << endl;
    cout << "SELAMAT DATANG DI WARNET JANGEKNET" << endl;
    cout << "      BILLING SYSTEM UNI ACA      " << endl;
    cout << "======================================" << endl;

    cout << "Masukkan Jam Mulai (0-23)    : ";
    cin >> jamMulai;
    cout << "Masukkan Menit Mulai (0-59)  : ";
    cin >> menitMulai;
    cout << "Masukkan Jam Selesai (0-23)  : ";
    cin >> jamSelesai;
    cout << "Masukkan Menit Selesai (0-59): ";
    cin >> menitSelesai;

    // Validasi input APA
    if (jamMulai < 0 || jamMulai > 23 || menitMulai < 0 || menitMulai > 59 ||
        jamSelesai < 0 || jamSelesai > 23 || menitSelesai < 0 || menitSelesai > 59) {
        cout << "\nERROR: Format waktu tidak valid!" << endl;
        return 0;
    }

    totalMulai = jamMulai * 60 + menitMulai;
    totalSelesai = jamSelesai * 60 + menitSelesai;

    // Jika melewati tengah malam
    if (jamSelesai < jamMulai || (jamSelesai == jamMulai && menitSelesai < menitMulai)) {
        totalSelesai = totalSelesai + 1440;
    }

    totalMenit = totalSelesai - totalMulai;

    lamaJam = totalMenit / 60;
    sisaMenit = totalMenit % 60;

    denda = 0;
    totalTagihan = 0;
    jumlahJam = 0;
    tarifPerJam = 0;
    kategori = 0;

    if (totalMenit >= 0 && totalMenit <= 30) {
        kategori = 1;
        totalTagihan = 5000;
    }
    else if (totalMenit >= 31 && totalMenit <= 120) {
        kategori = 2;
        jumlahJam = totalMenit / 60;
        if (totalMenit % 60 != 0) {
            jumlahJam = jumlahJam + 1;
        }
        tarifPerJam = 7000;
        totalTagihan = jumlahJam * tarifPerJam;
    }
    else if (totalMenit >= 121 && totalMenit <= 300) {
        kategori = 3;
        jumlahJam = totalMenit / 60;
        if (totalMenit % 60 != 0) {
            jumlahJam = jumlahJam + 1;
        }
        tarifPerJam = 6000;
        totalTagihan = jumlahJam * tarifPerJam;
    }
    else if (totalMenit > 300) {
        kategori = 4;
        jumlahJam = totalMenit / 60;
        if (totalMenit % 60 != 0) {
            jumlahJam = jumlahJam + 1;
        }
        tarifPerJam = 5000;
        denda = 10000;
        totalTagihan = (jumlahJam * tarifPerJam) + denda;
    }

    cout << "\n--- STRUK TAGIHAN ---" << endl;

    cout << "Waktu Mulai   : ";
        if (jamMulai < 10) cout << "0";
    cout << jamMulai << ":";
        if (menitMulai < 10) cout << "0";
    cout << menitMulai << endl;

    cout << "Waktu Selesai : ";
        if (jamSelesai < 10) cout << "0";
    cout << jamSelesai << ":";
        if (menitSelesai < 10) cout << "0";
    cout << menitSelesai << endl;

    cout << "Durasi        : " << lamaJam << " Jam " << sisaMenit
         << " Menit (" << totalMenit << " Menit)" << endl;

    if (kategori == 1) {
        cout << "Kategori      : 0 - 30 Menit" << endl;
        cout << "\nPerhitungan   : Rp 5000 (Biaya flat)" << endl;
    }
    else if (kategori == 2) {
        cout << "Kategori      : 31 - 120 Menit (Rp 7.000/jam)" << endl;
        cout << "\nPerhitungan   : " << jumlahJam << " Jam x Rp " << tarifPerJam
             << " = Rp " << jumlahJam * tarifPerJam << endl;
    }
    else if (kategori == 3) {
        cout << "Kategori      : 121 - 300 Menit (Rp 6.000/jam)" << endl;
        cout << "\nPerhitungan   : " << jumlahJam << " Jam x Rp " << tarifPerJam
             << " = Rp " << jumlahJam * tarifPerJam << endl;
    }
    else if (kategori == 4) {
        cout << "Kategori      : > 300 Menit (Rp 5.000/jam)" << endl;
        cout << "\nPerhitungan   : " << jumlahJam << " Jam x Rp " << tarifPerJam
             << " = Rp " << jumlahJam * tarifPerJam << endl;
        cout << "DENDA         : Rp 10000" << endl;
        cout << "ANDA MELEBIHI BATAS WAKTU WAJAR! DENDA RP 10.000 DIKENAKAN." << endl;
    }

    cout << "--------------------------------------";
    cout << "\nTOTAL TAGIHAN : Rp " << totalTagihan << endl;
    cout << "======================================" << endl;

}