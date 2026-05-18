#include "../include/bellekTaramasi.h"
#include <array>
#include <memory>
#include <stdexcept>

// RAM uzerinde en cok yer kaplayan ve calisan surecleri listeler.
std::string BellekTaramasi::calisanSurecleriAnalizEt() {
    std::string sonucVerisi = "\n--- BELLEK TARAMASI (EN YUKSEK RAM KULLANAN ILK 10 SUREC) ---\n";
    std::array<char, 128> tampon;
    
    // Ubuntu'da surecleri bellek kullanimina gore siralayip ilk 10 tanesini cekeriz.
    std::shared_ptr<FILE> boru(popen("ps -eo pid,user,%mem,comm --sort=-%mem | head -n 11", "r"), pclose);
    
    if (!boru) {
        return sonucVerisi + "[-] HATA: Bellek okunamadi.\n";
    }
    
    // Gelen veriyi satir satir okuyup sonuc string degiskenine ekler.
    while (fgets(tampon.data(), tampon.size(), boru.get()) != nullptr) {
        sonucVerisi += tampon.data();
    }
    
    return sonucVerisi;
}