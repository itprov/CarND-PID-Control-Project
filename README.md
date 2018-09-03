# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## PID controller

The PID controller comprises of 3 components: P (Proportional), I (Integral), and D (Differential). Here's the effect of these 3 components in the PID algorithm:

[//]: # (Image References)

[image1]: ./images/P_vs_PI.png "Effect of adding I component"
[image2]: ./images/P_vs_PI_vs_PID.png "Effect of adding D component"

**P (Proportional) Component**
This component causes steering of the vehicle toward the reference trajectory (in this case the center line of the track) in proportion to the cross-track error (CTE), which is the lateral distance between the reference trajectory and the vehicle. Use of this component alone results in overshooting of the vehicle about the center line, i.e. the vehicle oscillates on the road. The larger the value of the P component coefficient (Kp), the larger the amplitude of oscillations.

**I (Integral) Component**
This component results in compensating CTE increase caused by the systematic bias, such as steering drift causing the vehicle to turn away from the reference trajectory, due to misaligned wheels. It is proportional to the integrated CTE, which is the integral or sum of all CTEs accumulated over time.
In a perfect vehicle, if there is 0 bias in the vehicle system, use of this component would not be necessary. Apparently it amplifies the amplitude and frequency of oscillations in an unbiased system.
[Effect of adding I component][image1]

**D (Differential) Component**
This component results in dampening the oscillations caused by P & I components and thereby avoiding the overshooting of the vehicle. It is proportional to the derivative of CTE w.r.t. time.
[Effect of adding D component][image2]

**Hyperparameter value selection**
* I manually tuned the coefficients of the 3 components (Kp, Ki, and Kd). I started with Kp = 1.0, Kd = 0, Ki = 0, and then gradually decreased the value of Kp (to decrease the oscillation amplitude) while increasing the other 2 coefficient values.
[P controlled steering](./videos/P.mov)

* As mentioned above, I found that the I component resulted in amplifying the oscillation amplitude and frequency. I left a non-zero value of Ki = 0.0003 to ensure the controller will continue to work in case of biased system or steering drift. Values of Ki around 0.001 and above were found to be too high for the vehicle to safely drive along the track.
[PI controlled steering](./videos/PI.mov)

* Finally, I set Kd = 1.0 and increased it by 1 until the vehicle was able to drive safely along the entire track multiple times. Increasing Kd to values higher than 5.0 didn't seem to have any significant effect on the CTE.

The final combination of the hyperparameters is Kp = 0.2, Ki = 0.0003, Kd = 5.0.
[Final PID controlled steering](./videos/PID.mov)


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).
