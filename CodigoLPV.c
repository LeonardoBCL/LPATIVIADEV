#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100

// Definição da struct Livro
struct Livro {
    char titulo[50];
    char autor[50];
    int anoPublicacao;
    int disponivel; // 1 se disponível, 0 se emprestado
};

// Função para adicionar um livro à biblioteca
void adicionarLivro(struct Livro biblioteca[], int *numLivros) {
    if (*numLivros < MAX_LIVROS) {
        printf("Digite o título do livro: ");
        scanf(" %[^\n]", biblioteca[*numLivros].titulo);

        printf("Digite o autor do livro: ");
        scanf(" %[^\n]", biblioteca[*numLivros].autor);

        printf("Digite o ano de publicação do livro: ");
        scanf("%d", &biblioteca[*numLivros].anoPublicacao);

        biblioteca[*numLivros].disponivel = 1; // Livro é marcado como disponível

        (*numLivros)++;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("A biblioteca está cheia. Não é possível adicionar mais livros.\n");
    }
}

// Função para listar todos os livros da biblioteca
void listarLivros(struct Livro biblioteca[], int numLivros) {
    printf("\nLista de Livros na Biblioteca:\n");
    for (int i = 0; i < numLivros; i++) {
        printf("%d. Título: %s\n", i + 1, biblioteca[i].titulo);
        printf("   Autor: %s\n", biblioteca[i].autor);
        printf("   Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
        printf("   Disponível: %s\n", biblioteca[i].disponivel ? "Sim" : "Não");
        printf("------------------------------\n");
    }
}

// Função para buscar um livro por título
void buscarLivroPorTitulo(struct Livro biblioteca[], int numLivros) {
    char tituloBusca[50];
    printf("Digite o título do livro que deseja buscar: ");
    scanf(" %[^\n]", tituloBusca);

    int encontrado = 0;

    for (int i = 0; i < numLivros; i++) {
        if (strcmp(biblioteca[i].titulo, tituloBusca) == 0) {
            printf("\nLivro encontrado:\n");
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
            printf("Disponível: %s\n", biblioteca[i].disponivel ? "Sim" : "Não");
            printf("------------------------------\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Livro não encontrado.\n");
    }
}

// Função para emprestar um livro
void emprestarLivro(struct Livro biblioteca[], int numLivros) {
    char tituloEmprestimo[50];
    printf("Digite o título do livro que deseja emprestar: ");
    scanf(" %[^\n]", tituloEmprestimo);

    int encontrado = 0;

    for (int i = 0; i < numLivros; i++) {
        if (strcmp(biblioteca[i].titulo, tituloEmprestimo) == 0) {
            if (biblioteca[i].disponivel) {
                biblioteca[i].disponivel = 0; // Livro é marcado como emprestado
                printf("Livro emprestado com sucesso!\n");
            } else {
                printf("Desculpe, o livro não está disponível no momento.\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Livro não encontrado.\n");
    }
}

int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int numLivros = 0;
    int escolha;

    do {
        printf("\nSistema de Gestão de Biblioteca:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Buscar Livro por Título\n");
        printf("4. Emprestar Livro\n");
        printf("5. Sair\n");

        printf("Escolha uma opção (1-5): ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarLivro(biblioteca, &numLivros);
                break;

            case 2:
                listarLivros(biblioteca, numLivros);
                break;

            case 3:
                buscarLivroPorTitulo(biblioteca, numLivros);
                break;

            case 4:
                emprestarLivro(biblioteca, numLivros);
                break;

            case 5:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 5);

    return 0;
}
