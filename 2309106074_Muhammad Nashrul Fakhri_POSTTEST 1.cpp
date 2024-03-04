#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int loginAttempts = 0;
    string username, password;

    // Loop untuk login, maksimal 3 kali percobaan
    while (loginAttempts < 3) {
        cout << "=== Login ===" << endl;
        cout << "Nama Mahasiswa: ";
        cin >> username;
        cout << "NIM Mahasiswa: ";
        cin >> password;

        // Cek username dan password, misalnya username "admin" dan password "123"
        if (username == "Arul" && password == "74") {
            break; // Login berhasil, keluar dari loop
        } else {
            cout << "Nama atau Nim yang Anda Masukkan Salah. Silahkan Coba Lagi" << endl;
            loginAttempts++;
        }
    }

    // Cek apakah login berhasil
    if (loginAttempts == 3) {
        cout << "Anda telah melakukan percobaan login 3 kali. Program berhenti." << endl;
        return 0;
    }

    // Loop utama program
    while (true) {
        cout << "\n=== Menu Konversi ===" << endl;
        cout << "1. Konversi Kilometer/jam\n2. Konversi Centimeter/detik\n3. Konversi Meter/detik\n4. Konversi Mil/jam\n5. Keluar\n";
        
        int choice;  
        cout << "Pilih menu : ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double kmperjam;
                cout << "Masukkan kecepatan dalam Kilometer/jam: ";
                cin >> kmperjam;

                // Lakukan konversi
                double cmperdetik = kmperjam * 27.7778;
                double meterperdetik = kmperjam * 0.27778;
                double milperjam = kmperjam * 0.621371;

                // Tampilkan hasil konversi
                cout << fixed << setprecision(1);
                cout << "Hasil konversi:\n";
                cout << "Centimeter/detik: " << cmperdetik << "\n";
                cout << "Meter/detik: " << meterperdetik << "\n";
                cout << "Mil/jam: " << milperjam << "\n";
                break;
            }   
            case 2: {
                // Implementasi konversi Centimeter/detik
                double centiperdetik;
                cout << "Masukkan Centimeter/detik: ";
                cin >> centiperdetik;
                
                double kmperjam = centiperdetik * 27.7778;
                double meterperdetik = centiperdetik * 100;
                double milperjam = centiperdetik * 44.704;
				 
                cout << fixed << setprecision(2);
                cout << "Hasil konversi:\n";
                cout << "Kilometer/jam: " << kmperjam << "\n";
                cout << "Meter/Jam: " << meterperdetik << "\n";
                cout << "Mil/jam: " << milperjam << "\n";
                break;
            }
            case 3: {
                // Implementasi konversi Meter/detik
                double meterperdetik;
                cout << "Masukkan Meter/Detik: ";
                cin >> meterperdetik;
                
                double kmperjam = meterperdetik * 0.277778;
                double centimeterperdetik = meterperdetik * 0.010000008;
                double milperjam = meterperdetik * 0.447040357632;
				 
                cout << fixed << setprecision(3);
                cout << "Hasil konversi:\n";
                cout << "Kilometer/jam: " << kmperjam << "\n";
                cout << "Centi/detik: " << centimeterperdetik << "\n";
                cout << "Mil/jam: " << milperjam << "\n";
                break;
            }
            case 4: {
                // Implementasi konversi Mil/jam
                double milperjam;
                cout << "Masukkan Mil/Jam: ";
                cin >> milperjam;
                
                double kmperjam = milperjam * 0.621371689334;
                double centimeterperdetik = milperjam * 0.022369380816022212816;
                double meterperdetik = milperjam * 2.2369380816022212954;
				 
                cout << fixed << setprecision(4);
                cout << "Hasil konversi:\n";
                cout << "Kilometer/jam: " << kmperjam << "\n";
                cout << "Centi/detik: " << centimeterperdetik << "\n";
                cout << "Meter/detik: " << meterperdetik << "\n";
                break;
            }
            case 5: {
                cout << "Program berhenti.";
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
            }
        }
    }

    return 0;
}

