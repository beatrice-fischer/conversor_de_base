/* CONVERSOR DE BASE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen()
#include <math.h>   //pow()

int validarNumero(char *num, int origem);
int converteDecimal(char *num, int origem);
void numeroConvertido(int val, int destino);

int main(void) {
	system ("color FD");
	char n[50];
	int origem = 0, destino = 0, decimal = 0, validado = 0;
	
	do {
		//BASE DE ORIGEM
		do{ 
			
			printf("\t===== CONVERSOR DE BASES =====\n");
			printf("\t[1] Binario\n\t[2] Decimal\n\t[3] Hexadecimal\n\t[0] Sair\n");
			printf("\tSelecione o sistema de origem: ");
			scanf("%i",&origem);
			while(getchar() != '\n');
			
			if (origem == 0) return 0; // Encerra o programa
			if (origem<1 || origem>3) {
				system("cls");
				printf("\tOpcao invalida!");
			}
		} while (origem<1 || origem>3);
		system("cls");
		
		//BASE DE DESTINO
		do{ 
			printf("\t===== CONVERSOR DE BASES =====\n");
			printf("\t[1] Binario\n\t[2] Decimal\n\t[3] Hexadecimal\n\t[0] Sair\n");
			printf("\tSelecione o sistema de destino: ");
			scanf("%i",&destino);
			while(getchar() != '\n');
			
			if (origem == 0) return 0; // Encerra o programa
			if (destino<1 || destino>3) {
				system("cls");
				printf("\tOpcao invalida!\n");
			} else if (origem == destino) {
				printf("\tErro: os sistemas nao podem ser iguais!\n");
				destino = 0; //retorna ao menu
			}
		} while (destino<1 || destino>3 || origem==destino);
		system("cls");
		
		// NÚMERO PARA CONVERSÃO
		do{ 
			printf("\tDigite um numero para conversao: ");
			fgets(n, sizeof(n), stdin);
			n[strcspn(n, "\n")] = 0;
			
			validado = validarNumero(n, origem);
			
			if (validado == 0) {
				printf("\tNumero invalido! Digite apenas caracteres validos para a base escolhida.\n");
			}
		} while (validado == 0);
		
		//Converter para decimal 
		decimal = converteDecimal(n, origem);
		
		//Imprime após conversão
		printf("\n\t==== RESULTADO ====\n");
		printf("\t");
		numeroConvertido(decimal, destino);
		printf("\n\t===================\n");
		
		//Saída
		printf("\n\tPressione Enter para continuar...");
        getchar();
        system("cls");
	} while (origem != 0);
	
	return 0;
}

// VALIDAR NÚMERO - percorre cada caractere
int validarNumero(char *num, int origem) {
	int t = strlen(num); //tamanho do texto
	
	if (t == 0) return 0;
	
	for(int i=0; i<t; i++) { //converte para maiusculo usando a tabela ASCI
		if (num[i] >= 'a' && num[i] <= 'z') num[i] = num[i] -32;
		
		char c=num[i];
	
		if(origem == 1) {
			if (c != '0' && c!= '1') return 0; //Binário só aceita 0 e 1
	        }else if (origem == 2) { 
	            if(c < '0' || c > '9') return 0; //Decimal aceita de 0 a 9
	        }else if (origem == 3) {
	            if(! ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) return 0;
	            //Hexadecimal aceita de 0 a 9 e de A a F
		}
	}
	
	return 1;
}

// CONVERTER PARA DECIMAL
int converteDecimal(char *num, int origem) {
	int val = 0;
    int t = strlen(num);
    int multiplicador = 0; //usado para identificar a base

    if(origem == 1) multiplicador = 2; 
    else if(origem == 2) multiplicador = 10;
    else if(origem == 3) multiplicador = 16;

    for(int i=0; i<t; i++){
        int digito = 0;

        //converte para um valor numérico real (A = 10)
        if(num[i] >= '0' && num[i] <= '9'){
            digito = num[i] - '0';
        }else if(num[i] >= 'A' && num[i] <= 'F'){
            digito = num[i] - 'A' + 10;
        }

        int expoente = t-1-i;
        val += digito * pow(multiplicador, expoente); 
		//cada dígito é multiplicado pela base elevada à sua posição
		//Ex.: 101 = (1 * 2^2) + (0 * 2^1) + (1 * 2^0) = 5
    }
    return val;
}

// IMPRIMIR APÓS CONVERSÃO
void numeroConvertido(int val, int destino) {
	int resto[100];
    int count = 0;

    if(val == 0){
        printf("\t0");
        return;
    }

    if(destino == 2){ // DECIMAL => DECIMAL - só imprime
        printf("\t%i", val);
    }
    else if(destino == 1){ // DECIMAL => BINÁRIO
        while(val > 0){
            resto[count] = val % 2; //divide pela base de destino
            val = val / 2;          
            count++;
        }
        for(int i = count - 1; i >= 0; i--){
            printf("\t%i", resto[i]);
        }
    }
    else if(destino == 3){ // DECIMAL => HEXADECIMAL
        while(val > 0){
            resto[count] = val % 16; //divide pela base de destino
            val = val / 16; //repete até o número chegar a 0
            count++;
        }
        for(int i = count - 1; i >= 0; i--){ //lê os restos na ordem inversa
            if(resto[i] < 10){
                printf("\t%i", resto[i]);
            }else	printf("%c", resto[i] - 10 + 'A'); //converte os restos maiores que 10 em letras
        }
    }
}
