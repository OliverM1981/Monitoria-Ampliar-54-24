<h2 align="center">
  <img alt="Estutura de Dados" title="#Programa Ampliar" src="./assets/Captura de tela 2024-07-11 213826.png" width="800"/>
</h2>

# 🌐 Grafos

## Estruturas de Dados: Grafos e suas Aplicações

Explorar grafos é essencial na computação, pois essas estruturas de dados oferecem maneiras eficientes de representar e manipular conexões e relações entre dados.

### Componentes de um Grafo 🔗

**Definição:**
- Um grafo é uma estrutura de dados composta por um conjunto de vértices (ou nós) e arestas (ou ligações) que conectam esses vértices.
- As arestas podem ser direcionadas ou não direcionadas, e podem ou não ter um peso associado.

**Características:**
- Os vértices representam entidades ou objetos, e as arestas representam as relações entre eles.
- Grafos podem ser simples, conexos, completos, bipartidos, entre outros.
- A representação dos grafos pode ser feita de várias maneiras, como por meio de matriz de adjacência, lista de adjacência ou matriz de incidência.
- Grafos podem ser utilizados para representar redes sociais, mapas, relações entre objetos.
- Grafos podem ser utilizados para resolver problemas de otimização, como encontrar o caminho mais curto.

### Usos na Computação:
- Modelagem de redes de comunicação, como redes sociais ou a Internet.
- Implementação de algoritmos de busca, como busca em largura ou em profundidade.
- Análise de grafos para encontrar caminhos mínimos, árvores geradoras mínimas, etc.
- Aplicações em inteligência artificial, como aprendizado de máquina e visão computacional.
- Aplicações em ciência de dados, como análise de redes sociais e detecção de fraudes.

### Aplicações Práticas:
- 🚏 Roteamento em redes de computadores.
- 📊 Análise de redes sociais para detectar comunidades ou influenciadores.
- 🚚 Gestão de transporte e logística, como otimização de rotas.
- 📈 Análise de dados para identificar padrões e tendências em redes de comunicação.
- 🎮 Aplicações em jogos, como representação de mapas e lógica de jogo.

## Representação de Grafos 🧩

### Matriz de Adjacência

**Definição:**
Uma matriz de adjacência é uma matriz quadrada usada para representar um grafo. As linhas e colunas da matriz correspondem aos vértices do grafo. A entrada na posição `(i, j)` da matriz é um valor que indica se existe uma aresta entre o vértice `i` e o vértice `j`.

<img alt="Matriz de adjacencia" title="#matriz de adjacencia" src="./assets/Matriz Adjacencia.png" width="400"/>

**Características:**
- Para grafos não direcionados, a matriz é simétrica, pois a aresta de `i` para `j` é a mesma de `j` para `i`.
- Para grafos direcionados, a matriz não é necessariamente simétrica.
- Se a aresta tiver um peso, o valor na matriz pode ser o peso da aresta em vez de apenas um indicador binário (0 ou 1).

**Uso:**
A matriz de adjacência é eficiente para verificar a existência de uma aresta entre dois vértices e para grafos densos.

### Matriz de Incidência

**Definição:**
Uma matriz de incidência é uma matriz retangular usada para representar um grafo. As linhas da matriz correspondem aos vértices e as colunas correspondem às arestas. A entrada na posição `(i, j)` da matriz indica se o vértice `i` está conectado pela aresta `j`.

<img alt="Matriz de incidencia" title="#matriz de incidencia" src="./assets/Matriz Incidencia.png" width="400"/>

**Características:**
- Para grafos direcionados, a matriz usa dois valores para indicar a incidência: `1` se o vértice é o ponto de origem da aresta, `-1` se o vértice é o ponto de destino, e `0` se o vértice não está incidente com a aresta.
- Para grafos não direcionados, a matriz usa `1` se o vértice está conectado pela aresta e `0` caso contrário.

**Uso:**
A matriz de incidência é eficiente para representar grafos esparsos e para algoritmos que precisam iterar sobre as arestas.

## Aplicações no Dia a Dia 🏢📱

