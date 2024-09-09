import random

class Player:
    def __init__(self, name: str) -> None:
        self.name = name
        self.score = 0
        self.health = 100
        self.x = 0
        self.y = 0
    
    def move_player(self, direction: str) -> None:
        if direction == 'l':
            if self.x > 0:
                self.x -= 1
        elif direction == 'r':
            if self.x < 5:
                self.x += 1
        elif direction == 'u':
            if self.y > 0:
                self.y += 1
        elif direction == 'd':
            if self.y <  5:
                self.y -= 1

class DungeonGame:
    def __init__(self, name: str) -> None:
        self.player = Player(name)
        self.grid = [[],[],[],[],[]]
        self.grid_init()
    
    def grid_init(self):
        for row in self.grid:
            for i in range(5):
                row.append(random.choice(['T', 'H', 'E']))
        self.grid[self.player.x][self.player.y] = '@'

    def display(self):
        for row in self.grid:
            for col in row:
                print(col, end=' ')
            print()

game = DungeonGame('rafay')
