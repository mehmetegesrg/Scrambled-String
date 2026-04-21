# 🌳 Scramble String Analyzer (C Implementation)

Bu proje, bilgisayar bilimlerinde bilinen "Scramble String" (Karmaşık Metin) probleminin C programlama dili ile çözülmesini ve algoritma optimizasyonunu (Brute-Force vs. Backtracking) içermektedir.

## 📖 Problem Tanımı
İki farklı metin verildiğinde, birinci metnin rastgele noktalardan ikili ağaç (binary tree) yapısıyla alt düğümlere ayrılması ve bu düğümlerin kendi aralarında **yer değiştirerek (swap)** veya **sabit kalarak** ikinci metni oluşturup oluşturamayacağının sınanmasıdır. 

Algoritma, metinler tek bir karaktere inene kadar özyineli (recursive) olarak çalışır.

## 🚀 Algoritma Yaklaşımları ve Optimizasyon

Proje kapsamında problem iki farklı yöntemle çözülmüş ve sistem bellek (RAM) kullanımı ile zaman karmaşıklığı analiz edilmiştir:

### 1. Kaba Kuvvet (Brute-Force) Yöntemi
- **Mantık:** Metni her olası `i` indisinden böler ve alt ağaçlarda eşleşme olup olmadığını hiçbir kısıtlama olmadan özyineli olarak dener.
- **Zaman Karmaşıklığı:** Üstel — `O(5^N)`
- **Dezavantaj:** Eşleşme ihtimali olmayan karakter bloklarını dahi sonuna kadar hesapladığı için uzun metinlerde ciddi performans kaybına ve yığıt taşmasına (Stack Overflow) yol açar.

### 2. Böl ve Fethet & Geri İzleme (Backtracking / Pruning)
- **Mantık:** Brute-Force'un hantallığını aşmak için **Budama (Pruning)** tekniği kullanılmıştır.
- **Nasıl Çalışır?** Alt ağaçlara inmeden hemen önce, 256 elemanlı (ASCII standartlarına uygun) bir frekans dizisi oluşturulur. Birinci metnin karakterleri dizide artırılırken, ikinci metnin karakterleri azaltılır. Eğer dizide sıfırdan farklı bir değer kalırsa, bu iki parçanın "Anagram" olmadığı anlaşılır.
- **Performans Kazancı:** Anagram olmayan dallar tespit edildiğinde özyineli işlem anında iptal edilir (`return false;`). Böylece gereksiz ağaç dallanmaları başlamadan kesilerek sistem kaynağı korunur.

## 🛠️ Kurulum ve Çalıştırma

Projeyi yerel bilgisayarınızda çalıştırmak için sisteminizde bir C derleyicisi (örneğin `GCC`) kurulu olmalıdır.

1. Repoyu klonlayın:
   ```bash
   git clone [https://github.com/kullanici-adiniz/scramble-string-analyzer.git](https://github.com/kullanici-adiniz/scramble-string-analyzer.git)

2. Proje dizinine gidin ve kodu derleyin:
```bash
gcc scramble.c -o scramble
```
3. Derlenen dosyayı çalıştırın:
```bash
./scramble
```

💻 Kullanılan Teknolojiler
Dil: C (İşaretçi Aritmetiği ve Dinamik Bellek Yönetimi)

Veri Yapıları: İkili Ağaçlar (Binary Trees), Diziler (Arrays)

Kavramlar: Özyineleme (Recursion), Divide & Conquer, Backtracking, Pruning

Geliştirici: Mehmet Ege Sarıgöl

Kırklareli Üniversitesi - Yazılım Mühendisliği
