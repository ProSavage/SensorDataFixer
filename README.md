# SensorDataFixer

This is a commandline application to fix sensor data issues from a csv file, or a directory of csv files.

**Usage**
In cmd.exe: `SensorDataFixer.exe in out`

**Arguments**

> `in` represents the folder containing the data files to fix entries in.

> `out` represents the folder where the fixed files will be written to.

## About

I built this software to be able to theoretically parse massive data files, and I am utilizing file streams to do this.
The algorithm is a O(N) implementation, meaning it will scale linearly with the amount of data given, however it's memory footprint
should be low as the data is streamed and only the previous row is kept in memory once at a time, rather than the entire dataset being read,
manipulated, and then written to file.


## Problem Description
My girlfriend's lab requires the employees to go through massive files of sensor data.
This sensor data comes from fields where the sensors are **supposed** to send data once an hour.
However, many times the connection is spotty, or I presume a sensor dies, and there are data entries that are missing.
They are then told to manually do what this application does, which is a very tedious job.
This application goes through the files and automatically finds rows where data is missing and inserts blank ones.

### Example Data
| Date            | Sensor1 | Sensor2 | Sensor3 |
|-----------------|---------|---------|---------|
| 5/24/2018 11:32 | 0      | 0     | 0    |
| 5/24/2018 12:32 | 0      | 0     | 0    |
| 5/24/2018 14:23 | 0      | 0     | 0    |
| 5/24/2018 15:56 | 0      | 0     | 0    |
| 5/24/2018 19:41 | 0      | 0     | 0    |
| 5/24/2018 22:41 | 0      | 0     | 0    |
| 5/25/2018 0:23  | 0      | 0     | 0    |

The sensor values are not important, but the date column is, if you will notice there is an entry missing between row 2 and 3,
and there are multiple entries missing between row 4 and 5, and between row 6 and 7 we are missing entries that go on to the next day.

The application will automatically handle adding multiple missing entries, the resulting data looks like:

| Date            |       |       | Sensor1 | Sensor2 | Sensor3 |
|-----------------|-------|-------|---------|---------|---------|
| 5/24/2018 11:32 | 11:32 | 11:00 | 0       | 0       | 0       |
| 5/24/2018 12:32 | 12:32 | 12:00 | 0       | 0       | 0       |
|                 |       | 13:00 |         |         |         |
| 5/24/2018 14:23 | 14:23 | 14:00 | 0       | 0       | 0       |
| 5/24/2018 15:46 | 15:56 | 15:00 | 0       | 0       | 0       |
|                 |       | 16:00 |         |         |         |
|                 |       | 17:00 |         |         |         |
|                 |       | 18:00 |         |         |         |
| 5/24/2018 19:41 | 19:41 | 19:00 | 0       | 0       | 0       |
| 5/24/2018 19:41 | 19:41 | 20:00 | 0       | 0       | 0       |
| 5/24/2018 19:41 | 19:41 | 21:00 | 0       | 0       | 0       |
| 5/24/2018 22:41 | 22:41 | 22:00 | 0       | 0       | 0       |
|                 |       | 23:00 |         |         |         |
| 5/25/2018 0:23  | 0:23  |  0:00 | 0       | 0       | 0       |


