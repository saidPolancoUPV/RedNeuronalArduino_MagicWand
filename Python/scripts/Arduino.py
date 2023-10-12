from threading import Thread
from collections import deque
import serial
import time
import sys


class Arduino:
    """
    Clase para obtener datos desde el puerto serial
    """
    
    def __init__(self, port, num_metrics=1, max_samples=20, baudrate=9600, serial_timeout=0.1):
        """
        Método constructor
        """
        self.port_ = port
        self.baudrate_ = baudrate
        self.serial_ = None
        self.serial_timeout = serial_timeout
        self.thread_ = None
        self.isReceiving_ = False
        self.isRun_ = False
        self.num_metrics_ = num_metrics
        self.max_samples_ = max_samples
        self.data_ = []
        
        self.init_params_()
        
    def init_params_(self):
        for i in range(self.num_metrics_):
            self.data_.append(deque([0] * self.max_samples_, maxlen=self.max_samples_))
        
    def start(self):
        print(f"Intentando conectar al puerto {self.port_}")
        
        try:
            self.serial_ = serial.Serial(self.port_, baudrate=self.baudrate_, timeout=self.serial_timeout)
            self.thread_ = Thread(target=self.background_read_)
            self.thread_.start()
            self.isRun_ = True
            print("Conectado...");
        except:
            sys.exit("Failed to connect with " + str(self.port_))

    def get_serial_data(self, frame, lines, lineValueText, lineLabel, pltNumber):
        data = self.data_[pltNumber]
        lines.set_data(range(self.max_samples_), data)
        # lineValueText.set_text(lineLabel + ' = ' + str(self.rawData[pltNumber]))

    def background_read_(self):
        time.sleep(1.0)
        if self.serial_:
            self.serial_.flushInput()
            while self.isRun_:
                line = self.serial_.readline()
                if line:
                    raw_data = line.decode().strip().split("\t")
                    for i in range(self.num_metrics_):
                        self.data_[i].append(float(raw_data[i]))
    
    def get_data(self, index):
        if index not in [i for i in range(self.num_metrics_)]:
            print("El índice no es correcto")
        else:
            return list(self.data_[index])
    
    def close(self):
        self.isRun_ = False
        if self.thread_ is None:
            pass
        else:
            self.thread_.join()
        
        if self.serial_ is None:
            pass
        else:
            self.serial_.close()
        print("Desconectado...")
                    