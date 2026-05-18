#!/bin/bash

# Bu betik projeyi derler ve basarili olursa arayuzu calistirir.

echo "[*] C++ motoru derleniyor..."

cd build
cmake ..
make

if [ $? -eq 0 ]; then
    echo "[+] Derleme basarili! Arayuz baslatiliyor..."
    cd ../gui
    python3 arayuz.py
else
    echo "[-] Derleme hatasi! Lutfen kodlari kontrol edin."
fi