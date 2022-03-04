import serial  # Import UART Module
import time
import pandas as pd
from multiprocessing import Pool

from Mid import GVar

import ADR

from queue import Queue
from threading import Thread
import time



def f1(q, x):
    ADR.ADR_main(q,x)

if __name__ == '__main__':
    x1 = 10

    result_queue = Queue()

    # We create two threads and pass shared queue to both of them.
    t1 = Thread(target=f1, args=(result_queue, x1))


    # Starting threads...
    print("Start: %s" % time.ctime())
    t1.start()


    # Waiting for threads to finish execution...
    t1.join()

    print("End:   %s" % time.ctime())

    # After threads are done, we can read results from the queue.
    while not result_queue.empty():
        result = result_queue.get()
        print(result)

