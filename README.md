Bluetooth
=========
It is a Bluetooth Attandence system, I prepared in my B-tech Minor and Major

Requirements:
Hardware:
1. Raspberry pi (Type B) (Client machine)
2. Bluetooth Dongle for Raspberry Pi
3. Server Linux Machine (I worked over Ubuntu)
4. Ethernet port active in both machines

Software:
Client:
1. Mysql 
2. bluez stack
3. gcc and g++

Server:
1. Mysql
2. gcc and g++
3. Qt 4.8.4 

Usage:
Core hardware usage :
dump BAS.sql into your server machine. (it will create your database in mysql)
connect client and server both and start program client_new.c on client machine(Rpi) and testRpi.c server machine (Linux machine).
It will start listening and sending 

Gui:
open SmartAttendece 
qmake
make
./SmartAttendence
and run Gui

Contact:
talentediq@gmail.com
