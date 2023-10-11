from Arduino import Arduino
import time


a = Arduino("/dev/ttyUSB0")

a.start()


for i in range(50):
    print(a.get_data(0))
    time.sleep(1)

a.close()
