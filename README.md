# Labview Ve Arduino Kullanarak IR Sensörden veri Okuma
Bu projede iki adet IR sensör kullanılarak mesafe ve zaman bilgilerine göre hız tespiti yapılmıştır. Bu proje EDS(Elektronik Denetleme Sistemi)'nin çalışmasının çok daha temel halini anlamak için hazırlanmıştır. Projede devre kurulumu, Arduino programlama ve LabVIEW Arduiono seri haberleşme ve LabVIEW arayüz tasarımı olmak üzere açıklanacaktır.
## 1 - DEVRE ŞEMASI
![resim](https://github.com/sevvaleminekucuk/labviewProje/blob/main/ircircuit.png)

Devrede iki adet IR sensör kullanılmıştır. Bu iki sensör de aracı algıladığı zaman saat bilgisi tutacaktır. Bu iki zaman arasındaki mutlak fark alınarak çok basit bir şekilde x = v*t formülü kullanılarak hız bilgisi çekilecektir.

#### IR SENSOR
![resim](https://github.com/sevvaleminekucuk/labviewProje/blob/main/irsens%C3%B6r.jpg)

Resimden de görüldüğü gibi bu sensörde Vcc(5V), GND ve çıkış ucu olmak üzere üç pin bulunmaktadır. Sensör veri okurken kendi üzerindeki dahili ledi yakarak çalıştığını kullanıcıya bildirmektedir. Veri okurken 0, okumazken ise 1 değerini döndürmektedir.

## 2 - ARDUİNO PROGRAMLAMA

Aşağıdaki kodlar sayesinde aracın her sensörden geçerkenki zaman bilgisi alınacaktır ve total zaman hesaplanacaktır.

`time1 = millis();`
`time2 = millis();`


İki sensör arasındaki mesafe 20cm olarak ayarlanmıştır. hız değeri km/h cinsinden verileceği için aşağıdaki dönüştürmeler yapılmıştır.

```
    time = time / 1000; // milisaniye saniye cinsinden hesaplanıyor
    speed = (d / time); // hız = mesafe / zaman
    speed = speed * 3600; //saniye saate çevriliyor 60saniye --> 1dk / ? saniye --> 60dk 
    speed = speed / 100000; //santimetre kilometreye çevriliyor
```

son olarak yüksek hız kriteri belirlenip kod tamamlanmıştır.

```
if(speed > 25){Serial.println("yuksek hiz"); digitalWrite(buzzer, HIGH);}
    else{Serial.println("normal hiz");}
```

## 3 - DEVRE UYGULAMASI

![resim](https://github.com/sevvaleminekucuk/labviewProje/blob/main/realcircuit.jpg)

Görüldüğü üzere iki sensör arası yaklaşık 20 cm olarak belirlenmiştir.

Devrenin işleyişini daha net anlayabilmek için video ekledim. Videonun sesini açmayı unutmayın:)

https://user-images.githubusercontent.com/96637473/172067531-ccb3f5f5-0f63-4cfd-bdab-48a139b31a78.mp4

 
## 4- ARDUİNO LABVİEW SERİ HABERLEŞME

Seri haberleşme için VISA kullanılmıştır. Bu tool'u programı kurarken indirebilir veya sonradan ekleyebilirsiniz.
![resim](https://github.com/sevvaleminekucuk/labviewProje/blob/main/serialcommunication.png)

## 5 - LABVİEW İLE ARAYÜZ
![resim](https://github.com/sevvaleminekucuk/labviewProje/blob/main/labviewinterface.png)
