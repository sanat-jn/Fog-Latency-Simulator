# FogSim-C: Multi-Tasking Edge Computing Simulator

A discrete-event simulator written in **C** designed to model task offloading decisions in a heterogeneous Fog-Cloud environment. This project evaluates the trade-offs between local processing (Fog) and remote execution (Cloud) based on network latency, computational complexity, and hardware constraints.

##  Overview

In modern IoT ecosystems, sending every piece of data to the Cloud causes latency bottlenecks. **FogSim-C** simulates a "middle layer" (Fog node) that makes real-time decisions:
1.  **Process Locally:** If the Fog node has enough RAM and can finish the task faster.
2.  **Offload to Cloud:** If the Fog node is congested (Memory Full) or if the Cloud's high-speed processors can overcome the network delay.

##  Key Technical Features

* **Discrete-Time Simulation:** Uses a **Global Clock** to track task lifecycles over a continuous time horizon.
* **Dynamic Resource Management:** Implemented a **Linked List Task Queue** to manage concurrent tasks.
* **Manual Memory Management:** Utilizes `malloc` and `free` for efficient heap allocation, simulating real-world embedded system constraints.
* **Mathematical Modeling:** Decisions are powered by a cost-function: 
    $$Total\ Latency = \frac{Data}{Bandwidth} + Prop.\ Delay + \frac{Cycles}{CPU\ Speed}$$
* **Congestion Awareness:** The simulator detects "Memory Full" states and automatically triggers offloading protocols.

##  Installation & Usage

### Prerequisites
* A C compiler (GCC recommended)

### Compilation
```bash
gcc main.c -o FogSim