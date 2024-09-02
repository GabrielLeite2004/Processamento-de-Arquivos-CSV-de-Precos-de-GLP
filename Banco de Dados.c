  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  
  #define MAX_LINHA 125
  #define MAX 1024
  
  // Defina uma estrutura (struct) para armazenar os dados
typedef struct {
      char regiao_sigla[3];
      char estado_sigla[3];
      char municipio[MAX_LINHA];
      char revenda[MAX_LINHA];
      char cnpj_revenda[MAX_LINHA];
      char data_coleta[MAX_LINHA];
      char valor_venda[MAX_LINHA];
    } Dados;
typedef Dados elemento;

/* DECLARACOES GLOBAIS DE CONSTANTES */
const elemento VL_NULO = {"", "", "", "", "", "", ""};

#include "tad_lst2.h"

tipo_lista lista;
  
char* ler_palavra(FILE *arq) {
  char c;
  char palavra[MAX_LINHA] =""; 
  int indice = 0;
  c = fgetc(arq);
  if (c == '"') {
     while ((c = fgetc(arq)) != EOF) {
          if (c == '"' && fgetc(arq)==';') {
              palavra[indice] = '\0'; // Adiciona o caractere nulo ao final da palavra
             return palavra;
          } else {
             palavra[indice] = c; // Adiciona o caractere à palavra
             indice++;
         }
     }
  }
  else {  
    while (c != EOF) {
         if (c == '\n' || c == ';') {
             palavra[indice] = '\0'; // Adiciona o caractere nulo ao final da palavra
            return palavra;
         } else {
            palavra[indice] = c; // Adiciona o caractere à palavra
            indice++;
        }
        c = fgetc(arq);
    }
  }
// return '\0';
}

void listar() {
  FILE *arq_saida;
  
  int i, tam; elemento dados;
  arq_saida = fopen("glp-2004-01.txt", "w+");
   tam = tamanho(lista);
   if (tam > 0) {
     for (i=1;i<=tam;i++) {
        if (obter_elemento(lista,i,&dados)) {
            printf("Posição da gravação no arquivo de saída: %d\n", i); 
            // Imprima em aquivo os dados armazenados na estrutura
            fprintf(arq_saida,"Regiao - Sigla: %s\n", dados.regiao_sigla);
            fprintf(arq_saida,"Estado - Sigla: %s\n", dados.estado_sigla);
            fprintf(arq_saida,"Municipio: %s\n", dados.municipio);
            fprintf(arq_saida,"Revenda: %s\n", dados.revenda);
            fprintf(arq_saida,"CNPJ da Revenda: %s\n", dados.cnpj_revenda);
            fprintf(arq_saida,"Data da Coleta: %s\n", dados.data_coleta);
            fprintf(arq_saida,"Valor de Venda: %s\n\n", dados.valor_venda); 
       } 
     }
   }
  fclose(arq_saida);
}
  
int main() {
    FILE *arquivo;
    
    elemento dados; // Crie uma variável do tipo struct Dados para armazenar os dados de cada linha
    int pos=1;
    inicializa_lista(&lista);
    char pala[MAX_LINHA];
    // Abra o arquivo CSV para leitura
    arquivo = fopen("glp-2004-01.csv", "r");
    
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Leia e descarte o cabeçalho
    char cabecalho[MAX];
    if (fgets(cabecalho, MAX, arquivo) == NULL) {
        perror("Erro ao ler o cabeçalho");
        fclose(arquivo);
        return 1;
    }

    // Leia e imprima as linhas de dados
    while (!feof(arquivo)) {
        strcpy(pala, ler_palavra(arquivo));
        strncpy(dados.regiao_sigla, pala,2); 
        dados.regiao_sigla[3] = '\0';
        
        strcpy(pala, ler_palavra(arquivo));
        strncpy(dados.estado_sigla, pala,2);
        dados.estado_sigla[3] = '\0';
        
        strcpy(dados.municipio, ler_palavra(arquivo));
        strcpy(dados.revenda, ler_palavra(arquivo));
        strcpy(dados.cnpj_revenda, ler_palavra(arquivo));
        strcpy(pala, ler_palavra(arquivo)); //nome rua
        strcpy(pala, ler_palavra(arquivo)); // número rua
        strcpy(pala, ler_palavra(arquivo)); // complemento
        strcpy(pala, ler_palavra(arquivo)); // bairro
        strcpy(pala, ler_palavra(arquivo)); //cep
        strcpy(pala, ler_palavra(arquivo)); // produto
        strcpy(dados.data_coleta, ler_palavra(arquivo));
        strcpy(dados.valor_venda, ler_palavra(arquivo));
        strcpy(pala, ler_palavra(arquivo)); // valor_compra
        strcpy(pala, ler_palavra(arquivo)); // unidade_medida
        strcpy(pala, ler_palavra(arquivo)); // bandeira
        if (strcmp(dados.regiao_sigla, "NE") == 0 ||
            strcmp(dados.regiao_sigla, "N") == 0 || 
            strcmp(dados.regiao_sigla, "S") == 0 ||
            strcmp(dados.regiao_sigla, "SE") == 0 ||
            strcmp(dados.regiao_sigla, "CO") == 0 ) {
          printf("Posição de inserção na lista: %d\n", pos); 
          incluir_elemento(&lista,pos++,dados);
      }
    }

    // Feche o arquivo
    fclose(arquivo);
    listar();
    return 0;
}