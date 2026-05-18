#ifndef BELLEK_TARAMASI_H
#define BELLEK_TARAMASI_H

#include <string>

// Bu sinif sistem bellegindeki (RAM) aktif surecleri tarar.
class BellekTaramasi {
public:
    // RAM uzerinde en cok yer kaplayan ve calisan surecleri listeler.
    std::string calisanSurecleriAnalizEt();
};

#endif