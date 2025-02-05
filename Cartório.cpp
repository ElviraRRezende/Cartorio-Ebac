#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bliblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro() //função responsável por cadastrar os usuários no sistemas
{
	//inicio da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //"%" refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, o "w" e para indicar escrita, é a palavra escrita em inglês
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //O "a" é para alterar
	fprintf(file,","); //A "," é para separa o texto da tela
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //O "%s" é o string. 
	
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
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); 
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[100];
	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
  	
    FILE *file;
    file = fopen(cpf,"r"); //O "r" é da palavra escrever em inglês
  	
    if(file == NULL)
{
	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}
	
    while(fgets(conteudo, 100, file) != NULL) //O "while" é o laço de repetição a ser usado nesse caso. O "NULL" é nulo, para indicar que tal informação não existe no sistema
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
    fclose(file);
	system("pause");
	  
}

int deletar()
{
	char cpf[40]; // "char" é uma string que também funciona com valores numéricos e que nesse caso é a melhor opção
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //é o que salva o valor na variável, ele vai varrer tudo que o usuário digitar e salvar onde pedirmos
	
	remove(cpf); //função para ativar o deletar dos arquivos 
	
	FILE *file;
	file = fopen(cpf, "r"); //para fazer a consulta dos arquivos a serem deletados. ele abre o arquivo e lê ele
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	fclose(file);
	
}

int main()
{
	int opcao=0; //Definindo variáveis com o símbolo "=" de atribuição. O ";" é para indicar uma instrução 
	int laco=1;
	for(laco=1; laco=1;) //variável x
	{

system("cls");

	  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	  printf ("\t Cartório EBAC\n\n"); //Modifique o meu código, colocando no lugar das "###" o "t" para criar a estetica do espaço. Inicio do menu
	  printf ("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - regitrar nomes\n"); // "\n" quebra de linha
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n"); // "\n\n" indica final do texto
	  printf("\t Esse Softwre é de uso livre dos alunos\n\n");
	  printf("Escoclha uma opção:"); //Final do menu
	
	
	
	  scanf("%d", &opcao); //Armazenando a escolha do usuário, escanear o que o usuário coloca. Para armazenar uma variável do tipo inteiro usa-se "%d"
	
	  system("cls"); //O sistemaoperacional usando o camando "cls" que limpa a tela das mensagens que tinham antes
	  
	  switch(opcao)
	  {
	      case 1: 
	      registro(); //chamada de funções
		  break; //encerrando um laço
		  
		  case 2:
		  consulta();
		  break;
		  
		  case 3:
		  deletar();
		  break;
		  
		  default:
		  printf("Essa opção não está disponível!\n");
		  system("pause"); //comoando para para a execução do programa até pressionar "Enter"
		  break; 	
		 //fim da seleção	
	   }	  	 
    }
}
