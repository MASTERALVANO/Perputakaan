
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct databuku {
    string ISBN;
    string judul;
    string Penerbit;
    int jumlah;
};

struct peminjam {
    int no;
    string nama;
    string NISN;
    string kelas;
    string bukuPinjam;
    bool statusPinjam; // true jika buku dipinjam, false jika dikembalikan
};

databuku buku[15] = {
    {"1" , "Anak Semua Bangsa"      , "Bentang Pustaka", 3},
    {"2" , "Ayah"                   , "Bentang Pustaka", 3},
    {"3" , "Bumi Manusia"           , "Pustaka Sastra" , 3},
    {"4" , "Cinta Brontosaurus"     , "Gramedia"       , 3},
    {"5" , "Hafalan Shalat Delisa"  , "Republika"      , 3},
    {"6" , "Hujan"                  , "Bentang Pustaka", 3},
    {"7" , "Koala Kumal"            , "GagasMedia"     , 3},
    {"8" , "Laskar Pelangi"         , "Pustaka Sastra" , 3},
    {"9" , "Negeri 5 Menara"        , "Gramedia"       , 3},
    {"10", "Orang-Orang Biasa"      , "Bentang Pustaka", 3},
    {"11", "Perahu Kertas"          , "Bentang Pustaka", 3},
    {"12", "Pulang"                 , "Bentang Pustaka", 3},
    {"13", "Sang Pemimpi"           , "Pustaka Sastra" , 3},
    {"14", "Si Anak Pintar"         , "Bentang Pustaka", 3},
    {"15", "Supernova"              , "Bentang Pustaka", 3},
};

peminjam siswa[39] = {
    {1,  "ALDA ANASTASIA ADRIANA"      , "9801109826", "X MP 1"  ,"", false},
    {2,  "AKMALUSIRI DINATA"           , "3419300280", "XI ULW 1","", false},
    {3,  "ARDHI EKA"                   , "3334558694", "X TKJ 2" ,"", false},
    {4,  "ASYAFA TYAS DAMAYANTI"       , "6575390882", "XI TKI 1","", false},
    {5,  "AVISA VINA KHUMAIRA"         , "8294009832", "X DKV 1" ,"", false},
    {6,  "BERLIANA PUTRI"              , "8914274780", "X DKV 1" ,"", false},
    {7,  "BILLY SAPUTRA"               , "7078349385", "XI RPL 1","", false},
    {8,  "DIMAS ARYA ADIYATMA"         , "2932488516", "XI MP 3" ,"", false},
    {9,  "ECHA SAPUTRI"                , "3009252019", "XI TKJ 1","", false},
    {10, "MUHAMMAD IRFAN RAFA PUTRA"   , "8864351864", "XI RPL 2","", false},
    {11, "MUHAMMAD NUR IZZATUL HUDA"   , "8643454636", "X RPL 2" ,"", false},
    {12, "MUHAMMAD RIDWAN ANDIKA"      , "8576434958", "X RPL 1" ,"", false},
    {13, "MUHAMMAD ZAINY ARIF MIMA"    , "8764658494", "XI ANM 1","", false},
    {14, "MEGA PUTRI JELYTA"           , "8948937430", "X MP 3"  ,"", false},
    {15, "NAWFAL DWI HISAN RAMADHANI"  , "6484649480", "X TKJ 2" ,"", false},
    {16, "NIDA'UL RAHIMA"              , "6494649934", "XI AK 1" ,"", false},
    {17, "NIMAS AYU MIFTAKHUL JANAH"   , "3728706683", "XI ULW"  ,"", false},
    {18, "NUR AZIS DWI PRATAMA"        , "7864876664", "X ULW 2" ,"", false},
    {19, "NURSELA PUTRI"               , "7286274939", "X MP 3"  ,"", false},
    {20, "PILAR SAKTI INDERA WASPADA"  , "6498694658", "X BP 2"  ,"", false},
    {21, "RAJNI SABINA SUDARSONO"      , "2153769443", "XI MP 2" ,"", false},
    {22, "RANIA PUTRI SAVERA"          , "1863666877", "X RPL 1" ,"", false},
    {23, "RAYHAN MAHARDIKA"            , "4883473494", "X RPL 2" ,"", false},
    {24, "RADO FARISTRA AMSAH"         , "6846494931", "XI DKV 2","", false},
    {25, "SANIA MARIA"                 , "9435405121", "XI AK 4" ,"", false},
    {26, "SHOULTON HABIYAKSO"          , "9302846335", "X RPL 2" ,"", false},
    {27, "SINTA LESTARI"               , "7542146780", "X RPL 1" ,"", false},
    {28, "SRI MUHAMMAD HAMURWO BUMI"   , "9754321245", "XI RPL 2","", false},
    {29, "VRINSA LAUDYA PERMATA"       , "7392784634", "X AK 4"  ,"", false},
    {30, "YUAN RIZKA AGUSTIN"          , "9087654321", "X ANM 2" ,"", false},
    {31, "YUSUF LIAN RADITYA ABIDIN"   , "8899665547", "XI ANM 2","", false},
    {32, "ZAKI MAULANA AYUBI"          , "9876543210", "X DKV 1" ,"", false},
    {33, "ZHANDY SATRIA WIBAWA"        , "1234567899", "X TKJ 1" ,"", false},
    {34, "ZORINA GABRIELA VALENTINA"   , "6543211234", "X MP 3"  ,"", false},
    {35, "ZUNITA DWI HANDAYANI"        , "6543217898", "X PM 2"  ,"", false},
    {36, "ZYNA ARABELA CLLARISA"       , "7899876543", "X TKI 2" ,"", false},
    {37, "ZYNA CANTIKA PUTRI"          , "3346789981", "X AK 2"  ,"", false}
};

