class bullets():
    def __init__(self, position, velocity):
        self.is_destroyed = False
        self.position = position 
        self.bullet_shape = "I"
        self.bullet_delay = 0
        self.velocity = velocity
    
    def uptade(self): #True if player is shooting 
        self.bullet_delay+=1
        if self.bullet_delay == 10:
            self.bullet_delay = 0
            if self.position < 40 or self.position > 362 :
                self.is_destroyed =  True
            if self.is_destroyed == False:
                self.position += self.velocity
                
        
    
    