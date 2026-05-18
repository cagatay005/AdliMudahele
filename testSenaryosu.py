import subprocess
import sys

# Bu fonksiyon C++ motorunun baglanti verilerini hatasiz cekip cekmedigini test eder.
def agMotoruTestiYap():
    print("[*] Test basliyor: C++ motoru calistiriliyor...")
    try:
        surec = subprocess.Popen(["./bin/AdliMudaheleMotoru"], stdout=subprocess.PIPE, text=True)
        cikti, _ = surec.communicate()
        
        if len(cikti) > 20:
            print("[+] Test Basarili: Motor veri dondurdu.")
            print(f"[*] Toplam {len(cikti.splitlines())} satir baglanti verisi yakalandi.")
            sys.exit(0)
        else:
            print("[-] Test Basarisiz: Ag verisi alinamadi veya eksik.")
            sys.exit(1)
            
    except FileNotFoundError:
        print("[-] HATA: C++ motoru bulunamadi. Lutfen once CMake ile derleyin.")
        sys.exit(1)

if __name__ == "__main__":
    agMotoruTestiYap()