#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define MAX_TOKENS 100

// Estrutura para armazenar os tokens
typedef struct {
    char *type;
    char *value;
} Token;

// Função para corresponder regex e adicionar tokens ao array
void match_regex(const char *pattern, const char *text, Token *tokens, int *token_count, const char *type) {
    regex_t regex;
    regmatch_t match[1];
    int ret;

    // Compila a expressão regular
    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        fprintf(stderr, "Não foi possível compilar o regex\n");
        exit(1);
    }

    // Executa a expressão regular
    ret = regexec(&regex, text, 1, match, 0);
    if (!ret) {
        int start = match[0].rm_so;
        int end = match[0].rm_eo;
        char *token_value = (char *)malloc(end - start + 1);
        strncpy(token_value, text + start, end - start);
        token_value[end - start] = '\0';

        // Adiciona o token ao array
        tokens[*token_count].type = strdup(type);
        tokens[*token_count].value = token_value;
        (*token_count)++;
    }

    // Libera a memória alocada pelo regex
    regfree(&regex);
}

int main() {
    // Definição dos padrões regex e seus tipos correspondentes
    const char *patterns[] = {
        "^inteiro", "^real", "^se", "^entao", "^senao", "^enquanto", "^repita", "^ate", "^ler", "^mostrar",
        "^[a-zA-Z_][a-zA-Z0-9_]*", "^[0-9]+", "^[0-9]+\\.[0-9]+", "^[+\\-*/=<>!]+", "^[,;{}()]"
    };
    const char *types[] = {
        "KEYWORD", "KEYWORD", "KEYWORD", "KEYWORD", "KEYWORD", "KEYWORD", "KEYWORD", "KEYWORD", "KEYWORD", "KEYWORD",
        "IDENTIFIER", "INTEGER", "REAL", "OPERATOR", "DELIMITER"
    };

    // Texto de entrada para teste
    const char *text = "inteiro a, b, c; real comprimento, altura; se a > b entao mostrar(a);";

    // Array para armazenar os tokens
    Token tokens[MAX_TOKENS];
    int token_count = 0;

    // Testa o texto de entrada contra todos os padrões
    for (int i = 0; i < sizeof(patterns) / sizeof(patterns[0]); i++) {
        match_regex(patterns[i], text, tokens, &token_count, types[i]);
    }

    // Imprime os tokens reconhecidos
    for (int i = 0; i < token_count; i++) {
        printf("Token: %s, Value: %s\n", tokens[i].type, tokens[i].value);
        free(tokens[i].value);
        free(tokens[i].type);
    }

    return 0;
}
