import numpy as np


# Simulation parameter

SIM_TIME = 480
arrival_rate = 1/5
service_rate = 1/4


# State variables

current_time = 0
queue=[]
server_busy = Fcalse
waiting_times = []
queue_lengths= []

# Generate first customer arrival

next_arrival = np.random.exponential(1/arrival_rate)
next_departure = float("inf")

while current_time < SIM_TIME:
    if next_arrival <= next_departure:
        current_time = next_arrival
        queue.append(current_time)
        queue_lengths.append(len(queue))
        next_arrival = current_time + np.random.exponential(1/arrival_rate)

        if not server_busy:
            arrival_time = queue.pop(0)
            service_time = np.random.exponential(1/service_rate)
            next_departure = current_time + service_time
            waiting_times.append(current_time - arrival_time)
            server_busy = True
        else:
            current_time = next_departure
            if queue:
                arrival_time = queue.pop(0)
                server_time = np.random.exponential(1/service_rate)
                next_departure = current_time + server_time
                waiting_times.append(current_time - arrival_time)
            else:
                next_departure = float('inf')
                server_busy = False


average_wait = np.mean(waiting_times)
max_queue = max(queue_lengths)
utilization = sum(waiting_times)/SIM_TIME

print(f"Average Waiting Time: {avg_wait:.2f} minutes")
print(f"Maximum Queue Length: {max_queue}")
print(f"Teller Utilization (approx): {utilization:.2f}")
