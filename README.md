Basic snake game playing around with object collisions, movement & my first ever main menu! 
At first I struggled with the body collision lose logic because the way the movement worked was that each element of a vector was the snake's body, and their positions were being updated according to the head or 0th vector element, and since the body was overlapping the head
ever since the game starts due to the movement logic, the game was ending immediately after it starts. To fix this, I used data structure logic using std::deque where I used front() and made a duplicate head everytime and also removed the tail or the back element using pop_back().
I also adjusted the move speed, circle spacing & framerate so it doesn't glitch out and this time, the body collision works perfectly!
