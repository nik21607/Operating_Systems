#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int creditMoney = 5000;
 int firstValue, secondValue, thirdValue;
 int currentMoneyStatus = creditMoney;
 int paymentExecution = 90;
 int prizeCoefficientOne = 27;
 int prizeCoefficientTwo = 38;
 int fine = 22;
 void getRandValue(){
   firstValue = rand() % 8;
   secondValue = rand() % 8;
   thirdValue = rand() % 8;
 }
 void getInfo(){
   printf("Сумма денег на счете:%d\n",currentMoneyStatus);
   printf("Текущая комбинация: |%d| / |%d| / |%d| \n",firstValue,secondValue,thirdValue);
 }
 int definePrize(){
   int prize=0;
   if(firstValue==0 && secondValue==0 && thirdValue==0 || firstValue==1 && secondValue==1 && thirdValue==1 ||
   firstValue==2 && secondValue==2 && thirdValue==2 || firstValue==3 && secondValue==3 && thirdValue==3 || 
   firstValue==4 && secondValue==4 && thirdValue==4){
      printf("Выпадение призовой комбинации. Вам насчитаны призовые деньги по коэффициенту 2.\n");
      prize = (firstValue+thirdValue)*prizeCoefficientTwo;
   }else if(firstValue==7 && secondValue==7 && thirdValue==7) return 1;
   else if(firstValue==5 && secondValue>=0 && thirdValue>=0 || firstValue==5 && secondValue==5 && thirdValue>=0 
   || firstValue==5 && secondValue==5 && thirdValue>=5 || firstValue==7 && secondValue>=0 && thirdValue>=0 ||
   firstValue==7 && secondValue==7 && thirdValue>=0 || firstValue==7 && secondValue==7 && thirdValue>=7){
      printf("Выпадение призовой комбинации. Вам насчитаны призовые деньги по коэффициенту 1.\n");
      prize = (firstValue+secondValue)*prizeCoefficientOne;
   }else if(firstValue==6 && secondValue==6 && thirdValue==6) return 2;
   else{
     printf("Призовые комбинации отсутствуют.\n");
     prize = 0;
   }
   return prize;
 
 }
 void runGameAppplication(){
   if((currentMoneyStatus-paymentExecution)>=0){
   	getRandValue();
   	printf("-----------------------------------------------------------\n");
   	printf("|\tMessage Box\t\t\t\t\t  |\n");
   	printf("|Выполнен случайный выбор комбинации из 3 значений        |\n");
   	printf("|Комбинация:|%d| / |%d| / |%d| \t\t\t\t  |\n",firstValue,secondValue,thirdValue);
   	printf("-----------------------------------------------------------\n");
   	currentMoneyStatus = currentMoneyStatus-paymentExecution;
   	getInfo();
   	if(definePrize() == 1){
   	   printf("Выпал джекпот комбинация (7 7 7). Игра завершена, Вы победили!\n");
   	   exit(1);
   	}else if(definePrize() == 2){
   	   printf("Штрафная комбинация: 6 6 6\n");
   	   currentMoneyStatus = currentMoneyStatus-fine;
   	}else if(definePrize()!=1 && definePrize()!=2){
   	   currentMoneyStatus = currentMoneyStatus+definePrize();
   	}
   	getInfo();
   }else{
     printf("У Вас недостаточно денежных средств для продолжения игры! Игра завершена, Вы потерпели поражение");
     exit(0);
   }
 }
int main(){
  srand(time(NULL));
  printf("Стартовая сумма на счете: %d\n",currentMoneyStatus);
  while(1){
    printf("1. Показать комбинацию\n ");
    printf("2. Завершить работу приложения\n");
    int menubar;
    printf("Ваш выбор:");
    scanf("%d",&menubar);
    switch(menubar){
    	case 2: printf("Завершение работы программы\n"); exit(1);
        case 1:
         runGameAppplication();
       break;
       default: printf("Такого пункта нет в списке, повторите ввод\n");
    }
  
  }
  return 0;
}
