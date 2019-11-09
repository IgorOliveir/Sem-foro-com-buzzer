/* Semáforo para deficientes visuais
   Alunos: David Teixeira, Artur Capucho, Gabriel Fonseca, Igor Oliveira e Lucas de Carvalho
   Revisão e Data: 1, 07/11/2019
   Data: 02/11/2019
 *************************************************************************
*/
/* Declaração de variáveis */
int pedVermelho = 8;   // Define os pinos que serão utilizados
int pedVerde = 9; 
int carroVermelho = 10;
int carroAmarelo = 11;
int carroVerde = 12;
int buzzer = 7;

 

void setup() // Define os pinos como saidas
{
  /* Setup saídas */
  pinMode(pedVerde,      OUTPUT);
  pinMode(pedVermelho,   OUTPUT);
  pinMode(carroVerde,    OUTPUT);
  pinMode(carroAmarelo,  OUTPUT);
  pinMode(carroVermelho, OUTPUT);
  pinMode(buzzer,        OUTPUT);
  

  /* Declara valores iniciais para as saídas */
  digitalWrite(carroVerde,    HIGH); // Coloca na posição inicial. Somente o verde dos carros e o vermelho dos pedestres acesos
  digitalWrite(carroVermelho, LOW);
  digitalWrite(carroAmarelo,  LOW);
  digitalWrite(pedVerde,      LOW);
  digitalWrite(pedVermelho,   HIGH);
  digitalWrite(buzzer,        LOW);
}

void loop()
{
  digitalWrite(carroVerde,    HIGH); // Acende o verde dos carros e o vermelho dos pedestres
  digitalWrite(pedVermelho,   HIGH);
  delay(7000); // Aguarda 5 segundos

  digitalWrite(carroVerde,    LOW);
  digitalWrite(carroAmarelo,  HIGH); // Apaga o verde dos carros e acende o amarelo
  delay(3000); // Aguarda mais 3 segundos

  digitalWrite(carroAmarelo,  LOW); // Apaga o amarelo dos carros e acende o vermelho
  digitalWrite(carroVermelho, HIGH);
  digitalWrite(pedVermelho,   LOW); // Apaga o vermelho dos pedestres e acende o verde
  digitalWrite(pedVerde,      HIGH); 
  tone(buzzer,480,7000); // Buzzer começa a tocar, indicando o sinal verde para pedestres
  delay(7000);  // Aguarda mais 5 segundos

  digitalWrite(pedVerde,      LOW);
  tone(7,480,250);
  
  for (int x = 0; x < 6; x++) // Pisca o vermelho dos pedestres
  {
    digitalWrite(pedVermelho, HIGH);
    delay(250);
    digitalWrite(pedVermelho, LOW);
    delay(250);
    tone(7,480,250);
    noTone(7);
    tone(7,480,250);
  }
  
  digitalWrite(carroVermelho, LOW);

}
