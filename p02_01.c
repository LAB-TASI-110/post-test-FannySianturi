#include <stdio.h>
#include <string.h>

int main() {
    char kode[5];
    char namaKota[20], keterangan[20];
    float beratButet, beratUcok, totalBerat;
    int ongkirPerKg;
    float totalOngkos, diskon = 0, biayaAkhir;
    int asuransiGratis = 0;

    printf("=== SISTEM PENGIRIMAN DEL EXPRESS ===\n");
    printf("Kode Kota: MDN, BLG, JKT, SBY\n");
    printf("Masukkan Kode Kota Tujuan: ");
    scanf("%s", kode);
    printf("Masukkan Berat Paket Butet (kg): ");
    scanf("%f", &beratButet);

    // Logika Pemilihan Kota
    if (strcmp(kode, "MDN") == 0) {
        strcpy(namaKota, "Medan");
        ongkirPerKg = 8000;
        strcpy(keterangan, "Dalam Pulau");
    } else if (strcmp(kode, "BLG") == 0) {
        strcpy(namaKota, "Balige");
        ongkirPerKg = 5000;
        strcpy(keterangan, "Dalam Pulau");
    } else if (strcmp(kode, "JKT") == 0) {
        strcpy(namaKota, "Jakarta");
        ongkirPerKg = 12000;
        strcpy(keterangan, "Luar Pulau");
        asuransiGratis = 1;
    } else if (strcmp(kode, "SBY") == 0) {
        strcpy(namaKota, "Surabaya");
        ongkirPerKg = 13000;
        strcpy(keterangan, "Luar Pulau");
        asuransiGratis = 1;
    } else {
        printf("Kode kota tidak valid!\n");
        return 1;
    }

    // Perhitungan Berat (Ucok = 3/2 * Butet)
    beratUcok = (3.0 / 2.0) * beratButet;
    totalBerat = beratButet + beratUcok;

    // Perhitungan Ongkos Kirim
    totalOngkos = totalBerat * ongkirPerKg;

    // Logika Promo Lebaran (Diskon 10% jika berat > 10kg)
    if (totalBerat > 10) {
        diskon = 0.10 * totalOngkos;
    }
    
    biayaAkhir = totalOngkos - diskon;

    // Output Struk Pembayaran
    printf("\n======================================\n");
    printf("       STRUK PEMBAYARAN DEL EXPRESS     \n");
    printf("======================================\n");
    printf("Kota Tujuan          : %s (%s)\n", namaKota, keterangan);
    printf("Berat Paket Butet    : %.2f kg\n", beratButet);
    printf("Berat Paket Ucok     : %.2f kg\n", beratUcok);
    printf("Total Berat          : %.2f kg\n", totalBerat);
    printf("--------------------------------------\n");
    printf("Total Ongkos Awal    : Rp %.0f\n", totalOngkos);
    
    // Informasi Promo
    printf("Informasi Promo      : ");
    if (diskon > 0 || asuransiGratis == 1) {
        if (diskon > 0) printf("Diskon Lebaran 10%% ");
        if (asuransiGratis == 1) printf("+ Asuransi Gratis");
    } else {
        printf("Tidak ada promo");
    }
    
    printf("\nPotongan Diskon      : Rp %.0f\n", diskon);
    printf("TOTAL PEMBAYARAN     : Rp %.0f\n", biayaAkhir);
    printf("======================================\n");

    return 0;
}