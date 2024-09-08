<h2 align="center">

  <img alt="Estutura de Dados" title="#Programa Ampliar" src="./assets/Captura de tela 2024-07-11 213826.png" width=800/><h2>

# Algoritmos de Ordenação 📊

## 1. Ordenação por Merge Sort ⚡

O **Merge Sort** é um algoritmo de ordenação do tipo "dividir para conquistar". Ele divide o array em sub-arrays menores, ordena esses sub-arrays e, em seguida, combina (merge) os sub-arrays ordenados para formar o array final ordenado.

### Como funciona:
1. **Divisão**: Divida o array em duas metades.
2. **Ordenação**: Recursivamente, aplique o Merge Sort nas duas metades.
3. **Combinação**: Combine as duas metades ordenadas para formar um array único ordenado.

### Exemplo:
Dado o array `[38, 27, 43, 3, 9, 82, 10]`, o Merge Sort divide recursivamente o array até que cada sub-array tenha apenas um elemento. Depois, as partes são combinadas na ordem correta:
- `[38, 27, 43, 3, 9, 82, 10]`
- `[38, 27, 43]` e `[3, 9, 82, 10]`
- `[38, 27]` e `[43]` | `[3, 9]` e `[82, 10]`
- `[27, 38, 43]` | `[3, 9, 10, 82]`
- `[3, 9, 10, 27, 38, 43, 82]`

### Vantagens:
- **Estável**: A ordem dos elementos iguais é preservada.
- **Ótimo para listas grandes**: Mesmo no pior caso, o tempo de execução é sempre O(n log n).
- **Divisão recursiva**: Adequado para implementações recursivas.

### Desvantagens:
- **Uso de memória**: Requer espaço adicional proporcional ao tamanho do array.

### Complexidade:
- **Melhor caso**: O(n log n)
- **Pior caso**: O(n log n)
- **Espaço adicional**: O(n)

---

## 2. Ordenação por Quick Sort 🚀

O **Quick Sort** também é um algoritmo do tipo "dividir para conquistar". A diferença está no pivô: o Quick Sort escolhe um elemento como pivô, e reorganiza o array de forma que os menores que o pivô fiquem à esquerda e os maiores à direita. Depois, ele recursivamente ordena as duas partes.

### Como funciona:
1. Escolha um **pivô**.
2. **Particione** o array em duas partes: uma com elementos menores que o pivô e outra com elementos maiores.
3. **Recursivamente** aplique o Quick Sort nas duas partes.

### Exemplo:
Dado o array `[38, 27, 43, 3, 9, 82, 10]`, um possível pivô poderia ser o `38`. O array seria particionado em:
- `[27, 3, 9, 10]` e `[43, 82]`
- Recursivamente, os sub-arrays são ordenados:
- `[3, 9, 10, 27]` e `[43, 82]`
- Array final: `[3, 9, 10, 27, 38, 43, 82]`

### Vantagens:
- **Rápido na prática**: Para a maioria dos casos, o tempo médio de execução é O(n log n).
- **In-place**: Não requer memória adicional significativa.

### Desvantagens:
- **Instável**: A ordem dos elementos iguais pode não ser preservada.
- **Pior caso**: No pior caso (quando o pivô escolhido é o menor ou maior elemento), o tempo de execução é O(n²), embora esse caso seja raro e possa ser evitado com boas estratégias de escolha de pivô.

### Complexidade:
- **Melhor caso**: O(n log n)
- **Pior caso**: O(n²)
- **Espaço adicional**: O(log n)

---

## 3. Ordenação por Heap Sort 🏗️

O **Heap Sort** é um algoritmo que utiliza uma estrutura de dados chamada heap binário. A ideia é transformar o array em um heap máximo (uma árvore binária onde o maior elemento está na raiz) e, repetidamente, extrair o maior elemento (a raiz) e colocá-lo no final do array.

### Como funciona:
1. **Construção do heap**: O array é transformado em um heap máximo.
2. **Extração do maior**: O maior elemento (na raiz) é trocado com o último elemento do heap, removido do heap, e o processo de reordenação do heap é repetido.
3. Repita até que o heap esteja vazio e o array ordenado.

### Exemplo:
Dado o array `[38, 27, 43, 3, 9, 82, 10]`, o Heap Sort o converte em um heap máximo:
- `[82, 27, 43, 3, 9, 38, 10]`
- O maior elemento `82` é movido para o final e removido do heap:
- `[43, 27, 38, 3, 9, 10, 82]`
- Repita até o array estar ordenado:
- `[3, 9, 10, 27, 38, 43, 82]`

### Vantagens:
- **In-place**: Ordenação realizada no próprio array, sem necessidade de memória adicional significativa.
- **Eficiência garantida**: O tempo de execução é sempre O(n log n), independentemente da ordem dos elementos.

### Desvantagens:
- **Instável**: A ordem dos elementos iguais pode não ser preservada.
- **Mais lento que o Quick Sort** em muitos casos, devido à sobrecarga da manipulação de heaps.

### Complexidade:
- **Melhor caso**: O(n log n)
- **Pior caso**: O(n log n)
- **Espaço adicional**: O(1)

---

## 🔑 **Resumo**

| Algoritmo  | Estabilidade | Complexidade Melhor Caso | Complexidade Pior Caso | Uso de Memória |
|------------|--------------|--------------------------|------------------------|----------------|
| **Merge Sort** | Estável      | O(n log n)               | O(n log n)              | O(n)           |
| **Quick Sort** | Instável     | O(n log n)               | O(n²)                   | O(log n)       |
| **Heap Sort**  | Instável     | O(n log n)               | O(n log n)              | O(1)           |

- **Merge Sort** é ótimo para garantir estabilidade e uma complexidade sempre eficiente, mas requer mais memória.
- **Quick Sort** é geralmente o mais rápido na prática, mas pode ter desempenho ruim no pior caso.
- **Heap Sort** é eficiente e não requer memória adicional, mas é um pouco mais lento que o Quick Sort em muitos cenários.




<br><br><br>
<p align="center"><img alt="Unicesumar" title="#Unicesumar" src="./assets/logo-unicesumar.png" width=120/></p>

<p align="center">Programa Ampliar Tecnologias - Estrutura de Dados</p>

<p align="center">Copyright :copyright: 2024</p>
