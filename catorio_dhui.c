#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include  <string.h> // biblioteca respons�vel por cuidar das strig

	
int registro()  // fun��o respons�vel por cadastrar usu�rios no sistema
{
	// in�cio cria��o de vai�veis/strings
	char arquivo[40]; // variav�l tipo arquivo
	char cpf[40]; // variav�l tipo cpf
	char nome[40]; // variav�l tipo nome
	char sobrenome[40]; // variav�l tipo sobrenome
	char cargo[40]; // variav�l tipo cargo
	// final cria��o de vai�veis/strings
	
	printf("Digite o CPF a ser cadastrado"); // coletar inf do usuario
	scanf("%s", cpf); // refere-se a string cpf
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // atualiza o arquivo
	fprintf(file,","); // inseri a virgula entre as variaveis inseridas
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado");
	scanf("%s", nome); // refere-se a string nome
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,nome); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // atualiza o arquivo
	fprintf(file,","); // inseri a virgula entre as variaveis inseridas
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado");
	scanf("%s", sobrenome); // refere-se a string nome
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,sobrenome); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // atualiza o arquivo
	fprintf(file,","); // inseri a virgula entre as variaveis inseridas
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado");
	scanf("%s", cargo); // refere-se a string cargo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,cargo); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause"); // pausa o sistema



}

int consulta()  // fun��o respons�vel por consultar usu�rios no sistema
{
	setlocale(LC_ALL,"Portuguese"); // biblioteca
	
	// in�cio cria��o de vai�veis/strings
	char cpf[40]; // variav�l tipo cpf
	char conteudo[200]; // variav�l conteudo
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf); // refere-se a string cpf
	
	FILE *file; //abri o arquivo
	file = fopen(cpf,"r"); // abrindo comando referente ao arquivo cpf  e dando o comando "r" de leitura
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausa o sistema
	
}

int deletar() // fun��o respons�vel por deletar usu�rios no sistema
{
	char cpf[40]; // variav�l tipo cpf
	
	printf("Digitar o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf); // refere-se a string cpf
	
	remove(cpf); // deleta a variavel cpf do sistema
	
	FILE *file;  // abri o arquivo
	file = fopen(cpf,"r"); // abrindo comando referente ao arquivo cpf  e dando o comando "r" de leitura
	
	
	if(file == NULL)  // em caso de usu�rio n�o encontrado
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause"); // pausa o sistema
 	}

}

int main()
{
		
	int opcao=0;
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls"); // respons�vel por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); // biblioteca
		printf("### Cart�rio da EBAC ###\n\n");	//inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:");
		

		scanf("%d", &opcao);
		
		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao) // in�cio da sele��o das fun��es
		{
		
			case 1: // 
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
		
				
				
	}
}
