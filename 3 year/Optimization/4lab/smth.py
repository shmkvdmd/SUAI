import pulp

# Создание модели
model = pulp.LpProblem("Maximize_Z", pulp.LpMaximize)

# Определение переменных
x = pulp.LpVariable("x", lowBound=0)
y = pulp.LpVariable("y", lowBound=0)

# Коэффициенты целевой функции
a, b = 1, 2

# Целевая функция
model += a * x + b * y, "Z"

# Определение ограничений
c1, d1, e1 = 1, 1, 20
c2, d2, e2 = 3, 1, 30
model += c1 * x + d1 * y <= e1, "Constraint1"
model += c2 * x + d2 * y <= e2, "Constraint2"

# Решение задачи
model.solve()

# Результаты
optimal_value = pulp.value(model.objective)
x_value, y_value = x.varValue, y.varValue

# Теневые цены
shadow_prices = {name: constraint.pi for name, constraint in model.constraints.items()}

print("Оптимальное значение Z:", optimal_value)
print("Значения x и y:", x_value, y_value)
print("Теневые цены:", shadow_prices)