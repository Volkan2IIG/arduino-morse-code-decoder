# Arduino Morse Code Decoder

Bu proje, bir Arduino mikrodenetleyicisi ile buton aracılığıyla girilen Morse kodunu çözerek harfler, sayılar veya boşlukları seri monitöre yazdırır. Butona kısa basarak nokta (`.`), daha uzun basarak çizgi (`-`) oluşturabilirsiniz. Ayrıca, butona 3 saniye boyunca basılı tutarak bir boşluk ekleyebilirsiniz.

## Özellikler

- **Morse Kodu Girişi:** Bir buton aracılığıyla Morse kodu girişi yapılır.
- **LED Geri Bildirimi:** Her buton basışı sırasında bir LED yanar, basma süresi boyunca yanık kalır.
- **Harf ve Sayı Çözümü:** Girilen Morse kodu, harf veya sayıya dönüştürülerek seri monitöre yazdırılır.
- **Boşluk Ekleme:** Butona 3 saniye veya daha uzun süre basıldığında, kelimeler arası boşluk eklenir.
[Uploading mors.ino…]()

## Donanım Gereksinimleri

- Arduino (UNO, Nano, vb.)
- 1 adet buton
- 1 adet LED
- 1 adet 220 ohm direnç (LED için)
- Jumper kabloları
- Breadboard (opsiyonel)

## Devre Şeması

1. **LED:** LED'in uzun bacağını (anod) 220 ohm direnç üzerinden Arduino'nun `13` numaralı pinine, kısa bacağını (katod) ise GND'ye bağlayın.
2. **Buton:** Bir buton bacağını Arduino'nun `7` numaralı pinine, diğer bacağını GND'ye bağlayın. Ayrıca `7` numaralı pini `INPUT_PULLUP` modunda kullanarak dahili pull-up direnci aktif hale getirin.
