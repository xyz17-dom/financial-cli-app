#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

	// Validasi Password
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
		// Variabel untuk menyimpan data akun yang didaftarkan
		string username, password;
		bool apakahAkunSudahAda = 0;
		
		// 1.CEK DATABASE & AUTO-LOGIN / REGISTRASI
		
		// Coba buka file database_akun.txt untuk membaca (ifstream)
		ifstream fileMasuk("database_akun.txt");
		
		if (fileMasuk.is_open()) {
			// Jika file berhasil dibuka, artinya USER SUDAH PUNYA AKUN
			apakahAkunSudahAda = true;
			
			// Ambil data dari file teks, masukkan ke variabel sistem
			fileMasuk >> username;
			fileMasuk >> password;
			
			fileMasuk.close();
			cout << "[Sistem] Akun Terdeteksi. Silahkan Langsung Login!\n" << endl;
		} else {
			// jika file tidak ditemukan, artinya USER BARU
			cout << "=== REGISTRASI AKUN BARU ===" << endl;
			cout << "Buat username baru: ";
			cin >> username;
		
		// Looping do-while agar user membuat password sampai memenuhi ketentuan
		do {
			cout << "Buat Password baru (Min.6 karakter, kombinasi A-Z, 0-9): ";
			cin >> password;
		} while (apaPasswordValid(password) == false);
		
		// Setelah password valid, SIMPAN KE FILE 
		ofstream fileKeluar("database_akun.txt");
		if (fileKeluar.is_open()) {
			fileKeluar << username << endl;
			fileKeluar << password << endl;
			fileKeluar.close();
			cout << "[Sukses] Akun berhasil didaftarkan!\n" << endl;
		}
	}
		
		// 2. Login Aplikasi
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
			
			// Validasi apakah cocok dengan data registrasi tadi
			if (input_user == username && input_password == password) {
				cout << "[Sukses] Login Berhasil! Selamat Datang, " << username << ".\n" << endl;
				loginBerhasil = true;
				break;
			} else {
				kesempatan--;
				cout << "[Salah} Username atau Kata Sandi Keliru! Sisa kesempatan: " << kesempatan << endl;
				
			}
		}
		
		if (!loginBerhasil) {
			cout << "[Gagal] Anda salah memasukkan kata sandi 3 kali. Program dihentikan." << endl;
			return 0;
		}
		
		// 3. Menu Utama ( WARNA DAN TIPE TRANSAKSI)
		// Definis Kode Warna ANSI
		const string HIJAU = "\033[32m";
		const string MERAH = "\033[31m";
		const string KUNING = "\033[33m";
		const string RESET = "\033[0m";
		
		string menuTransaksi[100];
		int nominalTransaksi[100];
		string tipeTransaksi[100];
		int jumlahTransaksi = 0;
		int pilihan;
		
		do {
		//Menampilkan menu di layar
		cout << "\n=== APLIKASI KEUANGAN ===" << endl;
		cout << "1. Tambah Transaksi" << endl;
		cout << "2. Tampilkan Transaksi & Total Saldo" << endl;	
		cout << "3. Hapus Transaksi" << endl;
		cout << "4. Keluar" << endl;
		cout << "Pilih menu (1-4): " << endl;
		cin >> pilihan;
	
	//Menentukan aksi berdasarkan pilihan
	switch(pilihan) {
		case 1: {
		cout << "\n--- Tambah Transaksi Baru ---" << endl;
			cout << "Masukkan nama transaksi baru: ";
			cin >> menuTransaksi[jumlahTransaksi];
			
			cout << "Masukkan nominal uang: Rp ";
			cin >> nominalTransaksi[jumlahTransaksi];
			
			// PILIHAN TIPE TRANSAKSI
			int pilihanTipe;
			cout << "Pilih Tipe Transaksi: \n1. Pemasukan (Uang Masuk)\n2. Pengeluaran (Uang Keluar)\nPilihan (1-2): ";
			cin >> pilihanTipe;
			
			if (pilihanTipe== 1) {
				tipeTransaksi[jumlahTransaksi] = "Pemasukan";
			} else {
				tipeTransaksi[jumlahTransaksi] = "Pengeluaran";
			}
			
			jumlahTransaksi++;
			cout << "[Sukses] Transaksi berhasil dicatat!" <<endl;
		break;
		}
		
		case 2: {
		cout << "\n--- Daftar Semua Transaksi ---" << endl;
			if (jumlahTransaksi == 0) {
				cout << KUNING << "[Info] Belum ada transaksi yang dicatat." << RESET << "\n" << endl;
			} else {
				int totalPemasukan = 0;
				int totalPengeluaran = 0;
				
				// 1. menampilkan data sekaligus menghitung total
				for (int i = 0; i < jumlahTransaksi; i++) {
					if (tipeTransaksi[i] == "Pemasukan") {
						// Tampilkan warna Hijau untuk pemasukan
						cout << i +1 << ". " <<menuTransaksi[i] << " : " << HIJAU << "+Rp " << nominalTransaksi[i] << RESET << " (" << tipeTransaksi[i] << ")" << endl;
					} else {
						// Tampilkan warna MERAH untuk pengeluaran
						cout << i + 1 << ". " << menuTransaksi[i] <<" : " << MERAH << "-Rp " << nominalTransaksi[i] << RESET << " (" << tipeTransaksi[i] << ")" << endl;
						totalPengeluaran += nominalTransaksi[i];
					}	
				}
				
				//2. Hitung Saldo Akhir
				int saldoAkhir = totalPemasukan - totalPengeluaran;
				
				cout << "\n-----------------------------------" << endl;
				cout << "Total Pemasukan   : " << HIJAU << "Rp " << totalPemasukan << RESET << endl;
				cout << "Total Pengeluaran : " << MERAH << "Rp " << totalPengeluaran << RESET << endl;
				
				// 3. Cek apakah saldi minus atau tidak
				cout << "Status Saldo Anda : ";
				if (saldoAkhir < 0) {
					cout << MERAH << "Rp " << saldoAkhir << " (MINUS /SURPLUS NEGATIF)" << RESET << endl;
					
				} else {
					cout << HIJAU << "Rp " << saldoAkhir << " (AMAN /SURPLUS POSITIF)" << RESET << endl;
					
				}
				cout << "\n-----------------------------------";
			}
			break;
		}
		
		case 3:
			cout << "\n--- Hapus Transaksi ---" <<endl;
			// Cek dulu, apa ada data transaksi. kalau tdk ada maka transaksi tidak bisa dihapus
			if(jumlahTransaksi == 0) {
				cout << "[Info] Belum ada transaksi yang dicatat." << endl;
			} else {
				// 1.Tampilkan dulu daftar trasaksi agar user bisa memilih
				cout << "Daftar Transaksi Saat Ini: " << endl;
				for (int i = 0; i < jumlahTransaksi; i++) {
					cout << i + 1 << ". " << menuTransaksi[i] << " : Rp " << nominalTransaksi[i] << endl;
				}
				
				// 2. Minta input nomor mana yang akan dihapus
				int hapusNomor;
				cout << "Masukkan nomor transaksi yang ingin dihapus: ";
				cin >> hapusNomor;
				
				// 3. Validasi input (dicek, nomor ada dalam daftar)
				if (hapusNomor < 1 || hapusNomor > jumlahTransaksi) {
					cout << "[Peringatan] Nomor Transaksi Tidak Valid!" << endl;
				}else {
					//4. Logika menggeser elemen array . proses hapus terjadi disini
					for (int i = hapusNomor - 1; i < jumlahTransaksi - 1; i++) {
						menuTransaksi[i] = menuTransaksi [i + 1];
						nominalTransaksi[i] = nominalTransaksi[i + 1];
					}
					
					//5. mengurangi jumlah transaksi karena 1 data sudah dihapus
					jumlahTransaksi--;
					cout << "[Sukses] Transaksi nomor" << hapusNomor << " berhasil dihapus!" << endl;					
				}
			}
		break;
		case 4:
			cout << "Terima kasih telah menggunakan aplikasi ini :>" <<endl;
			//logika
		break;
		default:
			cout << "[Peringatan] Pilihan tidak valid! Silahkan coba lagi." << endl;
			
	}
		
	} while(pilihan != 4); // Program akan terus berjalan selama user tidak memilih 4 (Keluar)
	
	return 0;	
	}
