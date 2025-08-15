import time
import threading
import pygame
import sys


lyrics = [
    (25, "Biet noi nhu the nao"),
    (28, "Thi loi sau cuoi cung la loi chao"),
    (33, "Trai tim nghe nghen ngao"),
    (34, "Nuoc mat tuon trao"),
    (37, "Se xa nhau nghin trung"),
    (41, "Du chung nhau duoi cung khoang troi ay"),
    (61, "Biet chang the nao tay trong tay"),
    (67, "Chang phai tung hua yeu nhau dai lau"),
    (73, "Chang phai minh qua bao nhieu dam sau"),
    (79, "May troi con kia ma sao"),
    (85, "Nguoi nay chang thay nhau"),
    (91, "Dinh menh nao cho doi ta gap nhau"),
    (97, "Roi no cuop lay em ve chon ay"),
    (103,"Gio day chang con chi"),
    (109,"Le hoen bo mi em di"),
    (115,"Bau troi nhu xe tan nat coi long"),
    (121,"Gio chia tay nuoc mat chay thanh dong"),
    (127,"Cau mong em se niu buoc o lai voi toi duoc khong"),
    (133,"Ngay mua gop chut gio ay thanh bao"),
    (139,"Noi dau trong toi thet rao"),
    (145,"Khong biet vang em doi toi ra sao")
]

def play_music():
    pygame.mixer.init()
    pygame.mixer.music.load("loi.mp3")
    pygame.mixer.music.play()

def type_out(text, delay=0.5):
    sys.stdout.write("▶ ")
    for c in text:
        sys.stdout.write(c); sys.stdout.flush()
        time.sleep(delay)
    sys.stdout.write("\n"); sys.stdout.flush()

threading.Thread(target=play_music).start()
start = time.time() - 2.5

for ts, line in lyrics:
    wait = ts - (time.time() - start)
    if wait > 0:
        time.sleep(wait)
    type_out(line, delay=0.05)

pygame.mixer.music.set_endevent(pygame.USEREVENT)
while pygame.mixer.music.get_busy():
    time.sleep(0.5)
