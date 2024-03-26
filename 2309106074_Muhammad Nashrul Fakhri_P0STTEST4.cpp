#include <iostream>
#include <string>
#include <limits> // eror handling penginputan selain angka 

using namespace std;

const int MAX_MASKAPAI = 100;

struct Maskapai { //prinsip struct pada Maskapai
    int nomor; 
    string nama;

    struct Penerbangan { //penggunaan nested struct pada penerbangan, menampilkan struck lebih dari satu
        string kepergian;
        string kedatangan;
        int jam_berangkat;
    };

    Penerbangan Penerbangan[MAX_MASKAPAI];
    int jumlahpenerbangan;
};

void tambahData(Maskapai maskapaiList[], int& jumlahMaskapai) { 
    if (jumlahMaskapai < MAX_MASKAPAI) {
        Maskapai maskapai;
        maskapai.nomor = jumlahMaskapai + 1; 
        cout << "Masukkan Nama Maskapai: "; 
        getline(cin >> ws, maskapai.nama);

        maskapaiList[jumlahMaskapai++] = maskapai;

        cout << "Data maskapai berhasil ditambahkan." << endl; 
    } else {
    }
}

void tampilkanData(const Maskapai maskapaiList[], int jumlahMaskapai) {
    cout << "Daftar Maskapai Penerbangan:" << endl;
    for (int i = 0; i < jumlahMaskapai; ++i) {
        cout << " " << maskapaiList[i].nomor << "." << maskapaiList[i].nama << endl;
    }
}

void updateData(Maskapai maskapaiList[], int jumlahMaskapai) {
    int nomorToUpdate;
    cout << "Masukkan Nomor Maskapai yang ingin diupdate: "; 
    cin >> nomorToUpdate;

    int i;
    for (i = 0; i < jumlahMaskapai; ++i) {
        if (maskapaiList[i].nomor == nomorToUpdate) {
            break;
        }
    }

    if (i == jumlahMaskapai) {
        cout << "Nomor maskapai tidak ditemukan." << endl;//eror handling nomor maskapai salah input
        return;
    }

    cout << "Masukkan Nama Maskapai yang baru: ";
    getline(cin >> ws, maskapaiList[i].nama);
    cout << "Data maskapai berhasil diupdate." << endl;
}

void hapusData(Maskapai maskapaiList[], int& jumlahMaskapai) {
    int nomorToDelete;
    cout << "Masukkan Nomor Maskapai yang ingin dihapus: ";
    cin >> nomorToDelete;

    int i;
    for (i = 0; i < jumlahMaskapai; ++i) {
        if (maskapaiList[i].nomor == nomorToDelete) {
            for (int j = i; j < jumlahMaskapai - 1; ++j) {
                maskapaiList[j] = maskapaiList[j + 1];
            }
            jumlahMaskapai--;
            cout << "Data maskapai berhasil dihapus." << endl;
            return;
        }
    }

    cout << "Nomor maskapai tidak ditemukan." << endl;//eror handling nomor maskapai salah input
}

int main() {
    Maskapai maskapaiList[MAX_MASKAPAI] = {////array of struct pada maskapai list menampilkan nomor dan nama maskapai
        {1, "Citilink"},
        {2, "Lion Air"},
        {3, "Batik Air"},
        {4, "Garuda Indonesia"}
    };

    int jumlahMaskapai = 4;
    const int MAX_LOGIN_ATTEMPTS = 3;
    int loginAttempts = 0;
    string nama, nim;

    while (loginAttempts < MAX_LOGIN_ATTEMPTS) {
        cout << "=== Login ===" << endl;
        cout << "Nama: ";
        getline(cin >> ws, nama);
        cout << "NIM: ";
        cin >> nim;

        if (nama == "Arul" && nim == "74") {
            cout << "Login berhasil!" << endl;
            break;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;//eror handling salah input username dan password
            loginAttempts++;
        }
    }

    if (loginAttempts == MAX_LOGIN_ATTEMPTS) {
        cout << "Anda telah mencapai batas maksimum percobaan login. Program berhenti." << endl;//eror handling program berhenti
        return 0;
    }

    int pilihan;
    do {
        cout << "\n=== Menu Pendataan Maskapai ===" << endl;
        cout << "1. Tambah Data Maskapai" << endl;
        cout << "2. Tampilkan Data Maskapai" << endl;
        cout << "3. Update Data Maskapai" << endl;
        cout << "4. Hapus Data Maskapai" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        if (!(cin >> pilihan)) {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;//eror handling salah input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            switch (pilihan) {
                case 1:
                    tambahData(maskapaiList, jumlahMaskapai);
                    break;
                case 2:
                    tampilkanData(maskapaiList, jumlahMaskapai);
                    break;
                case 3:
                    updateData(maskapaiList, jumlahMaskapai);
                    break;
                case 4:
                    hapusData(maskapaiList, jumlahMaskapai);
                    break;
                case 5:
                    cout << "Terima kasih. Program berhenti." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl; // eror handling penginputan selain angka 
            }
        }
    } while (pilihan != 5);

    return 0;
}

