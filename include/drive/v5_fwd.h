/*-----------------------------------------------------------------------------*/
/* @file   v5_fwd.h
 * @brief   This class utilizes the vlib::four motorgroup to provide
 *          functionality for building a four-wheel drive.
 *          Controller binding is provided with a function,
 *          intended for two-stick control.
 *          Some of the methods are intended for use with autons.
 *//*---------------------------------------------------------------------------*/

#ifndef VEXT_FWD_H
#define VEXT_FWD_H

#include "v5_drive.h"
#include "../motors/v5_four.h"
#include "../auton/v5_autons.h"

namespace vext {
    /*! \addtogroup drive
    *  @{
    */
    class fwd : public drive, public vext::four {
    /*! @} */
    protected:
      bool moveWhileTurning;
      double diag;
      double wh;
      alliance allianceColor = alliance::RED;
    public:
      /*
      * Construct a chaindrive with left and right motors
      * @param left Left port
      * @param right Right port
      */
      fwd(vex::motor leftA ,vex::motor leftB, vex::motor rightA, vex::motor rightB, double wheel, double diagonal) : vext::four(leftA, leftB, rightA, rightB) {
        diag = diagonal;
        wh = wheel;
      };

      /**
      * Rotate the robot by an specific amount of degrees.
      *
      * Intended for use with autons.
      *
      * @param degrees Angle to spin bot, in degrees
      * @param speed The percentage of motor power to apply
      * @param left Left motor
      * @param right Right motor
      */
      void spinBy(double degrees, double speed);

      /**
      * Move the robot by an specific amount of inches.
      *
      * Intended for use with autons.
      *
      * @param inches Distance to move, in inches
      * @param speed The percentage of motor power to apply
      * @param left Left motor
      * @param right Right motor
      */

      void moveBy(double inches, double speed);

      /**
      * Drive a two-motor chaindrive bot in a straight line
      *
      * @param speed The percentage of motor power to apply
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
      *
      * @param speed The percentage of motor power to apply
      * @param left Left motor
      * @param right Right motor
      */

      void stop();

      void stopCoast();

      /**
        * @prog_lang{block|cpp|pro}
        * @drawer_cat{setting}
        * @block_sig{Motor.setMaxTorque(50,percent);}
        * @cpp_sig{Motor.setMaxTorque(50,vex::percentUnits::pct);}
        * @brief Sets the max torque of the motor.
        * @param value Sets the amount of torque.
        * @param units The measurement unit for the torque value.
        */
      void            setMaxTorque( double value, vex::percentUnits units );

      /**
        * @prog_lang{cpp|pro}
        * @drawer_cat{setting}
        * @block_sig{Motor.resetRotation();}
        * @brief Resets the motor's encoder to the value of zero.
        */
      void            resetRotation( void );

      /**
          * @prog_lang{cpp|pro}
          * @drawer_cat{action}
          * @block_sig{Motor.startRotateTo(90,vex::rotationUnits::deg,50,vex::velocityUnits::pct);}
          * @brief Starts spinning a motor to an absolute target rotation but does not wait for the motor to reach that target.
          * @param rotation Sets the amount of rotation.
          * @param units The measurement unit for the rotation value.
          * @param velocity Sets the amount of velocity.
          * @param units_v The measurement unit for the velocity value.
          */
    void            rotateTo( double rotation, vex::rotationUnits units, double velocity, vex::velocityUnits units_v );

    void setAlliance(alliance a) {
      allianceColor = a;
    }
    vext::alliance getAlliance() {
      return allianceColor;
    }


    };
} // namespace vext
#endif
