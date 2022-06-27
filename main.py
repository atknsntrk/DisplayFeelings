import cv2
import serial
import time
from deepface import DeepFace

video = cv2.VideoCapture(0)
arduino = serial.Serial(port='/dev/cu.usbmodem141401', baudrate=115200)


while True:
    _, frame = video.read()
    result = DeepFace.analyze(frame, actions=["emotion"], enforce_detection=False)

    print(result['dominant_emotion'])
    string = result['dominant_emotion'] + '\r'
    arduino.write(string.encode())
    time.sleep(2)