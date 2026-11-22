#include <stdio.h>
int main()
{
	// declaracao de variaveis
	int idade;
	
	// ler os dados da entrada
	printf("digite a idade do nadador:");
	scanf("%d" , &idade);
	
	//calcula idade
	printf("nadador de idade %d " ,idade);
	
	if (idade<5)
	printf(" nao se encontra em nenhuma categoria\n");
	
	if((idade>=5) && (idade<=7))
	printf(" e da categoria infantil A\n");
	
	
	if ((idade>=8) &&(idade<=10))
	printf(" e da categoria infantil B\n");
	
	if ((idade>=11) && (idade<=13))
	printf(" e da categoria Juvenil A\n");
	
	if ((idade>=14) && (idade<=17))
	printf(" e da categoria Juvenil B\n");
	
	if (idade>17)
	printf("e da categoria Senior\n");
}
