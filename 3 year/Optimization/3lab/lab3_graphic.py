import matplotlib.pyplot as plt

# Оптимальное решение
optimal_x1 = 1.7142857142857142
optimal_x2 = 2.857142857142857

# Создаем график
plt.figure(figsize=(8, 6))

# Оптимальное решение
plt.plot(optimal_x1, optimal_x2, 'ro', label="Оптимальное решение (1.71, 2.86)")

plt.xlim(0, 5)
plt.ylim(0, 5)
plt.xlabel("X1")
plt.ylabel("X2")
plt.legend(loc='upper right')
plt.title("Оптимальное решение задачи линейного программирования")
plt.grid(True)
plt.show()
