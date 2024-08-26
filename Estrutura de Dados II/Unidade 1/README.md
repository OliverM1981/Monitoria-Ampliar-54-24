<h2 align="center">

  <img alt="Estutura de Dados" title="#Programa Ampliar" src="./assets/Captura de tela 2024-07-11 213826.png" width=800/><h2>

# 🌳 Árvores Binárias

## O que são?

Árvores binárias são estruturas de dados hierárquicas em que cada nó tem no máximo dois filhos, chamados de "filho esquerdo" e "filho direito". Elas são uma forma especial de árvore, onde cada nó pode ter, no máximo, dois sub-nós.

## 🧩 Componentes de uma Árvore Binária:

- **Raiz (Root) 🌱**: O nó superior da árvore.
- **Nó (Node) 📦**: Cada elemento da árvore.
- **Filho (Child) 👶**: Nó subordinado a outro nó.
- **Pai (Parent) 👨‍👩‍👧**: Nó que possui filhos.
- **Folha (Leaf) 🍂**: Nó que não possui filhos (ou seja, está no nível mais baixo da árvore).
- **Subárvore (Subtree) 🌴**: Uma árvore que é parte de outra árvore.

## 🏷️ Tipos de Árvores Binárias:

- **Árvore Binária Completa 🎯**: Todos os níveis, exceto possivelmente o último, estão completamente preenchidos, e todos os nós estão o mais à esquerda possível.
- **Árvore Binária Cheia (Full Binary Tree) 🌐**: Todos os nós têm 0 ou 2 filhos.
- **Árvore Binária Balanceada ⚖️**: A diferença de altura entre as subárvores da esquerda e da direita de qualquer nó é, no máximo, 1.

## 🛠️ Operações em Árvores Binárias:

- **Inserção**: Adiciona um nó à árvore mantendo as propriedades da árvore binária.
- **Remoção**: Remove um nó da árvore e ajusta os nós restantes para manter a estrutura.
- **Busca**: Localiza um nó específico dentro da árvore.
- **Travessia (Traversal)**:
  - **Pré-ordem (Pre-order) 🚀**: Visita a raiz, depois a subárvore esquerda, seguida pela subárvore direita.
  - **Em-ordem (In-order) 🌀**: Visita a subárvore esquerda, depois a raiz, seguida pela subárvore direita.
  - **Pós-ordem (Post-order) ⏳**: Visita a subárvore esquerda, depois a subárvore direita, seguida pela raiz.
  - **Em Nível (Level-order) 🌐**: Visita os nós nível por nível.

## 🎯 Usos de Árvores Binárias:

- **Busca e Ordenação 🔍**: Árvores binárias de busca (Binary Search Trees - BST) são usadas para armazenar dados em uma ordem específica, permitindo operações rápidas de busca, inserção e remoção. Exemplos:
  - **Árvores AVL**: Uma árvore binária de busca balanceada onde a diferença de altura entre as subárvores é, no máximo, 1.
  - **Red-Black Tree**: Outra árvore binária de busca balanceada que impõe regras de coloração para garantir o balanceamento.

- **Expressões Matemáticas ➕➖✖️➗**: Árvores binárias são usadas para representar expressões matemáticas onde os nós internos são operadores e os nós folhas são operandos.

- **Compreensão de Dados 📊**: Árvores binárias são usadas em algoritmos de compressão de dados, como o **algoritmo de Huffman**, que usa uma árvore binária para construir um código de compressão eficiente.

## 🌐 Aplicações no Dia a Dia:

- **Sistemas de Arquivos 🗂️**: Muitos sistemas operacionais utilizam árvores (às vezes binárias) para representar e navegar pela estrutura de diretórios.
- **Autocompletar 🔤**: Motores de busca e sistemas de sugestão de texto utilizam árvores binárias para organizar e buscar palavras de forma eficiente.
- **Jogos e IA 🎮**: Árvores binárias podem ser usadas para tomar decisões, como no algoritmo Minimax, utilizado em jogos de tabuleiro para determinar a melhor jogada.
- **Banco de Dados 🗄️**: Árvores binárias, especialmente **B-trees** (que são uma generalização das árvores binárias), são usadas para indexação em sistemas de gerenciamento de banco de dados, permitindo que consultas sejam executadas rapidamente.

# 🌳 Aplicações de Árvores Binárias na Ciência da Computação

