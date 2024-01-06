import socket
from pynput import mouse

ESP32_IP = '192.168.1.26'  # Remplacez par l'adresse IP de votre ESP32
ESP32_PORT = 80

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def on_move(x, y):
    data = f"{x},{y}"
    client_socket.sendto(data.encode(), (ESP32_IP, ESP32_PORT))

with mouse.Listener(on_move=on_move) as listener:
    listener.join()
