import random

class Player:
    def __init__(self, name: str) -> None:
        self.name = name
        self.score = 0
        self.health = 100
        self.x = 0
        self.y = 0


class DungeonGame:
    def __init__(self, name: str) -> None:
        self.player = Player(name)
        self.grid = [[],[],[],[],[]]
    
    def grid_init(self):
        for row in self.grid:
            for col in row:
                col = random.choice(['T', 'H', 'E'])

    def display(self):
        for row in self.grid:
            print(row)

game = DungeonGame('rafay')
game.display()