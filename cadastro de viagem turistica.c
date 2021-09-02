#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
typedef struct{
int cliente, roteiro, quarto, carro,dias;
char nome[20];
}custo_viagem;

custo_viagem viagem[10];

float custo;
int qa, i, resp;
qa = 0;

do{

    printf("digite o codigo do cliente: ");
    scanf("%d", &viagem[qa].cliente);

    printf("\ndigite seu nome: ");
    scanf("%s",&viagem[qa].nome[20]);

    setbuf(stdin, 0);

    printf("\ndigite o roteiro\n1-Brasil - valor: 170\n2-EUA - valor: 350\n3-África - valor: 370\n: ");
    scanf("%d",&viagem[qa].roteiro);
    
    printf("\ndigite o quarto desejado \n1-Standard - valor atual\n2-Luxo +30 no valor\n: ");
    scanf("%d",&viagem[qa].quarto);

     
    printf("\ndigite se desejar carro:\n1-Sim\n0-Não\n------Valor dos carros para cada roteiro-------\nBrasil - 50\nEUA - 60\nÁfrica - 75\n: ");
    scanf("%d", &viagem[qa].carro);

    printf("\ndigite a quantidade de dias:\n");
    scanf("%d", &viagem[qa].dias);

    
  /*A diária do quarto de luxo é
  R$30 mais cara que o valor da diária em um quarto  standard.
  Exemplo: Se a pessoa escolher roteiro 2, em quarto de luxo, a
  diária irá custar: 320 + 30 = R$ 350.*/
  //variam de acordo com o roteiro escolhido.
   if (viagem[qa].quarto == 1) {
     
   
     //valor quarto Standart
   switch(viagem[qa].roteiro){ 
	 case 1: viagem[qa].quarto = 170; break;
	 case 2: viagem[qa].quarto = 350; break;
	 case 3: viagem[qa].quarto = 370; break;
   
   //case 4: viagem[qa].mens = 170; break;
   }
}   else {
  //valor quarto LUXO
   switch(viagem[qa].roteiro){ 
	 case 1: viagem[qa].quarto = 170+30; break;
	 case 2: viagem[qa].quarto = 350+30; break;
	 case 3: viagem[qa].quarto = 370+30; break;
   
   //case 4: viagem[qa].mens = 170; break;
   }

}
  
  if (viagem[qa].carro == 1){
 
   switch(viagem[qa].roteiro){ 
	 case 1: viagem[qa].carro = 50; break;
	 case 2: viagem[qa].carro = 60; break;
	 case 3: viagem[qa].carro = 75; break;
   
    }
}
    else{
//viagem[qa].carro = 0;

      printf("\nNão optou pelo carro\n");
 }
   
  custo = (viagem[qa].quarto + viagem[qa].carro)*viagem[qa].dias; 
 

 printf("\nVALOR: %.2f \n",custo);

   
  
   printf("\n\nDeseja cadastrar outro viajante(1-sim/0-nao)?\n ");
	scanf("%d",&resp);

  qa++;

}while ((resp == 1) && (qa <10));   
  
 
printf("\nViagem \n");
printf("\n\nRelatorio Geral\n");

printf("\n_________________________________________________________\n");

printf("\ncodigo\tnome\troteiro\tquarto\tcarro\tdias\tcusto\n");

for(i = 0; i < qa; i++){  
printf("\n%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n",
viagem[i].cliente, viagem[i].nome, viagem[i].roteiro,
viagem[i].quarto, viagem[i].carro, viagem[i].dias,custo);

}
printf("\n____________________________________________________________");

  return 0;
}
