# CueLightTrigger
A short embedded script to allow an arduino to interface with a tallyman tally system and trigger multiple camera mounted LEDs and monitor tally LEDs. The script consists of two sets of files, one for the trigger controller and one for the remotes, named accordingly. The trigger MCU is an arduino uno mounted in a control box to be placed in a central apparatus room, and the remote consists of an arduino mini pro mounted inside a Nuetrik Ethercon Coupler NE8FF, connected to each cat5 couplers pins. 

The basic premise of scripts is that two pins over a cat5 interface carry a binary channel selection via pulling each pin from default HIGH to LOW (MSB, TTL, up to four channels). Each remote checks these channel pins and compares them to a four channel dip switch attached to the MCU. If the channel selection pins are pulled to the channel that corresponds to the pin selected on the dip switch, the remote MCU will turn on a red LED and close a contact connected to two pins on the other connector. 

The full pinout is as follows:

Arduino Uno        Cat5         Pro Mini     Programming / Pass-Thru         LED        Dip Switch
    Pin            Pin            Pins                 Pins                  Pins          Pins
--------------------------------------------------------------------------------------------------
    GND             1              GND                 N/C
    N/C             2              RAW                 N/C                          
     2              3               2                  GND
     3              4               3                  VCC
    SDA             5              SCA                 RST
    SCL             6              SCL                 N/C
    RST             7              RST                 RX
     4              8               9                  TX
                                    8                                        POS
                                   GND                                       GND            
                                    4                                                       CH1
                                    5                                                       CH2
                                    6                                                       CH3
                                    7                                                       CH4
                                   GND                                                      GND
                    


(Raw pin is fed from a seperate 12VDC PSU in the control box with the Uno)