int miktar;

void setup() {

  // put your setup code here, to run once:
pinMode(11,OUTPUT); //11. pin çıkış
Serial.begin(9600); //Seri haberleşme başlat.
pinMode(3,INPUT); //3. pini giriş olarak ata, burada button olacak.
}

void loop() {
  attachInterrupt(digitalPinToInterrupt(3),dur,LOW); //3 numaralı pin LOW (0V) olduğu zaman program akışını KES ve "dur" fonksiyonuna ATLA.
  for(int i=0; i<=255; i++) { //0-255 değerleri arasında döngü başlat. Bu döngü i=0 dan i=255 olana kadar (256 kez) gerçekleşir.
    analogWrite(11,i); //i'nin değerini 11. pine yaz
    delay(10); //Görebilmemiz için gecikme koy.
    Serial.println(i);
    if(i==255) { //i=255 olmuşsa LED maksimum parlaklığa ulaşmış demektir. Bundan sonra LED'i söndürmeye başla.
      for(int j=255; j>=0; j--){ //255-0 değerleri arasında döngü başlat. Bu döngü j=255 ten j=0 olana kadar (256 kez) gerçekleşir.
        analogWrite(11,j); //j'nin değerini 11. pine yaz
        delay(10); //Görebilmemiz için gecikme koy.
        Serial.println(j); //j değerini yazdır.
        }
      }
    }
  // put your main code here, to run repeatedly:

}

void dur() {//Kendimiz "dur" isimli bir fonksiyon tanımladık.
  digitalWrite(11,LOW); //11. pini 0V Yap.
  }
