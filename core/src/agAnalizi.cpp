#include "../include/agAnalizi.h"
#include <array>
#include <memory>
#include <stdexcept>

// C++ hizinda calisan ana tarama fonksiyonudur.
std::string AgAnalizi::aktifBaglantilariGetir() {
    std::string sonucVerisi = "";
    std::array<char, 128> tampon;
    
    // Ubuntu uzerinde anlik tcp ve udp baglantilarini hizlica ceker.
    std::shared_ptr<FILE> boru(popen("ss -tupn", "r"), pclose);
    
    if (!boru) {
        throw std::runtime_error("Sistem borusu (pipe) acilamadi.");
    }
    
    // Gelen veriyi satir satir okuyup sonuc string degiskenine ekler.
    while (fgets(tampon.data(), tampon.size(), boru.get()) != nullptr) {
        sonucVerisi += tampon.data();
    }
    
    return sonucVerisi;
}