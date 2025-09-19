import socket
import numpy
import cv2

def main():
    UDP_IP = "172.100.6.133"
    UDP_PORT = 12345

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((UDP_IP, UDP_PORT))

    print("Waiting photo")

    data, addr = sock.recvfrom(65535)
    photo = numpy.fromstring(data, dtype=numpy.uint8)
    photo_2 = cv2.imdecode(photo, cv2.IMREAD_COLOR)

    cv2.imshow("Receive photo", photo_2)
    cv2.waitKey(0)
    cv2.destroyAllWindows()