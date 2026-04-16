#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>    

// Struct para manter o nome e as datas unidos durante a leitura
struct Pessoa {
    std::string nome;
    std::vector<std::string> datas;
};

// Função de comparação adaptada para a struct Pessoa
bool is_less(const Pessoa& p1, const Pessoa& p2) {
    std::string s1 = p1.nome;
    std::string s2 = p2.nome;
    
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    
    return s1 < s2;
}

// Função de ordenação
void sort(std::vector<Pessoa>& pessoas) {
    int tamanho = pessoas.size();
    
    // O primeiro loop (i) diz quantas vezes precisa-se passar pela lista
    for (int i = 0; i < tamanho - 1; i++) {
        
        // O segundo loop (j) faz as comparações em pares lado a lado
        for (int j = 0; j < tamanho - i - 1; j++) {
            
            // Se a pessoa da direita (j+1) deveria vir antes da pessoa da esquerda (j)
            if (is_less(pessoas[j + 1], pessoas[j])) {
                
                // Troca-se as pessoas de lugar
                Pessoa pessoa_temporaria = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = pessoa_temporaria;
            }
        }
    }
}

int main(){
    std::string name_file, line;
    std::vector<Pessoa> pessoas_temp; // Guarda os dados agrupados temporariamente

    std::cout << "Digite o nome do arquivo (com a extensao .txt): ";
    std::cin >> name_file;
    std::ifstream file(name_file);
    
    if (!file.is_open()){
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        return 1; // Encerra o programa com erro
    }

    // Lendo o arquivo linha por linha
    while(std::getline(file, line)) {
        Pessoa p;
        std::string temp_name = "";
        std::string temp_numbers = "";

        // Separação do nome e das datas
        for(char caractere : line){
            if(caractere >= '0' && caractere <= '9'){
                temp_numbers.push_back(caractere);
            } else {
                temp_name.push_back(caractere);
            }
        }

        p.nome = temp_name;

        // Extraindo as 3 datas 
        if(temp_numbers.length() >= 18) {
            p.datas.push_back(temp_numbers.substr(0, 6));   // Primeira data
            p.datas.push_back(temp_numbers.substr(6, 6));   // Segunda data
            p.datas.push_back(temp_numbers.substr(12, 6));  // Terceira data
        }

        pessoas_temp.push_back(p);
    }
    file.close(); 

    // Ordenamento das pessoas alfabeticamente 
    sort(pessoas_temp);

    std::vector<std::string> nomes_ordenados;
    std::vector<std::vector<std::string>> datas_ordenadas;

    for(const Pessoa& p : pessoas_temp){
        nomes_ordenados.push_back(p.nome);
        datas_ordenadas.push_back(p.datas);
    }

    // Exibindo os resultados 
    std::cout << "\n--- Resultados Ordenados ---" << std::endl;
    for(size_t i = 0; i < nomes_ordenados.size(); i++){
        std::cout << "Nome: " << nomes_ordenados[i] << " | Datas: ";
        // Imprime as 3 datas da pessoa
        for(std::string data : datas_ordenadas[i]){
            std::cout << data << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}