import Functions as F

three_angle = []
four_angle = []
F.create_prisms(three_angle, four_angle)
result_three = F.count_result(three_angle)
result_four = F.count_result(four_angle)
print(f"Суммарный объем всех созданных треугольных призм равен = {result_three}"
      f".\nСуммарная площадь боковых поверхностей всех четырехугольных призм равна = {result_four}")
