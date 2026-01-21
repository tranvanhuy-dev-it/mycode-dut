from PIL import Image
import os

FRAME_W = 128
FRAME_H = 128

def split(img):
    return [img.crop((i*FRAME_W, 0, (i+1)*FRAME_W, FRAME_H))
            for i in range(img.width // FRAME_W)]

idle   = split(Image.open("assets/boss/boss_idle.png").convert("RGBA"))
move   = split(Image.open("assets/boss/boss_move.png").convert("RGBA"))
charge = split(Image.open("assets/boss/boss_charge.png").convert("RGBA"))
attack = split(Image.open("assets/boss/boss_attack.png").convert("RGBA"))
hurt   = split(Image.open("assets/boss/boss_hurt.png").convert("RGBA"))
death  = split(Image.open("assets/boss/boss_death.png").convert("RGBA"))

# Fix thiếu frame
while len(hurt) < 4:
    hurt.append(hurt[-1])

death_frame = death[-1]

sheet = Image.new("RGBA", (FRAME_W*4, FRAME_H*4), (0,0,0,0))

# Row 0: Idle
for i in range(4):
    sheet.paste(idle[i], (i*FRAME_W, 0))

# Row 1: Move
for i in range(4):
    sheet.paste(move[i], (i*FRAME_W, FRAME_H))

# Row 2: Charge + Attack
sheet.paste(charge[0], (0, FRAME_H*2))
sheet.paste(charge[1], (FRAME_W, FRAME_H*2))
sheet.paste(attack[0], (FRAME_W*2, FRAME_H*2))
sheet.paste(attack[1], (FRAME_W*3, FRAME_H*2))

# Row 3: Hurt + Death
sheet.paste(hurt[0], (0, FRAME_H*3))
sheet.paste(hurt[1], (FRAME_W, FRAME_H*3))
sheet.paste(hurt[2], (FRAME_W*2, FRAME_H*3))
sheet.paste(death_frame, (FRAME_W*3, FRAME_H*3))

os.makedirs("assets/boss", exist_ok=True)
sheet.save("assets/boss/boss_spritesheet.png")

print("✔ boss_spritesheet with MOVE created")