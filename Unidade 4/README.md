<h2 align="center">

  <img alt="Estutura de Dados" title="#Programa Ampliar" src="./assets/Captura de tela 2024-07-11 213826.png" width=800/><h2>

# 🌐 Grafos

## Estruturas de Dados: Grafos e suas Aplicações

Explorar grafos é essencial na computação, pois essas estruturas de dados oferecem maneiras eficientes de representar e manipular conexões e relações entre dados.

### Componentes de um Grafo 🔗

**Definição:**
- Um grafo é uma estrutura de dados composta por um conjunto de vértices (ou nós) e arestas (ou ligações) que conectam esses vértices.
- As arestas podem ser direcionadas ou não direcionadas, e podem ou não ter um peso associado.

### Características:
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
- Roteamento em redes de computadores.
- Análise de redes sociais para detectar comunidades ou influenciadores.
- Gestão de transporte e logística, como otimização de rotas.
- Análise de dados para identificar padrões e tendências em redes de comunicação.
- Aplicações em jogos, como representação de mapas e lógica de jogo.


## Representação de Grafos 🧩
## Matriz de Adjacência

**Definição:**  
Uma matriz de adjacência é uma matriz quadrada usada para representar um grafo. As linhas e colunas da matriz correspondem aos vértices do grafo. A entrada na posição `(i, j)` da matriz é um valor que indica se existe uma aresta entre o vértice `i` e o vértice `j`.
<br>
<img alt="Matriz de adjacencia" title="#matriz de adjacencia" src="./assets/Matriz Adjacencia.png" width=250/>
<br>
**Características:**
- Para grafos não direcionados, a matriz é simétrica, pois a aresta de `i` para `j` é a mesma de `j` para `i`.
- Para grafos direcionados, a matriz não é necessariamente simétrica.
- Se a aresta tiver um peso, o valor na matriz pode ser o peso da aresta em vez de apenas um indicador binário (0 ou 1).

**Uso:**  
A matriz de adjacência é eficiente para verificar a existência de uma aresta entre dois vértices e para grafos densos.

## Matriz de Incidência

**Definição:**  
Uma matriz de incidência é uma matriz retangular usada para representar um grafo. As linhas da matriz correspondem aos vértices e as colunas correspondem às arestas. A entrada na posição `(i, j)` da matriz indica se o vértice `i` está conectado pela aresta `j`.
<br>
<img alt="Matriz de incidencia" title="#matriz de incidencia" src="./assets/Matriz Incidencia.png" width=250/>
<br>
**Características:**
- Para grafos direcionados, a matriz usa dois valores para indicar a incidência: `1` se o vértice é o ponto de origem da aresta, `-1` se o vértice é o ponto de destino, e `0` se o vértice não está incidente com a aresta.
- Para grafos não direcionados, a matriz usa `1` se o vértice está conectado pela aresta e `0` caso contrário.

**Uso:**  
A matriz de incidência é eficiente para representar grafos esparsos e para algoritmos que precisam iterar sobre as arestas.


## Aplicações no Dia a Dia 🏢📱

- **Redes de Transporte:** Modelagem de rotas de ônibus, metrô, e voos, onde as cidades são vértices e as rotas são arestas.
- **Redes de Comunicação:** Internet, redes sociais e telefonia, onde computadores, servidores ou usuários são vértices e as conexões entre eles são arestas.
- **Mapeamento de Estradas:** Vias são arestas e cruzamentos ou cidades são vértices.
- **Sistemas de Recomendação:** Onde usuários e itens (como filmes ou produtos) são vértices, e a preferência ou interação é representada por arestas.
- **Pesquisa Operacional:** Problemas de otimização como o menor caminho (Dijkstra), fluxo máximo, e árvore geradora mínima.
- **Algoritmos de Busca:** Para encontrar caminhos ou conexões em mapas, redes sociais, e até em jogos (busca em largura, profundidade, etc.).

<p align="center"><img alt="Unicesumar" title="#Unicesumar" src="./assets/logo-unicesumar.png" width=120/></p>

<p align="center">Programa Ampliar Tecnologias - Estrutura de Dados</p>

<p align="center">Copyright :copyright: 2024</p>
