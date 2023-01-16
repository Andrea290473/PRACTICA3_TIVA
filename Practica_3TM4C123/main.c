#include "lib/include.h"


//int cuantos;
//int *puntero;
int main(void)
{
    //puntero=&cuantos;
    //uint16_t valor = 0;
    char c='5';
    //char b='a';
    Configurar_PLL(_50MHZ);  //Confiuracion de velocidad de reloj
    Configurar_GPIO();
    Configurar_UART2();//PROFE FCLK 20MHZ Baudrate 9600

    //Experimento 1
    //  Configurar_UART1(); //Jorge,Alberto,Navarro,Saul,Fabela -fclk 25MHZ Baud-rate 57600
    //  Configurar_UART7(); //Angel,Fernanda,Sonia,Aleidis,Monse -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART4(); //Argelia,Roxana,Yesica,Vanesa,Christian,Abiu -fclk 10MHZ Baud-rate 4800
    //  Configurar_UART2(); //Brizet,Monse,Luis,Majo,Alonso -fclk 40MHZ Baud-rate 115200
    //  Configurar_UART3(); //Jesus,Yesica,Carlos,Dulce,Rodolfo,Leonardo -fclk 80MHZ Baud-rate 19200
    //  Configurar_UART2(); //Andrea,Avila,Pamela,Paulina -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART5(); //Hector,Cecilia,Carolina,Jozzafat -fclk 40MHZ Baud-rate 28800
    
    
       // Homogeneidad();
    //printString("Holis Bolis");

   printChar(c);
    //printChar(b);
  

    //printString("\n");
   // char *arr = readString(',');
   // printString(&arr[0]);
   
   
   //EXPERIMENTO1-PRENDER LED CON UART2
   /*while(1)
    {
         c = readChar();
         switch(c)
         {
             case 'r':
                 //GPIODATA port F 662
                 printChar('a');
                 GPIOF->DATA = (1<<1);
                 break;
             case 'b':
                 //GPIODATA port F 662
                 printChar('b');
                 GPIOF->DATA = (1<<2);
                 break;
             case 'g':
                 //GPIODATA port F 662
                 printChar('c');
                 GPIOF->DATA = (1<<3);
                 break;
             case 'y':
                 //GPIODATA port F 662
                 printChar('d');
                 GPIOF->DATA = (1<<3) | (1<<2);
                 break;
             default:
                 printChar((char)valor);
                 GPIOF->DATA = (0<<1) | (0<<2) | (0<<3);
                 break;
         }
    }

*/
//EXPERIMENTO2-ENVIAR NOMBRE(ANDREA)
//02 STX (inicio de texto-ascii)
//03 ETX (fin de texto-ascii)

char arreg[16]={'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//uint8_t cuantos;
char letra;
char letras[16];
char nombre[16]="";
//uint8_t i;
int i;
bool condicion=true;
int cuantos;
int *puntero;



cuantos=0;
puntero=&cuantos;
while (1)
    {
        
        c=readChar(); 
        if (c =='<')
        {           
            while(condicion)
            {
                letra=readChar();
                if (letra!='>')
                    {
                        cuantos++;
                        *(letras+cuantos)=letra;  
                        
                    }
                else
                    {
                        condicion=false;
                    }
                
            }
            
            for (i=*puntero;i>0;i--)
            {
                *(nombre+((cuantos-i)*2))=*(letras+i);
                //escribe letra sent inv
                printChar(*(letras+i));
                *(nombre+((cuantos-i)*2)+1)=*(arreg+(cuantos-i));
                //escribe simbolo sent ascendente
                printChar(*(arreg+(cuantos-i)));
            }
        }        
       
        
       // nombre[(cuantos+1)*2]='\000';
        //printString(nombre);     


    }


}
