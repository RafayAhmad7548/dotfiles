from abc import ABC, abstractmethod
import math

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
    




