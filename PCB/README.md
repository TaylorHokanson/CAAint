# PCB
We're trying to figure out how to supply the Node with efficient battery
power. It seems inefficient to start with a 3.7V LiPo, boost it to 5V, then
pull it back down to 3.3V via the onboard regulator. There's got to be a better way!

### Proposal
1. Remove the Node's 3.3V regulator.
2. Connect the LiPo charger board inputs (5V and Gnd) to the appropriate Node pins. Some Nodes have a VU pin to make this easy, some don't.
2. Connect 3.7V LiPo > battery recharger/protection board > buck/boost > Node 3.3V pin.
3. The above circuit should account for the variable voltage range the battery will supply.
5. It should also allow you to plug into the Node via USB and still charge the battery.

![alt text](1/SPX3819_pinout.jpg)

### Tiny Ass Regulator #1
This breakout was designed around the correct package but the wrong pinout. AFAIK, you can leave off the caps entirely and still get a reasonable 
 