# 📂 Organizador de Nomes e Datas em C++

Um programa simples e eficiente desenvolvido em C++ para ler dados de um arquivo de texto, processar as informações e ordená-las alfabeticamente. Este projeto foi criado com foco educacional para praticar manipulação de arquivos, estruturas de dados dinâmicas e algoritmos de ordenação.

## 🚀 Funcionalidades

* **Leitura de Arquivos (`std::ifstream`):** Importa dados de um arquivo de texto (`.txt`) linha por linha.
* **Processamento de Strings:** Separa inteligentemente os nomes das datas (identificando caracteres numéricos) e divide as datas em blocos de 6 dígitos (formato DDMMAA).
* **Estruturas de Dados (`struct` e `std::vector`):** Utiliza uma `struct` customizada para manter a integridade dos dados (garantindo que as datas não se percam do nome) e vetores dinâmicos para armazenar a lista de pessoas.
* **Algoritmo de Ordenação Próprio:** Implementação do algoritmo **Bubble Sort** do zero para ordenar a lista alfabeticamente (ignorando diferenças entre letras maiúsculas e minúsculas).

## 🛠️ Tecnologias Utilizadas

* C++ (Standard Library: `<iostream>`, `<fstream>`, `<string>`, `<vector>`, `<algorithm>`, `<cctype>`)

## ⚙️ Como Executar

### Pré-requisitos
* Um compilador C++ instalado (como GCC/G++ ou MinGW).
* O arquivo de texto contendo os dados brutos (ex: `arquivo.txt`) na mesma pasta do executável.

### Compilando pelo Terminal
1. Abra o terminal e navegue até a pasta do projeto.
2. Compile o código com o comando:
   ```bash
   g++ code.cpp -o programa
