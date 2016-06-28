#include <stdio.h>
#include <wiringPi.h>
#include <math.h>
#include <sr595.h>
 
#define MENOR 3 //Define o GPIO3 como MENOR
#define TAMANHO 400 //Parâmetro utilizado para definir o tamanho do vetor que serão gravados os dados do conversor
 
int main (void)
{
    int i = 0, bit, j, k, l, inicial; //Declara variáveis para realização de laços. Inicial conterá o valor inteiro que será enviado para o DA
   
    int lido[TAMANHO]; //Declara o vetor que será gravado os dados do conversor lido
   
    wiringPiSetup(); //Setup da biblioteca wiringPi
    sr595Setup(100,0,0,1,2); /* A função pronta sr595Setup (ver referência) configura os 3 GPIOS usados para transmissão serial. Ela internamente chama as subfunções pinMode() e digitalWrite()
    Formato:
    sr595Setup (pinBase, numPins, dataPin, clockPin, latchPin)  dataPin  -> GPIO0
    clockPin -> GPIO1
    latchPin -> GPIO2 */
   
    for (k=0; k<TAMANHO; k++)
    {
        inicial = 128; // Coloca-se 1 no bit mais significativo do conversor (8º bit, que vale 128)
        i =0;
       
        for (j=0;j<=7;j++) //Realiza o envio dos 8 bits (valores) Digital -> Analógico para comparação com sinal externo
        {
            i = i+inicial;
            i = 0;
            for(bit=0; bit<8; ++bit) //Varre cada um dos 8 bits
            {
                digitalWrite(100+bit,i&(1<<bit)); //Escreve o valor a ser comparado no conversor DA
            }
            delayMicroseconds(10); //Delay obtido empiricamente devido a problemas no valor do conversor quando a saída era menor que 1.5V
            if(digitalRead(MENOR) == 0) //Lê a saída do comparador que está ligada no GPIO3
            {
                i = i - inicial; //Se a leitura for menor, tem-se o bit 0, se for maior tem-se o bit 1
            }
            inicial = inicial/2; //Passa para o próximo bit (deslocamento binário)
        }
        lido[k] = i; //Grava o valor de 8 bits no vetor alocado anteriormente
    }
    while(1) //Após ter gravado os valores, existe este loop infinito que fica enviando os valores gravados no conversor DA para ser exibido
    {
        for(i=0;i<TAMANHO;i++) //Varre todos elementos do vetor gravado
        {
            for(bit=0;bit<8) //Envia os 8 bits de cada elemento
            {
                digitalWrite(100+bit; lido[i]&(1<<bit));
            }
            delayMicroseconds(900000/400); //Tempo para enviar cada valor para o DA para a onda não ficar distorcida no tempo (longa ou curta), valor obtido pela razão: Tempo gravação / Número de elementos
        }
    }
    return 0;
}
