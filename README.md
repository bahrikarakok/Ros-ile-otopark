# ROS Destekli Akıllı Otopark Simülasyon Sistemi 🚗🅿️

Bu proje, **Webots R2025a** simülasyon ortamı üzerinde geliştirilmiş, mesafe sensörleri ile donatılmış anlık doluluk tespiti yapabilen akıllı bir otopark yönetim sistemidir. İlk aşamada sistemin maksimum kararlılıkta çalışması amacıyla Webots'un yerel C API'si kullanılarak bir üst akıl (`Supervisor`) mimarisi inşa edilmiştir. İlerleyen aşamalarda bu verilerin robotik işletim sistemi (ROS) mimarisine aktarılması planlanmaktadır.

---

## 🚀 Proje Özellikleri
* **Kararlı C Tabanlı Kontrolcü:** Python/kütüphane bağımlılıklarından kaynaklanan simülasyon çökmelerini (crash) engellemek amacıyla doğrudan Webots çekirdeğinde koşan `c_otopark_manager` kontrolcüsü.
* **10 Kanallı Mesafe Sensörü Dizilimi:** Otopark slotlarının (Tesla, BMW, Traktör vb.) anlık doluluk durumunu üst açıdan lazer ışınları (`DistanceSensor`) ile milisaniyelik olarak tarayan sistem.
* **Dinamik Eşik Değeri Analizi:** Sensör verilerini anlık analiz ederek 1.8 metrenin altındaki engelleri `DOLU`, üstündeki boşlukları `BOS` olarak konsola raporlayan mantıksal mimari.

---

## 📁 Proje Yapısı
```text
Ros-ile-otopark/
│
├── controllers/
│   └── c_otopark_manager/
│       └── c_otopark_manager.c   # Slot durumlarını tarayan ana C kodu
│
├── worlds/
│   └── otopark.wbt               # 3D Otopark dünyası, araçlar ve sensör dizilimleri
│
├── .gitignore                    # Webots önbellek (cache) engelleyici dosya
└── README.md                     # Proje dokümantasyonu
