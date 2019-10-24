Hardware are Unlicense

android App are fork and modify from  [SimpleBluetoothTerminal](#https://github.com/kai-morichSimpleBluetoothTerminal) base on MIT license

many thanks

I have made the PCB and tested it, <del>every thing is good</del> except 

* some capacitors' footprint is not right(but I bend the leg....lol)

* pin3 and pin6 for IC1 should swap

* **the input voltage should abrove 7V**, in my case I only put 6V so that's a cirtical error. 

I think I have 3 options
 
1. connect to a 7.2V Li-ion battery

2. **remove the 7805 voltage regulator and put a Zener diode instead. ** [my choise]

3. remove the 7805 voltage regulator and put another 3.3V voltage regulator instead(like LM1117). but that would be a huge change bucause I need to change the capacitors too


TB6612 2.2mA
hc-02 30mA