#include "vex.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2017, All rights reserved.               */
/*                                                                            */
/*    Module:     vex_motorgroup.h                                            */
/*    Author:     James Pearman                                               */
/*    Created:    7 April 2019                                                */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef   VEXT_MOTOR_CLASS_H
#define   VEXT_MOTOR_CLASS_H

namespace vext {
  
  class motor : public vex::motor {
    public:
     /** 
     * @prog_lang{cpp|pro}
     * @drawer_cat{constructor}
     * @block_sig{vex::motor Motor = vex::motor(vex::PORT1);}     
     * @brief Creates a new motor object on the port specified.
     * @param index The port index for this motor. The index is zero-based.
     */
      motor( int32_t index ) : vex::motor(index) {};  
      ~motor() {

      }

     /** 
      * @prog_lang{cpp|pro}
      * @drawer_cat{constructor}
      * @block_sig{vex::motor Motor = vex::motor(vex::PORT1, false);}
      * @brief Creates a new motor object on the port specified and sets the reversed flag.
      * @param index The port index for this motor. The index is zero-based.
      * @param reverse Sets the reverse flag for the new motor object.
      */
      motor( int32_t index, bool reverse ) : vex::motor(index, reverse) {};

     /** 
      * @prog_lang{cpp|pro}
      * @drawer_cat{constructor}
      * @block_sig{vex::motor Motor = vex::motor(vex::PORT1, vex::gearSetting::ratio18_1);}
      * @brief Creates a new motor object on the port specified and sets the gear setting
      * @param index The port index for this motor. The index is zero-based.
      * @param gears Sets the gear's setting for the new motor object.
      */  
      motor( int32_t index, vex::gearSetting gears ) : vex::motor(index, gears) {};

      /** 
      * @prog_lang{cpp|pro}
      * @drawer_cat{constructor}
      * @block_sig{vex::motor Motor = vex::motor(vex::PORT1, vex::gearSetting::ratio18_1, false);}
      * @brief Creates a new motor object on the port specified Sets the reversed flag and the gear setting for the new motor object.
      * @param index The port index for this motor. The index is zero-based.
      * @param gears Sets the gear's setting for the new motor object.
      * @param reverse Sets the reverse flag for the new motor object.
      */  
      motor( int32_t index, vex::gearSetting gears, bool reverse ) : vex::motor(index, gears, reverse) {};

      void straight(int power) {
        vex::directionType direction =
            power < 0 ? vex::directionType::fwd : vex::directionType::rev;
        this->spin(direction, abs(power), vex::percentUnits::pct);
      }

    };
  }

  #endif