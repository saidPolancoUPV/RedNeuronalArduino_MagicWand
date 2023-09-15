import serial
from tkinter import *


def led_on():
    arduinoData.write('HHH'.encode())


def led_off():
    arduinoData.write('LLL'.encode())


led_control_windows = Tk()
led_control_windows.minsize(width=266, height=266)
led_control_windows.maxsize(width=266, height=266)


btn = Button(led_control_windows, text="led on", command=led_on)
btn2 = Button(led_control_windows, text='led off', command=led_off)

btn.pack()
btn2.pack()

arduinoData = serial.Serial('/dev/ttyUSB0', 9600)

mainloop()