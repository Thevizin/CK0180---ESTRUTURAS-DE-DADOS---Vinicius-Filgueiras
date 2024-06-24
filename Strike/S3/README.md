### 1. Em C++, um arquivo de texto pode ser aberto para leitura conforme exemplificado pelo seguinte programa:

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
  {
   try
     {
      ifstream arquivo ("meu_arquivo.txt");

      if (not arquivo.is_open())
        {
         cerr << "Erro ao abrir o arquivo! Arquivo inexistente?\n";
         return 2;
        }

      string linha;  getline(arquivo, linha);

      if (arquivo.eof())
        {
         // Supõe toda linha terminada por '\n'.
         cout << "Arquivo vazio.\n";
        }
      else
        {
         cout << "1ª linha: " << linha << '\n';

         getline (arquivo, linha);

         // Supõe toda linha terminada por '\n'.
         if (arquivo.eof())
           {
            cout << "Arquivo com apenas uma linha.\n";
           }
         else
           {
            cout << "2ª linha: " << linha << '\n';

            cout << "Arquivo com 2 ou mais linhas.\n";
           }
        }
     }
   catch (const exception &e)
     {
      cerr << "Exceção: " << e.what() << '\n';
      return 1;
     }
  }    // main

Observe que não é necessário fechar o arquivo explicitamente, pois o destrutor de "ifstream" se encarrega disso.

Assim sendo, escreva um programa que leia do usuário o nome de um estado brasileiro e que, com base no conteúdo do arquivo de texto "cidades.txt", imprima na tela a soma das populações das cidades do estado em questão.

O conteúdo do arquivo "cidades.txt" estará no formato exemplificado a seguir (naturalmente, o conteúdo abaixo apenas ilustra o formato em que os dados aparecerão no arquivo; o número de linhas, as cidades presentes e os valores a elas relativos não são conhecidos a priori):

POPULAÇÃO - CIDADE - ESTADO
868075 - Teresina - Piauí
1392121 - Guarulhos - São Paulo
276264 - Juazeiro do Norte - Ceará
259337 - Imperatriz - Maranhão
2886698 - Salvador - Bahia
2686612 - Fortaleza - Ceará
1108975 - São Luís - Maranhão

Assim, por exemplo, se o usuário digitar "Ceará", e se o arquivo "cidades.txt" tiver o conteúdo acima, então o programa deve imprimir uma população de 2962876 (que corresponde à soma das populações das cidades de Juazeiro do Norte e Fortaleza).


###2. Em C++, um arquivo de texto pode ser escrito como no programa a seguir:

#include <fstream>
#include <iostream>

using namespace std;

int main ()
  {
   try
     {
      ofstream arquivo ("meu_arquivo.txt");

      if (not arquivo.is_open())
        {
         cerr << "Erro ao abrir o arquivo!\n";
         return 2;
        }

      string l1;  cout << "Linha 1: ";  getline(cin,l1);
      string l2;  cout << "Linha 2: ";  getline(cin,l2);

      arquivo << l1 << '\n'
              << l2 << '\n';
     }
   catch (const exception &e)
     {
      cerr << "Exceção: " << e.what() << '\n';
      return 1;
     }
  }    // main

Assim sendo, escreva um programa que mantenha um cadastro de pessoas. Para cada pessoa, devem ser armazenados os seguintes dados: CPF, nome, data de nascimento e endereço. O programa deve permitir:

Inserção e remoção de pessoas no cadastro;
Consulta e edição dos dados das pessoas.
Os dados do cadastro devem ser gravados em arquivo, de forma que uma execução do programa comece com o estado do cadastro deixado pela execução anterior. Ao tentar abrir o arquivo no início do programa, deve-se verificar se o arquivo existe ou não; caso o arquivo não exista, o programa não deve terminar com um erro, mas sim simplesmente entender a situação como sinônimo de um cadastro vazio e prosseguir com a execução.