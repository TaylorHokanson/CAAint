Useful stuff:

MOVE (>0 0) (X Y); to move groups to a new relative X Y position

Board now centered on origin. Use 16.666, 8.333, 4.166, 2.083, and 1.042 grids for general placement.

Changes:

Cleaned up library. Most parts are now defined at library level, including protogrid and power rails. Made custom definition of RGB LEDs so that I could include the cap footprint, this helps prevent endless dragging of multiple parts during layout experiementation. Left the original set in place so that we can verify the wiring transferred OK. Added a switch and two styles of battery mount, switch should isolate bat from USB if both are present (though please check up on my work).
