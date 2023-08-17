import random 
from bullets import bullets
#there will be one AI enemy 
class enemy():
    def __init__(self, world_size: int, rows: int):
        self.rows = rows
        self.enemy_shape = "(*)"
        self.enemy_length = len(self.enemy_shape)
        self.world_size = world_size
        self.position = random.randint(0,self.rows-self.enemy_length+1)
        self.is_hard = False
        self.movement_delay = 0#delay for movement
        self.shoot_delay = 0 #delay of shoot
        self._bullets = list()
    
    def _movement(self, player_position: int, world: str, bullet: str):
        self.movement_delay += 1
        self._check_level()
        self.enemyPos = [self.position, self.position+1, self.position+2]
        bulletPos = world.find(bullet)
        check_list = list()
        CONSTANT_NUMBER = 41 #Consant number for linear motion
        Temp_pos_OfPLayer = player_position-CONSTANT_NUMBER*9#projection of pplayer position
        subs = Temp_pos_OfPLayer - self.position
        for i in range(1,4):
            check_list.append(bulletPos-CONSTANT_NUMBER*i)
    
        if self.movement_delay == 10 :#this delay
            self.shoot_delay+1
            self.movement_delay = 0
            if self._compare_intersect(check_list,self.enemyPos)  : 
                if self.position + self.move > 0 or self.position + self.move < self.rows:
                    self.position += self.move
            if subs < 0:
                self.position-=1
            elif subs > 0:
                self.position +=1
            elif subs ==  0 or self.shoot_delay == 10 :
                self._shoot()
                self.shoot_delay = 0 
            
    
    def _shoot(self):
        print("enemt bulletler",len(self._bullets))
        if len(self._bullets) <= 3 :
            self._bullets.append(bullets(self.position + 42, 41))

    def _crack(self):
        self.enemy_shape = "<BOOM>"
        self.enemy_length = len(self.enemy_shape)
        return True
     
    def _check_level(self):#This function will uptated
        if self.is_hard == False:
            self.move = random.choice([1,-1])

    def _compare_intersect(self,x, y):
        a = [i for i in x if i in y ]
        if len(a) > 0:
            return True