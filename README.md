# 💰 Aplikasi Keuangan CLI (C++)

Aplikasi pencatat keuangan berbasis teks (Command Line Interface) yang dirancang menggunakan bahasa C++. Proyek ini dibuat sebagai bentuk implementasi pembelajaran logika pemrograman, Array, File I/O, kontrol percabangan, serta manipulasi string di semester 2 Teknik Informatika.

## ✨ Fitur Utama
* **🛡️ Registrasi Akun & Validasi Password:** Pengguna dapat membuat akun sendiri dengan standarisasi keamanan password (wajib kombinasi Huruf Besar, Huruf Kecil, dan Angka dengan minimal 6 karakter).
* **💾 Sistem Auto-Login (File Database):** Data akun tersimpan secara permanen di dalam file teks lokal. Aplikasi otomatis mendeteksi jika pengguna sudah memiliki akun, sehingga tidak perlu mendaftar ulang saat aplikasi dibuka kembali.
* **📊 Manajemen Transaksi Keuangan:** Mendukung pencatatan jenis transaksi **Pemasukan** dan **Pengeluaran** (maksimal 100 data data sementara).
* **🎨 Interfasi CLI Berwarna (ANSI Color):** Tampilan nominal dinamis yang memanjakan mata; warna **Hijau** untuk Pemasukan/Surplus dan warna **Merah** untuk Pengeluaran/Minus.
* **📈 Kalkulator Saldo Otomatis:** Menghitung total akhir keuangan secara *real-time* lengkap dengan status kesehatan finansial pengguna.
* **🗑️ Hapus Transaksi Terstruktur:** Menghapus data transaksi tertentu dengan logika pergeseran indeks array yang rapi.

## 🛠️ Cara Menjalankan Aplikasi
1. Clone atau unduh file `Aplikasi Keuangan.cpp` di atas.
2. Buka file menggunakan IDE favoritmu (VS Code, Dev-C++, atau Code::Blocks).
3. Lakukan *Compile* dan *Run* program.
4. Jika baru pertama kali dijalankan, sistem akan meminta pendaftaran akun baru secara otomatis.

---
*Proyek ini dikembangkan secara bertahap demi melatih fundamental pemrograman yang kuat.*
