### Exercício 2

1. **Complete a implementação de fila em C++ iniciada na aula.**

2. **Explique como podemos representar uma pilha limitada via vetor.**

    A pilha é um Tipo Abstrato de Dados (TAD) que segue a ordem LIFO (Last In, First Out), ou seja, o último elemento inserido é o primeiro a ser removido. Para representar uma pilha limitada via vetor, podemos utilizar uma estrutura semelhante a seguir:

    - **Declaração da Pilha:**
        - Um vetor (array) de tamanho fixo para armazenar os elementos da pilha.
        - Uma variável inteira (`top`) que indica a posição do último elemento inserido na pilha. Inicialmente, `top` é igual a -1, indicando que a pilha está vazia.

    - **Operações da Pilha:**
        - **Push (inserir):** Adiciona um elemento no topo da pilha. Antes de inserir, verifica se a pilha não está cheia (ou seja, se `top` é menor que o tamanho máximo da pilha menos um).
        - **Pop (remover):** Remove o elemento do topo da pilha. Antes de remover, verifica se a pilha não está vazia (ou seja, se `top` é maior ou igual a 0).
        - **Top (consulta):** Retorna o elemento no topo da pilha sem removê-lo. Também verifica se a pilha não está vazia antes de retornar o elemento.
