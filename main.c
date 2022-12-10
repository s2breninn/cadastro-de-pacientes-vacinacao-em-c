#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_PAC 200

typedef struct{
  int codigo;
  char nome[30];
  char cpf[20];
  char vacina[20];
  char dataNasc[10];
  char numLote[30];
  int vrf;
}paciente;

int i;

paciente pac[MAX_PAC];

void menu();
void cadastro();
void pesquisa();
void lista();

struct dados_paciente;

int main(void)
{
  setlocale(LC_ALL, "Portuguese_Brazil");

  menu();
  cadastro();
  lista();
  pesquisa();
}

void menu(){
  
  int op;
  
  do{
    
    system("cls");
    printf("\n---------------------- CONTROLE DE VACINA ----------------------\n\n");
    printf("1 - Cadastrar\n2 - Listar\n3 - Consulta por CPF\n4 - Sair\n\n");
    printf("> ");
    scanf("%d", &op);

    getchar();
    
    switch(op){

      case 1:
          cadastro();
      break;

      case 2:
          lista();
      break;
      
      case 3:
          pesquisa();
      break;
    }
    getchar();
  }while(op!=4);
  
}

void cadastro()
{
  char nome[30];
  char cpf[20];
  char vacina[20];
  char dataNasc[11];
  char numLote[10];
  int vrf;
  int op;

  do{
    getchar();
    system("cls");

    printf("\n---------------------- CADASTRO ----------------------\n\n");
    
    printf("\nNome: ");
    fgets(nome, sizeof(nome),stdin);
    printf("\nCPF:");
    fgets(cpf, sizeof(cpf),stdin);
    printf("\nVacina aplicada: ");
    fgets(vacina, sizeof(vacina),stdin);
    printf("\nData da aplicacao: ");
    fgets(dataNasc, sizeof(dataNasc),stdin);
    printf("\nLote da vacina: ");
    fgets(numLote, sizeof(numLote),stdin);
    
    for (int i=0; i<MAX_PAC; ++i)
    {
      if(pac[i].vrf==0)
      {

        strcpy(pac[i].nome, nome);
        strcpy(pac[i].cpf, cpf);
        strcpy(pac[i].vacina, vacina);
        strcpy(pac[i].dataNasc, dataNasc);
        strcpy(pac[i].numLote, numLote);
        pac[i].vrf=1;
        break;
      }
    }
    
    printf("\n\n------------------------------------\n");
    printf("| 1 - Continuar Cadastrando        |\n");
    printf("| 0 - Sair                         |\n");
    printf("------------------------------------\n\n");
    printf("> ");
    scanf("%d", &op);
  }while(op!=0);
  
}

void lista(){
  system("cls");

  printf("\n---------------------- REGISTRO DE VACINADOS ----------------------\n\n");
  
  for (int i = 0; i < MAX_PAC; i++)
    {
      if(pac[i].vrf==1){
      printf("Codigo: %d \n",i);
      printf("\nNome: %s\n", pac[i].nome);
      printf("CPF: %s\n", pac[i].cpf);
      printf("Vacina aplicada: %s\n", pac[i].vacina);
      printf("Data da aplicacao: %s\n", pac[i].dataNasc);
      printf("Lote da Vacina: %s\n", pac[i].numLote);
      printf("\n--------------------------\n\n");
      }
    }

}

void pesquisa()
{
  system("cls");
  char cpf[30];
  int op;
  
  do{
    getchar();
    system("cls");
    printf("Digite o CPF: \n");
    fgets(cpf, sizeof(cpf), stdin);

  for(int i=0; 1<MAX_PAC; i++)
    {

      if(strcmp(pac[i].cpf, cpf)==0){
        printf("\n\n");
        printf("Codigo: %d \n", i);
        printf("Nome: %s\n", pac[i].nome);
        printf("CPF: %s\n", pac[i].cpf);
        printf("Vacina aplicada: %s\n", pac[i].vacina);
        printf("Data da aplicacao: %s\n", pac[i].dataNasc);
        printf("Lote da vacina: %s\n", pac[i].numLote);
        printf("\n\n");
        
      }else{
        printf("[!] - CPF invalido.\n");
        printf("\n\n------------------------------------\n");
        printf("| 1 - Pesquisar outro CPF          |\n");
        printf("| 0 - Sair                         |\n");
        printf("------------------------------------\n\n");
        printf("> ");
        scanf("%d", &op);
        break;
  
        }
      
    }

  }while(op!=0);
}