#include<Servo.h> //Servo ile ilgili fonksiyonları içeren Servo kütüphanesini çağırdık.
Servo edip; //edip isimli bir Servo nesnesi oluşturduk.
void setup() {
  // put your setup code here, to run once:
edip.attach(5); //edip isimli Servo nesnesini 5 numaralı pine bağladık.(Servonun bağlandığı pin PWM destekli olmak zorunda.)
Serial.begin(9600); //Seri haberleşme başlat.
edip.write(0); //En başta edipi 0 dereceye çek.
}

void loop() {
  for(int i; i<180; i++) { //for döngüsü ile 0-180 arasındaki bütün açıları tara
    edip.write(i); //döngünün o andaki "i" değerini servonun açısı olarak gönder.
    delay(5);
    Serial.println(i);
    if(i==179) { //i 179 olduğunda 
       for(int j=180; j>0; j--){ //180'den 0'a geri dönmeye başla.
      edip.write(j); //döngünün o andaki "j" değerini servonun açısı olarak gönder.
      delay(5);
      Serial.println(j);
    }
      }
    }
 
  // put your main code here, to run repeatedly:

}
