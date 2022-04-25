from math import tan, pi


class Prism:
    def __init__(self, base_corners: int = None, lateral_side: float = None, base_side: float = None):
        if lateral_side and base_side and base_corners:
            if lateral_side > 0 and base_side > 0 \
                    and base_corners >= 3:
                self._lateral_side = lateral_side
                self._base_side = base_side
                self.__base_corners = base_corners
            else:
                self._lateral_side = None
                self._base_side = None
                self.__base_corners = None
        else:
            self._lateral_side = lateral_side
            self._base_side = base_side
            self.__base_corners = base_corners

    def __get_base_perimetr(self):
        return self._base_side * self.__base_corners

    def __get_base_square(self):
        return (self._base_side ** 2 * self.__base_corners) / 4.0 * tan(pi / self.__base_corners)

    def set_base_corners(self, amount:int):
        if amount >= 3:
            self.__base_corners = amount

    def set_base_side(self, side:float):
        if side > 0:
            self._base_side = side

    def set_lateral_side(self, side:float):
        if side > 0:
            self._lateral_side = side

    def get_base_corners(self):
        return self.__base_corners

    def get_base_side(self):
        return self._base_side

    def get_lateral_side(self):
        return self._lateral_side

    def get_side_surface_square(self):
        return self._lateral_side * self.__get_base_perimetr()

    def get_volume(self):
        return self._lateral_side * self.__get_base_square()


class Prism3(Prism):
    def __init__(self, lateral_side: float = None, base_side: float = None):
        super().__init__(3, lateral_side, base_side)

    def set_base_corners(self, amount: int):
        super().set_base_corners(3)

    def get_side_surface_square(self):
        return self._lateral_side * self._base_side * 3

    def get_volume(self):
        return self._lateral_side * self._base_side ** 2 * 3.0 ** 0.5 * 0.25


class Prism4(Prism):
    def __init__(self, lateral_side: float = None, base_side: float = None):
        super().__init__(4, lateral_side, base_side)

    def set_base_corners(self, amount: int):
        super().set_base_corners(4)

    def get_side_surface_square(self):
        return self._lateral_side * self._base_side * 4

    def get_volume(self):
        return self._lateral_side * self._base_side ** 2
