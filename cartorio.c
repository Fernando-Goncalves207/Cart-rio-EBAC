#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca por regi�o
#include <string.h> //biblioteca strings

int registro() //fun��o de cadastro dos usu�rios
{
	setlocale(LC_ALL, "portuguese"); // linguagem utilizada
	
	char arquivo[40]; //cria��o de vari�veis, strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//----
		printf("CPF a ser cadastrado:");
		scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //arquivo = cpf
	
	FILE *file; //arquivos
	file = fopen(arquivo, "w");
	fprintf(file, cpf); //registra o arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	//----
	
		printf("Nome a ser cadastrado:");
		scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	//----
	
    	printf("Sobrenome: ");
		scanf("%s", sobrenome);
		
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	//----
	
		printf("Cargo:");
		scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
    system("pause");
	//----
}


int consulta() //fun��o de consulta
{
	setlocale(LC_ALL, "portuguese"); // linguagem utilizada
	
	char cpf[40];
	char conteudo[250];
	
	printf("CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar esse CPF.\n");
	}
	
	while(fgets(conteudo, 250, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}


int delete() //fun��o para deletar usu�rios
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	    
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!!\n");
		system("pause");
	}
}



int main() //fun��o principal
{
	int opcao=0; //definindo v�riaveis
    int loop=1; //ciclo das v�riaveis
	
	for(loop==1;loop==1;)
	{
		
	system("cls"); //respons�vel por limpar a tela, voltar ao inicio
	
	setlocale(LC_ALL, "portuguese"); // linguagem utilizada
	
	
	   printf("### Cart�rio da EBAC ###\n\n");  //inicio menu
	   printf("Escolha a op��o desejada no menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n\n");
	   printf("op��o:"); //fim menu
	
	scanf("%d" , &opcao); //escolhas do usu�rio
	
	    system("cls");
	
	    switch(opcao) //inicio sele��o
	    { //chamada das fun��es !!!
	    	case 1:
	    	registro();
    		break;
    		
    		case 2:
            consulta();
    		break;
    		
    		case 3:
    		delete();
		    break;
		    
		    default:
		    printf("op��o inv�lida.\n");
	    	system("pause");
	    	break;
		} //final sele��o
	
	
	
	
	
	
	
}
}
