
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


peminjam siswa[40] = {
    {1,"ARDHI EKA", "3334558694", "X TKJ 2"},
    {2,"AKMALUSIRI DINATA", "3419300280", "XI ULW 1"},
    {3,"BERLIANA PUTRI", "8914274780", "X DKV 1"},
    {4,"BILLY SAPUTRA", "7078349385", "XI RPL 1"},
    {5,"DIMAS ARYA ADIYATMA", "2932488516", "XI MP 3"},
    {6,"ECHA SAPUTRI", "3009252019", "XI TKJ 1"},
    {7,"NUROCHMAN ADI PRAYOGA", "4286565562", "XI TKI 2"},
    {8,"RANIA PUTRI SAVERA", "1863666877", "X RPL 1"},
    {9,"RAYHAN MAHARDIKA", "4883473494", "X RPL 2"},
    {10,"SANIA MARIA", "9435405121", "XI AK 4"},
    {11,"MUHAMMAD IRFAN RAFA PUTRA", "8864351864", "XI RPL 2"},
    {12,"MUHAMMAD NUR IZZATUL HUDA", "8643454636", "X RPL 2"},
    {13,"MUHAMMAD RIDWAN ANDIKA", "8576434958", "X RPL 1"},
    {14,"MUHAMMAD ZAINY ARIF MIMA", "8764658494", "XI ANM 1"},
    {15,"NAWFAL DWI HISAN RAMADHANI", "6484649480", "X TKJ 2"},
    {16,"NIDA'UL RAHIMA", "6494649934", "XI AK 1"},
    {17,"NUR AZIS DWI PRATAMA", "7864876664", "X ULW 2"},
    {18,"NURUL NADIA", "3787644821", "XI PM 2"},
    {19,"PILAR SAKTI INDERA WASPADA", "6498694658", "X BP 2"},
    {20,"RADO FARISTRA AMSAH", "6846494931", "XI DKV 2"},
    {21,"ALDA ANASTASIA ADRIANA", "9801109826", "X MP 1"},
    {22,"ARJUNNA SINATRIA FRADANA", "8873061925", "XI BP 1"},
    {23,"ASYAFA TYAS DAMAYANTI", "6575390882", "XI TKI 1"},
    {24,"AVISA VINA KHUMAIRA", "8294009832", "X DKV 1"},
    {25,"MEGA PUTRI JELYTA", "8948937430", "X MP 3"},
    {26,"NIMAS AYU MIFTAKHUL JANAH", "3728706683", "XI ULW"},
    {27,"NURSELA PUTRI", "7286274939", "X MP 3"},
    {28,"RAJNI SABINA SUDARSONO", "2153769443", "XI MP 2"},
    {29,"SHOULTON HABIYAKSO", "9302846335", "X RPL 2"},
    {30,"VRINSA LAUDYA PERMATA", "7392784634", "X AK 4"},
    {31,"Sinta Lestari","75421467800","X RPL 1"},
    {32,"Sri Muhammad Hamurwo Bumi","9754321245","XI RPL 2"},
    {33,"Yuan Rizka Agustin","9087654321","X ANM 2"},
    {34,"Yusuf Lian Raditya Abidin","8899665547","XI ANM 2"},
    {35,"Zaki Maulana Ayubi","9876543210","X DKV 1"},
    {36,"Zhandy Satria Wibawa","1234567899","X TKJ 1"},
    {37,"Zunita Dwi Handayani","6543217898","X PM 2"},
    {38,"Zorina Gabriela Valentina","6543211234","X MP 3"},
    {39,"Zyna Arrabela Cllarisa","7899876543","X TKI 2"},
    {40,"Zyna Cantika Putri","3346789981","X AK 2"}
};


