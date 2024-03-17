#include <iostream>
#include <string>

using namespace std;

const int MAX_MASKAPAI = 100;

struct Maskapai {
    int nomor; 
    string nama;
};
  
void tambahData //fungsi overloading penambahan Data Maskapai
(Maskapai maskapaiList[], int& jumlahMaskapai) { //prosedur kompleks maskapailist dan jumlah maskapai
    if (jumlahMaskapai < MAX_MASKAPAI) {
        Maskapai maskapai;//prosedur sederhana maskapai
        maskapai.nomor = jumlahMaskapai + 1; 
        cout << "Masukkan Nama Maskapai: "; //fungsi iostream menginput Nama Maskapai
        getline(cin >> ws, maskapai.nama);

        maskapaiList[jumlahMaskapai++] = maskapai;//rekursif jumlah maskapai

        cout << "Data maskapai berhasil ditambahkan." << endl; //fungsi iostream berhasil menambahkan maskapai
    } else {
        cout << "Data maskapai sudah mencapai batas maksimum." << endl;//fungsi iostream input maskapai mencapai batas
    }
}

void tampilkanData//fungsi overloading menampilkan data 
(const Maskapai maskapaiList[], int jumlahMaskapai) {//prosedur kompleks maskapailist dan jumlah maskapai
    cout << "Daftar Maskapai Penerbangan:" << endl;//fungsi iostream output daftar maskapai
    for (int i = 0; i < jumlahMaskapai; ++i) {//rekursif jumlah maskapai
        cout << " " << maskapaiList[i].nomor << "." << maskapaiList[i].nama << endl;//fungsi iostream daftar maskapai
    }
}

void updateData//fungsi overloading update maskapai
(Maskapai maskapaiList[], int jumlahMaskapai) {//prosedur kompleks maskapailist dan jumlah maskapai
    int nomorToUpdate;
    cout << "Masukkan Nomor Maskapai yang ingin diupdate: ";//fungsi iostream input nomor maskapai 
    cin >> nomorToUpdate;//fungsi iostream nomor maskapai diubah

    int i;
    for (i = 0; i < jumlahMaskapai; ++i) {//rekursif jumlah maskapai
        if (maskapaiList[i].nomor == nomorToUpdate) {
            break;
        }
    }

    if (i == jumlahMaskapai) {
        cout << "Nomor maskapai tidak ditemukan." << endl;//fungsi iostream nomor maskapai tidak ada
        return;
    }

    cout << "Masukkan Nama Maskapai yang baru: ";//fungsi iostream input nama maskapai 
    getline(cin >> ws, maskapaiList[i].nama);
    cout << "Data maskapai berhasil diupdate." << endl;//fungsi input maskapai berhasil diubah
}

void hapusData//fungsi overloading hapus maskapai
(Maskapai maskapaiList[], int& jumlahMaskapai) {//prosedur kompleks maskapailist dan jumlah maskapai
    int nomorToDelete;
    cout << "Masukkan Nomor Maskapai yang ingin dihapus: ";//fungsi iostream input maskapai 
    cin >> nomorToDelete;//fungsi iostream output daftar maskapai

    int i;
    for (i = 0; i < jumlahMaskapai; ++i) {//rekursif jumlah maskapai
        if (maskapaiList[i].nomor == nomorToDelete) {
            for (int j = i; j < jumlahMaskapai - 1; ++j) {
                maskapaiList[j] = maskapaiList[j + 1];
            }
            jumlahMaskapai--;
            cout << "Data maskapai berhasil dihapus." << endl;//fungsi iostream output maskapai berhasil dihapus
            return;
        }
    }

    cout << "Nomor maskapai tidak ditemukan." << endl;//fungsi iostream output nomor maskapai tidak ditemukan
}

int main() {
    // Inisialisasi daftar maskapai
    Maskapai maskapaiList[MAX_MASKAPAI] = {
        {1, "Citilink"},
        {2, "Lion Air"},
        {3, "Batik Air"},
        {4, "Garuda Indonesia"}
    };

    int jumlahMaskapai = 4; // Jumlah maskapai awal
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
        cin >> pilihan;

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
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}


