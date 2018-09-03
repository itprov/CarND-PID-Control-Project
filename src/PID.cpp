#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

// Initialize all member variables using initializer list
PID::PID(double Kp, double Ki, double Kd) :
    Kp(Kp), Ki(Ki), Kd(Kd), p_error(0), d_error(0), i_error(0)  {}

PID::~PID() {}

void PID::UpdateError(double cte) {
  // Differential term = current cte - previous cte
  d_error = cte - p_error;
  // Add current cte to itegral term
  i_error += cte;
  // Update previous cte
  p_error = cte;
}

double PID::TotalError() {
  // steering = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte
  return - Kp * p_error - Kd * d_error - Ki * i_error;
}
