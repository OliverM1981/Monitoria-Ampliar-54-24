<h2 align="center">

  <img alt="Estutura de Dados" title="#Programa Ampliar" src="./assets/Captura de tela 2024-07-11 213826.png" width=800/><h2>

# Pilha e Fila

Usar pilhas e filas em computação é fundamental porque essas estruturas de dados fornecem maneiras eficientes e organizadas de gerenciar dados que seguem padrões específicos de acesso. 

##  Por que usar PILHAS? 🧱🧱🧱

Usar pilhas em computação é fundamental devido às suas características específicas que atendem a várias necessidades em algoritmos e sistemas. 

### Padrão de Acesso LIFO (Last In, First Out)
#### Operações Naturais para LIFO:
<p align="left">As pilhas são ideais para cenários onde o último elemento inserido precisa ser o primeiro a ser removido. Isso é útil em várias aplicações, como desfazer ações ou reverter operações.</p>

### Gerenciamento de Memória em Recursão
#### Chamadas de Funções:
<p align="left">Linguagens de programação utilizam pilhas para gerenciar chamadas de função. Cada chamada de função empilha informações como variáveis locais e o endereço de retorno, permitindo que a execução continue corretamente após o retorno de uma função.</p>

#### Funções Recursivas:
<p align="left">Quando uma função recursiva é chamada, um novo contexto é empilhado. Isso ajuda a rastrear o ponto de retorno e as variáveis locais para cada chamada recursiva, essencial para a execução correta.</p>

### Backtracking e Algoritmos de Busca
#### Backtracking:
<p align="left">Algoritmos de backtracking, como aqueles usados para resolver quebra-cabeças ou explorar caminhos em grafos, usam pilhas para armazenar caminhos parciais. Isso permite desfazer passos quando um caminho sem saída é encontrado.</p>

#### Busca em Profundidade(DFS):
<p align="left">A busca em profundidade usa pilhas para explorar grafos ou árvores. A pilha ajuda a rastrear quais vértices ou nós visitar a seguir, facilitando a exploração completa de todos os caminhos possíveis.</p>

### Avaliação de Expressões e Análise de Sintaxe
#### Expressões Matemáticas:
<p align="left">Pilhas são usadas na conversão e avaliação de expressões infixas para pós-fixas (notação polonesa reversa), onde operadores e operandos são empilhados e desempilhados conforme necessário.</p>

#### Compiladores:
<p align="left">Compiladores utilizam pilhas para analisar a sintaxe de código fonte, especialmente para lidar com estruturas de controle aninhadas ou expressões complexas.</p>

### Navegação em navegadores e aplicações
#### Histórico de Navegação:
<p align="left">Navegadores da web usam pilhas para gerenciar o histórico de páginas. O botão "voltar" desempilha a última página visitada, retornando à página anterior.</p>

#### Aplicativos com Função Desfazer:
<p align="left">Em editores de texto e gráficos, as operações são empilhadas para permitir a funcionalidade de desfazer/redo. A pilha mantém o histórico de alterações, permitindo reverter ou reaplicar mudanças.</p>

### Simplicidade e Eficiência
#### Operações Rápidas:
<p align="left">As operações de empilhar e desempilhar são muito eficientes, com tempo de execução constante (O(1)). Isso faz das pilhas uma escolha prática para operações que exigem velocidade e simplicidade.</p>

#### Facilidade de Implantação
<p align="left">Pilhas são simples de implementar e usar, tornando-as uma solução conveniente para problemas que se encaixam naturalmente em seu padrão de acesso.</p>

### Resumo
As pilhas são escolhidas pela sua capacidade de modelar naturalmente problemas que requerem um padrão LIFO, além de sua eficiência e simplicidade na implementação de operações críticas em computação. Essa combinação de fatores torna as pilhas uma ferramenta poderosa e versátil em várias aplicações de software.
<br><br>

