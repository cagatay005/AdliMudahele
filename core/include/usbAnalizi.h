#ifndef USB_ANALIZI_H
#define USB_ANALIZI_H

#include <string>

// Bu sinif sisteme takilan USB belleklerin izlerini tarar.
class UsbAnalizi {
public:
    // Cekirdek (kernel) loglarindan son takilan USB cihazlari listeler.
    std::string usbIzleriniTara();
};

#endif