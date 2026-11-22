#include<stdio.h>

int main(){

	int mes;
	
	// ler entrada de dados
	printf("digite o mes: ");
	scanf("%d" , &mes);
	
	// realiza os calculos
	switch (mes) {
	case 2:
		printf("28 dias");
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
			printf("tem 31 dias");
			break;
	case 4:
	case 6 :
	case 9 :
	case 11:
	printf("tem 30 dias");
	break;	
	}
}
