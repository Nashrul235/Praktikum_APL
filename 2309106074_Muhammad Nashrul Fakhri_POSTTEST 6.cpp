#include <iostream>
#include <string>
#include <limits> 

using namespace std;

const int MAX_MASKAPAI = 100;

struct Penerbangan { 
    string kepergian;
    string kedatangan;
    int jam_berangkat;
};

struct Maskapai { 
    int nomor; 
    string nama;
    Penerbangan penerbangan[MAX_MASKAPAI];
    int jumlahpenerbangan;
};

void tambahData(Maskapai* maskapaiList, int* jumlahMaskapai) {
    if (*jumlahMaskapai < MAX_MASKAPAI) {
        Maskapai maskapai;
        maskapai.nomor = (*jumlahMaskapai) + 1; 
        cout << "Masukkan Nama Maskapai: "; 
        getline(cin >> ws, maskapai.nama); 

        maskapaiList[(*jumlahMaskapai)++] = maskapai;

        cout << "Data maskapai berhasil ditambahkan." << endl; 
    } else {
        cout << "Tidak dapat menambahkan data. Batas maksimum telah tercapai." << endl;
    }
}

void tampilkanData(const Maskapai* maskapaiList, const int* jumlahMaskapai) { 
    cout << "Daftar Maskapai Penerbangan:" << endl;
    for (int i = 0; i < *jumlahMaskapai; ++i) {
        cout << " " << maskapaiList[i].nomor << "." << maskapaiList[i].nama << endl; 
    }
}

void updateData(Maskapai* maskapaiList, const int* jumlahMaskapai) { 
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
    getline(cin >> ws, maskapaiList[i].nama);
    cout << "Data maskapai berhasil diupdate." << endl;
}

void hapusData(Maskapai* maskapaiList, int* jumlahMaskapai) {
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

void bubbleSort(Maskapai arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].nama > arr[j + 1].nama) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSort(Maskapai* maskapaiList, const int* jumlahMaskapai) {
    bubbleSort(maskapaiList, *jumlahMaskapai);
    cout << "Data berhasil diurutkan menggunakan Bubble Sort." << endl;
}

void selectionsort(Maskapai* maskapaiList, const int* jumlahMaskapai) {
    for (int i = 0; i < *jumlahMaskapai - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < *jumlahMaskapai; ++j) {
            if (maskapaiList[j].nomor < maskapaiList[minIndex].nomor) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Maskapai temp = maskapaiList[i];
            maskapaiList[i] = maskapaiList[minIndex];
            maskapaiList[minIndex] = temp;
        }
    }
    cout << "Data berhasil diurutkan secara ascending berdasarkan nomor maskapai." << endl;
}

int partition(Maskapai arr[], int low, int high) {
    string pivot = arr[high].nama;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].nama < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Maskapai arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortWrapper(Maskapai* maskapaiList, const int* jumlahMaskapai) {
    quickSort(maskapaiList, 0, *jumlahMaskapai - 1);
    cout << "Data berhasil diurutkan menggunakan Quick Sort." << endl;
}

// Binary Search pada data yang terurut secara ascending
int binarySearchAscending(const Maskapai* maskapaiList, int jumlahMaskapai, string target) {
    int left = 0;
    int right = jumlahMaskapai - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Jika elemen tengah adalah target, kembalikan indeksnya
        if (maskapaiList[mid].nama == target) {
            return mid;
        }
        // Jika target lebih kecil, cari di sebelah kiri
        else if (maskapaiList[mid].nama < target) {
            left = mid + 1;
        }
        // Jika target lebih besar, cari di sebelah kanan
        else {
            right = mid - 1;
        }
    }

    // Jika target tidak ditemukan, kembalikan -1
    return -1;
}

// Sequential Search pada data yang terurut secara descending
int sequentialSearchDescending(const Maskapai* maskapaiList, int jumlahMaskapai, string target) {
    for (int i = 0; i < jumlahMaskapai; ++i) {
        // Jika nama maskapai saat ini lebih besar dari target, maka maskapai tidak ditemukan
        if (maskapaiList[i].nama > target) {
            return -1;
        }
        // Jika nama maskapai saat ini sama dengan target, maka kembalikan indeksnya
        else if (maskapaiList[i].nama == target) {
            return i;
        }
    }
    // Jika tidak ditemukan, kembalikan -1
    return -1;
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
        cout << "5. Bubble Sort" << endl;
        cout << "6. Selection Sort" << endl;
        cout << "7. Quick sort" << endl;
        cout << "8. Binary Search Ascending" << endl;
        cout << "9. Sequential Search Descending" << endl;
        cout << "10. Keluar" << endl;

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
                    bubbleSort(maskapaiList, &jumlahMaskapai);
                    break;
                case 6:
                    selectionsort(maskapaiList, &jumlahMaskapai);
                    break;
                case 7:
                    quickSortWrapper(maskapaiList, &jumlahMaskapai);
                    break;
                case 8: {
                    string target;
                    cout << "Masukkan nama maskapai yang ingin dicari: ";
                    cin >> target;
                    int result = binarySearchAscending(maskapaiList, jumlahMaskapai, target);
                    if (result != -1) {
                        cout << "Maskapai ditemukan pada indeks " << result << "." << endl;
                    } else {
                        cout << "Maskapai tidak ditemukan." << endl;
                    }
                    break;
                }
                case 9: {
                    string target;
                    cout << "Masukkan nama maskapai yang ingin dicari: ";
                    cin >> target;
                    int result = sequentialSearchDescending(maskapaiList, jumlahMaskapai, target);
                    if (result != -1) {
                        cout << "Maskapai ditemukan pada indeks " << result << "." << endl;
                    } else {
                        cout << "Maskapai tidak ditemukan." << endl;
                    }
                    break;
                }
            }
        }
    } while (pilihan != 10);

    return 0;
}


