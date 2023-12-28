#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // bilbioteca de alocação de espaço em memória
#include <locale.h> //bilbioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() //função responsavel por cadastrar os usuários do sistema
{
	
	//início da criação de variáveis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];   
	char cargo[40];
	//final da criação de variaveis/strings
	 
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); // '' %s '' Refere-se a string, que a gente está armazenando strings nesse comando
	 
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variável
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
    	printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
    {

    char cpf[40];
	printf("Digite o cpf do usuário a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse usuário não se encontra no sistema!\n");
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
	
	
	printf(" #### cartório da EBAC #### \n\n"); //inicio do menu
	printf("Escolha a opção desejada do menu\n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar Nomes\n\n\n"); //Fim do Menu
	printf("Escolha a opção desejada:");
	
	scanf("%d" , &opcao); // armazenandao a escolha do usuário
	
    system("cls");
	
	switch(opcao) //inicio da selação de Menu
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
		printf("essa opção não está disponível!\n");
		system("pause");
		break;
		
		}
	
	
    }
}
