#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de texto por região
#include  <string.h> // biblioteca responsável por cuidar das strig

	
int registro()  // função responsável por cadastrar usuários no sistema
{
	// início criação de vaiáveis/strings
	char arquivo[40]; // variavél tipo arquivo
	char cpf[40]; // variavél tipo cpf
	char nome[40]; // variavél tipo nome
	char sobrenome[40]; // variavél tipo sobrenome
	char cargo[40]; // variavél tipo cargo
	// final criação de vaiáveis/strings
	
	printf("Digite o CPF a ser cadastrado"); // coletar inf do usuario
	scanf("%s", cpf); // refere-se a string cpf
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // atualiza o arquivo
	fprintf(file,","); // inseri a virgula entre as variaveis inseridas
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado");
	scanf("%s", nome); // refere-se a string nome
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,nome); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // atualiza o arquivo
	fprintf(file,","); // inseri a virgula entre as variaveis inseridas
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado");
	scanf("%s", sobrenome); // refere-se a string nome
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,sobrenome); // salva o valor da variável
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

int consulta()  // função responsável por consultar usuários no sistema
{
	setlocale(LC_ALL,"Portuguese"); // biblioteca
	
	// início criação de vaiáveis/strings
	char cpf[40]; // variavél tipo cpf
	char conteudo[200]; // variavél conteudo
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf); // refere-se a string cpf
	
	FILE *file; //abri o arquivo
	file = fopen(cpf,"r"); // abrindo comando referente ao arquivo cpf  e dando o comando "r" de leitura
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausa o sistema
	
}

int deletar() // função responsável por deletar usuários no sistema
{
	char cpf[40]; // variavél tipo cpf
	
	printf("Digitar o CPF do usuário a ser deletado:");
	scanf("%s",cpf); // refere-se a string cpf
	
	remove(cpf); // deleta a variavel cpf do sistema
	
	FILE *file;  // abri o arquivo
	file = fopen(cpf,"r"); // abrindo comando referente ao arquivo cpf  e dando o comando "r" de leitura
	
	
	if(file == NULL)  // em caso de usuário não encontrado
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause"); // pausa o sistema
 	}

}

int main()
{
		
	int opcao=0;
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls"); // responsável por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); // biblioteca
		printf("### Cartório da EBAC ###\n\n");	//inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção:");
		

		scanf("%d", &opcao);
		
		system("cls"); // responsável por limpar a tela
		
		switch(opcao) // início da seleção das funções
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
		
				
				
	}
}
