#include "../include/usbAnalizi.h"
#include <array>
#include <memory>

// Cekirdek (kernel) loglarindan son takilan USB cihazlari listeler.
std::string UsbAnalizi::usbIzleriniTara() {
    std::string sonucVerisi = "\n--- USB VERI SIZINTISI (SON BAGLANAN CIHAZLAR) ---\n";
    std::array<char, 256> tampon;
    
    // dmesg ile kernel loglarindan USB uretici ve seri numaralarini ceker.
    std::string komut = "dmesg 2>/dev/null | grep -i 'usb' | grep -E 'Product:|Manufacturer:|SerialNumber:' | tail -n 12";
    
    std::shared_ptr<FILE> boru(popen(komut.c_str(), "r"), pclose);
    bool veriBulundu = false;
    
    if (boru) {
        while (fgets(tampon.data(), tampon.size(), boru.get()) != nullptr) {
            sonucVerisi += tampon.data();
            veriBulundu = true;
        }
    }
    
    if (!veriBulundu) {
        sonucVerisi += "[-] Yakin zamanda takilmis USB izine rastlanmadi veya loglari okumak icin 'sudo' yetkisi gerekiyor.\n";
    }
    
    return sonucVerisi;
}