#ifndef TARAYICI_ANALIZI_H
#define TARAYICI_ANALIZI_H

#include <string>

// Bu sinif sistemdeki web tarayici gecmisini (phishing analizi icin) tarar.
class TarayiciAnalizi {
public:
    // Tarayici veritabanini guvenli sekilde kopyalayip son girilen URL'leri listeler.
    std::string sonSiteleriGetir();
};

#endif