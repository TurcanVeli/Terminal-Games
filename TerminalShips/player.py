import random
from bullets import bullets
class player():
    def __init__(self, world_size: int, rows: int, ship_shape):
        self.rows = rows
        self.ship_shape = ship_shape
        self.player_length = len(self.ship_shape)
        self.world_size = world_size
        #position 
        self.position = random.randint(self.world_size-self.rows-1,(self.world_size-self.player_length))
        #400-40 = 360   400 - 5 =  395
        self._bullets = []
        
    def movement(self, key):
        if key == "right":
            if self.position != self.world_size-self.player_length: 
                self.position += 1
                
        if key == "left": 
            if self.position != self.world_size - self.rows: 
                self.position -= 1

    def shoot(self):
        if len(self._bullets) <= 3 :
            self._bullets.append(bullets(self.position-39, -41))
            
        
        