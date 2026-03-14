#include <stdio.h>

int main() {
    int N, kodeKategori;

    // 1. Input jumlah total jenis barang
    printf("Masukkan jumlah total jenis data (N): ");
    scanf("%d", &N);

    // Inisialisasi array berdasarkan jumlah N
    int stok[N];

    // 2. Input deret stok barang
    printf("Masukkan deret stok barang (pisahkan dengan spasi):\n");
    for (int i = 0; i < N; i++) {
        printf("Stok barang ke-%d: ", i + 1);
        scanf("%d", &stok[i]);
    }

    // 3. Input kode kategori yang dicari
    printf("\n--- Pilih Kategori ---\n");
    printf("Masukkan kode kategori barang (1-%d): ", N);
    scanf("%d", &kodeKategori);

    // 4. Menentukan dan menampilkan hasil
    // Gunakan (kodeKategori - 1) karena array mulai dari indeks 0
    if (kodeKategori >= 1 && kodeKategori <= N) {
        printf("\nTotal stok untuk kategori kode %d adalah: %d pcs\n", 
                kodeKategori, stok[kodeKategori - 1]);
    } else {
        printf("\nMaaf, kode kategori tidak valid!\n");
    }

    return 0;
}