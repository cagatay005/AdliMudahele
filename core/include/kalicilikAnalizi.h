#ifndef KALICILIK_ANALIZI_H
#define KALICILIK_ANALIZI_H

#include <string>

// Bu sinif sistemdeki kalicilik (persistence) izlerini arastirir.
class KalicilikAnalizi {
public:
    // Zamanlanmis gorevler (cron) gibi supheli baslangic noktalarini tarar.
    std::string supheliGorevleriTara();
};

#endif