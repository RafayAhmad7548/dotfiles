from abc import abstractmethod
import math

def calculate_total_area(shapes: list):
    sum = 0
    for shape in shapes:
        sum += shape.area()
    return sum

class Shape:
    @abstractmethod
    def area():
        pass

class Rectangle(Shape):
    def __init__(self, width: int, height: int) -> None:
        super().__init__()
        self.width = width
        self.height = height
    
    def area(self) -> int:
        return self.width * self.height
    
class Circle(Shape):
    def __init__(self, radius: int) -> None:
        super().__init__()
        self.radius = radius
    
    def area(self) -> float:
        return math.pi * (self.radius ** 2)
    

shape = Rectangle(5, 5)
print(shape.area())