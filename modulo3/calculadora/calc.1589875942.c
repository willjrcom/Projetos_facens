#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  float n1=0.0,n2=0.0,pr,vl,resp;
  char operacao=0,eh=130;
  char ans=0;
  
  do{
  printf("\t Bem Vindos a Calculadora Basica.\n\n");            
               printf("Digite o Primeiro Numero e a Operacao Desejada e o  Segundo Numero.\n");
               printf("\n + para Soma. \n - para Subtracao. \n * para Multiplicacao. \n / para Divisao.\n\n");
               scanf("%f %c %f",&n1,&operacao,&n2);
               
               
  switch(operacao)
  {
   case '+':        
        resp=n1+n2;
        printf("\t A Soma %c: %f\n\n",eh,resp);
        printf("\t Calculo Concluido com Sucesso!\n\n");
   break;
  
   case '-':          
        resp=n1-n2;
        printf("\t A Subtracao %c: %f\n\n",eh,resp);
        printf("\t Calculo Concluido com Sucesso!\n\n");
   break;    
  
   case '*':          
        resp=n1*n2;
        printf("\t A Multiplicacao %c: %f\n\n",eh,resp);
        printf("\t Calculo Concluido com Sucesso!\n\n");
   break;
  
   case '/':          
        resp=n1/n2;
        printf("\t A Divisao %c: %f\n\n",eh,resp);
        printf("\t Calculo Concluido com Sucesso!\n\n");
   break;
        
   default: 
   printf("\a \t Operacao Invalida\n\n");
  
   }
   printf("Deseja realizar outro Calculo: S para Sim ou N para Nao\n\n");
   scanf("%s",&ans);
}while((ans=='s')||(ans=='S')) ;
system("CLS");
system("PAUSE");	
return 0;
  
}
