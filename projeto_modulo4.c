#include <stdio.h> 		//biblioteca de comunica��o com o usu�rio
#include <stdlib.h> 	//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> 	//biblioteca de aloca��o de texto por regi�o
#include <string.h>	 	//biblioteca respond�vel por cuidar das string




int registro() 			//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	            		//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
						//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); 	//%s refere-se a string

	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; 		//cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e "w" significa escrever
	fprintf(file,cpf); 	//salva o valor da vari�vel
	fclose(file); 		//fecha o arquivo
	
	file = fopen(arquivo, "a");   // Abre o arquivo para adi��o
	fprintf(file, ",");           // Escreve uma v�rgula no arquivo
	fclose(file);                 // Fecha o arquivo

	printf("Digite o nome a ser cadastrado: ");   // Pede o nome ao usu�rio
	scanf("%s", nome);           // L� o nome digitado

	file = fopen(arquivo, "a");   // Abre o arquivo para adi��o
	fprintf(file, "%s", nome);    // Escreve o nome no arquivo
	fclose(file);                 // Fecha o arquivo

	printf("Digite o sobrenome a ser cadastrado: "); // Pede o sobrenome ao usu�rio
	scanf("%s", sobrenome);       // L� o sobrenome digitado

	file = fopen(arquivo, "a");   // Abre o arquivo para adi��o
	fprintf(file, "%s", sobrenome); // Escreve o sobrenome no arquivo
	fclose(file);                 // Fecha o arquivo
	
	file = fopen(arquivo, "a");   // Abre o arquivo para adi��o
	fprintf(file, ",");           // Escreve uma v�rgula no arquivo
	fclose(file);                 // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  // Pede o cargo ao usu�rio
	scanf("%s", cargo);           // L� o cargo digitado

	file = fopen(arquivo, "a");   // Abre o arquivo para adi��o
	fprintf(file, "%s", cargo);   // Escreve o cargo no arquivo
	fclose(file);                 // Fecha o arquivo
	
	system("pause");              // Pausa o sistema
	

}

int consulta()			//Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];		// Declara um array de caracteres para armazenar o CPF
	char conteudo[200];	// Declara um array de caracteres para armazenar conte�do
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
	
int deletar()			//Fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
	
}

int main()				// In�cio da fun��o principal do programa
{
	int opcao=0; 		//Definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); 	//respons�vel por limpar a tela
		
		
		switch(opcao) 	//inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
			
			
			

			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
				
				
				
				
		} 				//fim da sele��o
	
	}
} 						// Fim da fun��o principal do programa

