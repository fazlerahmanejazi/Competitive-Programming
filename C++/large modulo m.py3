# Uses python3
import sys

def optimal_weight(total,weights):
    values = weights
    total_items = len(weights)
    rows = total_items + 1
    cols = total + 1

    memory = [[0 for _ in range(cols)] for _ in range(rows)]

    for i in range(1, rows):
        for j in range(1, cols):
            if j < weights[i - 1]:
                memory[i][j] = memory[i - 1][j]
            else:
                memory[i][j] = max(memory[i - 1][j], values[i - 1] + memory[i - 1][j - weights[i - 1]])

    max_value = memory[rows - 1][cols -1]


if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
