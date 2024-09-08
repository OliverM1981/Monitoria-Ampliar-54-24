<h2 align="center">

  <img alt="Estutura de Dados" title="#Programa Ampliar" src="./assets/Captura de tela 2024-07-11 213826.png" width=800/><h2>

# Conceitos Básicos de Busca e Tabelas de Dispersão 🔍

## 1. Operação de Busca Sequencial 🚶‍♂️

A **busca sequencial** é um método simples de busca onde percorremos uma lista de elementos um por um até encontrar o valor desejado.

### Como funciona:
- Começamos no primeiro elemento da lista.
- Comparar cada elemento com o valor que estamos procurando.
- Se o valor for encontrado, a busca é concluída.
- Se o final da lista for atingido sem encontrar o valor, significa que o valor não está presente.

### Exemplo de uso:
- Buscar um nome em uma lista desordenada de nomes.

### Vantagens:
- Simples de implementar.
- Funciona em qualquer tipo de lista (ordenada ou desordenada).

### Desvantagens:
- Ineficiente para listas grandes, pois pode precisar percorrer todos os elementos.

---

## 2. Busca Sequencial Indexada 📚

A **busca sequencial indexada** é uma variação da busca sequencial que usa um índice para melhorar a eficiência em listas grandes.

### Como funciona:
- Uma parte da lista (ou arquivo) é indexada. O índice contém referências a blocos de dados.
- Ao realizar uma busca, consultamos o índice para localizar o bloco correto.
- Dentro do bloco, uma busca sequencial normal é realizada.

### Exemplo de uso:
- Buscar em bases de dados que são muito grandes para armazenar inteiramente na memória.

### Vantagens:
- Reduz o número de elementos a serem percorridos.

### Desvantagens:
- Requer espaço adicional para armazenar o índice.
- Pode não ser eficiente para pequenas listas.

---

## 3. A Busca Binária ⚡

A **busca binária** é uma técnica de busca eficiente para listas ordenadas. Ela divide a lista em duas partes repetidamente até encontrar o valor desejado.

### Como funciona:
1. Comparar o valor buscado com o elemento do meio da lista.
2. Se o valor for menor que o elemento do meio, pesquisar na metade inferior.
3. Se for maior, pesquisar na metade superior.
4. Repetir o processo até encontrar o valor ou reduzir a busca a zero.

### Exemplo de uso:
- Buscar um número em uma lista de números ordenados.

### Vantagens:
- Muito eficiente para listas grandes ordenadas.
- O tempo de busca é logarítmico: O(log n).

### Desvantagens:
- A lista precisa estar ordenada previamente.

---

## 4. Busca por Interpolação 📈

A **busca por interpolação** é semelhante à busca binária, mas em vez de dividir a lista ao meio, ela tenta adivinhar onde o valor pode estar com base na distribuição dos dados.

### Como funciona:
1. Calcular a posição provável do valor baseado em uma interpolação linear.
2. Verificar o valor nessa posição.
3. Ajustar a posição e repetir até encontrar o valor ou esgotar a lista.

### Exemplo de uso:
- Buscar em listas grandes onde os valores estão distribuídos de maneira relativamente uniforme (como números sequenciais).

### Vantagens:
- Pode ser mais rápida que a busca binária em listas muito grandes e distribuídas uniformemente.

### Desvantagens:
- Se os dados não forem uniformemente distribuídos, a eficiência cai.

---

## 5. Tabelas de Dispersão (Hash) 🗂️

Uma **tabela de dispersão** (ou hash table) é uma estrutura de dados que associa chaves a valores, onde uma função hash é usada para calcular um índice para armazenar e buscar os valores.

### Como funciona:
1. A chave é passada para uma função hash.
2. A função calcula um índice na tabela onde o valor correspondente à chave será armazenado.
3. Para buscar o valor, a chave é novamente passada pela função hash e o índice calculado é usado para acessar o valor.

### Exemplo de uso:
- Implementar uma tabela de símbolos em um compilador.

### Vantagens:
- Operações de busca, inserção e remoção são muito rápidas na maioria dos casos (O(1)).

### Desvantagens:
- Pode haver colisões (duas chaves diferentes gerarem o mesmo índice), o que precisa ser tratado com técnicas como encadeamento ou endereçamento aberto.
- O desempenho pode ser afetado se a função hash não for bem projetada.

---

🔑 **Resumo**:
- **Busca Sequencial**: Simples, mas ineficiente para grandes listas.
- **Busca Sequencial Indexada**: Usa um índice para melhorar a busca sequencial.
- **Busca Binária**: Eficiente para listas ordenadas, com tempo de O(log n).
- **Busca por Interpolação**: Melhor para listas grandes com dados uniformemente distribuídos.
- **Tabelas de Dispersão (Hash)**: Estrutura eficiente para busca, inserção e remoção, com um tempo esperado de O(1).




<br><br><br>
<p align="center"><img alt="Unicesumar" title="#Unicesumar" src="./assets/logo-unicesumar.png" width=120/></p>

<p align="center">Programa Ampliar Tecnologias - Estrutura de Dados</p>

<p align="center">Copyright :copyright: 2024</p>
