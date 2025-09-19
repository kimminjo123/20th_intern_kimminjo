import socket
import cv2

def main():
    UDP_IP = "172.100.4.74"
    UDP_PORT = 9505

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    photo = cv2.imread("/home/kmj/Desktop/hw2.jpg")
    photo_2 = cv2.imencode(".jpg", photo)[1].tobytes()

    sock.sendto(photo_2, (UDP_IP, UDP_PORT))
    print("Sending complete")