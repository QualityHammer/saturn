# Main IDE Architecture

*NOTE: This architecture is currently just an idea of how the "Saturn" IDE will process events. It has not been fully implemented yet, and will most likely change as more ideas arise.*  

The "Saturn" IDE needs to constantly deal with events. (ex: file read/write, buffer/tab editing, parsing, compilation, etc.) These events will be spread out to separate threads so that they can finish as fast as possible. The events also need to be processed in a way that keeps all data in sync so that nothing becomes corrupted by two threads writing to the same data. This multi-threaded architecture hopes to achieve that goal.  

## Current IDE Architecture

![IDE Architecture V0.1](../charts/V0.1-Architecture.jpg)  
The architecture for "Saturn" is centered around the **Event**, as everything that happens in the IDE is followed by an **Event** created from the user's input. (ex: mouse click, keypress, etc.) Thus, the architecture is created to process these events as fast as possible, while keeping the UI experience smooth and synchronized.  

#### Rendering Synchronization
The **IDE Core** goes through an iteration of it's process loop once every frame. (the speed of these iterations depends on the refresh rate of the monitor being used)  

Every iteration, the **IDE Core** begins by synchronizing the data needed for rendering, which basically goes through the **Buffers** and pulls all fully proccessed data to the **Rendering Data** to then be rendered. This will be described in more detail in the **Rendering** architecture.  

#### Event Processing
Then, it will read all user input and create **Events** from that input. Those **Events** will be sent to the **Thread Pool** to be split up and sent to the individual threads to be processed. The proccess of splitting **Events** into separate threads will be described in more detail in the **Thread Pool** architecture.  

#### GPU Processing
After sending the **Events** to the **Thread Pool**, the **IDE Core** sends the **Rendering Data** to the **Window** to be processed in the GPU and rendered to the screen.  

#### Wait for Threads
Once it's finished with GPU processing, the **IDE Core** waits for all **Meteoroid Threads** to finish. (basically threads that finish processing at the end of every frame to synchronize up with the core. these threads are used only for the tasks that are very quick to process. the types of threads will be described in more detail in the **Thread Pool** archictecture.) After this, the loop begins again.
