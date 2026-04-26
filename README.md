# RatCar

Robô móvel autônomo capaz de navegar por um labirinto físico, desviar de paredes e encontrar a saída sem nenhuma intervenção humana. O projeto utiliza lógica de programação embarcada e leitura de sensores em tempo real para tomada de decisão.

---

## Estrutura de Hardware

A construção do RatCar é dividida em quatro blocos principais de componentes:

### Cérebro e Controle
Responsável pelo processamento lógico e distribuição de comandos.
* 1x Placa Arduino Uno
* 1x Módulo Ponte H

### Energia e Alimentação
Sistema projetado para fornecer energia estável e permitir recarga segura.
* 1x Bateria de Lítio 3.7V
* 1x Módulo Carregador de Bateria TP4056
* 1x Módulo de Tensão Step-Up
* 1x Chave Gangorra (Interruptor Liga/Desliga para corte geral)

### Mecânica e Locomoção
Base estrutural e movimentação por tração diferencial.
* 2x Motores DC 3.7V
* 2x Rodas de Tração
* 1x Roda Boba (Apoio direcional)

### Sensores e Navegação
Sistema de visão e varredura de obstáculos do ambiente.
* 1x Sensor Ultrassônico
* 1x Micro Servo Motor
