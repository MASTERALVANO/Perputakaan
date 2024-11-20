
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
};

databuku buku[15] = {
    {"1", "Anak Semua Bangsa", "Bentang Pustaka", 3},
    {"2", "Ayah", "Bentang Pustaka", 3},
    {"3", "Bumi Manusia", "Pustaka Sastra", 3},
    {"4", "Cinta Brontosaurus", "Gramedia", 3},
    {"5", "Hafalan Shalat Delisa", "Republika", 3},
    {"6", "Hujan", "Bentang Pustaka", 3},
    {"7", "Koala Kumal", "GagasMedia", 3},
    {"8", "Laskar Pelangi", "Pustaka Sastra", 3},
    {"9", "Negeri 5 Menara", "Gramedia", 3},
    {"10", "Orang-Orang Biasa", "Bentang Pustaka", 3},
    {"11", "Perahu Kertas", "Bentang Pustaka", 3},
    {"12", "Pulang", "Bentang Pustaka", 3},
    {"13", "Sang Pemimpi", "Pustaka Sastra", 3},
    {"14", "Si Anak Pintar", "Bentang Pustaka", 3},
    {"15", "Supernova", "Bentang Pustaka", 3},
};


peminjam siswa[39] = {
    {1, "ALDA ANASTASIA ADRIANA", "9801109826", "X MP 1"},
    {2, "AKMALUSIRI DINATA", "3419300280", "XI ULW 1"},
    {3, "ARDHI EKA", "3334558694", "X TKJ 2"},
    {4, "ASYAFA TYAS DAMAYANTI", "6575390882", "XI TKI 1"},
    {5, "AVISA VINA KHUMAIRA", "8294009832", "X DKV 1"},
    {6, "BERLIANA PUTRI", "8914274780", "X DKV 1"},
    {7, "BILLY SAPUTRA", "7078349385", "XI RPL 1"},
    {8, "DIMAS ARYA ADIYATMA", "2932488516", "XI MP 3"},
    {9, "ECHA SAPUTRI", "3009252019", "XI TKJ 1"},
    {10, "MUHAMMAD IRFAN RAFA PUTRA", "8864351864", "XI RPL 2"},
    {11, "MUHAMMAD NUR IZZATUL HUDA", "8643454636", "X RPL 2"},
    {12, "MUHAMMAD RIDWAN ANDIKA", "8576434958", "X RPL 1"},
    {13, "MUHAMMAD ZAINY ARIF MIMA", "8764658494", "XI ANM 1"},
    {14, "MEGA PUTRI JELYTA", "8948937430", "X MP 3"},
    {15, "NAWFAL DWI HISAN RAMADHANI", "6484649480", "X TKJ 2"},
    {16, "NIDA'UL RAHIMA", "6494649934", "XI AK 1"},
    {17, "NIMAS AYU MIFTAKHUL JANAH", "3728706683", "XI ULW"},
    {18, "NUR AZIS DWI PRATAMA", "7864876664", "X ULW 2"},
    {19, "NURSELA PUTRI", "7286274939", "X MP 3"},
    {20, "PILAR SAKTI INDERA WASPADA", "6498694658", "X BP 2"},
    {21, "RAJNI SABINA SUDARSONO", "2153769443", "XI MP 2"},
    {22, "RANIA PUTRI SAVERA", "1863666877", "X RPL 1"},
    {23, "RAYHAN MAHARDIKA", "4883473494", "X RPL 2"},
    {24, "RADO FARISTRA AMSAH", "6846494931", "XI DKV 2"},
    {25, "SANIA MARIA", "9435405121", "XI AK 4"},
    {26, "SHOULTON HABIYAKSO", "9302846335", "X RPL 2"},
    {27, "SINTA LESTARI", "75421467800", "X RPL 1"},
    {28, "SRI MUHAMMAD HAMURWO BUMI", "9754321245", "XI RPL 2"},
    {29, "VRINSA LAUDYA PERMATA", "7392784634", "X AK 4"},
    {30, "YUAN RIZKA AGUSTIN", "9087654321", "X ANM 2"},
    {31, "YUSUF LIAN RADITYA ABIDIN", "8899665547", "XI ANM 2"},
    {32, "ZAKI MAULANA AYUBI", "9876543210", "X DKV 1"},
    {33, "ZHANDY SATRIA WIBAWA", "1234567899", "X TKJ 1"},
    {34, "ZORINA GABRIELA VALENTINA", "6543211234", "X MP 3"},
    {35, "ZUNITA DWI HANDAYANI", "6543217898", "X PM 2"},
    {36, "ZYNA ARABELA CLLARISA", "7899876543", "X TKI 2"},
    {37, "ZYNA CANTIKA PUTRI", "3346789981", "X AK 2"}
};


void cetaktabelbuku() {
    cout << string(70, '=') << endl;
    cout << left << "Selamat Datang Di Perputakaan!!" << endl;
    cout << string(70, '=') << endl;
    cout << setw(7) << "ISBN" << setw(25) << "Judul" << setw(20) << "Penerbit" << setw(20) << "Jumlah Buku" << endl;
    cout << string(70, '=') << endl;
    for(int i = 0; i < 15; i++) {
        cout << setw(7) << buku[i].ISBN << setw(25) << buku[i].judul << setw(20) << buku[i].Penerbit << setw(20) << buku[i].jumlah << endl;
    }
    cout << string(70, '=') << endl;
}

