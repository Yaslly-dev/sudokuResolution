# Sudoku Solver

Um resolvedor de Sudoku eficiente desenvolvido em **C**, utilizando o algoritmo de **Backtracking**. O projeto processa tabuleiros de Sudoku através de uma matriz e apresenta a solução formatada no console.

## 🚀 Tecnologias
* **Linguagem:** C
* **Algoritmo:** Backtracking (Busca em profundidade)

---

## 🧩 O Algoritmo
A resolução utiliza a técnica de **tentativa e erro sistemática**. O programa percorre cada célula vazia (representada por `0`), tenta inserir um número de 1 a 9 e valida se ele respeita as três regras fundamentais do Sudoku:
1. O número não pode se repetir na **linha**.
2. O número não pode se repetir na **coluna**.
3. O número não pode se repetir no **quadrante 3x3**.

Se o algoritmo encontrar um impasse, ele retorna à célula anterior (backtrack) e tenta o próximo número possível.

---
