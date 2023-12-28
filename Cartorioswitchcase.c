#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // bilbioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bilbioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usu�rios do sistema
{
	
	//in�cio da cria��o de vari�veis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];   
	char cargo[40];
	//final da cria��o de variaveis/strings
	 
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); // '' %s '' Refere-se a string, que a gente est� armazenando strings nesse comando
	 
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	 
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	 
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	 
	file = fopen(arquivo, "a");
    fprintf(file,nome);
	fclose(file);
	 
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	 
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	 
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	 
	file = fopen(arquivo, "a");  // file = fopen abre o arquivo
	fprintf(file,",");
	fclose(file); //fclose fecha o arquivo
	 
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	 
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	 
	system("pause");
	 
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem

    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
    {

    char cpf[40];
	printf("Digite o cpf do usu�rio a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse usu�rio n�o se encontra no sistema!\n");
		system("pause");
		
	}




	}



int main()
    {
    int opcao=0;
    int x=1;

    for(x=1;x=1;)
    {
	
	system("cls"); //responsavel por limpar a tela
	
	
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
	
	printf(" #### cart�rio da EBAC #### \n\n"); //inicio do menu
	printf("Escolha a op��o desejada do menu\n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar Nomes\n\n\n"); //Fim do Menu
	printf("Escolha a op��o desejada:");
	
	scanf("%d" , &opcao); // armazenandao a escolha do usu�rio
	
    system("cls");
	
	switch(opcao) //inicio da sela��o de Menu
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
		
		
        default:
		printf("essa op��o n�o est� dispon�vel!\n");
		system("pause");
		break;
		
		}
	
	
    }
}
