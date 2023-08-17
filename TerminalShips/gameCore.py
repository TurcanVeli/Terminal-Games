
import sys
import time
from bullets import bullets
from player import player
from enemy import enemy
import os
import keyboard
class GameCore():
    def __init__(self, world, rows, ship_shape,fps):
        self.world = world
        self.rows = rows
        self.ship_shape =  ship_shape
        self.level = 1     #for enemy power
        self._player = player(len(self.world),self.rows, self.ship_shape)#player object
        self._enemy =  enemy(len(self.world), self.rows) #enemy object
        if fps == 60:
            self.fps = 0.016   #60 fps: 0.01666666666 , 30 fps : 0.03333333333
        else :
            self.fps = 0.03
        self.enemy_crack = False
    
    def _run(self):
            self._clear_terminal()
            while True :
                if self.enemy_crack == False:
                    
                    self._core()
                    self._check_collision()
                    self._draw()
                    self._enemy._movement(self._player.position,self.new_world, "I")
                    self._uptade_bullets()
                    time.sleep(self.fps)
                    self._clear_terminal()
                else :
                    self._draw()
                    print("\nCong. pass next level! but there is no next level :D\n\n")
                    break
                    
    def _core(self):
        print(f"Level : {self.level}")
        if keyboard.is_pressed("q"):
            print("Game Over")
            sys.exit()
        if keyboard.is_pressed("a"):
            self._player.movement("left")
        elif keyboard.is_pressed("d"):
            self._player.movement("right")
        elif keyboard.is_pressed("space"):
            self._player.shoot() 

    def _draw(self):
        world_list = list(self.world)
        world_list[self._player.position:self._player.position + self._player.player_length] = self.ship_shape
        world_list[self._enemy.position:self._enemy.position + self._enemy.enemy_length] = self._enemy.enemy_shape
        world_list = self._bullet_print(self._player._bullets,world_list)
        world_list = self._bullet_print(self._enemy._bullets,world_list)
        self.new_world= "".join(world_list) 
        print(self.new_world)
    
    def _uptade_bullets(self):
        for index, bullet in enumerate(self._player._bullets): 
            bullet.uptade()
            if bullet.is_destroyed:
                self._player._bullets.pop(index)
        
        for index, bullet in enumerate(self._enemy._bullets): 
            bullet.uptade()
            if bullet.is_destroyed:
                self._enemy._bullets.pop(index)
        
    
    def _bullet_print(self, Bullet_List: list , world: list): 
        for bullet in Bullet_List:
            if  world[bullet.position] != bullet.bullet_shape:#düzelt
                world[bullet.position] = bullet.bullet_shape
            else : 
                Bullet_List.pop()
        return world
    
    def _check_collision(self):
        enemyPos = [i + self._enemy.position for i in range(self._enemy.enemy_length)]
        playerPos = [i+ self._player.position for i in range(self._player.player_length)]
        for index,bullet in enumerate(self._player._bullets):
            if bullet.position in enemyPos:
                self._player._bullets.pop(index)
                self.enemy_crack =  self._enemy._crack()

        for index,bullet in enumerate(self._enemy._bullets):
            if bullet.position in playerPos:
                self._enemy._bullets.pop(index)
                print("GAME OVER")
                sys.exit()
    
    def _clear_terminal(self):
   		os.system('cls' if os.name == 'nt' else 'clear')
    
    
    
    
        

    
