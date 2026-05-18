#include "../include/tarayiciAnalizi.h"
#include <array>
#include <memory>
#include <stdexcept>

// Tarayici veritabanini guvenli sekilde kopyalayip son girilen URL'leri listeler.
std::string TarayiciAnalizi::sonSiteleriGetir() {
    std::string sonucVerisi = "\n--- TARAYICI ANALIZI (FIREFOX SON 10 URL) ---\n";
    std::array<char, 256> tampon;
    
    // sudo ile calistiginda asil kullanicinin ev dizinini bulmak icin $SUDO_USER kullanilir.
    std::string komut = "ASIL_KULLANICI=${SUDO_USER:-$USER}; EV_DIZINI=$(getent passwd $ASIL_KULLANICI | cut -d: -f6); PROFILE_DB=$(find $EV_DIZINI/.mozilla/firefox $EV_DIZINI/snap/firefox/common/.mozilla/firefox -name 'places.sqlite' 2>/dev/null | head -n 1); if [ -n \"$PROFILE_DB\" ]; then cp \"$PROFILE_DB\" /tmp/adli_places.sqlite 2>/dev/null && sqlite3 /tmp/adli_places.sqlite 'SELECT url FROM moz_places WHERE last_visit_date IS NOT NULL ORDER BY last_visit_date DESC LIMIT 10;' 2>/dev/null; rm -f /tmp/adli_places.sqlite; fi";
    
    std::shared_ptr<FILE> boru(popen(komut.c_str(), "r"), pclose);
    
    if (!boru) {
        return sonucVerisi + "[-] HATA: Tarayici borusu acilamadi.\n";
    }
    
    bool veriBulundu = false;
    while (fgets(tampon.data(), tampon.size(), boru.get()) != nullptr) {
        sonucVerisi += tampon.data();
        veriBulundu = true;
    }
    
    if (!veriBulundu) {
        sonucVerisi += "[-] Gecmis bulunamadi veya sqlite3 araci kurulu degil.\n";
    }
    
    return sonucVerisi;
}