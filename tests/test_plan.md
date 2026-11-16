\\Test Plan – Smart Classroom Comfort Monitor

1. Objective

The purpose of testing is to verify that the Raspberry Pi correctly reads temperature inputs, determines whether temperatures are within the acceptable range, and controls the LED accordingly.

2. Testing Requirements
- Acceptable temperature range: 68°F–76°F.
- LED turns ON when temperature is below 68°F or above 76°F.
- LED turns OFF when temperature is between 68°F and 76°F, including the boundary values.
- The program calculates the average of five temperature readings.
3. Test Cases

Test	Temperature Input	Expected LED	Expected Result
T1	           60°F	               ON	          Too cold
T2	           65°F	               ON	          Too cold
T3	           68°F	               OFF	        Lower boundary
T4	           72°F	               OFF	        Normal temperature
T5	           76°F	               OFF	        Upper boundary
T6	           78°F	               ON	          Too hot
T7	           85°F	               ON	          Too hot

4. Outcome
The program should successfully identify temperatures outside the acceptable range, activate the LED warning, turn off the LED when temperatures return to the acceptable range, and calculate the average of five readings.

5. Conclusion
The test plan verifies that the Smart Classroom Comfort Monitor works as intended. Successful testing confirms that the temperature checking logic, LED warning system, and average calculation function correctly.
