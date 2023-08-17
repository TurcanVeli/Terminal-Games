import sys 
import os
class menu ():
    def __init__(self):
        self.menu = '''__________________

|    1) Start    |
|    2) Options  |
|    3) Exit     |
__________________'''
    
        self.options = '''    Options    
        Select shape of your ship
        1) T*T
        2) {+}
        3) +(0)+
        4) *|+|*
        
        Choose Fps
        5) 60 fps 6) 30 fps 
        7)  to back previos page, press 7\n'''
    
        self.ships = ["T*T","{+}","+(0)+","*|+|*"]
        self.selected_ship = "^+^"
        self.fps = 30
    
    def _run(self):
        while True:
            print(self.menu)
            ans =  self._ask()
            if ans == 1:
                return 1
            elif ans ==  2:
                self._clear()
                print(self.options)
                ans = self._ask()
                if ans >=1 and ans <=4 :
                    self.selected_ship = self.ships[ans-1]
                elif ans == 5:
                    self.fps = 60
                    
                elif ans == 6:
                    self.fps == 30
                self._clear()
                

            elif ans == 3:
                sys.exit()
            
            elif ans > 0 or ans < 3:
                self._clear()
                print("Choose a number between 1 to 3 incule bot of them\n")

    def _ask(self):
        try :
            self.ans = int(input("what is your choice?\n"))
            return self.ans
        except ValueError:
            return 0
    

    def _clear(self):
        os.system('cls' if os.name == 'nt' else 'clear')