## Por que usar FILAS? 🚶‍♂️🚶‍♀️🚶
As filas são uma estrutura de dados que segue o princípio FIFO (First In, First Out), onde o primeiro elemento adicionado é o primeiro a ser removido. Este padrão de acesso é particularmente útil em diversas situações em computação

### Padrão de Acesso FIFO (Firstt In, First Out)
#### Operações Naturais para FIFO:
<p align="left">Em uma fila, os elementos são adicionados (enfileirados) no final e removidos (desenfileirados) do início. Isso garante que o primeiro elemento a ser inserido será o primeiro a ser removido.</p>

### Gerenciamento de Processos e Tarefas
#### Filas de Processos em Sistemas Operacionais:
<p align="left">Sistemas operacionais usam filas para gerenciar processos que aguardam a execução. Isso garante que os processos sejam tratados na ordem em que chegam, assegurando um processamento justo e previsível.</p>

#### Gerenciamento de Tarefas:
<p align="left">Em sistemas de processamento em lote ou servidores de aplicativos, as tarefas são enfileiradas para serem processadas sequencialmente. Isso ajuda a organizar e priorizar tarefas de forma eficiente.</p>

### Serviços de Rede e Comunicação
#### Filas de Pacotes em Redes:
<p align="left">Roteadores e switches de rede usam filas para gerenciar pacotes de dados que chegam antes de serem enviados ao destino final. Isso ajuda a manter a ordem de entrega e a eficiência na transmissão.</p>

#### Filas de Mensagens:
<p align="left">Em sistemas de mensagens assíncronas, como o RabbitMQ ou o Apache Kafka, as filas são usadas para armazenar mensagens até que os consumidores estejam prontos para processá-las. Isso permite a comunicação desacoplada entre componentes de software.</p>

### Aplicações Interativas e Interfaces de Usuário
#### Filas de Eventos:
<p align="left">Em sistemas de interface gráfica de usuário (GUI), filas de eventos são usadas para gerenciar interações do usuário, como cliques e pressionamentos de tecla, garantindo que os eventos sejam processados na ordem em que ocorrem.</p>

### Sistemas de Impressão e Agendamento
#### Filas de Impressão:
<p align="left">Documentos enviados para impressão são enfileirados, garantindo que sejam impressos na ordem de chegada. Isso é comum em ambientes de escritório com impressoras compartilhadas.</p>

#### Filas de Agendamento:
<p align="left">Aplicativos de agendamento, como sistemas de reserva ou cronogramas de tarefas, utilizam filas para garantir que as tarefas sejam executadas conforme programado.</p>

### Simulações e Modelagem de Sistemas
#### Modelagem de Filas de Espera:
<p align="left">Na simulação de sistemas, como filas em supermercados ou atendimento de serviços, as filas são usadas para modelar e analisar o comportamento de espera e atendimento.</p>

### Simplicidade e Eficiência
#### Operações Rápidas:
<p align="left">Na simulação de sistemas, como filas em supermercados ou atendimento de serviços, as filas são usadas para modelar e analisar o comportamento de espera e atendimento.</p>

#### Facilidade de Implementação:
<p align="left">Filas são fáceis de implementar e usar, oferecendo uma solução direta para muitos problemas que exigem processamento sequencial.</p>

### Resumo
As filas são uma escolha natural para modelar problemas que exigem um padrão FIFO, proporcionando um processamento ordenado e previsível. Sua simplicidade e eficiência tornam as filas uma ferramenta essencial em uma ampla gama de aplicações computacionais, desde sistemas operacionais até serviços de rede e interfaces de usuário.


## Conclusão

Em resumo, pilhas e filas são escolhidas devido à sua capacidade de organizar e gerenciar dados de forma eficiente, atendendo a padrões específicos de acesso que são comuns em muitos sistemas e algoritmos.

<br><br><br>
<p align="center"><img alt="Unicesumar" title="#Unicesumar" src="./assets/logo-unicesumar.png" width=120/></p>

<p align="center">Programa Ampliar Tecnologias - Estrutura de Dados</p>

<p align="center">Copyright :copyright: 2024</p>
