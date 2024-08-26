<h2 align="center">

  <img alt="Estutura de Dados" title="#Programa Ampliar" src="./assets/Captura de tela 2024-07-11 213826.png" width=800/><h2>

# Listas Dinamicas

# Estruturas de Dados: Listas e suas Variações

Explorar listas e suas variações é essencial na computação, pois essas estruturas de dados oferecem maneiras eficientes de organizar e manipular dados.

## Listas Encadeadas 🔗

**Definição:**
- Uma lista encadeada é uma estrutura de dados linear composta de uma sequência de elementos, chamados de nós.
- Cada nó contém dois componentes: um dado e uma referência (ou ponteiro) para o próximo nó na sequência.
- A lista começa com um nó especial chamado "cabeça" (head), que aponta para o primeiro elemento da lista.

### Características:
- Inserções e remoções podem ser feitas de forma eficiente, especialmente no início da lista.
- O tamanho da lista pode aumentar ou diminuir dinamicamente conforme necessário.
- O acesso a elementos é feito de forma sequencial, tornando o acesso aleatório menos eficiente.

### Usos na Computação:
- Base para implementar outras estruturas de dados, como pilhas e filas.
- Adequada para aplicativos que precisam de operações frequentes de inserção e remoção.

### Aplicações Práticas:
- Manipulação de listas de contatos em aplicativos de mensagens.
- Gerenciamento de histórico de ações em editores de texto.

## Listas Duplamente Encadeadas 🔄

**Definição:**
- Uma lista duplamente encadeada é semelhante a uma lista encadeada, mas cada nó contém dois ponteiros: um para o próximo nó e outro para o nó anterior.
- Isso permite a navegação bidirecional, ou seja, é possível percorrer a lista tanto para frente quanto para trás.

### Características:
- A navegação bidirecional facilita operações como a remoção de um nó, uma vez que o nó anterior pode ser acessado diretamente.
- Mais memória é usada devido aos ponteiros adicionais.

### Usos na Computação:
- Implementação de listas de prioridade, onde a navegação bidirecional pode ser benéfica.
- Estruturas onde é necessário mover-se para frente e para trás entre elementos.

### Aplicações Práticas:
- Implementação de navegadores para gerenciar histórico de navegação (retroceder e avançar páginas).
- Realização de operações de desfazer/refazer em aplicativos de edição.

## Listas Circulares 🔁

**Definição:**
- Uma lista circular é uma variante da lista encadeada onde o último nó aponta de volta para o primeiro nó, formando um ciclo contínuo.
- Pode ser implementada como uma lista circular encadeada simples ou uma lista circular duplamente encadeada.

### Características:
- Não possui um ponto final fixo, facilitando implementações onde é necessário circular através dos elementos repetidamente.
- Pode ser útil para aplicações que exigem iterações contínuas sobre a lista.

### Usos na Computação:
- Ideal para algoritmos que requerem uma volta contínua sobre os elementos.
- Base para implementar filas circulares.

### Aplicações Práticas:
- Implementação de listas de reprodução de música, onde a lista repete do começo ao fim.
- Agendamento circular de tarefas em sistemas operacionais, como round-robin.

## Listas do Tipo Pilha (Stack) 🧱🧱🧱

**Definição:**
- Uma pilha é uma estrutura de dados que segue o princípio LIFO (Last In, First Out), onde o último elemento inserido é o primeiro a ser removido.
- A pilha suporta principalmente duas operações: push (inserir um elemento) e pop (remover um elemento).

### Características:
- Inserções e remoções são feitas no topo da pilha.
- Útil para rastrear chamadas de funções e contextos de execução em linguagens de programação.

### Usos na Computação:
- Implementação de chamadas de função e recursão em linguagens de programação.
- Avaliação de expressões aritméticas e sintáticas.

### Aplicações Práticas:
- Implementação de sistemas de desfazer/refazer em editores de texto e aplicativos de design gráfico.
- Processamento de expressões matemáticas utilizando notação polonesa reversa.

## Listas do Tipo Fila (Queue) 🚶‍♂️🚶‍♀️

**Definição:**
- Uma fila é uma estrutura de dados que segue o princípio FIFO (First In, First Out), onde o primeiro elemento inserido é o primeiro a ser removido.
- Suporta principalmente duas operações: enqueue (inserir um elemento) e dequeue (remover um elemento).

### Características:
- Inserções são feitas no final da fila e remoções no início.
- Adequada para situações onde a ordem de chegada dos elementos deve ser preservada.

### Usos na Computação:
- Gerenciamento de tarefas em sistemas operacionais, como impressão e processamento de pedidos.
- Implementação de filas de espera em sistemas de atendimento.

### Aplicações Práticas:
- Implementação de filas de impressão em ambientes de escritório.
- Gerenciamento de filas de espera em sistemas de reserva e atendimento ao cliente.

## Aplicações no Dia a Dia 🏢📱

- **Listas Encadeadas:** Usadas em aplicativos que precisam manipular listas de dados dinâmicos, como listas de reprodução de música.
- **Listas Duplamente Encadeadas:** Úteis em editores de texto para gerenciar histórico de edição.
- **Listas Circulares:** Aplicadas em jogos para rodadas ou turnos contínuos.
- **Pilha:** Utilizada em navegadores para gerenciar o histórico de navegação (botão voltar).
- **Fila:** Implementada em sistemas de processamento de pedidos, como filas de clientes em um sistema de atendimento.



<p align="center"><img alt="Unicesumar" title="#Unicesumar" src="./assets/logo-unicesumar.png" width=120/></p>

<p align="center">Programa Ampliar Tecnologias - Estrutura de Dados</p>

<p align="center">Copyright :copyright: 2024</p>