#import "vlib_chaindrive.h"

      /**
      * Rotate the robot by an specific amount of degrees.
      *
      * Internal and blocking.
      *
      * @param degrees Angle to spin bot, in degrees
      * @param speed The percentage of motor power to apply
      */
      void vlib::chaindrive::_spinBy(double degrees, double speed) {
          double revs = ((degrees/360.0) * 13.70)/4;
          getLeft().spinFor(-revs, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, false);
          getRight().spinFor(revs, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, true);
      }


    /**
    * Move the robot by an specific amount of inches.
    *
    * Internal and blocking.
    *
    * @param inches Distance to move, in inches
    * @param speed The percentage of motor power to apply
    */

    void vlib::chaindrive::_moveBy(double inches, double speed) {
        double revs = inches / (5 * M_PI);
        getLeft().spinFor(-revs, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, false);
        getRight().spinFor(-revs, vex::rotationUnits::rev, speed, vex::velocityUnits::pct, true);
    }

    /**
    * Drive a two-motor bot in a straight line
    *
    * @param speed The percentage of motor power to apply
    */

    void vlib::chaindrive::straight(int power)  {
      vlib::two::straight(power, getLeft(), getRight());
    }

    /**
    * Turn a two-motor bot using the controller joysticks
    *
    * @param x The position of the horizontal joystick
    * @param y The position of the vertical joystick
    */

    void vlib::chaindrive::turn(int x, int y)  {
        vlib::two::turn(x, y, getLeft(), getRight());
    }


    /**
    * Stop a two-motor bot and hold
    *
    * @param speed The percentage of motor power to apply
    * @param left Left motor
    * @param right Right motor
    */

    void vlib::chaindrive::stop() {
       vlib::two::stop(getLeft(), getRight());
     }

    void vlib::chaindrive::bind(vex::controller::axis x, vex::controller::axis y) {
      static auto moveUpdate = [&] {
        if (direction(y) != 0 && direction(x) == 0) { // axis 1 and axis 3
          straight(-1 * y.position());
        } else if (direction(x) != 0) {
          turn(x.position(), y.position());
        } else {
          stop();
        }
      };

      y.changed([] { moveUpdate(); });
      x.changed([] { moveUpdate(); });
    }
 // namespace vlib