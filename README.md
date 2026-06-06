# Financial CLI Application 💰

A C++ based Command Line Interface (CLI) financial application designed to track incomes and expenses. This project features secure user authentication and persistent file-based database management, making it an ideal tool for personal finance budgeting.

## 🚀 Features

- **Secure Authentication & Account Management**: 
  - User registration and login system with 3 maximum login attempts.
  - Password validator requiring a combination of uppercase, lowercase, and numeric characters.
  - Built-in secure **Change Password** option directly from the main menu.
- **Transaction Tracker**: Easily log new financial entries as either *Income* (Pemasukan) or *Expense* (Pengeluaran).
- **Date & Timestamping**: Every single transaction is automatically saved with its respective date record.
- **Persistent Storage**: Data is saved locally using file handling (`database_akun.txt` and `database_transaksi.txt`), ensuring data is not lost when the program closes.
- **Live Balance & Status Summary**: Dynamically calculates total incomes, total expenses, and highlights surplus or negative balance statuses with terminal color coding.
- **Advanced Operations**:
  - **Search Feature**: Quickly search for past entries using specific keywords.
  - **Delete Record**: Remove incorrect entries with real-time file synchronization.

## 🛠️ Tech Stack

- **Language**: C++
- **Concepts Used**: Array Manipulation, File Handling (I/O Streams), Functions, Data Structures, Control Flow, and Linear Search Algorithm.

## 🖥️ Preview / How it Works

1. **Authentication Screen**: Upon starting, the app checks for existing databases. Users must pass the credential validation to access the main menu.
2. **Main Menu Structure**:
```text
=== APLIKASI KEUANGAN ===
1. Tambah Transaksi
2. Tampilkan Transaksi & Total Saldo
3. Hapus Transaksi
4. Cari Transaksi
5. Ubah Password Akun
6. Keluar
```

## ⚙️ How to Run Locally

Follow these steps to run the application on your local machine:

1. Clone this repository:
```bash
git clone [https://github.com/xyz17-dom/financial-cli-app.git](https://github.com/xyz17-dom/financial-cli-app.git)
```
2. Navigate to the project directory:
```bash
cd financial-cli-app
```
3. Compile the source code using g++:
```bash
g++ financial_app.cpp -o FinancialApp
```
4. Execute the compiled binary program:
- **On Linux/macOS**:
  ```bash
  ./FinancialApp
  ```
- **On Windows (Command Prompt/PowerShell)**:
  ```bash
  FinancialApp.exe
  ```

---
*Developed as an independent portfolio project by a second-semester Computer Science student.*
