#include  "../vex.h"
#include "../motors/v5_two.h"
#include "../auton/v5_autons.h"
#include "v5_drive.h"

#ifndef VEXT_CHAINDRIVE_H
#define VEXT_CHAINDRIVE_H

/*-----------------------------------------------------------------------------*/
/** @file       v5_chaindrive.h
 *  @brief      This class utilizes the vlib::two motorgroup to provide
 *              functionality for building a chaindrive (one motor per side,
 *              with wheels connected by a chain).
 *              Controller binding is provided with a function,
 *              intended for one-stick control.
 *              Some of the methods are intended for use with autons.
 *//*---------------------------------------------------------------------------*/

namespace vext {
    /*! \addtogroup drive
    *  @{
    */
    class chaindrive : public drive {
    /*! @} */
    private:
      vext::two motors;

    public:
      /*
       * Construct a chaindrive with left and right motors
       * @param left Left port
       * @param right Right port
       */
      chaindrive(int32_t left, int32_t right) {
        auto leftMotor = vex::motor(left, true);
        auto rightMotor = vex::motor(right);
        motors = two(leftMotor, rightMotor);
      };

      /**
       * Rotate the robot by an specific amount of degrees.
       *
       * Intended for use with autons.
       *
       * @param degrees Angle to spin bot, in degrees
       * @param speed The percentage of motor power to apply
       */
      void spinBy(double degrees, double speed);

      /**
       * Move the robot by an specific amount of inches.
       *
       * Intended for use with autons.
       *
       * @param inches Distance to move, in inches
       * @param speed The percentage of motor power to apply
       */

      void moveBy(double inches, double speed);

      /**
       * Drive a two-motor chaindrive bot in a straight line
       *
       * @param power The percentage of motor power to apply
       */

      void straight(int power);

      /**
       * Turn a two-motor bot using the controller joysticks
       *
       * @param x The position of the horizontal joystick
       * @param y The position of the vertical joystick
       */

      void turn(int x, int y);

      /**
       * Stop a two-motor bot and hold
       */

      void stop();

    };
} // namespace vlib

#endif
