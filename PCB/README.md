# PCB
We're trying to figure out how to supply the Node with efficient battery
power. It seems inefficient to start with a 3.7V LiPo, boost it to 5V, then
pull it back down to 3.3V via the onboard regulator. There's got to be a better way!

### Proposal
1. Remove the Node's 3.3V regulator.
2. Connect the LiPo charger board inputs (5V and Gnd) to the appropriate Node pins. Some Nodes have a VU pin to make this easy, some don't.
2. Connect 3.7V LiPo > [https://tinyurl.com/y8s9t5f9](battery recharger/protection board) > [https://www.mouser.com/Search/ProductDetail.aspx?R=SPX3819M5-L-3-3%2fTRvirtualkey66950000virtualkey701-SPX3819M5-L-33TR](buck/boost) > Node 3.3V pin.
3. The above circuit should account for the variable voltage range the battery will supply.
5. It should also allow you to plug into the Node via USB and still charge the battery.

![alt text](1/SPX3819_pinout.jpg)
![alt text](1/tiny-ass-setup.jpg)

### Tiny Ass Regulator #1
This breakout was designed around the correct package but the wrong
pinout. AFAIK, you can leave off the caps entirely and still get good
performance. I tested the setup with USB plugged in, then uploaded the
HelloServer demo file so that I could verify the circuit was working
without serial feedback.
 
### Design #2