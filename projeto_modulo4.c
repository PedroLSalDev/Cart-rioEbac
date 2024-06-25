#include <stdio.h> 		//biblioteca de comunicação com o usuário
#include <stdlib.h> 	//biblioteca de alocação de espaço em memória
#include <locale.h> 	//biblioteca de alocação de texto por região
#include <string.h>	 	//biblioteca respondável por cuidar das string




int registro() 			//Função responsável por cadastrar os usuários no sistema
{
	            		//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
						//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); 	//%s refere-se a string

	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; 		//cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e "w" significa escrever
	fprintf(file,cpf); 	//salva o valor da variável
	fclose(file); 		//fecha o arquivo
	
	file = fopen(arquivo, "a");   // Abre o arquivo para adição
	fprintf(file, ",");           // Escreve uma vírgula no arquivo
	fclose(file);                 // Fecha o arquivo

	printf("Digite o nome a ser cadastrado: ");   // Pede o nome ao usuário
	scanf("%s", nome);           // Lê o nome digitado

	file = fopen(arquivo, "a");   // Abre o arquivo para adição
	fprintf(file, "%s", nome);    // Escreve o nome no arquivo
	fclose(file);                 // Fecha o arquivo

	printf("Digite o sobrenome a ser cadastrado: "); // Pede o sobrenome ao usuário
	scanf("%s", sobrenome);       // Lê o sobrenome digitado

	file = fopen(arquivo, "a");   // Abre o arquivo para adição
	fprintf(file, "%s", sobrenome); // Escreve o sobrenome no arquivo
	fclose(file);                 // Fecha o arquivo
	
	file = fopen(arquivo, "a");   // Abre o arquivo para adição
	fprintf(file, ",");           // Escreve uma vírgula no arquivo
	fclose(file);                 // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  // Pede o cargo ao usuário
	scanf("%s", cargo);           // Lê o cargo digitado

	file = fopen(arquivo, "a");   // Abre o arquivo para adição
	fprintf(file, "%s", cargo);   // Escreve o cargo no arquivo
	fclose(file);                 // Fecha o arquivo
	
	system("pause");              // Pausa o sistema
	

}

int consulta()			//Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];		// Declara um array de caracteres para armazenar o CPF
	char conteudo[200];	// Declara um array de caracteres para armazenar conteúdo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
	
int deletar()			//Função responsável por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	
	
}

int main()				// Início da função principal do programa
{
	int opcao=0; 		//Definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //fim do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usuário
	
		system("cls"); 	//responsável por limpar a tela
		
		
		switch(opcao) 	//inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
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
				
				
				
				
		} 				//fim da seleção
	
	}
} 						// Fim da função principal do programa

