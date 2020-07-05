# saturn
Saturn is an IDE project in it's very early development. 

The main goal of the project is to see if it's possible to create a very minimal IDE that can be easily expanded to a developer's desire with powerful plugins/addons. 

All of these features will keep that goal in focus during development: 
   
  1.  Keep the main executable a very small size. (< 50mb ?) It should be much smaller than the size of other text editors/IDEs that have a size of 60-200mb with the bulk of the storage
      used by any plugins/addons installed. 
  2.  Run all "visible" tasks in separate threads to allow the user to do their work while waiting as little as possible for the IDE's tasks to be performed. 
      This means that the user should never be impeded from working because of either visible lag or a task being run. 
    a.  A visible task in this feature is described as anything that takes a visible amount of time to run (> 16 milliseconds ?) 
    b.  Some tasks such as compiling are limited by the speed of the computer, and the speed of such tasks cannot be increased unless the compiler itself is run on multiple threads. (among other features such as a compiler cache) 
        Even so, compiling is a task that can only be sped up by so much. If your computer is not fast enough, you will have to wait for your program to compile in many cases no matter what IDE you use. 
  3.  Have an API accessible from python for easy creation of plugins/addons. Any feature that is not crucial enough to be put in the main IDE will be put into a plugin/addon. The API 
      will also be accessible from c++ for any plugins that need it. This will allow users to choose what they do and don't want to install so as to not install any features they wouldn't be using anyways.
  4.  Run as much graphics rendering as possible on the GPU (currently using OpenGL) to free up the CPU for all other tasks.

## NOTE
The name "Saturn" is a placeholder and will change in the future.
