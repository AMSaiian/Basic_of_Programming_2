import Prism as P


def create_prisms(three_angle: list[P.Prism3], four_angle: list[P.Prism4]):
    user_prism3 = P.Prism3()
    user_prism3.set_base_side(float(input("Введите длину стороны основания треугольной правильной призмы: ")))
    user_prism3.set_lateral_side(float(input("Введите длину боковой стороны треугольной правильной призмы: ")))
    three_angle.append(user_prism3)
    print(f"\nСоздана 1 треугольная правильная призма с размером боковой стороны = "
          f"{user_prism3.get_lateral_side()} и размером стороны основания = {user_prism3.get_base_side()}"
          f".\nЕе объем равен = {user_prism3.get_volume()}"
          f"\nЕе площадь боковой поверхности равна = {user_prism3.get_side_surface_square()}")
    user_prism4 = P.Prism4()
    user_prism4.set_base_side(float(input("\nВведите длину стороны основания четырехугольной правильной призмы: ")))
    user_prism4.set_lateral_side(float(input("Введите длину боковой стороны четырехугольной правильной призмы: ")))
    four_angle.append(user_prism4)
    print(f"\nСоздана 1 четырехугольная правильная призма с размером боковой стороны = "
          f"{user_prism4.get_lateral_side()} и размером стороны основания = {user_prism4.get_base_side()}"
          f".\nЕе объем равен = {user_prism4.get_volume()}"
          f"\nЕе площадь боковой поверхности равна = {user_prism4.get_side_surface_square()}")
    m = int(input("\nВведите количество треугольных и четырехугольных призм, которые нужно создать: "))
    lateral_side3 = user_prism3.get_lateral_side()
    base_side3 = user_prism3.get_base_side()
    lateral_side4 = user_prism4.get_lateral_side()
    base_side4 = user_prism4.get_base_side()
    for i in range(m):
        lateral_side3 = lateral_side3 + 20 * 3.0**0.5 / (3.0 * base_side3**2)
        temp_prism3 = P.Prism3(lateral_side3, base_side3)
        three_angle.append(temp_prism3)
        print(f"\nСоздана {i + 2} треугольная правильная призма с размером боковой стороны = "
              f"{temp_prism3.get_lateral_side()} и размером стороны основания = {temp_prism3.get_base_side()}"
              f".\nЕе объем равен = {temp_prism3.get_volume()}"
              f"\nЕе площадь боковой поверхности равна = {temp_prism3.get_side_surface_square()}")
        lateral_side4 = lateral_side4 + 5.0 / base_side4**2
        temp_prism4 = P.Prism4(lateral_side4, base_side4)
        four_angle.append(temp_prism4)
        print(f"\nСоздана {i + 2} четырехугольная правильная призма с размером боковой стороны = "
              f"{temp_prism4.get_lateral_side()} и размером стороны основания = {temp_prism4.get_base_side()}"
              f".\nЕе объем равен = {temp_prism4.get_volume()}"
              f"\nЕе площадь боковой поверхности равна = {temp_prism4.get_side_surface_square()}\n")


def count_result(prisms):
    result = 0
    if prisms[0].get_base_corners() == 3:
        for prism in prisms:
            result += prism.get_volume()
    else:
        for prism in prisms:
            result += prism.get_side_surface_square()
    return result
