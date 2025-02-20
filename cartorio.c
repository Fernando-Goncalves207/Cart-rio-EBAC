#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca por região
#include <string.h> //biblioteca strings

int registro() //função de cadastro dos usuários
{
	setlocale(LC_ALL, "portuguese"); // linguagem utilizada
	
	char arquivo[40]; //criação de variáveis, strings
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


int consulta() //função de consulta
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
		printf("Não foi possível localizar esse CPF.\n");
	}
	
	while(fgets(conteudo, 250, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}


int delete() //função para deletar usuários
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
		printf("O usuário não se encontra no sistema!!\n");
		system("pause");
	}
}



int main() //função principal
{
	int opcao=0; //definindo váriaveis
    int loop=1; //ciclo das váriaveis
	
	for(loop==1;loop==1;)
	{
		
	system("cls"); //responsável por limpar a tela, voltar ao inicio
	
	setlocale(LC_ALL, "portuguese"); // linguagem utilizada
	
	
	   printf("### Cartório da EBAC ###\n\n");  //inicio menu
	   printf("Escolha a opção desejada no menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n\n");
	   printf("opção:"); //fim menu
	
	scanf("%d" , &opcao); //escolhas do usuário
	
	    system("cls");
	
	    switch(opcao) //inicio seleção
	    { //chamada das funções !!!
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
		    printf("opção inválida.\n");
	    	system("pause");
	    	break;
		} //final seleção
	
	
	
	
	
	
	
}
}
