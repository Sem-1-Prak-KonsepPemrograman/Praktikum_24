#include <stdio.h>

// Fungsi untuk mencari elemen dalam array
// Mengembalikan 1 jika elemen ditemukan, 0 jika tidak
// Menyimpan posisi elemen yang ditemukan dalam array 'dapat'
// Menghitung jumlah elemen yang ditemukan dalam variabel 'C'
int cariElemen(int *arr, int n, int value, int dapat[], int *C) {
    int kond = 0; // Variabel untuk menandakan apakah elemen ditemukan

    // Mengiterasi setiap elemen dalam array untuk mencari nilai yang cocok
    for (int i = 0; i < n; i++) {
        // Membandingkan elemen array dengan nilai yang dicari
        if (*(arr + i) == value) {
            dapat[i] = i + 1; // Menyimpan posisi elemen yang ditemukan (1-based index)
            *C += 1; // Menambah jumlah elemen yang ditemukan
            kond = 1; // Menandakan elemen ditemukan
        }
    }
    return kond; // Mengembalikan 1 jika ditemukan, 0 jika tidak
}

int main() {
    // Praktikum 3, no. 1
    printf("---------------------------------------------------------------------------------\n");
    printf("Program untuk mencari elemen dalam array dan menampilkan posisi elemen yang ditemukan\n");
    printf("---------------------------------------------------------------------------------\n\n");

    // Deklarasi variabel
    int arr[] = {2, 2, 3, 4, 5}, cari;
    int size = sizeof(arr) / sizeof(arr[0]); // Menghitung jumlah elemen dalam array
    int dapat[size], count = 0, *C = &count; // Array untuk menyimpan posisi elemen yang ditemukan, variabel count untuk menghitung jumlah elemen yang ditemukan

    // Meminta input dari pengguna untuk elemen yang ingin dicari
    printf("Masukkan elemen yang ingin dicari: ");
    scanf("%d", &cari);

    // Memanggil fungsi cariElemen untuk mencari elemen dalam array
    int cariStatus = cariElemen(arr, size, cari, dapat, C);

    // Jika elemen ditemukan, tampilkan posisi-posisi elemen yang ditemukan
    if (cariStatus == 1) {
        printf("Elemen yang anda cari ditemukan pada elemen ke: ");
        for (int i = 0; i < *C; i++) {
            printf("%d ", dapat[i]); // Menampilkan posisi elemen yang ditemukan
        }
    } else {
        // Jika elemen tidak ditemukan
        printf("Elemen yang anda cari tidak dapat ditemukan\n");
    }

    return 0; // Mengembalikan 0 untuk menandakan program berhasil
}