- 🚍 **Redes de Transporte:** Modelagem de rotas de ônibus, metrô e voos, onde as cidades são vértices e as rotas são arestas.
- 🌐 **Redes de Comunicação:** Internet, redes sociais e telefonia, onde computadores, servidores ou usuários são vértices e as conexões entre eles são arestas.
- 🛣️ **Mapeamento de Estradas:** Vias são arestas e cruzamentos ou cidades são vértices.
- 🎥 **Sistemas de Recomendação:** Onde usuários e itens (como filmes ou produtos) são vértices, e a preferência ou interação é representada por arestas.
- 🔧 **Pesquisa Operacional:** Problemas de otimização como o menor caminho (Dijkstra), fluxo máximo, e árvore geradora mínima.
- 🎮 **Algoritmos de Busca:** Para encontrar caminhos ou conexões em mapas, redes sociais, e até em jogos (busca em largura, profundidade, etc.).

# 🚀 Busca em Largura (Breadth-First Search - BFS) em Grafos

## ❓ O que é a Busca em Largura?
A busca em largura (BFS) é um algoritmo clássico para percorrer ou buscar em grafos. Ele explora os nós (ou vértices) de um grafo de maneira sistemática, começando em um nó inicial (ou origem) e explorando todos os seus vizinhos antes de prosseguir para os nós vizinhos destes, nível por nível. Esse método garante que todos os nós a uma determinada distância do nó inicial sejam visitados antes de qualquer nó a uma distância maior.

## 🔍 Como funciona a BFS?
- **🟢 Início:** Começa no nó inicial, marcando-o como visitado e o adicionando a uma fila.
- **⚙️ Processamento:** Remove o primeiro nó da fila e examina todos os seus vizinhos não visitados.
- **🔄 Exploração:** Para cada vizinho não visitado, ele é marcado como visitado e adicionado à fila.
- **🔁 Repetição:** O processo continua removendo o próximo nó da fila, explorando seus vizinhos, até que a fila esteja vazia.
- **🏁 Conclusão:** Quando a fila estiver vazia, o algoritmo termina, e todos os nós que podem ser alcançados a partir do nó inicial terão sido visitados.

## 🌐 Onde usamos BFS no dia a dia?
A BFS é utilizada em várias situações práticas, algumas delas incluem:

- 🗺️ **Sistemas de Navegação:** BFS pode ser usado para encontrar o caminho mais curto entre dois pontos em mapas ou redes de transporte público, onde cada ponto (nó) representa uma localização e as conexões (arestas) representam as rotas entre elas.
- 👥 **Redes Sociais:** No contexto de redes sociais, BFS pode ser utilizado para descobrir conexões ou recomendações de amigos. Por exemplo, pode-se determinar a distância (em termos de conexões) entre dois usuários.
- 🌐 **Sistemas de Busca em Largura no Web Crawling:** BFS é frequentemente usado em web crawlers para explorar todos os links de uma página web antes de seguir para os links das próximas páginas.
- 🎮 **Soluções de Problemas de Jogo e Quebra-Cabeças:** Em jogos onde você precisa explorar todas as possibilidades de movimento em um tabuleiro, BFS pode ser usado para garantir que todas as opções em um nível sejam exploradas antes de mover para o próximo.
- 🔄 **Detecção de Ciclos e Conectividade em Redes:** BFS pode ser usado para verificar se todos os nós em um grafo são conectados (grafo conexo) ou para detectar a existência de ciclos em grafos.

## ⚖️ Vantagens e Desvantagens da BFS

### ✅ Vantagens:
- Garante encontrar o caminho mais curto em termos de número de arestas, se todas as arestas tiverem o mesmo peso.
- Simples de implementar e entender.

### ❌ Desvantagens:
- Requer espaço adicional para armazenar a fila e o conjunto de nós visitados, o que pode ser problemático em grafos grandes.
- Pode ser menos eficiente que outros algoritmos, como DFS, em grafos muito densos.

# 🌳 Busca em Profundidade (Depth-First Search - DFS) em Grafos

## ❓ O que é a Busca em Profundidade?
A busca em profundidade (DFS) é um algoritmo fundamental para percorrer grafos. Diferentemente da BFS, que explora cada nível completamente antes de descer para o próximo, a DFS explora o mais fundo possível em cada ramo antes de retroceder e explorar outros ramos. Isso significa que a DFS segue um caminho até o final antes de retornar e tentar um caminho alternativo.