// Fungsi untuk mencetak tabel buku
void cetaktabelbuku() {
    cout << string(70, '=') << endl;
    cout << setw(7) << "ISBN" << setw(25) << "Judul" << setw(20) << "Penerbit" << setw(20) << "Jumlah Buku" << endl;
    cout << string(70, '=') << endl;
    for (int i = 0; i < 15; i++) {
        cout << setw(7) << buku[i].ISBN << setw(25) << buku[i].judul << setw(20) << buku[i].Penerbit << setw(20) << buku[i].jumlah << endl;
    }
    cout << string(70, '=') << endl;
}

// Fungsi untuk mencetak tabel siswa
void cetaktabelsiswa() {
    cout << string(70, '=') << endl;
    cout << setw(7) << "No" << setw(25) << "Nama" << setw(20) << "NISN" << setw(20) << "Kelas" << endl;
    cout << string(70, '=') << endl;
    for (int i = 0; i < 39; i++) {
        cout << setw(7) << siswa[i].no << setw(25) << siswa[i].nama << setw(20) << siswa[i].NISN << setw(20) << siswa[i].kelas << endl;
    }
    cout << string(70, '=') << endl;
}

// Fungsi untuk mencetak daftar peminjam
void cetaktabelpeminjam() {
    cout << string(70, '=') << endl;
    cout << setw(7) << "No" << setw(25) << "Nama" << setw(20) << "NISN" << setw(20) << "Buku" << setw(20) << "Status" << endl;
    cout << string(70, '=') << endl;
    for (int i = 0; i < 39; i++) {
        if (siswa[i].statusPinjam) {
            cout << setw(7) << siswa[i].no << setw(25) << siswa[i].nama << setw(20) << siswa[i].NISN << setw(20) << siswa[i].bukuPinjam << setw(20) << "Dipinjam" << endl;
        }
    }
    cout << string(70, '=') << endl;
}

// Fungsi untuk mencetak buku yang sedang dipinjam
void cekbukudipinjam() {
    cout << string(70, '=') << endl;
    cout << "Buku Yang Dipinjam" << endl;
    cout << string(70, '=') << endl;
    for (int i = 0; i < 15; i++) {
        if (buku[i].jumlah < 3) {
            cout << setw(7) << buku[i].ISBN << setw(25) << buku[i].judul << setw(20) << buku[i].Penerbit << setw(20) << 3 - buku[i].jumlah << endl;
        }
    }
    cout << string(70, '=') << endl;
}

// Fungsi untuk membaca buku dari file
void bacabuku(string file) {
    string line;
    ifstream myfile("buku/" + file + ".txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << '\n';
        }
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

// Fungsi untuk meminjam buku
void pinjamBuku() {
    int noBuku;
    string nama, NISN, kelas;
    cout << "Masukkan nomor buku yang ingin dipinjam: ";
    cin >> noBuku;
    cin.ignore();
    cout << "Masukkan nama peminjam: ";
    getline(cin, nama);
    cout << "Masukkan NISN peminjam: ";
    cin >> NISN;
    cout << "Masukkan kelas peminjam: ";
    cin >> kelas;

    if (noBuku > 0 && noBuku <= 15 && buku[noBuku - 1].jumlah > 0) {
        buku[noBuku - 1].jumlah--;
        for (int i = 0; i < 39; i++) {
            if (siswa[i].nama == nama) {
                cetaktabelbuku();
                siswa[i].bukuPinjam = buku[noBuku - 1].judul;
                siswa[i].statusPinjam = true;
                break;
            }
        }
        cout << "Buku berhasil dipinjam!" << endl;
    } else {
        cout << "Buku tidak tersedia!" << endl;
    }
}

// Fungsi untuk mengembalikan buku
void kembalikanBuku() {
    string nama;
    cout << "Masukkan nama peminjam yang mengembalikan buku: ";
    cin.ignore();
    getline(cin, nama);

    for (int i = 0; i < 39; i++) {
        if (siswa[i].nama == nama && siswa[i].statusPinjam) {
            for (int j = 0; j < 15; j++) {
                if (buku[j].judul == siswa[i].bukuPinjam) {
                    buku[j].jumlah++;
                    siswa[i].statusPinjam = false;
                    siswa[i].bukuPinjam = "";
                    cout << "Buku berhasil dikembalikan!" << endl;
                    return;
                }
            }
        }
    }
    cout << "Peminjaman buku tidak ditemukan!" << endl;
}

// Fungsi utama
int main() {
    int pilihan;
    do {
        cout << "\nSistem Informasi Perpustakaan" << endl;
        cout << "1. Lihat Daftar Buku" << endl;
        cout << "2. Lihat Daftar Siswa" << endl;
        cout << "3. Lihat Daftar Peminjam" << endl;
        cout << "4. Lihat Buku Yang Dipinjam" << endl;
        cout << "5. Pinjam Buku" << endl;
        cout << "6. Mengembalikan Buku" << endl;
        cout << "7. Baca Buku (Dari File)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cetaktabelbuku();
                break;
            case 2:
                cetaktabelsiswa();
                break;
            case 3:
                cetaktabelpeminjam();
                break;
            case 4:
                cekbukudipinjam();
                break;
            case 5:
                pinjamBuku();
                break;
            case 6:
                kembalikanBuku();
                break;
            case 7: {
                string namaFile;
                cout << "Masukkan nama file (tanpa ekstensi): ";
                cin >> namaFile;
                bacabuku(namaFile);
                break;
            }
            case 0:
                cout << "Terima kasih telah menggunakan sistem ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan > 0 || pilihan < 7);

    return 0;
}
