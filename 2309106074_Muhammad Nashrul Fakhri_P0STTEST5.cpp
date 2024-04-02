#include <iostream>
#include <string>
#include <limits> 

using namespace std;

const int MAX_MASKAPAI = 100;

struct Maskapai { 
    int nomor; 
    string nama;

    struct Penerbangan { 
        string kepergian;
        string kedatangan;
        int jam_berangkat;
    };

    Penerbangan Penerbangan[MAX_MASKAPAI];
    int jumlahpenerbangan;
};

void tambahData(Maskapai* maskapaiList, int* jumlahMaskapai) { //fungsi pointer parameter address off pada tambahdata
    if (*jumlahMaskapai < MAX_MASKAPAI) {
        Maskapai maskapai;
        maskapai.nomor = (*jumlahMaskapai) + 1; 
        cout << "Masukkan Nama Maskapai: "; 
        getline(cin >> ws, maskapai.nama); //fungsi pointer parameter address off pada tambahdata

        maskapaiList[(*jumlahMaskapai)++] = maskapai;

        cout << "Data maskapai berhasil ditambahkan." << endl; 
    } else {
        cout << "Tidak dapat menambahkan data. Batas maksimum telah tercapai." << endl;
    }
}

void tampilkanData(const Maskapai* maskapaiList, const int* jumlahMaskapai) { //fungsi pointer parameter address off pada tampilan data
    cout << "Daftar Maskapai Penerbangan:" << endl;
    for (int i = 0; i < *jumlahMaskapai; ++i) {
        cout << " " << maskapaiList[i].nomor << "." << maskapaiList[i].nama << endl; //fungsi pointer parameter address off pada tampilan data
    }
}

void updateData(Maskapai* maskapaiList, const int* jumlahMaskapai) { //fungsi pointer parameter address off pada update data
    int nomorToUpdate;
    cout << "Masukkan Nomor Maskapai yang ingin diupdate: "; 
    cin >> nomorToUpdate;

    int i;
    for (i = 0; i < *jumlahMaskapai; ++i) {
        if (maskapaiList[i].nomor == nomorToUpdate) {
            break;
        }
    }

    if (i == *jumlahMaskapai) {
        cout << "Nomor maskapai tidak ditemukan." << endl;
        return;
    }

    cout << "Masukkan Nama Maskapai yang baru: ";
    getline(cin >> ws, maskapaiList[i].nama);//fungsi pointer parameter address off pada update data
    cout << "Data maskapai berhasil diupdate." << endl;
}

void hapusData(Maskapai* maskapaiList, int* jumlahMaskapai) {//fungsi pointer parameter address off pada hapus data
    int nomorToDelete;
    cout << "Masukkan Nomor Maskapai yang ingin dihapus: ";
    cin >> nomorToDelete;

    int i;
    for (i = 0; i < *jumlahMaskapai; ++i) {
        if (maskapaiList[i].nomor == nomorToDelete) {
            for (int j = i; j < *jumlahMaskapai - 1; ++j) {
                maskapaiList[j] = maskapaiList[j + 1];
            }
            (*jumlahMaskapai)--;
            cout << "Data maskapai berhasil dihapus." << endl;
            return;
        }
    }

    cout << "Nomor maskapai tidak ditemukan." << endl;
}

int main() {
    Maskapai maskapaiList[MAX_MASKAPAI] = {
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
            cout << "Login gagal. Silakan coba lagi." << endl;
            loginAttempts++;
        }
    }

    if (loginAttempts == MAX_LOGIN_ATTEMPTS) {
        cout << "Anda telah mencapai batas maksimum percobaan login. Program berhenti." << endl;
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
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            switch (pilihan) {
                case 1:
                    tambahData(maskapaiList, &jumlahMaskapai);
                    break;
                case 2:
                    tampilkanData(maskapaiList, &jumlahMaskapai);
                    break;
                case 3:
                    updateData(maskapaiList, &jumlahMaskapai);
                    break;
                case 4:
                    hapusData(maskapaiList, &jumlahMaskapai);
                    break;
                case 5:
                    cout << "Terima kasih. Program berhenti." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    } while (pilihan != 5);

    return 0;
}
