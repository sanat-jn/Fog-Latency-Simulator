# Simulation Sample Output

This document provides a trace of the `Fog-Latency-Simulator` execution and the resulting data stored in `results.csv`.

## Terminal Execution Trace

Below is a snapshot of the decision engine processing tasks in real-time. Note how the system switches to **CLOUD** only when task complexity exceeds the local processing threshold.

```text
Fog Computing Offloading Simulator 
Fog Limit: 2048 KB | Cloud Bandwidth: 2.0 Mbps

Task [1]: Size=1069.00KB, Complexity=3.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 1.4000s | FOG MEMORY: 1069.00/2048 KB

Task [2]: Size=1003.00KB, Complexity=2.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 1.0000s | FOG MEMORY: 1003.00/2048 KB

Task [3]: Size=493.00KB, Complexity=4.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 1.8000s | FOG MEMORY: 493.00/2048 KB

Task [4]: Size=252.00KB, Complexity=2.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 1.0000s | FOG MEMORY: 252.00/2048 KB

Task [5]: Size=903.00KB, Complexity=2.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 1.0000s | FOG MEMORY: 903.00/2048 KB

Task [6]: Size=384.00KB, Complexity=0.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 0.2000s | FOG MEMORY: 384.00/2048 KB

Task [7]: Size=1078.00KB, Complexity=1.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 0.6000s | FOG MEMORY: 1078.00/2048 KB

Task [8]: Size=846.00KB, Complexity=1.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 0.6000s | FOG MEMORY: 846.00/2048 KB

Task [9]: Size=599.00KB, Complexity=0.50GC
 -> LATENCY: 0.6000s | FOG MEMORY: 846.00/2048 KB

 -> LATENCY: 0.6000s | FOG MEMORY: 846.00/2048 KB
 -> LATENCY: 0.6000s | FOG MEMORY: 846.00/2048 KB

Task [9]: Size=599.00KB, Complexity=0.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 0.2000s | FOG MEMORY: 599.00/2048 KB

Task [10]: Size=687.00KB, Complexity=2.50GC
 -> DECISION: PROCESS AT FOG
 -> LATENCY: 1.0000s | FOG MEMORY: 687.00/2048 KB