#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import cgi

# Вывод заголовка Content-type перед выводом данных
print("Content-type: text/html\n")

# Получение данных из формы
form = cgi.FieldStorage()

# Получение значений полей из формы
model = form.getvalue('model')
creator = form.getvalue('creator')
color = form.getvalue('color')
choices = form.getvalue('choices')
battery = form.getvalue('battery') if 'battery' in form else None
cable = form.getvalue('cable') if 'cable' in form else None
age = form.getvalue('age')

# Вывод данных на страницу
print("<h2>Характеристики нового робота:</h2>")
print("<p>Модель: {}</p>".format(model))
print("<p>Производитель: {}</p>".format(creator))
print("<p>Цвет: {}</p>".format(color))
print("<p>Тип робота: {}</p>".format(choices))
print("<p>Зарядка: {}</p>".format(', '.join(filter(None, [battery, cable])) if battery or cable else "Не указано"))
print("<p>Минимальный возраст ребенка: {}</p>".format(age))
