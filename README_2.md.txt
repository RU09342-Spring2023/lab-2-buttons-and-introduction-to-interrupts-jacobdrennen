Part 4 of lab:
Part 4 of the lab was building a make shift alarm system using buttons. To do this I layed out
some psuedocode of what the code structure should look like. After that the next step was to set
all the ports and pins I would be using in the code. Next, was to program how the 2.3 pin button
would work. If the button was not being pressed the button would blink every 3 seconds, and if the
button was pressed the button would start blinking every .5s for 15 seconds. This was done with 
to if statements to determine if the button was pressed. Then for the 15 seconds there was a while
statement that had a counter going up every cycle. Next was to code how the led would stay on 
after 15 seconds. To achieve this I made an If statment that would look at the counter to statement
if it was greater then or equal to a certain value. The final step was to make the reset switch
with the other 4.1 button. To this I made an if staement outside of the if statement for the
2.3 button that looked to see if the button was presssed then reset the green switch off and set
the counter to 0.