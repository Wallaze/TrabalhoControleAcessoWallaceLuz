#include <stdio.h>
#include <string.h>

// definição de cores para o console
#define BLACK "\x1b[30m"
// preto
#define RED "\x1b[31m"
// vermelho
#define GREEN "\x1b[32m"
// verde
#define YELLOW "\x1b[33m"
// amarelo
#define RESET "\x1b[0m"
// padrão

void opcoes(char perfil[]) {
// Função que imprime as opções de perfil do usuário
  printf("\nSeja bem vindo %s!", perfil);
  printf("\n\nAcesse:\n");
  if (strcmp(perfil, "Administrador") == 0) {
    printf(BLACK "| 1 | Gestão de funcionários |\n");
    printf(YELLOW "| 2 | Gestão de dados        |\n");
    printf(GREEN "| 3 | Acesse o portal        |\n");
  } else if (strcmp(perfil, "Usuário 1") == 0) {
    printf(YELLOW "| 1 | Gestão de dados       |\n");
    printf(GREEN "| 2 | Acesse o portal       |\n");
  } else if (strcmp(perfil, "Visitante") == 0) {
    printf(GREEN "| 1 | Acesse o portal        |");
  }
}

int main(void) {
  printf("Controle de acesso de funcionários\n\n");

  printf("Digite um nome de usuário: ");
  char nome[9];
  // char nome [9] - a maior quantidades de caracteres possível será 9
  scanf("%s", nome);
  printf("Digite a senha: ");
  char senha[13];
  // char senha [13] - para 12 caracteres mais o \0, vazio
  scanf("%s", senha);

  if (strcmp(nome, "admin") == 0 && strcmp(senha, "admin123") == 0) {
    opcoes("Administrador");
    // declara a string "opcoes" como Administrador, o mesmo será para as outras
  } else if (strcmp(nome, "usuario1") == 0 &&
             strcmp(senha, "usuario123") == 0) {
    opcoes("Usuário 1");
  } else if (strcmp(nome, "visitante") == 0 &&
             strcmp(senha, "visitante123") == 0) {
    opcoes("Visitante");
  } else {
    printf(RED "\nAcesso negado!" RESET
               "\nTente digitar um nome de usuário ou senha válidos.");
  }
  return 0;
}