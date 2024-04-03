#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk kontak
struct Contact {
    string nama;
    string nomorHp;
    string email;
};

// Fungsi untuk menambahkan kontak baru
void tambahKontak(Contact contacts[], int &jumlahKontak) {
    cout << "Masukkan nama: ";
    cin >> contacts[jumlahKontak].nama;
    cout << "Masukkan nomor telepon: ";
    cin >> contacts[jumlahKontak].nomorHp;
    cout << "Masukkan email: ";
    cin >> contacts[jumlahKontak].email;
    jumlahKontak++;
}

// Fungsi untuk menampilkan semua kontak
void displayContacts(Contact contacts[], int jumlahKontak) {
    cout << "Daftar Kontak:" << endl;
    for (int i = 0; i < jumlahKontak; ++i) {
        cout << "Nama: " << contacts[i].nama << endl;
        cout << "Nomor Telepon: " << contacts[i].nomorHp << endl;
        cout << "Email: " << contacts[i].email << endl;
        cout << "-----------------------" << endl;
    }
}

int main() {
    const int MAX_CONTACTS = 50;
    Contact contacts[MAX_CONTACTS];
    int jumlahKontak = 0;
    char choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Kontak" << endl;
        cout << "2. Tampilkan Kontak" << endl;
        cout << "3. Keluar" << endl;
        cout << "4. hapus Kontak" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case '1':
                tambahKontak(contacts, jumlahKontak);
                break;
            case '2':
                 cout << "------------------------" << endl;
                        displayContacts(contacts, jumlahKontak);
                break;
            case '3':
                cout << "Berhasil Menyimpan Pembaharuan Kontak";
                break;
            case '4':
                if (jumlahKontak > 0) {
                    string kontakHapus;
                    cout << "Masukkan nama kontak yang ingin dihapus: ";
                    cin >> kontakHapus;

                    int indeksHapus = -1;
                    for (int i = 0; i < jumlahKontak; i++) {
                        if (contacts[i].nama == kontakHapus) {
                            indeksHapus = i;
                            break;
                        }
                    }

                    if (indeksHapus != -1) {
                        for(int i = indeksHapus; i < jumlahKontak - 1; i++)
                            {
                            contacts[i] = contacts[i + 1];
                            }

                        jumlahKontak--;

                        cout << "Kontak telah dihapus." << endl;
                    } else {
                        cout << "Kontak dengan nama " << kontakHapus << " tidak ditemukan." << endl;
                    }
                } else {
                    cout << "Belum ada Kontak yang dimasukkan." << endl;
                }
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (choice != '3');

    return 0;
}
