#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bliblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro() //fun��o respons�vel por cadastrar os usu�rios no sistemas
{
	//inicio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //"%" refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, o "w" e para indicar escrita, � a palavra escrita em ingl�s
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //O "a" � para alterar
	fprintf(file,","); //A "," � para separa o texto da tela
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //O "%s" � o string. 
	
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
    file = fopen(cpf,"r"); //O "r" � da palavra escrever em ingl�s
  	
    if(file == NULL)
{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
}
	
    while(fgets(conteudo, 100, file) != NULL) //O "while" � o la�o de repeti��o a ser usado nesse caso. O "NULL" � nulo, para indicar que tal informa��o n�o existe no sistema
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
    fclose(file);
	system("pause");
	  
}

int deletar()
{
	char cpf[40]; // "char" � uma string que tamb�m funciona com valores num�ricos e que nesse caso � a melhor op��o
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //� o que salva o valor na vari�vel, ele vai varrer tudo que o usu�rio digitar e salvar onde pedirmos
	
	remove(cpf); //fun��o para ativar o deletar dos arquivos 
	
	FILE *file;
	file = fopen(cpf, "r"); //para fazer a consulta dos arquivos a serem deletados. ele abre o arquivo e l� ele
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	fclose(file);
	
}

int main()
{
	int opcao=0; //Definindo vari�veis com o s�mbolo "=" de atribui��o. O ";" � para indicar uma instru��o 
	int laco=1;
	for(laco=1; laco=1;) //vari�vel x
	{

system("cls");

	  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	  printf ("\t Cart�rio EBAC\n\n"); //Modifique o meu c�digo, colocando no lugar das "###" o "t" para criar a estetica do espa�o. Inicio do menu
	  printf ("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - regitrar nomes\n"); // "\n" quebra de linha
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n"); // "\n\n" indica final do texto
	  printf("\t Esse Softwre � de uso livre dos alunos\n\n");
	  printf("Escoclha uma op��o:"); //Final do menu
	
	
	
	  scanf("%d", &opcao); //Armazenando a escolha do usu�rio, escanear o que o usu�rio coloca. Para armazenar uma vari�vel do tipo inteiro usa-se "%d"
	
	  system("cls"); //O sistemaoperacional usando o camando "cls" que limpa a tela das mensagens que tinham antes
	  
	  switch(opcao)
	  {
	      case 1: 
	      registro(); //chamada de fun��es
		  break; //encerrando um la�o
		  
		  case 2:
		  consulta();
		  break;
		  
		  case 3:
		  deletar();
		  break;
		  
		  default:
		  printf("Essa op��o n�o est� dispon�vel!\n");
		  system("pause"); //comoando para para a execu��o do programa at� pressionar "Enter"
		  break; 	
		 //fim da sele��o	
	   }	  	 
    }
}
