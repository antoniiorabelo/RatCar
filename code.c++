#include <Servo.h>

const int pinoServo = 9;
const int pinoEcho  = 10;
const int pinoTrig  = 11;

Servo meuServo;

void setup() {
  Serial.begin(9600);
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  
  meuServo.attach(pinoServo);
  
  // Posiciona o servo olhando para frente (90 graus)
  meuServo.write(90);
  delay(1000);
  
  Serial.println("--- Radar Ativado ---");
}

void loop() {
  // 1. Garante que a cabeça está no centro antes de medir
  meuServo.write(90);
  delay(200); // Pequena pausa para a mecânica estabilizar
  
  // 2. Mede a distância na frente do robô
  int distanciaFrente = medirDistancia();
  
  Serial.print("Distancia Atual: ");
  Serial.print(distanciaFrente);
  Serial.println(" cm");

  // 3. A LÓGICA: Verifica se está a 10cm ou menos
  if (distanciaFrente <= 10 && distanciaFrente > 0) {
    
    Serial.println("⚠️ ATENÇÃO: Obstáculo detectado! Iniciando varredura...");
    
    // Olha para a Direita
    meuServo.write(0);
    delay(500); 
    
    // Olha para a Esquerda
    meuServo.write(180);
    delay(800); // Mais tempo aqui, pois o trajeto de 0 até 180 é o mais longo
    
    // Volta para o Centro para verificar de novo no próximo ciclo
    meuServo.write(90);
    delay(500); 
    
    Serial.println("Varredura terminada. Verificando a frente novamente...");
    Serial.println("--------------------------------------------------");
    
  } else {
    // 4. CAMINHO LIVRE: 11cm ou mais
    // Ele não faz a varredura. Apenas fica parado olhando para frente.
    
    delay(400); // Pausa de quase meio segundo apenas para não travar o Monitor Serial
  }
}

// ---------------------------------------------------------
// FUNÇÃO AUXILIAR: Dispara o som e calcula a distância
// ---------------------------------------------------------
int medirDistancia() {
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);
  
  long duracao = pulseIn(pinoEcho, HIGH);
  int distanciaCm = duracao * 0.034 / 2;
  
  return distanciaCm;
}