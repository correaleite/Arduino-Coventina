# Arduino-Coventina

## Descrição do projeto
Simulação de um arduino com sensor e lcd feito para o nosso robô Coventina que será enviado a lua para perfurar e coletar gelo lunar.

## Objetivo da solução
O circuito criado na simulação realiza duas funções essenciais para que a extração de gelo lunar dê certo. Coventina possui um sensor que detecta objetos para evitar a colisão do robô enquanto ele se desloca para o local designado da missão, e ao ser ativado o robô irá iniciar a escavação ao mesmo tempo mostrando a profundidade perfurada. 

## Componentes utilizados
- 1 Arduino Uno R3
- 1 Protoboard
- 1 Sensor de distância ultrassônico HC-SR04
- 1 Display LCD 16 x 2
- 1 Potenciômetro (250kΩ)
- 1 LED vermelho
- 1 Botão (Push)
- 32 Fios (Jumpers)
- 2 resistores (220Ω)

## Explicação do funcionamento
O sensor ultrassônico monitora continuamente a distância entre o robô e obstáculos à sua frente. As informações são exibidas no display LCD juntamente com mensagens de alerta de acordo com a proximidade detectada:

Acima de 50 cm: caminho livre.
Entre 35 cm e 50 cm: precaução.
Entre 20 cm e 35 cm: cuidado.
Abaixo de 20 cm: perigo.

Além do sistema de detecção de obstáculos, o robô possui uma função de escavação simulada. Ao pressionar o botão, o sistema inicia uma sequência de escavação, exibindo no LCD mensagens de status e a profundidade atingida pela escavadeira, que aumenta gradualmente até 500 cm.

Quando a profundidade máxima é alcançada, o sistema informa que a escavação foi concluída. Um novo acionamento do botão faz com que a escavadeira seja retraída, reduzindo gradualmente a profundidade até retornar a 0 cm. Durante o processo, um LED permanece aceso para indicar que a operação de escavação ou retração está em andamento.

## Estrutura do Circuito
Ligações do LCD 16x2<br>
LCD	/ Arduino
GND - GND
VCC - 5V
VO - Potenciômetro (meio)
RS - D12
RW - GND
E -	D11
DB4 - D5
DB5 - D4
DB6 - D3
DB7 - D2
LED Ânodo (+) - Resistor 220 Ω - 5V
LED Cátodo (-) - GND

Ligações do HC-SR04
HC-SR04 /	Arduino
VCC - 5V
GND -	GND
TRIG - D6
ECHO - D7

Ligações do Botão
Botão /	Arduino
Terminal 1 - D8
Terminal 2 - GND

Ligações do LED
LED /	Arduino
Ânodo (+) - Resistor 220 Ω -	D13
Cátodo (-) - GND

Ligações do Potenciômetro
Potenciômetro / Arduino
Potenciômetro (esquerda) - 5V
Potenciômetro (direita) - GND

## Instruções de execução
1. Inicie a simulação ou energize o circuito.
2. Ajuste o potenciômetro até que as informações sejam exibidas corretamente no LCD.
3. Observe a distância medida pelo sensor ultrassônico e os alertas apresentados no display.
4. Pressione o botão (2s) para iniciar a simulação de escavação.
5. Aguarde a profundidade atingir 500 cm.
6. Após a conclusão da escavação, pressione novamente o botão (2s) para iniciar a retração da escavadeira.
7. Após a retração completa, o sistema retorna ao modo de monitoramento de obstáculos.
8. Durante as operações de escavação e retração, o LED permanecerá aceso indicando que o processo está em execução.
