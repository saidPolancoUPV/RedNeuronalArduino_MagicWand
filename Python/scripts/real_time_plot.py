import numpy as np
import matplotlib.pyplot as plt

import matplotlib.animation as animation
from collections import deque
from Figure import makeFigure
from Arduino import Arduino
import time

maxSample = 100
sizeData = 6
sampleTime = 100

legendLabel = ['ax', 'ay', 'az', 'gx', 'gy', 'gz']
xLimit = [(0, maxSample)]*sizeData
yLimit = [(-20, 20), (-20, 20), (-20, 20), (-500, 500), (-500, 500), (-500, 500)]
style = ['r-', 'g-', 'b-', 'r-', 'g-', 'b-']
anim = []

X = list(range(100))
y = deque([0]*100, maxlen=100)

a = Arduino("/dev/ttyUSB0", num_metrics=sizeData, max_samples=maxSample)
a.start()

time.sleep(0.5)

for i in range(sizeData):
    fig, ax = makeFigure(xLimit[i], yLimit[i], 'Data'+str(i))
    lines = ax.plot([], [], style[i], label=legendLabel[i])[0]
    legendValue = ax.text(0.50, 0.90, '', transform=ax.transAxes)
    anim.append(animation.FuncAnimation(fig, a.get_serial_data, fargs = (lines, legendValue, legendLabel[i], i), interval = sampleTime))
    plt.legend(loc='upper left')
    plt.grid()

plt.show()

a.close()
