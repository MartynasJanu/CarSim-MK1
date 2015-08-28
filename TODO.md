###Current version: 0.0a


####v0.2a TODO:

[ ] Saving/loading machines

[ ] Add friction

####v0.1a TODO:

[ ] Prepare the project

[ ] Build basic interfaces, abstract classes and classes

[ ] Build the main loop mechanism

[ ] Build test machine and run it with reasonable results



------------
* Battery
Stores: electricity
Inputs: electricity
Outputs: electricity

* Spark plug:
Stores: electricity
Inputs: electricity
Outputs: spark

* Firing chamber
Stores: volume, fuel, air
Triggered by: spark
Inputs: volume, fuel, air, spark
Outputs: force, air

* Fuel injector
Stores: fuel
Triggered by: el_impulse
Inputs: fuel
Outputs: fuel

* Fuel tank
Stores: fuel
Inputs: fuel
Outputs: fuel

* Intake valve
Stores: air
Inputs: air
Output: air

* Exhaust valve
Stores: air
Inputs: air
Output: air

* Atmosphere
Stores: air
Input: air
Output: air

* Piston
Outputs to firing chamber: volume
Inputs from firing chamber: volume
Inputs: force
Outputs: force

* Crankshaft tooth
Inputs: force, torque
Outputs: force, torque

* Crankshaft:
Inputs: torque
Outputs: torque

* Flywheel
Inputs: torque
Outputs: torque

* cog
Inputs: force
Outputs: force, torque