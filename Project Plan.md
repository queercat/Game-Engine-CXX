# Feature List
	* Be able to render a level.
	* Be able to move a camera around a level.

# System Design
	
[Initialization] -> [Loop] -> [Clean Up]

--------------------------------------------------

# [Initialization]

[Initialize SDL] -> [Load Level] -> [Start Loop]

# [Loop]

[Game Logic] -> [Render Engine]

# [Clean Up]

[Destroy SDL Objects] -> [Quit SDL]

--------------------------------------------------

# [Game Logic]
[Execute Logic Bus] -> [Check Inputs] -> [Check Entity List]

# [Render Engine]
[Append Render Bus to Back Buffer] -> [Update Display]