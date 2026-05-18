#include <iostream>
#include "../include/agAnalizi.h"
#include "../include/kalicilikAnalizi.h"
#include "../include/bellekTaramasi.h"
#include "../include/tarayiciAnalizi.h"
#include "../include/usbAnalizi.h"

// Arka plan C++ motorunun baslangic noktasidir.
int main() {
    AgAnalizi agAnalizoru;
    KalicilikAnalizi kalicilikAnalizoru;
    BellekTaramasi bellekTarayicisi;
    TarayiciAnalizi tarayiciAnalizoru;
    UsbAnalizi usbAnalizoru;
    
    std::string agSonuclari = agAnalizoru.aktifBaglantilariGetir();
    std::string kalicilikSonuclari = kalicilikAnalizoru.supheliGorevleriTara();
    std::string bellekSonuclari = bellekTarayicisi.calisanSurecleriAnalizEt();
    std::string tarayiciSonuclari = tarayiciAnalizoru.sonSiteleriGetir();
    std::string usbSonuclari = usbAnalizoru.usbIzleriniTara();
    
    // Tum adli bilisim bulgulari sirasiyla standart ciktiya basilir.
    std::cout << agSonuclari << std::endl;
    std::cout << kalicilikSonuclari << std::endl;
    std::cout << bellekSonuclari << std::endl;
    std::cout << tarayiciSonuclari << std::endl;
    std::cout << usbSonuclari << std::endl;
    
    return 0;
}