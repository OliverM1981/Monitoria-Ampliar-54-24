<h2 align="center">
  <img alt="Estutura de Dados" title="#Programa Ampliar" src="./assets/Captura de tela 2024-07-11 213826.png" width=800/>
</h2>
🌐 Grafos
Estruturas de Dados: Grafos e suas Aplicações
Explorar grafos é essencial na computação, pois essas estruturas de dados oferecem maneiras eficientes de representar e manipular conexões e relações entre dados.

Componentes de um Grafo 🔗
Definição:

Um grafo é uma estrutura de dados composta por um conjunto de vértices (ou nós) e arestas (ou ligações) que conectam esses vértices.
As arestas podem ser direcionadas ou não direcionadas, e podem ou não ter um peso associado.
Características:
Os vértices representam entidades ou objetos, e as arestas representam as relações entre eles.
Grafos podem ser simples, conexos, completos, bipartidos, entre outros.
A representação dos grafos pode ser feita de várias maneiras, como por meio de matriz de adjacência, lista de adjacência ou matriz de incidência.
Usos na Computação:
Modelagem de redes de comunicação, como redes sociais ou a Internet.
Implementação de algoritmos de busca, como busca em largura ou em profundidade.
Análise de grafos para encontrar caminhos mínimos, árvores geradoras mínimas, etc.
Aplicações Práticas:
Roteamento em redes de computadores.
Análise de redes sociais para detectar comunidades ou influenciadores.
Gestão de transporte e logística, como otimização de rotas.
Representação de Grafos 🧩
Matriz de Adjacência
Definição: Uma matriz onde as linhas e colunas representam vértices, e as entradas indicam se há ou não uma aresta entre os vértices.
<p align="center">
  <img alt="Matriz de Adjacência" title="Matriz de Adjacência" src="https://miro.medium.com/v2/resize:fit:1400/format:webp/1*AVz0wORPqOY2u1pqg0Edyg.png" width=400/>
</p>
c
Copiar código
// Representação computacional em C
int matriz_adjacencia[4][4] = {
    {0, 1, 0, 0},
    {1, 0, 1, 1},
    {0, 1, 0, 1},
    {0, 1, 1, 0}
};
Lista de Adjacência
Definição: Uma lista onde cada vértice tem uma lista associada que contém os vértices com os quais está conectado.
<p align="center">
  <img alt="Lista de Adjacência" title="Lista de Adjacência" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/10/Simple_graph.svg/2000px-Simple_graph.svg.png" width=400/>
</p>

Matriz de Incidência
Definição: Uma matriz onde as linhas representam vértices e as colunas representam arestas. As entradas indicam a relação entre vértices e arestas.
<p align="center">
  <img alt="Matriz de Incidência" title="Matriz de Incidência" src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/0b/Matriz_de_incid%C3%AAncia_exemplo.png/220px-Matriz_de_incid%C3%AAncia_exemplo.png" width=400/>
</p>

Aplicações no Dia a Dia 🏢📱
Redes de Transporte: Modelagem de rotas de ônibus, metrô, e voos, onde as cidades são vértices e as rotas são arestas.
Redes de Comunicação: Internet, redes sociais e telefonia, onde computadores, servidores ou usuários são vértices e as conexões entre eles são arestas.
Mapeamento de Estradas: Vias são arestas e cruzamentos ou cidades são vértices.
Sistemas de Recomendação: Onde usuários e itens (como filmes ou produtos) são vértices, e a preferência ou interação é representada por arestas.
Pesquisa Operacional: Problemas de otimização como o menor caminho (Dijkstra), fluxo máximo, e árvore geradora mínima.
Algoritmos de Busca: Para encontrar caminhos ou conexões em mapas, redes sociais, e até em jogos (busca em largura, profundidade, etc.).
<p align="center"><img alt="Unicesumar" title="#Unicesumar" src="./assets/logo-unicesumar.png" width=120/></p>
<p align="center">Programa Ampliar Tecnologias - Estrutura de Dados</p>
<p align="center">Copyright :copyright: 2024</p>