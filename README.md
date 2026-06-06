# Financial CLI Application 💰

A C++ based Command Line Interface (CLI) financial application designed to track incomes and expenses. This project features secure user authentication and persistent file-based database management, making it an ideal tool for personal finance budgeting.

## 🚀 Features

- **Secure Authentication & Account Management**: 
  - User registration and login system with maximum login attempts.
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

## 🖥️ Main Menu Structure

```text
=== APLIKASI KEUANGAN ===
1. Tambah Transaksi
2. Tampilkan Transaksi & Total Saldo
3. Hapus Transaksi
4. Cari Transaksi
5. Ubah Password Akun
6. Keluar

## ⚙️ How to Run Locally

1. Clone this repository to your local machine:
git clone [https://github.com/xyz17-dom/financial-cli-app.git](https://github.com/xyz17-dom/financial-cli-app.git)
2. Navigate to the project directory:
cd financial-cli-app
3. Compile the source code using g++:
g++ financial_app.cpp -o FinancialApp
4. Execute the compiled binary program:
- On Linux/macOS: ./FinancialApp
- On Windows (Command Prompt/PowerShell): FinancialApp.exe

Developed as an independent portfolio project by second-semester computer science students
