import sys

# Verificar se o argumento do caminho do arquivo foi fornecido
if len(sys.argv) < 2:
    print("Uso: python script.py <caminho_do_arquivo>")
    sys.exit(1)

# Ler o caminho do arquivo do programa
program_filepath = sys.argv
print(f"Lendo o arquivo: {program_filepath}")

# Ler as linhas do arquivo
program_lines = []
try:
    with open(program_filepath, "r") as program_file:
        program_lines = [line.strip() for line in program_file.readlines()]
except FileNotFoundError:
    print(f"Erro: Arquivo '{program_filepath}' não encontrado.")
    sys.exit(1)

program = []
for line in program_lines:
    parts = line.split(" ")
    opcode = parts

    # Verificar se a string está vazia
    if opcode == "":
        continue

    # Armazenar o token do opcode
    program.append(opcode)

    # Tratar cada opcode
    if opcode == "PUSH":
        # Esperando um número
        try:
            number = int(parts)
            program.append(number)
        except ValueError:
            print(f"Erro: Valor inválido para PUSH na linha: {line}")
            sys.exit(1)
    elif opcode == "PRINT":
        # Analisar literal de string
        string_literal = ' '.join(parts[1:])[1:-1]
        program.append(string_literal)
    elif opcode == "JUMP.EQ.0":
        # Ler rótulo
        label = parts
        program.append(label)
    elif opcode == "JUMP.GT.0":
        # Ler rótulo
        label = parts
        program.append(label)

print(program)
