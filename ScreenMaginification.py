# screen maginification

import pyautogui
import pygame
import PIL
from PIL import Image

pygame.init()

LocationLeft = 50
LocationTop = 50
LocationWidth = 100
LocationHeight = 100

Magnification = 3

gameDisplay = pygame.display.set_mode((LocationWidth * Magnification , LocationHeight * Magnification ))

crashed = False

ImageFileName="ScreenLarger.png"

try:
    while not crashed:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                crashed = True
                
        x, y = pyautogui.position()

        LocationLeft = x - 25
        LocationTop = y - 25
    
        screenshot = pyautogui.screenshot(region=(LocationLeft,LocationTop, LocationWidth, LocationHeight))
        
        img = Image.frombytes(screenshot.mode,screenshot.size,screenshot.tobytes())
        img = img.resize((LocationWidth * Magnification, LocationHeight * Magnification))
        
        theimg = pygame.image.frombuffer(img.tobytes(), img.size, img.mode) 

        gameDisplay.blit(theimg,(0,0))
        
        pygame.display.update()

except KeyboardInterrupt:
    print('\n')