## 🔍 Como funciona a DFS?
- **🟢 Início:** Começa no nó inicial, marcando-o como visitado.
- **🔄 Exploração:** Para cada vizinho do nó atual que não foi visitado, o algoritmo realiza uma chamada recursiva para explorar esse vizinho.
- **🔙 Retrocesso:** Quando todos os vizinhos de um nó atual são visitados, o algoritmo retorna ao nó anterior para continuar a exploração.
- **🏁 Conclusão:** O processo continua até que todos os nós alcançáveis sejam visitados.

## 🌐 Onde usamos DFS no dia a dia?
A DFS é aplicada em diversas situações práticas, como:

- 🔄 **Detecção de Ciclos em Grafos:** DFS é útil para identificar ciclos em grafos, como em sistemas de dependências.
- 📊 **Algoritmos de Ordenação Topológica:** DFS é a base para algoritmos de ordenação topológica em grafos direcionados acíclicos.
- 🧩 **Resolução de Labirintos:** DFS pode ser usado para explorar todos os caminhos possíveis em um labirinto para encontrar a saída.
- 🔗 **Problemas de Conectividade:** DFS pode ser usado para determinar componentes conectados em grafos.
- 🌲 **Geração de Árvores de Expansão:** DFS é utilizado para gerar árvores de expansão mínimas em algoritmos como o de Kruskal.

## ⚖️ Vantagens e Desvantagens da DFS

### ✅ Vantagens:
- Pode ser mais eficiente em termos de espaço do que a BFS, especialmente em grafos grandes.
- É útil para explorar completamente todos os caminhos possíveis em um grafo.

### ❌ Desvantagens:
- Não garante o caminho mais curto.
- Pode entrar em loops infinitos se houver ciclos e o algoritmo não for implementado com um mecanismo de detecção de ciclos.

# Algoritmo de Dijkstra

O **algoritmo de Dijkstra** é um algoritmo de busca em grafos que resolve o problema do caminho mínimo de um vértice para todos os outros vértices em um grafo ponderado. O algoritmo foi desenvolvido por Edsger Dijkstra em 1956 e é amplamente utilizado em diversas aplicações no dia a dia.

## 🧠 Como funciona o algoritmo de Dijkstra?

1. **Inicialização:**
   - Definimos o nó de origem, que terá uma distância inicial de 0 para si mesmo, e todos os outros nós terão uma distância inicial de infinito.
   - Criamos um conjunto de nós não visitados.

2. **Iteração:**
   - Selecionamos o nó não visitado com a menor distância acumulada.
   - Atualizamos a distância para os vizinhos desse nó se encontrarmos um caminho mais curto através dele.
   - Marcamos o nó como visitado e o removemos do conjunto de nós não visitados.

3. **Finalização:**
   - O algoritmo termina quando todos os nós foram visitados ou quando o nó de destino tiver sido visitado (caso queiramos encontrar o caminho mais curto até um nó específico).

## 🎯 Aplicações no Dia a Dia

O algoritmo de Dijkstra é essencial em várias áreas e pode ser visto em várias aplicações cotidianas:

1. 🚗 **Navegação e Rotas GPS:**
   - Quando você usa um aplicativo de navegação como Google Maps ou Waze, o algoritmo de Dijkstra é utilizado para encontrar o caminho mais curto entre o ponto de origem e o destino, levando em consideração a distância e o tempo de viagem.

2. 📡 **Redes de Computadores:**
   - Em redes de computadores, o algoritmo ajuda a determinar o caminho mais eficiente para o envio de pacotes de dados, minimizando a latência e o uso de largura de banda.

3. 📦 **Sistemas de Logística:**
   - Empresas de logística, como Amazon e FedEx, usam o algoritmo para otimizar as rotas de entrega de produtos, garantindo que os pacotes cheguem ao destino da maneira mais rápida e eficiente.

4. 🛠️ **Planejamento de Infraestruturas:**
   - Na construção de infraestruturas como gasodutos, estradas e linhas de energia, o algoritmo é utilizado para otimizar o layout, minimizando os custos e o impacto ambiental.

<p align="center">
  <img alt="Unicesumar" title="#Unicesumar" src="./assets/logo-unicesumar.png" width="120"/>
</p>

<p align="center">Programa Ampliar Tecnologias - Estrutura de Dados</p>

<p align="center">Copyright :copyright: 2024</p>
