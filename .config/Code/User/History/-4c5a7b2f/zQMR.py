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
            if self.x < 4:
                self.x += 1
        elif direction == 'u':
            if self.y > 0:
                self.y += 1
        elif direction == 'd':
            if self.y < 4:
                self.y -= 1

class DungeonGame:
    def __init__(self, name: str) -> None:
        self.player = Player(name)
        self.grid = [[],[],[],[],[]]
        self.game_over = False
        self.grid_init()
    
    def grid_init(self) -> None:
        for row in self.grid:
            for i in range(5):
                row.append(random.choice(['T', 'H', 'E']))
        self.grid[self.player.x][self.player.y] = '@'

    # def display(self):
    #     for row in self.grid:
    #         for col in row:
    #             print(col, end=' ')
    #         print()
    
    def check_cell(self, x: int, y: int) -> None:
        if self.grid[x][y] == 'T':
            self.player.health -= 20
            print('the player hit a trap, ouuuch!!')
            if self.player.health <= 0:
                self.game_over = True
                print('aaaaa my health, i die -- game over')
        elif self.grid[x][y] == 'H':
            if self.player.health < 100:
                self.player.health += 10
            print('the player got a health potion, nom nom')
        elif self.grid[x][y] == 'E':
            print('ooo nothing here')
    
    def play_turn(self):
        a = input('enter a character to move the player(l, r, u, d): ')
        self.player.move_player(a)
        self.check_cell(self.player.x, self.player.y)
        print('current player health: ', self.player.health)


game = DungeonGame('rafay')
while not game.game_over:
    game.play_turn()
