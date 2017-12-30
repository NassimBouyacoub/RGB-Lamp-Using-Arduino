/*
  Utilisation LED RGB commande simple (tout ou rien)
  modified 21 Nov 2015
  by Jérémy Dulout
*/

  const int ledRouge=11; 
  const int ledVert=10; 
  const int ledBleu=9;

// Initialisation des pattes 9, 10 et 11 de l'arduino
void setup() {
  pinMode(ledRouge, OUTPUT);  //Patte 11 reliée à la cathode de la LED rouge
  pinMode(ledVert, OUTPUT);  //Patte 10 reliée à la cathode de la LED vert
  pinMode(ledBleu, OUTPUT);  //Patte 9 reliée à la cathode de la LED bleu
}

// Actions à faire en boucle
void loop() {
  //Couleur rouge 
  CommandePWM_ON(ledRouge);
  delay(150);
  CommandePWM_OFF(ledRouge);
  //Couleur verte     
  CommandePWM_ON(ledVert);
  delay(150);   
  CommandePWM_OFF(ledVert); 
  //Couleur bleue    
  CommandePWM_ON(ledBleu);    
  delay(150);
  //Couleur cyan (Vert+Bleu)
  CommandePWM_ON(ledVert);
  delay(250);
  CommandePWM_OFF(ledBleu);   
  //Couleur jaune (Rouge+Vert)   
  CommandePWM_ON(ledRouge);
  delay(250);
  CommandePWM_OFF(ledVert);
  //Couleur magenta (Rouge+Bleu)
  CommandePWM_ON(ledBleu);
  delay(250);
  //Couleur blanche (Vert+Rouge+Bleu)
  CommandePWM_ON(ledVert);
  delay(250);
  CommandePWM_OFF(ledVert);
  CommandePWM_OFF(ledRouge);
  CommandePWM_OFF(ledBleu); 
}

//fonction qui permet d'augmenter progressivement le courant qui traverse la led
void CommandePWM_ON(int NumPin)  {
  for( int i = 0; i <= 255; i++ ) {
        analogWrite(NumPin, i); 
        delay(5);
   } 
} 

//fonction qui permet de diminuer progressivement le courant qui traverse la led 
void CommandePWM_OFF(int NumPin) {
for( int i = 255; i >= 0; i-- ) {
        analogWrite(NumPin, i);
        delay(5);
  }
}
