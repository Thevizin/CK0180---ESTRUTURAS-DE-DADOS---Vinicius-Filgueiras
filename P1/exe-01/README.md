# Exercício 1: **Hello World**

## Preparação do Ambiente de Desenvolvimento C++

1. **Tenha um compilador C++ disponível para uso. Existem diferentes caminhos para isso:**

    - **Opção Rápida:**
        - Procure por "online C++ compiler" no Google. Existem várias opções disponíveis para compilar código C++ diretamente no navegador.
        - Há também aplicativos de compiladores C++ para celular (exemplo: para Android).

    - **Para Uso Regular:**
        - Instalar uma IDE (Integrated Development Environment) pode ser uma alternativa conveniente. Algumas opções populares incluem:
            - **Visual Studio Code** (com extensão para C++)
            - **Code::Blocks**
            - **Dev-C++**
    
    - **Separando o Editor de Texto do Compilador:**
        - Esta é a abordagem que será utilizada em sala de aula.
        - **No Windows:**
            - Use o Notepad++ como editor de texto.
            - Instale o MSYS2 para configurar o ambiente do compilador. Após instalar o MSYS2, instale o pacote `mingw-w64-i686-gcc`.
    
2. **Teste sua instalação com o seguinte programa:**

    ```cpp
    #include <iostream>

    int main() {
        std::cout << "Olá, mundo!\n";
        return 0;
    }
    ```
---