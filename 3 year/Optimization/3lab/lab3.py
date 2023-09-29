from scipy.optimize import linprog

# Коэффициенты целевой функции (максимизируем X1 - X2)
c = [-1, 1]

# Коэффициенты левых частей ограничений
A = [
    [2, 3],    # для 2*X1 + 3*X2 <= 12
    [1, -2],   # для -X1 + 2*X2 >= -4
    [-1, -1]   # для X1 + X2 >= 1
]

# Правые части неравенств
b = [12, -4, -1]

# Границы переменных (x1 и x2)
x_bounds = [(0, None), (0, None)]

# Решение задачи
result = linprog(c, A_ub=A, b_ub=b, bounds=x_bounds, method='simplex')

# Вывод оптимального решения
print("Оптимальное решение:")
print("x1 =", result.x[0])
print("x2 =", result.x[1])
print("Максимальное значение X1 - X2 =", -result.fun)
