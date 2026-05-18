import tkinter as tk
from tkinter import messagebox
import subprocess
from datetime import datetime
import os
import hashlib # Yeni eklendi: Hash (dijital muhur) islemleri icin

# Bu sinif kullaniciya siber yesil temali adli bilisim arayuzunu sunar.
class MatrixAnaPencere:
    def __init__(self, kok):
        self.kok = kok
        self.kok.title("AdliMudahele - Canli Ag Delili")
        self.kok.configure(bg="black")
        
        self.metinEkrani = tk.Text(self.kok, bg="black", fg="#00FF00", font=("Consolas", 12))
        self.metinEkrani.pack(expand=True, fill="both")
        
        self.altPanel = tk.Frame(self.kok, bg="black")
        self.altPanel.pack(fill="x", side="bottom", pady=10)
        
        self.kaydetButonu = tk.Button(self.altPanel, text="RAPORU KAYDET VE MUHURLE", bg="black", fg="#00FF00", activebackground="#00FF00", activeforeground="black", font=("Consolas", 12, "bold"), command=self.raporuKaydet)
        self.kaydetButonu.pack(side="right", padx=20)
        
        self.motoruCalistir()

    # Arka plandaki C++ motorunu calistirir ve ciktisini arayuze yazar.
    def motoruCalistir(self):
        try:
            surec = subprocess.Popen(["../bin/AdliMudaheleMotoru"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            cikti, hata = surec.communicate()
            
            if hata:
                self.metinEkrani.insert(tk.END, "Motor Hatasi:\n" + hata)
            else:
                self.metinEkrani.insert(tk.END, "--- ANLIK AG DURUMU (C++ MOTORU) ---\n\n")
                self.metinEkrani.insert(tk.END, cikti)
        except Exception as e:
            self.metinEkrani.insert(tk.END, "C++ motoru calistirilamadi. Lutfen derleme adimini yaptiginiza emin olun.\nHata Detayi: " + str(e))

    # Ekrandaki adli bilisim raporunu kaydeder ve SHA-256 ile muhurler.
    def raporuKaydet(self):
        raporIcerigi = self.metinEkrani.get("1.0", tk.END)
        zamanDamgasi = datetime.now().strftime("%Y%m%d_%H%M%S")
        dosyaAdi = f"../veri/adli_rapor_{zamanDamgasi}.txt"
        muhurDosyaAdi = f"../veri/adli_rapor_{zamanDamgasi}_muhur.sha256"
        
        try:
            os.makedirs("../veri", exist_ok=True)
            
            # 1. Raporu normal metin dosyasi olarak kaydet
            with open(dosyaAdi, "w", encoding="utf-8") as dosya:
                dosya.write(raporIcerigi)
                
            # 2. Raporun SHA-256 hash (dijital parmak izi) degerini hesapla
            raporBaytlari = raporIcerigi.encode('utf-8')
            hashDegeri = hashlib.sha256(raporBaytlari).hexdigest()
            
            # 3. Hash degerini muhur dosyasi olarak ayni dizine kaydet
            with open(muhurDosyaAdi, "w", encoding="utf-8") as muhurDosyasi:
                muhurDosyasi.write(f"{hashDegeri} *adli_rapor_{zamanDamgasi}.txt\n")
                
            messagebox.showinfo("Adli Muhur Basarili", f"Rapor ve Dijital Muhur kaydedildi:\n\n1) {dosyaAdi}\n2) {muhurDosyaAdi}")
        except Exception as e:
            messagebox.showerror("Hata", f"Kayit sirasinda hata olustu:\n{str(e)}")

# Arayuzu baslatan ana fonksiyondur.
def ana():
    kok = tk.Tk()
    kok.geometry("900x650")
    uygulama = MatrixAnaPencere(kok)
    kok.mainloop()

if __name__ == "__main__":
    ana()