As árvores binárias são estruturas fundamentais na ciência da computação devido à sua eficiência em organizar, buscar e manipular dados. Aqui estão algumas das aplicações mais comuns:

## 1. 🌲 Árvores Binárias de Busca (BST)

- **Armazenamento e Busca de Dados**: As BSTs armazenam dados de forma que cada comparação em uma operação de busca, inserção ou exclusão reduz pela metade o conjunto de dados a ser considerado, tornando essas operações muito eficientes.
- **Implementação de Dicionários e Conjuntos**: As BSTs são utilizadas em estruturas de dados como dicionários e conjuntos, onde é necessário adicionar, remover e buscar elementos rapidamente.

## 2. ⚖️ Árvores AVL

- **Árvores Binárias Balanceadas**: As árvores AVL são um tipo de BST que se autoequilibra, mantendo a altura mínima, o que garante operações de busca, inserção e exclusão em tempo logarítmico.
- **Aplicações em Bancos de Dados**: As AVL são usadas em sistemas de banco de dados onde a velocidade de acesso e modificação de dados é crítica.

## 3. 📁 Árvores B e B+

- **Sistemas de Arquivos e Bancos de Dados**: Árvores B e B+ são amplamente usadas para indexar grandes volumes de dados em sistemas de arquivos e bancos de dados. Elas permitem buscas eficientes, minimizando o número de acessos ao disco.
- **Gerenciamento de Índices**: Crucial para o desempenho em sistemas de grande escala, as árvores B e B+ organizam dados de maneira a otimizar acessos sequenciais, especialmente em discos rígidos.

## 4. ⛏️ Árvores Heap (Heap Binário)

- **Implementação de Filas de Prioridade**: Heaps binários são usados para implementar filas de prioridade, onde os elementos de maior (ou menor) prioridade são removidos primeiro. Exemplos incluem algoritmos de escalonamento de tarefas e simulação de eventos.
- **Algoritmos de Ordenação**: O Heapsort, que utiliza um heap binário, é uma técnica eficiente de ordenação com complexidade O(n log n).

## 5. 🤖 Árvores de Decisão

- **Aprendizado de Máquina**: Árvores de decisão são usadas em algoritmos de aprendizado supervisionado, onde decisões são tomadas com base nas características dos dados. Elas são essenciais para tarefas de classificação e regressão.
- **IA e Jogos**: Em jogos e inteligência artificial, árvores de decisão modelam o processo de tomada de decisão, onde cada nó representa uma possível escolha ou ação.

## 6. 📐 Árvores de Segmento

- **Computação Geométrica**: Árvores de segmento armazenam intervalos e respondem a consultas sobre quais intervalos contêm um determinado ponto. Isso é útil em aplicações como Sistemas de Informação Geográfica (GIS).
- **Análise de Desempenho de Sistemas**: Utilizadas para monitorar o desempenho de sistemas, onde os segmentos representam intervalos de tempo ou outras métricas.

## 7. 🔍 Árvores Trie

- **Busca de Strings**: As Tries são usadas para armazenar e buscar strings, como em implementações de dicionários ou sistemas de correção ortográfica. Elas permitem buscas rápidas e eficientes, especialmente em grandes conjuntos de dados textuais.
- **Sistemas de Autocompletar**: Em sistemas de autocompletar, as Tries são usadas para prever as próximas letras ou palavras que um usuário pode querer digitar.

## 8. 🗜️ Compressão de Dados

- **Algoritmo de Huffman**: Árvores binárias são usadas no algoritmo de compressão de Huffman para criar códigos de comprimento variável, minimizando o tamanho total dos dados codificados. Esta técnica é amplamente utilizada em compressão de arquivos e transmissão de dados.

---

As árvores binárias são versáteis e essenciais em muitos algoritmos e estruturas de dados na ciência da computação, proporcionando eficiência e desempenho em diversas aplicações.


## 📝 Resumo

Árvores binárias são fundamentais em ciência da computação devido à sua eficiência em organizar, pesquisar e manipular dados. Elas têm uma ampla aplicação em diversas áreas tecnológicas, desde o armazenamento de dados até a tomada de decisões em sistemas de inteligência artificial.


<br><br><br>
<p align="center"><img alt="Unicesumar" title="#Unicesumar" src="./assets/logo-unicesumar.png" width=120/></p>

<p align="center">Programa Ampliar Tecnologias - Estrutura de Dados</p>

<p align="center">Copyright :copyright: 2024</p>
