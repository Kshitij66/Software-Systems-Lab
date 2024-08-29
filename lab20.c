//Kshitij Tiwari MT2024080 
//Lab20 
//Obtain the priority of current running process and modify it using nice command

First of all I had compile and execute a infinite program which I have create in lab2 of this hands-on.

i) using the command "nice -n 5 ./lab2.out &" I have set the nice value of this particular process to 5. 

ii) Then using command "ps-l" I have obtained the confirm whether for that particular process nice value is successfully set or not

iii) Now to reset the priority I have used another command 
    "renice 2 -p 12267" here "2" signifies the new priority i.e. nice value of the process. "12267" is process id of lab2.out process.
    
    Output flashed on the screen was :- 12267 (process ID) old priority 5, new priority 2
    
