class Shape:
    def area():
        pass

class Rectangle(Shape):
    def __init__(self, width: int, height: int) -> None:
        super().__init__()
        self.width = width
        self.height = height
    
    def area(self) -> int:
        return self.width * self.height