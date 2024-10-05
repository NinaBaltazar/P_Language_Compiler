## Definicões de Tokens e Expressões Regulares

### Palavras Reservadas:
`inteiro`: ^inteiro
`real`: ^real
`se`: ^se
`entao`: ^entao
`senao`: ^senao
`enquanto`: ^enquanto
`repita`: ^repita
`ate`: ^ate
`ler`: ^ler
`mostrar`: ^mostrar

`Identificadores`: ^[a-zA-Z_][a-zA-Z0-9_]*

`Números Inteiros`: ^[0-9]+

`Números Reais`: ^[0-9]+\.[0-9]+

`Operadores`: ^[+\-*/=<>!]+

`Delimitadores`: ^[,;{}()]


### Comandos para testar o programa:
- gcc main.c lexer.c -o lexical_analyzer
- .\lexical_analyzer.exe