void cetaktabelsiswa() {
    cout << string(70, '=') << endl;
    cout << left << "Selamat Datang Di Perputakaan!!" << endl;
    cout << string(70, '=') << endl;
    cout << setw(7) << "No" << setw(25) << "Nama" << setw(20) << "NISN" << setw(20) << "Kelas" << endl;
    cout << string(70, '=') << endl;
    for(int i = 0; i < 40; i++) {
        cout << setw(7) << i+1 << setw(25) << siswa[i].nama << setw(20) << siswa[i].NISN << setw(20) << siswa[i].kelas << endl;
    }
    cout << string(70, '=') << endl;
}

void bacabuku(string file) {
    string line;
    ifstream myfile("buku/" + file + ".txt");
    if(myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << '\n';
        }
        myfile.close();
    } else cout << "Unable to open file";
}

void cetaktabelpeminjam() {
    cout << string(70, '=') << endl;
    cout << left << "Selamat Datang Di Perputakaan!!" << endl;
    cout << string(70, '=') << endl;
    cout << setw(7) << "No" << setw(25) << "Nama" << setw(20) << "NISN" << setw(20) << "Kelas" << endl;
    cout << string(70, '=') << endl;
    for(int i = 0; i < 40; i++) {
        cout << setw(7) << i+1 << setw(25) << siswa[i].nama << setw(20) << siswa[i].NISN << setw(20) << siswa[i].kelas << endl;
    }
    cout << string(70, '=') << endl;
}

int main() {
    int hari1 = 1, bulan1 = 2, tahun1 = 2022,hari2, bulan2,tahun2;
    cetaktabelbuku();
    cout << endl << endl;
    string nama,kelas,NIS;
    cout << "Masukan Identitas :" << endl;
    cout << "Nama  : "; getline(cin,nama);
    cout << "Kelas : "; getline(cin,kelas);
    cout << "NISN   : "; getline(cin,NIS);
    bool found = false;
    for(int i = 0; i < 40; i++) {
        if(siswa[i].NISN == NIS || siswa[i].nama == nama || siswa[i].kelas == kelas) {
            cout << "Siswa ditemukan: " << endl;
            cout << "NIS   : " << siswa[i].NISN << endl;
            cout << "Nama  : " << siswa[i].nama << endl;
            cout << "Kelas : " << siswa[i].kelas << endl;
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "Siswa tidak ditemukan." << endl;
        return 0;
    }
    int pil;
    cout << "Pilihan :" << endl;
    cout << "1. Baca Buku" << endl;
    cout << "2. Pinjam Buku" << endl;
    cout << "3. Kembali Buku" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilihlah (1/2):"; cin >> pil;

    string namabuku;
    auto pilih1 = (pil == 1) ? "baca buku" : (pil == 2) ? "pinjam buku" : (pil == 3) ? "kembali buku" : "keluar";

    if(pilih1 == "baca buku") {
        int NO;
        cout << "Masukan No Buku: "; cin >> NO;
        bool bookFound = false;
        for(int i = 0; i < 15; i++) {
            if(stoi(buku[i].ISBN) == NO) {
                cout << "Buku ditemukan: " << endl;
                cout << "ISBN     : " << buku[i].ISBN << endl;
                cout << "Judul    : " << buku[i].judul << endl;
                cout << "Penerbit : " << buku[i].Penerbit << endl;
                cout << "Jumlah   : " << buku[i].jumlah << endl;
                bacabuku(buku[i].judul);
                bookFound = true;
                break;
            }
        }
        if(!bookFound) {
            cout << "Buku tidak ditemukan." << endl;
        }
    }

    else if(pilih1 == "pinjam buku") {
        int NO;
        cout << "Masukan No Buku: "; cin >> NO;
        bool bookFound = false;
        for(int i = 0; i < 15; i++) {
            if(stoi(buku[i].ISBN) == NO) {
                cout << "Buku ditemukan: " << endl;
                cout << "ISBN     : " << buku[i].ISBN << endl;
                cout << "Judul    : " << buku[i].judul << endl;
                cout << "Penerbit : " << buku[i].Penerbit << endl;
                cout << "Jumlah   : " << buku[i].jumlah << endl;
                bookFound = true;
                break;
            }   
        }
    }
    else if(pilih1 == "kembali buku") {
        string NO;
        cout << "Masukan Nama Buku: "; cin >> NO;
        bool bookFound = false;
        for(int i = 0; i < 15; i++) {
            if(buku[i].judul == namabuku) {
                if(buku[i].jumlah > 0 && buku[i].jumlah < 3) {
                    buku[i].jumlah += 1;
                    cout << "Berhasil mengembalikan buku " << endl;
                    found = true;
                    break;
                }
                cout << "Error" << endl;
                break;
            }
        }
    }
    return 0;
}

