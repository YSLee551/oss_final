# 2021-1 OSS Lab Class Final Project
22000551 Yongseok Lee

**Project name**
    
    Ticket Sales Management Program

**Inspiration**

      In Handong, there are many concerts that sell tickets. I’ve seen most of them writing sales record by hand.
      This way is slow, you can’t sort, if you want to get some meaningful info from the data you have to calculate every time a new dataset comes in.


**What does this project do?**

    ● This project makes managing ticket sales much easier.
    
    ● Enter reservation info and save in file.
  
    ● Calculates, sorts, and searches data from the list.
  
   
**Why is this project useful?**

    ● You can easily open an existing file to continue writing.
  
    ● Saves list in a file for later.
  
    ● Calculates and searches meaningful data for sales.
  
   
**How do I get started?**

    1. Only thing you need is a raspberrypi computer connected to internet.
    
    2. Download zip file or clone this project.
       
       $ git clone https://github.com/YSLee551/oss_final.git
  
    3. In terminal, go to the directory where the file is located.
    
    4. Compile oss_final.cpp file with g++. If you don't have g++, you can easily download with apt-get.
    
        $ sudo apt-get update
        $ sudo apt-get install g++
    
        $ g++ -o management_program oss_final.cpp
        
    5. Run compiled file.
        
        $ ./management_program
        
    6. Enter the name of your list file. The names of sample list files are <ticket.txt> and <new_ticket.txt>.
    
    7. Enter an option number to use functions.
    
    8. You can save the result with option <7. Save≥>.
  
      
**Where can I get more help, if I need it?**
 
    email: 22000551@handong.edu
 
**Contributions**

    I, Yongseok Lee, came up with idea, designed, and developed on my own.
    I referenced binary search tree algorithm from Data Structure class.
   
**Presentation Video**
    -> https://youtu.be/1qw6ul-of9Y
  
