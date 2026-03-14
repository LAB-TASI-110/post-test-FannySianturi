#include <stdio.h>

int main() {
    int jam, menit;
    int pilihan, jumlah_porsi, jumlah_jenis_menu;
    int total_bayar = 0;

    printf("=== Sistem Kafetaria IT Del ===\n");
    
    // 1. Input Jam Operasional
    printf("Masukkan jam saat ini (format 24 jam, contoh 08 30): ");
    scanf("%d %d", &jam, &menit);

    // Cek Jam Operasional (08:00 - 17:00)
    if (jam < 8 || jam >= 17) {
        printf("\nMaaf, Kafetaria saat ini TUTUP (08:00 - 17:00).\n");
        return 0;
    }

    printf("\nSelamat Datang! Silahkan lihat menu di bawah:\n");
    printf("------------------------------------------\n");
    printf("1. PKL (10rb)          6. Nugget (15rb)\n");
    printf("2. Piscok (10rb)       7. Matcha (8rb)\n");
    printf("3. Batagor (10rb)      8. Nasi Goreng (20rb)\n");
    printf("4. Roti Ayam (15rb)    9. Mie Goreng (20rb)\n");
    printf("5. Sosis (15rb)        10. Sandwich (13rb)\n");
    printf("------------------------------------------\n");

    // 2. Input berapa banyak jenis menu yang mau dibeli
    printf("Berapa jenis menu yang ingin Anda pesan? ");
    scanf("%d", &jumlah_jenis_menu);

    // 3. Perulangan berdasarkan jumlah jenis menu
    for (int i = 1; i <= jumlah_jenis_menu; i++) {
        printf("\nPesanan ke-%d\n", i);
        printf("Pilih nomor menu (1-10): ");
        scanf("%d", &pilihan);
        
        printf("Masukkan jumlah porsi: ");
        scanf("%d", &jumlah_porsi);

        // Logika penghitungan harga
        if (pilihan == 1 || pilihan == 2 || pilihan == 3) {
            total_bayar += 10000 * jumlah_porsi;
        } else if (pilihan == 4 || pilihan == 5 || pilihan == 6) {
            total_bayar += 15000 * jumlah_porsi;
        } else if (pilihan == 7) {
            total_bayar += 8000 * jumlah_porsi;
        } else if (pilihan == 8 || pilihan == 9) {
            total_bayar += 20000 * jumlah_porsi;
        } else if (pilihan == 10) {
            total_bayar += 13000 * jumlah_porsi;
        } else {
            printf("Nomor menu tidak valid! Pesanan ini dilewati.\n");
        }
    }

    // 4. Output Total
    printf("\n==============================\n");
    printf("TOTAL PEMBAYARAN: Rp %d\n", total_bayar);
    printf("Terima kasih telah memesan!\n");
    printf("==============================\n");

    return 0;
}