int main() {
    int hari1 = 1, bulan1 = 2, tahun1 = 2022,hari2, bulan2,tahun2;
    cout << "Tanggal : 1 Februari 2022" << endl;
    cout << string(70, '=') << endl;
    cout << left << "Selamat Datang Di Perputakaan!!" << endl;
    cout << string(70, '=') << endl;
    cout << setw(7) << "ISBN" << setw(25) << "Judul" << setw(20) << "Penerbit" << setw(20) << "Jumlah Buku" << endl;
    cout << string(70, '=') << endl;
    for(int i = 0; i < 15; i++) {
        cout << setw(7) << buku[i].ISBN << setw(25) << buku[i].judul << setw(20) << buku[i].Penerbit << setw(20) << buku[i].jumlah << endl;
    }
    cout << string(70, '=') << endl;
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
    cout << "3. Mengembailkan Buku" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilihlah (1/2/3):"; cin >> pil;

    string namabuku;
    if(pil == 1){
        int pilbuku;
        cout << "pilihlah buka diatas untuk dibaca atau dilihat \n"
        << "Pilih Buku (1/2/3/4/5/6/7/8/9/10) :"; cin >> pilbuku;
        cout << endl << endl << endl << endl;   
        if(pilbuku == 1){
            ifstream bukaFile("Buku/Anak Semua Bangsa - Pramoedya Ananta.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 2){
            ifstream bukaFile("Buku/Ayah - Andrea Hirata.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 3){
            ifstream bukaFile("Buku/Bumi Manusia - Pramoedya Ananta Toer.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 4){
            ifstream bukaFile("Buku/Cinta Brontosaurus - Raditya Dika.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 5){
            ifstream bukaFile("Buku/Hafalan shalat Delisa - Tere liye.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 6){
            ifstream bukaFile("Buku/Hujan - Tere Liye.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 7){
            ifstream bukaFile("Buku/Koala Kumal - Raditya Dika.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 8){
            ifstream bukaFile("Buku/Laskar Pelangi -  Andrea Hirata.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 9){
            ifstream bukaFile("Buku/Negeri 5 Menara - Ahmad Fuadi.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 10){
            ifstream bukaFile("Buku/Orang-Orang Biasa - Andrea Hirata.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 11){
            ifstream bukaFile("Buku/Perahu Kertas - Dee Lestari.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 12){
            ifstream bukaFile("Buku/Pulang - Tere Liye.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 13){
            ifstream bukaFile("Buku/Sang Pemimpi - Andrea Hirata.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 14){
            ifstream bukaFile("Buku/Si Anak Pintar - Tere Liye.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
        else if(pilbuku == 15){
            ifstream bukaFile("Buku/Supernova - Dee Lestari.txt");
            if (bukaFile.is_open()) {
                string line;
                while (getline(bukaFile, line)) {
                    cout << line << endl;
                }
                bukaFile.close();
            }
            else {
                cout << "Tidak dapat membuka file" << endl;
            }
        }
    }
    else if(pil == 2){

        cout << "formulir peminjaman" << endl;
        cout << "Nama : "; getline(cin, nama);
        cout << "Buku yang dipinjam : "; cin >> namabuku;
        bool found = false;
        for(int i = 0; i < 10; i++) {
            if(siswa[i].nama == nama) {
                found = true;
                break;
            }
        }
        for(int i = 0; i < 15; i++) {
            if(buku[i].judul == namabuku) {
                found = true;
                buku[i].jumlah -= 1;
                break;
            }
        }
        if(found) {

            cout << "Peminjaman berhasil dilakukan" << endl;
        }
        else {
            cout << "Buku atau Nama tidak tersedia" << endl;
        }
    }
    else if(pil == 3){

        cout << "formulir pengembalian" << endl;
        cout << "Nama : "; getline(cin, nama);
        cout << "Buku yang dikembalikan : "; cin >> namabuku;
        bool found = false;
        for(int i = 0; i < 10; i++) {
            if(siswa[i].nama == nama) {
            found = true;
            break;
            }
        }
    
        for(int i = 0; i < 15; i++) {
            if(buku[i].judul == namabuku) {
                if(buku[i].jumlah > 0 && buku[i].jumlah < 3) {
                    buku[i].jumlah += 1;
                    found = true;
                    break;
                }
                found = false;
                break;
            }
        }
        
        if(found) {

            cout << "Pengembalian berhasil dilakukan" << endl;
        }
        else {
            cout << "Error" << endl;
        }
    }
        

    return 0;
}
