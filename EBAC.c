#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de epaço de mémoria.
#include <locale.h> //biblioteca de alocação de espaço de região.
#include <string.h> //biblioteca voltada para o funcionamento de strings

int registro() //Função responsável por cadastrar os usuários no sistema.
{
	//Início de criação de variáveis/strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final de criação de variáveis/strings.
	
	printf("\n\nDigite o CPF a ser cadastrado:\n"); //Coletando informações do usuário.
	scanf("%s", &cpf); //%s refere-se a string
	strcpy(arquivo, cpf); //responsável por copiar os valores da string cpf e transformar no id do arquivo.
	
	FILE *file; //cria o arquivo do banco de dados
	file = fopen(arquivo,"w"); //cria o arquivo do banco de dados e o "w" faz a função de escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo.
	
	fopen(arquivo, "a"); //Abre o arquivo e o "a" faz a atualização do mesmo.
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
	
	system("pause"); //Pausa o sistema fazendo o usuário vizualizar uma determinada etapa.
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Define o idioma, por estar fora da int main deve ser evocada novamente.
	
	//Definindo variáveis.
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado\n\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e "r" é utilizado para ler (write).
	
	if(file == NULL) //Refere-se a quando o valor selecionado não constar no arquivo.
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //"Enquanto" realiza a busca do conteúdo no arquivo (200 vezes) até possuir o valor nulo.
	{
		printf("\nEssas são as informações desse usuário:\tCPF:");
		printf("%s", conteudo); //Apresenta a string consultada.
		printf("\n\n"); //Salta linhas após apresentar o conteúdo. 
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40]; //A Função char também apresenta números.
	
	printf("Digite o CPF a ser deletado\n\n");
	scanf("%s",cpf);
	
	remove(cpf); //função responsável por apagar a variável cpf e consequentemente o arquivo existente.
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e lê seu conteúdo.
	
	if(file == NULL)
	{
		printf("O usuário não foi identificado no sistema!.\n\n");
		system("pause");
	}
	

}


int main()
{
	int opcao=0; //Definindo as variáveis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "portuguese"); //Definindo o idioma.
	
		printf("\n\n\t\t\t\t\t\t Cartório da EBAC\n\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n\n");
		printf("\t1 - Registrar nomes\n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n"); //Final do menu.
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:");
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Respnsável por limpar a tela.
		
		switch (opcao) //Início da seleção de menu
		{
			case 1: 
			registro(); //Chama as funções.
			break; //Responsável por encerrar a função no switch case.
			
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
			printf("\n\nInfelizmente essa não é uma opção valida!\n\nzn");
			system("pause");
			break;
		} //Fim da seleção
	}
}
