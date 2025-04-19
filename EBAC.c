#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de epa�o de m�moria.
#include <locale.h> //biblioteca de aloca��o de espa�o de regi�o.
#include <string.h> //biblioteca voltada para o funcionamento de strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema.
{
	//In�cio de cria��o de vari�veis/strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final de cria��o de vari�veis/strings.
	
	printf("\n\nDigite o CPF a ser cadastrado:\n"); //Coletando informa��es do usu�rio.
	scanf("%s", &cpf); //%s refere-se a string
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string cpf e transformar no id do arquivo.
	
	FILE *file; //cria o arquivo do banco de dados
	file = fopen(arquivo,"w"); //cria o arquivo do banco de dados e o "w" faz a fun��o de escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo.
	
	fopen(arquivo, "a"); //Abre o arquivo e o "a" faz a atualiza��o do mesmo.
	fprintf(file, ",\tNome:"); //Atualiza o arquivo aberto escrevendo nele.
	fclose(file);
	
	printf("\n\nDigite o nome a ser cadastrado:\n");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	fopen(arquivo, "a");
	fprintf(file,",\tSobrenome:");
	fclose(file);
	
	printf("\n\nDigite o sobrenome a ser cadastrado:\n");
	scanf("%s",sobrenome);
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	fopen(arquivo,"a");
	fprintf(file, ",\tCargo:");
	fclose(file);
	
	printf("\n\nDigite o cargo a ser cadastrado:\n");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	fopen(arquivo, "a");
	fprintf(file,".\t");
	fclose(file);
	
	system("pause"); //Pausa o sistema fazendo o usu�rio vizualizar uma determinada etapa.
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Define o idioma, por estar fora da int main deve ser evocada novamente.
	
	//Definindo vari�veis.
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado\n\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e "r" � utilizado para ler (write).
	
	if(file == NULL) //Refere-se a quando o valor selecionado n�o constar no arquivo.
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //"Enquanto" realiza a busca do conte�do no arquivo (200 vezes) at� possuir o valor nulo.
	{
		printf("\nEssas s�o as informa��es desse usu�rio:\tCPF:");
		printf("%s", conteudo); //Apresenta a string consultada.
		printf("\n\n"); //Salta linhas ap�s apresentar o conte�do. 
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40]; //A Fun��o char tamb�m apresenta n�meros.
	
	printf("Digite o CPF a ser deletado\n\n");
	scanf("%s",cpf);
	
	remove(cpf); //fun��o respons�vel por apagar a vari�vel cpf e consequentemente o arquivo existente.
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e l� seu conte�do.
	
	if(file == NULL)
	{
		printf("O usu�rio n�o foi identificado no sistema!.\n\n");
		system("pause");
	}
	

}


int main()
{
	int opcao=0; //Definindo as vari�veis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "portuguese"); //Definindo o idioma.
	
		printf("\n\n\t\t\t\t\t\t Cart�rio da EBAC\n\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n\n");
		printf("\t1 - Registrar nomes\n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n"); //Final do menu.
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:");
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Respns�vel por limpar a tela.
		
		switch (opcao) //In�cio da sele��o de menu
		{
			case 1: 
			registro(); //Chama as fun��es.
			break; //Respons�vel por encerrar a fun��o no switch case.
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("\n\nObrigado por utilizar o sistema!\n\n");
			return 0;
			break;
				
			default:
			printf("\n\nInfelizmente essa n�o � uma op��o valida!\n\nzn");
			system("pause");
			break;
		} //Fim da sele��o
	}
}
