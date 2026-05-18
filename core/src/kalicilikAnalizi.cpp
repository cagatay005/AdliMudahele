#include "../include/kalicilikAnalizi.h"
#include <fstream>
#include <string>

// Zamanlanmis gorevler (cron) gibi supheli baslangic noktalarini tarar.
std::string KalicilikAnalizi::supheliGorevleriTara() {
    std::string sonucVerisi = "\n--- KALICILIK ANALIZI (AKTIF CRON GOREVLERI) ---\n";
    std::ifstream cronDosyasi("/etc/crontab");

    if (cronDosyasi.is_open()) {
        std::string satir;
        while (std::getline(cronDosyasi, satir)) {
            // Yorum satiri olmayan ve bos olmayan cron kayitlarini yakala
            if (!satir.empty() && satir[0] != '#') {
                sonucVerisi += satir + "\n";
            }
        }
        cronDosyasi.close();
    } else {
        sonucVerisi += "[-] HATA: Crontab dosyasi okunamadi (Yetki gerekebilir).\n";
    }

    return sonucVerisi;
}