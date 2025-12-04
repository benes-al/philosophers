```
        _     _ _       
       | |   (_) |      
  _ __ | |__  _| | ___  
 | '_ \| '_ \| | |/ _ \ 
 | |_) | | | | | | (_) |
 | .__/|_| |_|_|_|\___/ 
 | |                    
 |_|                    
 ```
 
🍽️ Simulation Behavior

Philosophers alternate between thinking, eating, and sleeping.

To eat, a philosopher must take two forks (mutexes).

A philosopher dies if they don’t start eating before their time_to_die.

The simulation ends when:

A philosopher dies, or

All philosophers have eaten the required number of times (only if the 5th argument is provided).


🛠️ Build the program:

make


▶️ Run the program:

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]


Example:

./philo 5 800 200 200


📜 Arguments

number_of_philosophers
Must be ≥ 1.

time_to_die
Time (in ms) a philosopher can stay alive without eating.

time_to_eat
Time (in ms) a philosopher spends eating.

time_to_sleep
Time (in ms) a philosopher spends sleeping.

(Optional) number_of_times_each_philosopher_must_eat
Simulation ends when all philosophers have eaten this many times.


⚠️ Invalid Input

The program will print an error if:

Arguments are missing or invalid.

Values are non-numeric or negative.

The number of philosophers is 0.

Timing parameters are 0.
