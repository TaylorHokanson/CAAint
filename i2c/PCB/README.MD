##Seeed Fusion PCB Design Notes
Some of the following are hard and fast rules. Others are just there to qualify for a discount.

1. 100 x 100 mm
2. Panelized designs can only feature two variations
3. Smallest trace/clearance is 6/6 mil
   - Work larger whenever possible
   - Edit > Net Classes to establish t/c families
      - defaults 10/10 mil
      - VCC/GND 25/10 mil
4. Circuit-to-edge: .3mm
5. Circuit-to-V groove: .8mm
   - Seeed DRC will not catch this
   - Measured from V groove centerline
    - Our modified Seeed DRC has a Distance > Copper/Dimension of 40mil to account for this omission

##Eagle Design Notes
1. TBA
