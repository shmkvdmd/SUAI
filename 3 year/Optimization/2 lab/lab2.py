import numpy as np
from scipy.optimize import linprog
import matplotlib.pyplot as plt

c = [-2, -3]  
A = [[3, 2], [1, 5], [-3, -1]]  
b = [8, 10, -33] 

# Решение задачи
result = linprog(c, A_ub=A, b_ub=b)

# Графическое решение
x1_values = np.linspace(0, 10, 100)
x2_values = np.linspace(0, 10, 100)
X1, X2 = np.meshgrid(x1_values, x2_values)
Z = 2 * X1 + 3 * X2  # Целевая функция

# Ограничения
constraint1 = X1 * 3 + X2 * 2 <= 8
constraint2 = X1 + X2 * 5 <= 10
constraint3 = X1 * 3 + X2 >= 33

plt.figure(figsize=(10, 6))
plt.contourf(X1, X2, Z, levels=20, cmap='viridis')
plt.colorbar(label='Значение целевой функции (Z)')
plt.xlabel('x1')
plt.ylabel('x2')

plt.plot(x1_values, (8 - 3 * x1_values) / 2, label='3*x1 + 2*x2 <= 8', linestyle='--')
plt.plot(x1_values, (10 - x1_values) / 5, label='x1 + 5*x2 <= 10', linestyle='--')
plt.plot(x1_values, 33 - 3 * x1_values, label='3*x1 + x2 >= 33', linestyle='--')

# Проверка на случай единственного решения
if result.status == 0:
    x1, x2 = result.x  # Получение значений переменных x1 и x2
    plt.plot(x1, x2, 'ro', label=f'Решение: x1 = {x1:.2f}, x2 = {x2:.2f}')
    print("Случай единственного решения.")
    
# Проверка на случай бесконечного множества решений
elif result.status == 2:
    print("Случай бесконечного множества решений (альтернативный оптимум).")

# Проверка на случай неограниченности целевой функции
elif result.status == 3:
    print("Случай неограниченности целевой функции.")
    
# Проверка на случай несовместности
elif result.status == 2 and result.fun == -np.inf:
    print("Случай несовместности (область допустимых значений пуста).")

plt.legend()
plt.title('Графическое решение задачи линейного программирования')
plt.grid(True)
plt.show()
