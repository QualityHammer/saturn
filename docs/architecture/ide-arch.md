# Main IDE Architecture

*NOTE: This architecture is currently just an idea of how the IDE will process events. It has not been fully implemented yet, and will most likely change as more 
ideas arise.*  

The "Saturn" IDE needs to constantly deal with events. (ex: file read/write, buffer/tab editing, parsing, compilation, etc.) These events will be spread out to 
separate threads so that they can finish as fast as possible. The events also need to be processed in a way that keeps all data in sync so that nothing becomes 
corrupted by two threads writing to the same data. This multi-threaded architecture hopes to achieve that goal.

![IDE Architecture V0.1](../charts/V0.1-Architecture.jpg)
