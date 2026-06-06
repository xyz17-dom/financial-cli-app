#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

	//  Fungsi Validasi Password
	bool apaPasswordValid (string password) {
		// 1. Syarat panjang mininal 6 karakter
		if (password.length() < 6) {
			cout << "[Peringatan] Password Terlalu Pendek! Minimal 6 Karakter." << endl;
			return false;
		}
		
		bool hurufBesar = false;
		bool hurufKecil = false;
		bool angka = false;
		
		// 2. Looping memeriksa karakter satu persatu
		for (int i = 0; i < password.length(); i++) {
			char karakter = password[i];
			
			if (isupper(karakter)) {
				hurufBesar = true;
			} else if (islower(karakter)) {
				hurufKecil = true;
			} else if (isdigit(karakter)) {
				angka = true;
			}
		}
		
		// 3. Memeriksa apa semua syarat terpenuhi
		if (hurufBesar && hurufKecil && angka) {
			return true;
		} else {
			cout << "[Peringatan] Password harus ada kombinasi Huruf Besar, Huruf Kecil, dan Angka!" << endl;
			return false; // password gagal
		}
	}

int main() {
    string username, password;
    bool apakahAkunSudahAda = false;
    
    // -----------------------------------------------------
    // 1. CEK DATABASE AKUN & AUTO-LOGIN / REGISTRASI
    // -----------------------------------------------------
    ifstream fileMasuk("database_akun.txt");
    
    if (fileMasuk.is_open()) {
        apakahAkunSudahAda = true;
        fileMasuk >> username;
        fileMasuk >> password;
        fileMasuk.close();
        cout << "[Sistem] Akun Terdeteksi. Silahkan Langsung Login!\n" << endl;
    } else {
        cout << "=== REGISTRASI AKUN BARU ===" << endl;
        cout << "Buat username baru: ";
        cin >> username;
    
        do {
            cout << "Buat Password baru (Min.6 karakter, kombinasi A-Z, 0-9): ";
            cin >> password;
        } while (apaPasswordValid(password) == false);
        
        ofstream fileKeluar("database_akun.txt");
        if (fileKeluar.is_open()) {
            fileKeluar << username << endl;
            fileKeluar << password << endl;
            fileKeluar.close();
            cout << "[Sukses] Akun berhasil didaftarkan!\n" << endl;
        }
    }
    
    // -----------------------------------------------------
    // 2. PROSES LOGIN APLIKASI
    // -----------------------------------------------------
    string input_user;
    string input_password;
    int kesempatan = 3;
    bool loginBerhasil = false;
    
    cout << "=== LOGIN APLIKASI KEUANGAN ===" << endl;
    while (kesempatan > 0) {
        cout << "Masukkan Username: ";
        cin >> input_user;
        cout << "Masukkan kata Sandi: ";
        cin >> input_password;
        
        if (input_user == username && input_password == password) {
            cout << "[Sukses] Login Berhasil! Selamat Datang, " << username << ".\n" << endl;
            loginBerhasil = true;
            break;
        } else {
            kesempatan--;
            cout << "[Salah] Username atau Kata Sandi Keliru! Sisa kesempatan: " << kesempatan << endl;
        }
    }
    
    if (!loginBerhasil) {
        cout << "[Gagal] Anda salah memasukkan kata sandi 3 kali. Program dihentikan." << endl;
        return 0;
    }
    
    // -----------------------------------------------------
    // 3. MENU UTAMA APLIKASI KEUANGAN
    // -----------------------------------------------------
    // Definisi Kode Warna ANSI
    const string HIJAU = "\033[32m";
    const string MERAH = "\033[31m";
    const string KUNING = "\033[33m";
    const string RESET = "\033[0m";
    
    string menuTransaksi[100];
    int nominalTransaksi[100];
    string tipeTransaksi[100];
    string tanggalTransaksi[100];
    int jumlahTransaksi = 0;
    int pilihan;
        
    // LOAD DATABASE TRANSAKSI (BACA FILE SAAT START)
    ifstream fileTransaksiMasuk("database_transaksi.txt");
    if (fileTransaksiMasuk.is_open()) {
        while (fileTransaksiMasuk >> menuTransaksi[jumlahTransaksi]
                                 >> nominalTransaksi[jumlahTransaksi]
                                 >> tipeTransaksi[jumlahTransaksi]
								 >> tanggalTransaksi[jumlahTransaksi]) {
            jumlahTransaksi++;
        }
        fileTransaksiMasuk.close();
        cout << KUNING << "[Sistem] Berhasil memuat " << jumlahTransaksi << " riwayat transaksi lama.\n" << RESET << endl;
    }
    
    do {
        cout << RESET; // Memastikan menu utama selalu berwarna normal
        
        cout << "\n=== APLIKASI KEUANGAN ===" << endl;
        cout << "1. Tambah Transaksi" << endl;
        cout << "2. Tampilkan Transaksi & Total Saldo" << endl;    
        cout << "3. Hapus Transaksi" << endl;
        cout << "4. Cari Transaksi" << endl;
        cout << "5. Ubah Password Akun" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu (1-6): "; 
        cin >> pilihan;

        switch(pilihan) {
            case 1: {
                cout << "\n--- Tambah Transaksi Baru ---" << endl;
                cout << "Masukkan nama transaksi baru: ";
                cin >> menuTransaksi[jumlahTransaksi];
                
                cout << "Masukkan nominal uang: Rp ";
                cin >> nominalTransaksi[jumlahTransaksi];
                
                int pilihanTipe;
                cout << "Pilih Tipe Transaksi: \n1. Pemasukan (Uang Masuk)\n2. Pengeluaran (Uang Keluar)\nPilihan (1-2): ";
                cin >> pilihanTipe;
                
                if (pilihanTipe == 1) {
                    tipeTransaksi[jumlahTransaksi] = "Pemasukan";
                } else {
                    tipeTransaksi[jumlahTransaksi] = "Pengeluaran";
                }
                
                // INPUT TANGGAL BARU
            	cout << "Masukkan tanggal transaksi: ";
            	cin >> tanggalTransaksi[jumlahTransaksi];
            	
                // SIMPAN LANGSUNG KE FILE TRANSAKSI WITH SPACES
                ofstream fileTransaksiKeluar("database_transaksi.txt", ios::app);
                if (fileTransaksiKeluar.is_open()) {
                    fileTransaksiKeluar << menuTransaksi[jumlahTransaksi] << " "
                                        << nominalTransaksi[jumlahTransaksi] << " "
                                        << tipeTransaksi[jumlahTransaksi] << " "
										<< tanggalTransaksi[jumlahTransaksi] << endl;
                    fileTransaksiKeluar.close();
                }
                
                jumlahTransaksi++;    
                cout << HIJAU << "[Sukses] Transaksi berhasil dicatat dan disimpan ke database!" << RESET << endl;
                break;
            }
            
            case 2: {
                cout << "\n--- Daftar Semua Transaksi ---" << endl;
                if (jumlahTransaksi == 0) {
                    cout << KUNING << "[Info] Belum ada transaksi yang dicatat." << RESET << "\n" << endl;
                } else {
                    int totalPemasukan = 0;
                    int totalPengeluaran = 0;
                    
                    for (int i = 0; i < jumlahTransaksi; i++) {
                        if (tipeTransaksi[i] == "Pemasukan") {
                            cout << i + 1 << ". [" << tanggalTransaksi[i] << "] " << menuTransaksi[i] << " : " << HIJAU << "+Rp " << nominalTransaksi[i] << RESET << " (" << tipeTransaksi[i] << ")" << endl;
                            totalPemasukan += nominalTransaksi[i];
                        } else {
                            cout << i + 1 << ". [" << tanggalTransaksi[i] << "] " << menuTransaksi[i] << " : " << MERAH << "-Rp " << nominalTransaksi[i] << RESET << " (" << tipeTransaksi[i] << ")" << endl;
                            totalPengeluaran += nominalTransaksi[i];
                        }    
                    }
                    
                    int saldoAkhir = totalPemasukan - totalPengeluaran;
                    
                    cout << "\n-----------------------------------" << endl;
                    cout << "Total Pemasukan   : " << HIJAU << "Rp " << totalPemasukan << RESET << endl;
                    cout << "Total Pengeluaran : " << MERAH << "Rp " << totalPengeluaran << RESET << endl;
                    
                    cout << "Status Saldo Anda : ";
                    if (saldoAkhir < 0) {
                        cout << MERAH << "Rp " << saldoAkhir << " (MINUS / SURPLUS NEGATIF)" << RESET << endl;
                    } else {
                        cout << HIJAU << "Rp " << saldoAkhir << " (AMAN / SURPLUS POSITIF)" << RESET << endl;
                    }
                    cout << "-----------------------------------\n" << endl;
                }
                break;
            }
            
            case 3: {
                cout << "\n--- Hapus Transaksi ---" << endl;
                if (jumlahTransaksi == 0) {
                    cout << KUNING << "[Info] Belum ada transaksi yang dicatat." << RESET << "\n" << endl;
                } else {
                    cout << "Daftar Transaksi Saat Ini: " << endl;
                    for (int i = 0; i < jumlahTransaksi; i++) {
                        cout << i + 1 << ". [" << tanggalTransaksi[i] << "] " << menuTransaksi[i] << " : Rp " << nominalTransaksi[i] << " (" << tipeTransaksi[i] << ")" << endl;
                    }
                    
                    int indeksHapus;
                    cout << "Masukkan nomor transaksi yang ingin dihapus: ";
                    cin >> indeksHapus;
                    
                    if (indeksHapus >= 1 && indeksHapus <= jumlahTransaksi) {
                        // 1. Geser Array di RAM
                        for (int i = indeksHapus - 1; i < jumlahTransaksi - 1; i++) {
                            menuTransaksi[i] = menuTransaksi[i + 1];
                            nominalTransaksi[i] = nominalTransaksi[i + 1];
                            tipeTransaksi[i] = tipeTransaksi[i + 1];
                            tanggalTransaksi[i] = tanggalTransaksi[i + 1];
                        }
                        jumlahTransaksi--;
                        
                        // 2. SINKRONISASI ULANG KE FILE DATABASE (Menimpa file lama)
                        ofstream fileTransaksiKeluar("database_transaksi.txt");
                        if (fileTransaksiKeluar.is_open()) {
                            for (int i = 0; i < jumlahTransaksi; i++) {
                                fileTransaksiKeluar << menuTransaksi[i] << " "
                                                    << nominalTransaksi[i] << " "
                                                    << tipeTransaksi[i] << " "
													<< tanggalTransaksi[i] << endl;
                            }
                            fileTransaksiKeluar.close();
                        }
                        cout << HIJAU << "[Sukses] Transaksi berhasil dihapus dari sistem dan database!" << RESET << "\n" << endl;
                    } else {
                        cout << MERAH << "[Salah] Nomor transaksi tidak valid!" << RESET << "\n" << endl;
                    }
                }
                break; 
            }
            
            case 4:
                cout << "\n--- Cari Transaksi ---" << endl;
                if (jumlahTransaksi == 0) {
                	cout << KUNING << "[Info] Belum ada transaksi yang dicatat. Tidak bisa mencari." << RESET << "\n" << endl;
				} else {
					string kataKunci;
					cout << "Masukkan kata kunci transaksi yang dicari: ";
					cin >> kataKunci;
					
					cout << "\n--- Hasil Pencarian untuk '" << kataKunci << "' ---" << endl;
					bool ditemukan = false;
					int nomorHasil = 1;
				
					// Melakukan looping dari awal sampai akhir array transaksi
					for (int i = 0; i < jumlahTransaksi; i++) {
						// Cek apakah nama transaksi mengandung kata kunci
						if (menuTransaksi[i].find(kataKunci) != string::npos) {
							ditemukan = true;
							
							// Tampilkann hasil pencarian sesuai tipenya
							if (tipeTransaksi[i] == "Pemasukan") {
								cout << nomorHasil << ". [" << tanggalTransaksi[i] << "] " << menuTransaksi[i] << " : " << HIJAU << "+Rp " << nominalTransaksi[i] << RESET << " (" << tipeTransaksi[i] << ")" << endl;
							} else {
								cout << nomorHasil << ". [" << tanggalTransaksi[i] << "] " << menuTransaksi[i] << " : " << MERAH << "-Rp " << nominalTransaksi[i] << RESET << " (" << tipeTransaksi[i] << ")" << endl;
							}
							nomorHasil++;
						}
					}
					
					if (!ditemukan) {
						cout << MERAH << "[Info] Tidak ada transaksi yang cocok dengan kata kunci tersebut." << RESET << endl;
					}
					break;
				}
				
			case 5: {
				cout << "\n--- Ubah Password Akun ---" << endl;
				string passLama;
				cout << "Masukkan password kamu saat ini: ";
				cin >> passLama;
				
				// Verifikasi apakah password lama yng dimasukkan sudah cocok
				if (passLama != password) {
					cout << MERAH << "[Gagal] Password lama salah! Akses ditolak." << RESET << endl;
				} else {
					string passBaru;
					do {
						cout << "Masukkan Password Baru Anda (Min.6 karakter, kombinasi A-Z, Angka 0-9): ";
						cin >> passBaru;
					} while (apaPasswordValid(passBaru) == false);
					
					// Tulis ulang ke database_akun
					ofstream fileAkunKeluar("database_akun.txt");
					if (fileAkunKeluar.is_open()) {
						fileAkunKeluar << username << endl;
						fileAkunKeluar << passBaru << endl;
						fileAkunKeluar.close();
						
						// Perbarui variabel password 
						password == passBaru;
						cout << HIJAU << "[Sukses] Password berhasil diubah di sistem dan database!" << RESET << endl;
					} else {
						cout << MERAH << "[Error] Gagal membuka database untuk memperbarui password." << RESET << endl;
					} 
				}
				break;
			}	
			
			case 6:
				cout << "Terima kasih telah menggunakan aplikasi ini :>" << endl;	
				break;
				
				default:
					cout << KUNING << "[Peringatan] Pilihan tidak valid! Silahkan coba lagi." << RESET << endl;
    	}
	 
	} while(pilihan != 6);
    
    return 0;    
}
