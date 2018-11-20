const byte led=13; //ledi bağlamak için 13. bacağı seçtik.
const byte button=9; //buttonu bağlamak için 9. bacağı seçtik.
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT); //led pini çıkış
  pinMode(button,INPUT); //buton pini giriş

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button)==LOW) { //eğer buton pini DÜŞÜK(LOW/0V) ise
    digitalWrite(led,HIGH); //led pinine 5V ver.
    }
  else {          //Diğer türlü
    digitalWrite(led,LOW); //LED pinine 0V ver.
    }

}
