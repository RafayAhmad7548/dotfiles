import random

class Player:
    def __init__(self, name) -> None:
        self.name = name
        self.score = 0
        self.health = 100
        self.x = 0
        self.y = 0


class DungeonGame:
    def __init__(self) -> None:
        self.player = Player()
        self.grid = [[],[],[],[],[]]
    
    def grid_init(self):
        for row in self.grid:
            for col in row:
                pass

        pass