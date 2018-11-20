const byte trig=11; //Sensörün "trig" pinine bağlamak için 11. pini seçtik.
const byte echo=10; //Sensörün "echo" pinine bağlamak için 10. pini seçtik.
int sure; //süreyi saklamak için bir değişken atadık.
const float hiz=0.034; //Ses hızını cm/us olarak hiz değişkenine atadık.
float mesafe; //sonradan mesafeyi saklamak için bir değişken atadık.
const byte led1=8; //1. ledi bağlayacağımız bacağı 8 olarak seçtik.
const byte led2=9; //2. ledi bağlayacağımız bacağı 9 olarak seçtik.

void setup() {
  pinMode(trig,OUTPUT); //ses sinyalini göndermek için trig pinine işaret göndereceğiz. Bu nedenle trig pini çıkış atadık.
  pinMode(echo,INPUT); //echodaki yüksek işaretli pinin süresini okuyacağımız için bu pini giriş olarak atadık.
  Serial.begin(9600); //Seri haberleşme başlat.

}

void loop() {
  //Bu 3 satırda datasheette yazdığı üzere trig pinine 10us lik bir 5V sinyal gönderdik.
  //Meraklıları için datasheet de GitHub'da.
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  sure=pulseIn(echo,HIGH); //pulseIn komutu bağlı olan pindeki sinyalin ne kadar süre 5V (HIGH) veya 0V (LOW)
                           //olduğunu bize mikrosaniye cinsinden verir. Biz de bu süreyi "sure" değişkenine atadık.
  mesafe=hiz*sure/2;       //Mesafeyi hesaplamak için x=v*t, burada ölçtüğümüz süre gidip gelmesi içindi bu sebeple ikiye böldük.
  Serial.println(mesafe);  //Mesafeyi seri ekrana yazdır.
  delay(100);
  if(mesafe<10) {           //Mesafe 10 cm'den küçükse
    digitalWrite(led1,HIGH); //led1'i yak, led2'yi söndür.
    digitalWrite(led2,LOW);
    }
  else {
    digitalWrite(led1,LOW);   //Diğer türlü (yani mesafe 10 cm'den büyükse)
    digitalWrite(led2,HIGH);  //led2'yi yak led1'i söndür.
    }
}
