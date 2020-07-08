# Cache-Buffer Architecture

To keep data in sync and usable at almost any point in the iteration, (besides the sync process) "Saturn" will utilize multiple layers of temporary storage.

## Cache

The **Cache** is the first layer of temporary storage. All data in the **Cache** has been synchronized in the sync process at the beginning of the iteration. Thus, any thread can read from the **Cache** at any point (besides the sync process) to get the most current, synchronized data without issues.  

## Buffer

When a thread needs to update the data in the **Cache**, (ex: open a file, move the cursor, edit an open file) the thread should first store the data in a **Buffer**. The **Buffer** is the second layer of temporary storage, and new data will be stored in a **Buffer** until the end of the iteration.

## Synchronizer

The final piece to the synchronized storage is the **Synchronizer**. At the beginning of every iteration, the **Synchronizer** reads from the **Buffer** and moves any new data into the **Cache**.  

The data needs to be moved in the order of the user **Events** that called for the data to be updated. So, each piece of new data in the **Buffer** will need to be timestamped with the same timestamp as the **Event**.
