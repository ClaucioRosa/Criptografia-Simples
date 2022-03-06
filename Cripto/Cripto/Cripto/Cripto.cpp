/*
Projeto:
Um  processador  deve  receber  diversos  bytes  e  realizar  uma
conversão criptografada dos mesmos. A criptografia será somar 5 aos elementos pares do vetor
e subtrair 3 dos elementos ímpares.
Exemplo:  você  entra  com  os  bytes  0xA0,  0x73,  0x25,  0xD3,  0xCA,  0xFE.  A  função  os
converterá para                         0xA5, 0x70,  0x22,  0xD0,  0xCF,  0x103.
Após, desenvolva também uma função para descriptografar estes bytes.
Utilizando a passagem de vetores para funções.

Autor : Claucio Rosa
Data : 25 / 09 / 2021
* /


/*############  BIBLIOTECAS  ###############*/

#include <iostream>
#include <stdlib.h>

/*############  Declaração de Constantes  ####*/

#define num 6

/*############  PROTOTIPOS DAS FUNÇÕES  ####*/

void crypto(int vet[], int N);
void decrypto(int vet[], int N);

/*############  FUNÇÃO PRINCIPAL  ##########*/

int main()
{
	int vector[num] = { 0xA0,0X73,0X25,0XD3,0XCA,0XFE };
	int codigo = 0;
	int cont = 0;

	do
	{
		/*system("cls");*/
		putchar('\n');
		printf(">>>>>>>>Menu de Opcao<<<<<<<<\n");
		printf(" 0 - Para sair\n");
		printf(" 1 - Para criptografar\n");
		printf(" 2 - Para descriptografar\n\n");
		printf("Digite uma opcao:  ");
		scanf_s("%d", &codigo);
		putchar('\n');

		switch (codigo)
		{
		case 0:
			printf("Encerrando o programa\n");
			break;
		case 1:
			if (cont <= 0)
			{
				crypto(vector, num);
				cont++;
			}
			else
				printf(" Numeros Criptografados\n ");
			break;
		case 2:
			if (cont > 0)
			{
				decrypto(vector, num);
				cont--;
			}
			else
				for (int i = 0; i < num; i++)
					printf("0X%X  ", vector[i]);
			break;
		default:
			printf("Codigo Invalido\n");
			break;
		}
		putchar('\n\n');
		/*system("PAUSE");*/
	} while (codigo != 0);
	return 0;
}

/*############  FUNÇÕES  ###################*/

void crypto(int vet[], int N)
{
	register int i;

	for (i = 0; i < N; i++)
	{
		vet[i] % 2 == 0 ? vet[i] += 5 :
			vet[i] -= 3;
		printf("0X%X  ", vet[i]);
	}
}
void decrypto(int vet[], int N)
{
	for (int i = 0; i < N; i++)
	{
		vet[i] % 2 == 0 ? vet[i] += 3 :
			vet[i] -= 5;
		printf("0X%X  ", vet[i]);
	}
}
