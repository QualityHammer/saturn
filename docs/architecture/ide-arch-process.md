# IDE Architecture Process
The process for the "Saturn" architecture is an infinite loop that only ends when the user closes the window. Each iteration of that loop is described here.

#### Rendering Synchronization
The **IDE Core** goes through an iteration of it's process loop once every frame. (the speed of these iterations depends on the refresh rate of the monitor being used)  

Every iteration, the **IDE Core** begins by synchronizing the data needed for rendering, which basically goes through the **Buffers** and pulls all fully proccessed data to the **Rendering Data** to then be rendered. This will be described in more detail in the **Rendering** architecture.  

#### Event Processing
Then, it will read all user input and create **Events** from that input. Those **Events** will be sent to the **Thread Pool** to be split up and sent to the individual threads to be processed. The proccess of splitting **Events** into separate threads will be described in more detail in the **Thread Pool** architecture.  

#### GPU Processing
After sending the **Events** to the **Thread Pool**, the **IDE Core** sends the **Rendering Data** to the **Window** to be processed in the GPU and rendered to the screen.  

#### Wait for Threads
Once it's finished with GPU processing, the **IDE Core** waits for all **Meteoroid Threads** to finish. (basically threads that finish processing at the end of every frame to synchronize up with the core. these threads are used only for the tasks that are very quick to process. the types of threads will be described in more detail in the **Thread Pool** archictecture.) After this, the loop begins again.
